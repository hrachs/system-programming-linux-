#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    //     printf("Number of arguments: %d\n", argc);
    //     for (int i = 0; i < argc; ++i) {
    //         printf("argv[%d] == %s\n", i, argv[i]);
    //     }
    //     return 0;
    // }
    // const char* arr[] = {"a.out", "arg1", "arg2"};

    if (argc != 4)
    {
        printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
        return 1;
    }
    //  "a.out" // argv[0]
    //  "6"     // argv[1]
    //  "+*-"     // argv[2]
    //  "5"     // argv[3]
    int num1 = atoi(argv[1]);
    char operator= argv[2][0];
    int num2 = atoi(argv[3]);
    long result = 0;

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Error: Division by zero.\n");
            return 1;
        }
        result = num1 / num2;
        break;
    default:
        printf("Invalid operator. Use +, -, *, or /.\n");
        return 1;
    }
    printf("%d %c %d = %ld\n", num1, operator, num2, result);
}