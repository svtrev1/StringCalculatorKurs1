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
    double operand = 0, operand2 = 0;
    long int s;
    int m = 0;
    int minus = 0;
    fgets(str, sizeof(str), stdin);
//    for (int i1 = 0; i1 < 100; i1++)
//    {
//        if (str[i1] == ' ')
//        {
//            for (int i2 = i1; i2 < 100; i2++)
//                str[i2] = str[i2+1];
//            i--;
//        }
//    }
//    printf("str = %s", str);
    if (str[0] == 'h')
        print();
    else if (str[0] >= '0' && str[0] <= '9')
    {
        operand = Simple(str);
        s = ((strchr(arr1, str[i])) - arr1);
        g = 0;
        i++;
        if (str[i] < '0' && str[i] > 9 && str[i] != '-')
            s = -1;
        else
        {
            if (str[i] == '0')
                operand2 = 0;
            else
            {
                if (str[i] == '-')
                {
                    i++;
                    minus = 1;
                }
                operand2 = Simple(str);
                if (g == 0)
                    s = -2;
                if (minus)
                    operand2 *= -1;
            }
        }
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
            case -2:
                m = -1;
                printf("Error input in second operand\n");
                break;
        }
        if (m == -1)
            printf("The last result = %lg", result);
        else
            printf("result = %lg", result);
        
    }
    else if (str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*' || str[0] == '^')
    {
        if (str[1] >= '0' && str[1] <= '9')
        {
            i++;
            operand = Simple(str);
            operand *= -1;
        }
        else
            operand = result;
        s = ((strchr(arr1, str[i])) - arr1);
        g = 0;
        i++;
        if (str[i] < '0' && str[i] > 9 && str[i] != '-')
            s = -1;
        else
        {
            if (str[i] == '0')
                operand2 = 0;
            else
            {
                if (str[i] == '-')
                {
                    i++;
                    minus = 1;
                }
                operand2 = Simple(str);
                if (g == 0)
                    s = -2;
                if (minus)
                    operand2 *= -1;
            }
        }
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
        int k, c = 0, m1 = 0;
        for(k = 0; k < 100; k++)
        {
            if (str[k] == '(')
                c = 1;
        }
        if (c == 0)
            m = -2;
        else
        {
            m = -1;
            char *buf;
            buf = (char *)malloc(sizeof(char)*7);
            Hard(str, &buf);
            i++;
            if (str[i] == ')')
                operand = result;
            else
            {
                if (str[i] == '-')
                {
                    for (k = 0; k < 10; k++)
                    {
                        if (strcmp(buf, arr2[k]) == 0)
                        {
                            m = k;
                            break;
                        }
                    }
                    if (m == 0 || m == 1)
                        m1 = -3;
                    else
                        m = -1;
                    if (str[i+1] >= '0' && str[i+1] <= '9')
                    {
                        i++;
                        operand = Simple(str) * -1;
                        c = 0;
                    }
                    else if(str[i+2] < '0' && str[i+2] > '9')
                        m = -2;
                        
                }
                if (c != 0)
                    operand = Simple(str);
            }
            for (k = 0; k < 10; k++)
            {
                if (strcmp(buf, arr2[k]) == 0)
                {
                    m = k;
                    break;
                }
            }
        }
        if (m1 == -3)
            m = -3;
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
                m = -1;
                printf("Error input!\nYou can use only: sqrt2 sqrt3 sin cos tg ctg asin acos atg actg\n");
                break;
            case -2:
                m = -1;
                printf("Error input in first operand\n");
                break;
            case -3:
                m = -1;
                printf("Error input!\nYou can not use x < 0 in sqrt2, sqrt3\n");
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
