#include "libft/libft.h"
#include "assert.h"
#include "stdio.h"

void test_ft_strchr(void) {
    assert(ft_strchr("hello", 'h') == "hello");
    assert(ft_strchr("hello", 'e') == "ello");
    assert(ft_strchr("hello", 'l') == "llo");
    assert(ft_strchr("hello", 'o') == "o");
    assert(ft_strchr("hello", 'x') == NULL);
    assert(ft_strchr("", 'a') == NULL);
    assert(ft_strchr("abc", '\0') == NULL); // Null terminator case
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

    printf("All tests passed!\n");
    return 0;
}