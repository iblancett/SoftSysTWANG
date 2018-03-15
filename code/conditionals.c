#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "math.h"
#include "conditionals.h"
#define FALSE "()"
#define TRUE  "t"

// evaluates the conditional
int eval_cond(char* token){
    char result = eval_math(token, 1);
    return result;
}

/* evaluates the if statment
expr: pointer to token

returns integer
*/
int eval_if(char* expr){
    // selects the next token
    char *token= strtok(NULL,"(");

    // evaluates the conditional
    int result = eval_cond(token);
    int tf = 0;

    if (result == *TRUE) {
        tf = 1;
    } else if (result == *FALSE) {
        tf = 2;
    }
    return eval(token,tf);
}

/* evaluates user input
expr: pointer to char expression function evaluates
calln: integer indicating what kind of function call this is
    0: first call (ie: evaluate expression from main func)
    1: if statement is true
    2: if statement is false
*/
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
        token = strtok(NULL, s);
    }

    // if token is if, evaluate second token
    if (strcmp(token, "if ") == 0){;
        result = eval_if(expr);

    // if if statement is true    
    } else if (calln == 1) {
        // evaluate true statement
        result = eval_math(token, 1);

    // if if statement is false    
    } else if (calln == 2) {
        // skip token
        token = strtok(NULL, s);
        // evaluate false statement
        result = eval_math(token, 1);
    } else {

        // if input to program is just math expression
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
