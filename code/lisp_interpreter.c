#include <stdio.h>
#include <stdlib.h>

#define OP_ADD '+'
#define OP_SUB '-'
#define OP_MUL '*'
#define OP_DIV '/'



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

int compute_product(char* expr) {

    int product = 1; // 1 is neutral for product

    while (*expr != ')') {
        if (*expr == ' ') {
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

    while(*(++expr) == ' ');

    // first value found
    sscanf(expr, "%d", &m);
    ++expr;

    while(*(++expr) == ' ');

    // second value found
    sscanf(expr, "%d", &n);

    return m / n;
}

int eval(char* expr) {  
    if (*(expr++) != '(') {
        printf("Error: must begin with a '(' \n");
        return 0;
    }

    char* op = *(expr++); // read the operator

    int result = 0;
    switch (op) {
        switch (op) {
        case OP_ADD:
            result = compute_add(expr);
            break;
        case OP_MUL:
            result = compute_product(expr);
            break;
        //case OP_DIV:
            //result = compute_div(expr);
            //break;
        default:
            result = 0; // undefined operation
            break;
    }

    return result;
}

char* read() {  
    char* expr = malloc(256);
    fgets(expr, 256, stdin);
    return expr;
}

int main(int argc, char* argv[]) {  
    while (1) {
        printf("-> %d", eval(read()));
    }

    return 0;
}