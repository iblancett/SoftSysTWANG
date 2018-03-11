#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int eval(char* expr, int calln);

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

    while(*expr == ' ') {
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

typedef struct {

} IfCond;

#define OP_ADD '+'
#define OP_SUB '-'
#define OP_MUL '*'
#define OP_DIV '/'
#define OP_EQ  '='
#define OP_COM '<'

int eval_cond(char* token){
    return 1;
}

int eval_if(char* expr){
    char *token= strtok(NULL,"(");
    int result = eval_cond(token);

    if (result == 1){
        //token = strtok(NULL,"(");
        eval(token, 1);
    } else {
        token = strtok(NULL, "(");
        eval(token,2);
    }
    return 1;
}

//int eval_statement(char *expr){
    
//}

int eval(char* expr, int calln) {
    char *token;
    const char s[2] = "(";
    if (*(expr++) != '(' && calln == 0) {
        printf("Error: must begin with a '(' \n");
        return 0;
    }
    if (calln == 0){
        token  = strtok(expr, s);
    } else {
        token = strtok(NULL, ")");
        printf("This is the token: %s\n", token);
    }    
    if (strcmp(token, "if ") == 0){;
        printf("If statement\n");
        eval_if(expr);
    } else if (calln == 1) {//(strcmp(token, "then do this) ") ==0){
        printf("We're doing the thing\n");
    } else if (calln == 2) {//(strcmp(token, "if no then do this))\n") ==0){
        printf("We're doing the other thing\n");
    }
    /*
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
        //case OP_EQ:
            //result = compute_eq(expr);
            //break;
        //case OP_COM:
            //result = compute_com(expr);
            //break;
        default:
            result = 0; // undefined operation
            break;
    }
    */
    int result = 0;
    return result;
}

char* read() {
    char* expr = malloc(256);
    fgets(expr, 256, stdin);
    return expr;
}

int main(int argc, char* argv[]) {
    while (1) {
        printf("-> %d\n", eval(read(), 0));
    }

    return 0;
}
