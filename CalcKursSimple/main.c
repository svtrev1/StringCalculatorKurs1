#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char arr1[] = {'+', '-', '*', '/', '^'};
char arr2[10][6] = {"sqrt2", "sqrt3", "sin", "cos", "tg", "ctg", "asin",
    "acos", "atg", "actg"};

int i = 0;
double result;
int g = 0;

double Simple(char *str);
void Hard(char *str, char **buf);
void Calc(void);
void print(void);

int main(void)
{
    print();
    while(1)
    {
        Calc();
        printf("\n");
    }
}

void Calc(void)
{
    char str[100];
    double operand, operand2;
    long int s;
    int m = 0;
    fgets(str, sizeof(str), stdin);
    if (str[0] == 'h')
        print();
    else if (str[0] >= '0' && str[0] <= '9')
    {
        operand = Simple(str);
        s = ((strchr(arr1, str[i])) - arr1);
        g = 0;
        i++;
        operand2 = Simple(str);
        if (g == 0)
            s = -1;
        switch(s)
        {
            case 0:
                result = operand + operand2;
                break;
            case 1:
                result = operand - operand2;
                break;
            case 2:
                result = operand * operand2;
                break;
            case 3:
                result = operand / operand2;
                break;
            case 4:
                result = pow(operand, operand2);
                break;
            case -1:
                m = -1;
                printf("Error input\nYou can use only: + - * / ^\n");
                break;
        }
        if (m == -1)
            printf("The last result = %lg", result);
        else
            printf("result = %lg", result);
        
    }
    else if (str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*' || str[0] == '^')
    {
        operand = result;
        s = ((strchr(arr1, str[i])) - arr1);
        g = 0;
        i++;
        operand2 = Simple(str);
        if (g == 0)
            s = -1;
        switch(s)
        {
            case 0:
                result = operand + operand2;
                break;
            case 1:
                result = operand - operand2;
                break;
            case 2:
                result = operand * operand2;
                break;
            case 3:
                result = operand / operand2;
                break;
            case 4:
                result = pow(operand, operand2);
                break;
            case -1:
                m = -1;
                printf("Error input\nYou can use only: + - * / ^\n");
                break;
        }
        if (m == -1)
            printf("The last result = %lg", result);
        else
            printf("result = %lg", result);
    }
    else
    {
        char *buf;
        buf = (char *)malloc(sizeof(char)*7);
        Hard(str, &buf);
        i++;
        if (str[i] == ')')
            operand = result;
        else
            operand = Simple(str);
        for (int k = 0; k < 10; k++)
        {
            if (strcmp(buf, arr2[k]) == 0)
            {
                m = k;
                break;
            }
        }
        switch(m)
        {
            case 0:
                result = sqrt(operand);
                break;
            case 1:
                result = pow(operand, (double)1/3);
                break;
            case 2:
                operand = operand * M_PI / 180;
                result = sin(operand);
                break;
            case 3:
                operand = operand * M_PI / 180;
                result = cos(operand);
                break;
            case 4:
                operand = operand * M_PI / 180;
                result = tan(operand);
                break;
            case 5:
                operand = operand * M_PI / 180;
                result = tan(M_PI/2-operand);
                break;
            case 6:
                operand = operand * M_PI / 180;
                result = asin(operand);
                break;
            case 7:
                operand = operand * M_PI / 180;
                result = acos(operand);
                break;
            case 8:
                operand = operand * M_PI / 180;
                result = atan(operand);
                break;
            case 9:
                operand = operand * M_PI / 180;
                result = atan(M_PI/2 -operand);
                break;
            case -1:
                printf("Error input\nYou can use only: sqrt2 sqrt3 sin cos tg ctg asin acos atg actg\n");
                break;
        }
        if (m == -1)
            printf("The last result = %lg", result);
        else
            printf("result = %lg", result);
    }
    i = 0;
}

double Simple(char *str)
{
    double x = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        x *= 10;
        x += str[i] - '0';
        i++;
    }
    int j = 0;
    
    if (str[i] == '.' || str[i] == ',')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            x *= 10;
            x += str[i] - '0';
            i++;
            j++;
        }
        if (j != 0)
            x /= pow(10,j);
    }
    if (x != 0)
        g = 1;
    return x;
}

void Hard(char *str, char ** buf)
{
    int j = 0;
    while ((str[i] >= 'a' && str[i] <= 'z') || str[i] == '2' || str[i] == '3')
    {
        (*buf)[j] = str[i];
        i++;
        j++;
    }
}

void print(void)
{
    printf("\n-------------------------------------------------------------------\n");
    printf("Press h to see this instruction\n");
    printf("Calculator can count:\n");
    printf("1. x+y\n");
    printf("2. x-y\n");
    printf("3. x*y\n");
    printf("4. x/y\n");
    printf("5. x^y\n");
    printf("6. sin(x)\n");
    printf("7. cos(x)\n");
    printf("8. tg(x)\n");
    printf("9. ctg(x)\n");
    printf("10. sqrt2(x)\n");
    printf("11. sqrt3(x)\n");
    printf("12. asin(x)\n");
    printf("13. acos(x)\n");
    printf("14. atg(x)\n");
    printf("15. actg(x)\n");
    printf("Also you can use the last result as new first operand\n");
    printf("You just need to write any of 1-13 operations with ' ' instead 'x'\n");
    printf("-------------------------------------------------------------------\n");
    if (result != 0)
        printf("The last result = %lg", result);
}

void Error(void)
{
    
}


      //x+y;
      //x-y;
      //x*y;
      //x/y;
      //x^y;
      //sqrt2(x);
      //sqrt3(x);
      //sin(x);
      //cos(x);
      //tg(x);
      //ctg(x);
      //arctg(x);
      //arcsin(x);
      //arccos(x);
      //arcctg(x);
