/* Example code for Software Systems at Olin College.

Copyright 2017 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "math.h"

#define mu_assert(message, test) do { if (!(test)) return message; } while (0)

#define mu_run_test(test) do { char *message = test(); tests_run++; \
                              if (message) return message; } while (0)

#define FALSE 40
#define TRUE  116

int tests_run = 0;

static char *test_compute_add1() {
    int res = compute_add("(+ 3 7)");
    char *message = "test_compute_add1 failed: compute_add(\"(+ 3 7)\") should return 10";
    mu_assert(message, res == 10);
    return NULL;
}

static char *test_compute_diff1() {
    int res = compute_diff("(- 9 6)");
    char *message = "test_compute_diff1 failed: compute_diff(\"(- 9 6)\") should return 3";
    mu_assert(message, res == 3);
    return NULL;
}

static char *test_compute_diff2() {
    int res = compute_diff("(- 9 6 2)");
    char *message = "test_compute_diff2 failed: compute_diff(\"(- 9 6 2)\") should return 1";
    mu_assert(message, res == 1);
    return NULL;
}

static char *test_compute_product1() {
    int res = compute_product("(* 7 3 1)");
    char *message = "test_compute_product1 failed: compute_product(\"(* 7 3 1)\") should return 21";
    mu_assert(message, res == 21);
    return NULL;
}

static char *test_compute_product2() {
    int res = compute_product("(* 7 2)");
    char *message = "test_compute_product2 failed: compute_product(\"(* 7 2)\") should return 14";
    mu_assert(message, res == 14);
    return NULL;
}

static char *test_compute_div1() {
    int res = compute_div("(/ 8 4)");
    char *message = "test_compute_div1 failed: compute_div(\"(/ 8 4)\") should return 2";
    mu_assert(message, res == 2);
    return NULL;
}

static char *test_compute_eq1() {
    int res = *compute_eq("(= 8 4)");
    char *message = "test_compute_eq1 failed: compute_product(\"(= 8 4)\") should return '()'";
    mu_assert(message, res == FALSE);
    return NULL;
}

static char *test_compute_eq2() {
    int res = *compute_eq("(= 4 4)");
    char *message = "test_compute_eq2 failed: compute_product(\"(= 4 4)\") should return 't'";
    mu_assert(message, res == TRUE);
    return NULL;
}

static char *test_compute_comp1() {
    int res = *compute_comp("(< 8 4)");
    char *message = "test_compute_comp1 failed: compute_product(\"(< 8 9)\") should return '()'";
    mu_assert(message, res == FALSE);
    return NULL;
}

static char *test_compute_comp2() {
    int res = *compute_comp("(< 4 8)");
    char *message = "test_compute_comp2 failed: compute_product(\"(< 4 8)\") should return 't'";
    mu_assert(message, res == TRUE);
    return NULL;
}


static char * all_tests() {
    mu_run_test(test_compute_add1);
    mu_run_test(test_compute_diff1);
    mu_run_test(test_compute_diff2);
    mu_run_test(test_compute_product1);
    mu_run_test(test_compute_product2);
    mu_run_test(test_compute_div1);
    mu_run_test(test_compute_eq1);
    mu_run_test(test_compute_eq2);
    mu_run_test(test_compute_comp1);
    mu_run_test(test_compute_comp2);
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
