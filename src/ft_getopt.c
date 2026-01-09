/*
 * ft_getopt.c ― POSIX-style and re-entrant getopt clone for mylib
 *
 *   Build options:
 *     - uses ft_strcmp / ft_strchr from the rest of mylib
 *
 *   Public API (see <mylib/ft_getopt.h>):
 *     int  ft_getopt (int argc, char *const argv[], const char *optstring);
 *     int  ft_getopt_r(ft_getopt_state *st,
 *                      int argc, char *const argv[], const char *optstring);
 *
 *   The classic interface exposes globals (thread-unsafe but familiar):
 *       int  ft_optind  = 1;
 *       int  ft_optopt  = 0;
 *       int  ft_opterr  = 1;
 *       char *ft_optarg = NULL;
 *
 *   The re-entrant interface keeps its own state in a user-supplied
 *   ft_getopt_state struct and never touches global variables.
 */

#include <stdio.h>              /* fprintf */
#include "libft/ft_getopt.h"    /* prototypes / struct */
#include "libft/libft.h"        /* ft_strcmp, ft_strchr */

/* ────────────────────────────────────────────────────────────────────── */
/*  Global variables for the POSIX-style wrapper                         */
/* ────────────────────────────────────────────────────────────────────── */
int ft_optind = 1;
int ft_optopt = 0;
int ft_opterr = 1;
char *ft_optarg = NULL;

/* ────────────────────────────────────────────────────────────────────── */
/*  Internal worker: does all the actual parsing                         */
/* ────────────────────────────────────────────────────────────────────── */
static int
_getopt_internal(
    int *p_optind,
    int *p_optopt,
    int *p_opterr,
    char **p_optarg,
    int *p_optpos,
    int argc,
    char *const argv[],
    const char *optstring
) {
    /* Ensure optpos starts at 1 the first time */
    if (*p_optpos < 1)
        *p_optpos = 1;

    /* -------- 1. out-of-arguments or not an option ------------------- */
    if (*p_optind >= argc ||
        argv[*p_optind][0] != '-' ||
        argv[*p_optind][1] == '\0')
        return -1;

    /* -------- 2. "--" terminator ­­----------------------------------- */
    if (ft_strcmp(argv[*p_optind], "--") == 0) {
        ++(*p_optind);
        *p_optpos = 1;
        return -1;
    }

    /* -------- 3. examine current option char ------------------------- */
    char opt = argv[*p_optind][*p_optpos];
    const char *spec = ft_strchr(optstring, opt);

    /* unknown option -------------------------------------------------- */
    if (!spec) {
        *p_optopt = opt;
        if (*p_opterr)
            fprintf(stderr, "ft_getopt: unknown option '-%c'\n", opt);

        /* advance to next character / argv */
        goto advance_char_and_return_unknown;
    }

    /* option takes an argument? --------------------------------------- */
    if (spec[1] == ':') {
        int argument_optional = (spec[2] == ':'); /* "::" */

        /* 3.a  attached argument "-oARG" or "-o=ARG" ------------------ */
        if (argv[*p_optind][*p_optpos + 1] != '\0') {
            *p_optarg = &argv[*p_optind][*p_optpos + 1];
            if (**p_optarg == '=') /* "-o=ARG" */
                ++(*p_optarg);
            goto advance_argv_and_return_option;
        }

        /* 3.b  separate argument "-o ARG" ----------------------------- */
        if (*p_optind + 1 < argc &&
            (!argument_optional || argv[*p_optind + 1][0] != '-')) {
            *p_optarg = argv[*p_optind + 1];
            *p_optind += 2;
            *p_optpos = 1;
            return opt;
        }

        /* 3.c  optional argument missing ------------------------------ */
        if (argument_optional) {
            *p_optarg = NULL;
            goto advance_argv_and_return_option;
        }

        /* 3.d  **missing required** argument -------------------------- */
        *p_optopt = opt;
        if (*p_opterr)
            fprintf(stderr,
                    "ft_getopt: option '-%c' requires an argument\n", opt
            );
        ++(*p_optind);
        *p_optpos = 1;
        return ':'; /* POSIX signal  */
    }

    /* flag option – no argument --------------------------------------- */
    *p_optarg = NULL;

advance_char_and_return_unknown:
    /* advance inside current "-abc" cluster */
    if (argv[*p_optind][++(*p_optpos)] == '\0') {
    advance_argv_and_return_option:
        ++(*p_optind);
        *p_optpos = 1;
    }

    /* return '?' for unknown, or the actual option letter */
    return spec ? opt : '?';
}

/* ────────────────────────────────────────────────────────────────────── */
/*  POSIX-style wrapper (uses globals)                                   */
/* ────────────────────────────────────────────────────────────────────── */
int
ft_getopt(int argc, char *const argv[], const char *optstring) {
    /* static keeps position across calls */
    static int optpos = 1;
    return _getopt_internal(&ft_optind, &ft_optopt, &ft_opterr,
                            &ft_optarg, &optpos,
                            argc, argv, optstring
    );
}

/* ────────────────────────────────────────────────────────────────────── */
/*  Re-entrant wrapper (caller provides state struct)                    */
/* ────────────────────────────────────────────────────────────────────── */
int
ft_getopt_r(
    ft_getopt_state *st,
    int argc,
    char *const argv[],
    const char *optstring
) {
    if (!st) /* defensive */
        return -1;

    return _getopt_internal(&st->optind, &st->optopt, &st->opterr,
                            &st->optarg, &st->_optpos,
                            argc, argv, optstring
    );
}
