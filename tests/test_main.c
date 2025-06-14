#include <string.h>
#include <secure/_string.h>

#include "libft/libft.h"
#include "libft/ft_getopt.h"
#include "assert.h"
#include "stdio.h"

// void test_ft_memcpy(void)
// {
//     char buf1[16], buf2[16];
//
//     strcpy(buf1, "hello world");
//     ft_memcpy(buf2, buf1, strlen(buf1) + 1);
//     assert(strcmp(buf1, buf2) == 0);
//
//     puts("ft_memcpy test passed");
// }

void test_ft_strtol(void)
{
    char *end;

    assert(ft_strtol("42", &end, 10) == 42 && *end == '\0');
    assert(ft_strtol("   -101", &end, 2) == -5);
    assert(ft_strtol("0xFF", &end, 0) == 255);
    assert(ft_strtol("0755", &end, 0) == 493);
    assert(ft_strtol("123abc", &end, 10) == 123 && *end == 'a');
    assert(ft_strtol("deadBEEF", &end, 16) == 0xDEADBEEF);
    assert(ft_strtol("zzz", &end, 36) == (35 + 36 * 35 + 36 * 36 * 35));
}

void test_ft_memset(void)
{
    char buf1[10], buf2[10];

    memset(buf1, 'x', sizeof(buf1));
    ft_memset(buf2, 'x', sizeof(buf2));

    assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);
    puts("ft_memset test passed");
}

static void test_posix_style(void)
{
    char *argv[] = { "prog", "-a", "-bfoo", "--", "-c", NULL };
    int   argc   = (int)(sizeof(argv)/sizeof(*argv)) - 1;

    int opt;
    while ((opt = ft_getopt(argc, argv, "ab:")) != -1) {
        if (opt == 'a')
            assert(ft_optarg == NULL);
        else if (opt == 'b')
            assert(ft_strcmp(ft_optarg, "foo") == 0);
        else
            assert(0 && "unexpected option");
    }
    assert(ft_optind == 4); /* argv[4] == "-c" */
}

static void test_reentrant(void)
{
    char *argv[] = { "prog", "-x", "bar", NULL };
    int   argc   = 3;
    ft_getopt_state st = { .optind = 1, .opterr = 0 };

    int opt = ft_getopt_r(&st, argc, argv, "x:");
    assert(opt == 'x');
    assert(ft_strcmp(st.optarg, "bar") == 0);
    assert(ft_getopt_r(&st, argc, argv, "x:") == -1);
}

void test_ft_strchr(void) {
   assert(ft_strcmp(ft_strchr("hello", 'h'), "hello") == 0);
    assert(ft_strcmp(ft_strchr("hello", 'e'), "ello") == 0);
    assert(ft_strcmp(ft_strchr("hello", 'l'), "llo") == 0);
    assert(ft_strcmp(ft_strchr("hello", 'o'), "o") == 0);
    assert(ft_strchr("hello", 'x') == NULL);
    assert(ft_strchr("", 'a') == NULL);
    assert(ft_strcmp(ft_strchr("abc", '\0'), "") == 0);// Points to the null terminator Null terminator case
}

void test_ft_strcmp(void) {
    assert(ft_strcmp("hello", "hello") == 0);
    assert(ft_strcmp("hello", "world") < 0);
    assert(ft_strcmp("world", "hello") > 0);
    assert(ft_strcmp("abc", "abcd") < 0);
    assert(ft_strcmp("abcd", "abc") > 0);
    assert(ft_strcmp("", "") == 0);
    assert(ft_strcmp("", "a") < 0);
    assert(ft_strcmp("a", "") > 0);
}

int main(void) {
    test_ft_strcmp();
    test_ft_strchr();
    test_posix_style();
    test_reentrant();
    test_ft_strtol();

    printf("All tests passed!\n");
    return 0;
}