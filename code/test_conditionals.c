/* Test cases for LISP interpreter created in 
Software Systems in Spring 2018

Author: Emily Lepert

Inspired by Allen Downey's Example code for Software Systems at Olin College.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "math.h"
#include "conditionals.h"

 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)

 #define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

int tests_run = 0;

static char *test_true_eq() {
    char expr[] = "(if (= 6 6) (+ 8 9) (- 5 4))";
    int res = eval(expr,0);
    char *message = "test_compute_add1 failed: eval(\"(if (= 6 6) (+ 8 9) (- 5 4))\", 0) should return 17";
    mu_assert(message, res == 17);
    return NULL;
}

static char *test_false_eq() {
    char expr[] = "(if (= 6 7) (+ 6 5) (- 5 4))";
    int res = eval(expr, 0);
    char *message = "test_false_eq failed: eval(\"(if (= 6 7) (+ 6 5) (- 5 4))\", 0) should return 1";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test_true_comp() {
    char expr[] = "(if (< 6 7) (+ 6 5) (- 4 5))";
    int res = eval(expr,0);
    char *message = "test_compute_diff1 failed: eval(\"(if (< 6 7) (+ 6 5) (- 4 5))\", 0) should return 11";
    mu_assert(message, res == 11);
    return NULL;
}

static char *test_false_comp() {
    char expr[] = "(if (< 7 6) (+ 6 5) (- 4 5))";
    int res = eval(expr,0);
    char *message = "test_compute_diff2 failed: eval(\"(if (> 6 7) (+ 6 5) (- 4 5))\", 0) should return -1";
    mu_assert(message, res == -1);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test_true_eq);
    mu_run_test(test_false_eq);
    mu_run_test(test_true_comp);
    mu_run_test(test_false_comp);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
