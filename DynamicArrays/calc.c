/* CS261- Assignment 2 - calc.c*/
/* Name: Corey Hemphill
 * Date: 10/16/2015
 * Solution description: (none)
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 for false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num) {
    char *end;
    double returnNum;
    if(strcmp(s, "0") == 0) {
        *num = 0;
        return 1;
    }
    else {
        returnNum = strtod(s, &end);
        /* If there's anything in end, it's bad */
        if((returnNum != 0.0) && (strcmp(end, "") == 0)) {
            *num = returnNum;
            return 1;
        }
    }
    /* If got here, it was not a number... */
    /* If there is a bad input, set num to NULL and blow-up the program. */
    printf("\n The character '%s' is not a valid argument. Please try again...\n \n", s);
    num = NULL;
    assert(num != NULL);
    return 0;
}

/* *************************OPERATORS************************* */

/*	param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and
    their sum is pushed back onto the stack.
*/
void add(struct DynArr *stack) {
    /* FIXME: You will write this function */
    double num1, num2;
    if(sizeDynArr(stack) >= 2) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        num2 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, (num1 + num2));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (+).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and
    their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack) {
    /* FIXME: You will write this function */
    double num1, num2;
    if(sizeDynArr(stack) >= 2) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        num2 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, (num2 - num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (-).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and
    their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack) {
    /* FIXME: You will write this function */
    double num1, num2;
    if(sizeDynArr(stack) >= 2) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        num2 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, (num2 / num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (/).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and
    their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack) {
    double num1, num2;
    if(sizeDynArr(stack) >= 2) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        num2 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, (num1 * num2));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (x).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and
    their power-product is pushed back onto the stack.
*/
void power(struct DynArr *stack) {
    double num1, num2;
    if(sizeDynArr(stack) >= 2) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        num2 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, pow(num2, num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (^).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and its squared
    product is pushed back onto the stack.
*/
void squared(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, pow(num1, 2));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (^2).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and its cubed
    product is pushed back onto the stack.
*/
void cubed(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, pow(num1, 3));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (^3).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and its
    absolute value is pushed back onto the stack.
*/
void absValue(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, abs(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (abs).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the square
    root value is pushed back onto the stack.
*/
void squareRoot(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, sqrt(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (sqrt).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the exponential
    value is pushed back onto the stack.
*/
void exponential(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, exp(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (exp).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the
    natural log value is pushed back onto the stack.
*/
void naturalLog(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, log(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (ln).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top two elements are popped and
    the log10 value is pushed back onto the stack.
*/
void logarithm(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, log10(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (log).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the sine
    of the radian angle pushed back onto the stack.
*/
void sinRad(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, sin(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (sin).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}


/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the cosine
    of the radian angle pushed back onto the stack.
*/
void cosRad(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, cos(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (cos).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the tangent
    of the radian angle pushed back onto the stack.
*/
void tanRad(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, tan(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (tan).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the arc
    sine in radians is pushed back onto the stack.
*/
void sinArc(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, asin(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (asin).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the arc
    cosine in radians is pushed back onto the stack.
*/
void cosArc(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, acos(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (acos).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the arc
    tangent in radians is pushed back onto the stack.
*/
void tanArc(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, atan(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (atan).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the ceiling
    of the value is pushed back onto the stack.
*/
void ceilNum(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, ceil(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (ceil).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/*	param: stack the stack being manipulated
    pre: the stack contains at least one element
    post: the top element is popped and the floor
    of the value is pushed back onto the stack.
*/
void floorNum(struct DynArr *stack) {
    double num1;
    if(sizeDynArr(stack) >= 1) {
        num1 = topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, floor(num1));
    }
    else {
        printf("\n There are not enough values on the stack to complete the operation (floor).\n \n");
        stack = NULL;
        assert(stack != NULL);
    }
}

/* *********************************************************** */

double calculate(int numInputTokens, char **inputString) {
    int i;
    double result = 0.0;
    double *num = malloc(sizeof(double));
    char *s;
    struct DynArr *stack;
    /* Set up the stack.*/
    stack = createDynArr(20);
    /* Start at 1 to skip the name of the calculator "calc." */
    for(i = 1; i < numInputTokens; i++) {
        s = inputString[i];
        /* Hint: General Algorithm:*/
        /* (1) Check if the string s is in the list of operators. */
        /*   (1a) If it is, perform corresponding operations. */
        /*   (1b) Otherwise, check if s is a number. */
        /*     (1b - I) If s is not a number, produce an error. */
        /*     (1b - II) If s is a number, push it onto the stack. */
        if(strcmp(s, "+") == 0) {
            add(stack);
        }
        else if(strcmp(s, "-") == 0) {
            subtract(stack);
        }
        else if(strcmp(s, "/") == 0) {
            divide(stack);
        }
        else if(strcmp(s, "x") == 0) {
            multiply(stack);
        }
        else if(strcmp(s, "^") == 0) {
            power(stack);
        }
        else if(strcmp(s, "^2") == 0) {
            squared(stack);
        }
        else if(strcmp(s, "^3") == 0) {
            cubed(stack);
        }
        else if(strcmp(s, "abs") == 0) {
            absValue(stack);
        }
        else if(strcmp(s, "sqrt") == 0) {
            squareRoot(stack);
        }
        else if(strcmp(s, "exp") == 0) {
            exponential(stack);
        }
        else if(strcmp(s, "ln") == 0) {
            naturalLog(stack);
        }
        else if(strcmp(s, "log") == 0) {
            logarithm(stack);
        }
        else if(strcmp(s, "sin") == 0) {
            sinRad(stack);
        }
        else if(strcmp(s, "cos") == 0) {
            cosRad(stack);
        }
        else if(strcmp(s, "tan") == 0) {
            tanRad(stack);
        }
        else if(strcmp(s, "asin") == 0) {
            sinArc(stack);
        }
        else if(strcmp(s, "acos") == 0) {
            cosArc(stack);
        }
        else if(strcmp(s, "atan") == 0) {
            tanArc(stack);
        }
        else if(strcmp(s, "ceil") == 0) {
            ceilNum(stack);
        }
        else if(strcmp(s, "floor") == 0) {
            floorNum(stack);
        }
        else {
            /* FIXME: You need to develop the code here (when s is not an operator). */
            /* Remember to deal with special values ("pi" and "e"). */
            if(isNumber(s, num) == 1) {
                assert(num != NULL);
                pushDynArr(stack, *num);
            }
            else if(strcmp(s, "pi") == 0) {
                *num = 3.14159265;
                pushDynArr(stack, *num);
            }
            else if(strcmp(s, "e") == 0) {
                *num = 2.7182818;
                pushDynArr(stack, *num);
            }
        }
    }/* End for loop*/
    /* FIXME: You will write this part of the function (2 steps below)
     * (1) Check if everything looks OK and produce an error if needed.
     * (2) Store the final value in result and print it out.
     */
    if(sizeDynArr(stack) > 1) {
        printf("\n There are %d unused values in the input. Please try again...\n \n", (sizeDynArr(stack) - 1));
        return result;
    }
    else {
        result = topDynArr(stack);
        printf("\n %.3f\n \n", result);
        return result;
    }
}

int main(int argc, char** argv) {
    /* Assume each argument is contained in the argv array. */
    /* Argc-1 determines the number of operands + operators. */
    if (argc == 1)
        return 0;
    calculate(argc, argv);
    return 0;
}
