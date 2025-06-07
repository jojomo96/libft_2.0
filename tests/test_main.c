#include "libft/libft.h"
#include "assert.h"
#include "stdio.h"

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

    printf("All tests passed!\n");
    return 0;
}