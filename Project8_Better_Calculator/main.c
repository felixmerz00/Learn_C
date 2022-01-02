#include <stdio.h>
#include <stdlib.h>

int main()
{
    double num1;
    double num2;
    char op;
    double result;
    printf("Enter a number: ");
    scanf("%lf", &num1);
    printf("Enter an operator: ");
    scanf(" %c", &op);
    printf("Enter the second number: ");
    scanf("%lf", &num2);

    if (op == '+'){
        result = num1 + num2;
    }
    else if(op == '-'){
        result = num1 - num2;
    }
    else if(op == '*'){
        result = num1 * num2;
    }
    else if(op == ':' || op == '/'){
        result = num1 / num2;
    }
    else{
        printf("Invalid operator\n");
    }

    printf("Result: %f", result);
    return 0;
}
