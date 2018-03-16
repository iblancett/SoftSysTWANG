#include <stdio.h>
#include <stdlib.h>

#define FALSE "()"
#define TRUE  "t"

int compute_add(char* expr) {

    int sum = 0;

    while (*expr != ')') {
        if (*expr == ' ') {
            expr++; continue;
        }

        int m = 0;
        sscanf(expr++, "%d", &m);

        sum += m;

    }

    return sum;
}

int compute_diff(char* expr) {
    while(*expr == ' ' || *expr == '-' || *expr == '(') {
        expr++;
    }

    int diff = 0;
    sscanf(expr++, "%d", &diff);

    while (*expr != ')') {
        if (*expr == ' ') {
            expr++; continue;
        }

        int m = 0;
        sscanf(expr++, "%d", &m);
        diff -= m;
    }
    return diff;
}

int compute_product(char* expr) {

    int product = 1; // 1 is neutral for product

    while (*expr != ')') {
        if (*expr == ' ' || *expr == '*' || *expr == '(') {
            expr++; continue;
        }

        int m = 0;
        sscanf(expr++, "%d", &m);
        product *= m;
    }

    return product;
}

int compute_div(char* expr) {
    int m = 0;
    int n = 0;

    while(*expr == ' ' || *expr == '/' || *expr == '(') {
        expr++;
    }

    // first value found
    sscanf(expr, "%d", &m);
    ++expr;

    while(*(++expr) == ' ');

    // second value found
    sscanf(expr, "%d", &n);

    return m / n;
}

char *compute_eq(char* expr) {
    int m = 0;
    int n = 0;

    while(*expr == ' ' || *expr == '=' || *expr == '(') {
        expr++;
    }

    // first value found
    sscanf(expr, "%d", &m);
    ++expr;

    while(*(++expr) == ' ');

    // second value found
    sscanf(expr, "%d", &n);

    if (m==n) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

char *compute_comp(char* expr) {
    int m = 0;
    int n = 0;

    while(*expr == ' ' || *expr == '<' || *expr == '(') {
        expr++;
    }

    // first value found
    sscanf(expr, "%d", &m);
    ++expr;

    while(*(++expr) == ' ');

    // second value found
    sscanf(expr, "%d", &n);

    if (m<n) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}



#define OP_ADD '+'
#define OP_SUB '-'
#define OP_MUL '*'
#define OP_DIV '/'
#define OP_EQ  '='
#define OP_COM '<'

// Function to evaluate mathematical statement
int eval_math(char* expr, int original) {
    if (original == 0 && *(expr++) != '(' ) {
        printf("Error: must begin with a '(' \n");
        return 0;
    }

    char* op = expr++; // read the operator

    int result = 0;
    switch (*op) {
        case OP_ADD:
            result = compute_add(expr);
            break;
        case OP_SUB:
            result = compute_diff(expr);
            break;
        case OP_MUL:
            result = compute_product(expr);
            break;
        case OP_DIV:
            result = compute_div(expr);
            break;
        case OP_EQ:
            result = *compute_eq(expr);
            break;
        case OP_COM:
            result = *compute_comp(expr);
            break;
        default:
            result = 0; // undefined operation
            break;
    }

    return result;
}

/*char* read() {
    char* expr = malloc(256);
    fgets(expr, 256, stdin);
    return expr;
}*/
/*
int main(int argc, char* argv[]) {
    while (1) {
        printf("-> %d\n", eval(read()));
    }

    return 0;
}
 */
