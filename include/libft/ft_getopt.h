#ifndef LIBFT_FT_GETOPT_H
#define LIBFT_FT_GETOPT_H
#ifdef __cplusplus
extern "C" {
#endif

    /* ---------------- classic POSIX-style ---------------- */
    extern int  ft_optind;   /* =1 */
    extern int  ft_optopt;   /* =0 */
    extern int  ft_opterr;   /* =1 */
    extern char *ft_optarg;  /* =NULL */

    int ft_getopt(int argc, char *const argv[], const char *optstring);

    /* ---------------- re-entrant, no globals ------------- */
    typedef struct {
        int   optind;   /* public – initialise to 1 */
        int   optopt;   /* public – read-only for caller */
        int   opterr;   /* public – default 1 (print on error) */
        char *optarg;   /* public – result */
        /* private: */
        int _optpos;
    } ft_getopt_state;

    int ft_getopt_r(ft_getopt_state *st,
                    int argc, char *const argv[], const char *optstring);

#ifdef __cplusplus
}
#endif
#endif /* LIBFT_FT_GETOPT_H */
