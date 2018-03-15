#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "math.h"
#include "conditionals.h"
#define FALSE "()"
#define TRUE  "t"


int eval_cond(char* token){
    char result = eval_math(token, 1);
    return result;
}

int eval_if(char* expr){
    char *token= strtok(NULL,"(");
    int result = eval_cond(token);
    int tf = 0;
    if (result == *TRUE) {
        tf = 1;
    } else if (result == *FALSE) {
        tf = 2;
    }
    return eval(token,tf);
}

//int eval_statement(char *expr){
    
//}

int eval(char* expr, int calln) {

    char *token;
    int result = 0;
    const char s[2] = "(";
    if (*(expr++) != '(' && calln == 0) {
        
        printf("Error: must begin with a '(' \n");
        return 0;
    }
    if (calln == 0){

        token  = strtok(expr, s);

    } else {
        token = strtok(NULL, "(");
    }


    if (strcmp(token, "if ") == 0){;
        
        result = eval_if(expr);
    } else if (calln == 1) {
        result = eval_math(token, 1);
        
    } else if (calln == 2) {
        token = strtok(NULL, "(");
        result = eval_math(token, 1);
        
    } else {
        result = eval_math(expr, 1);
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
        int result = eval(read(), 0);
        printf("-> %d\n", result);
    }

    return 0;
}
