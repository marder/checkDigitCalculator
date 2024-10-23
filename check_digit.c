#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void red()
{
    printf("\033[1;31m");
}

void yellow()
{
    printf("\033[1;33m");
}

void reset()
{
    printf("\033[0m");
}

int get_wage(char c);
char *get_number(char court[], char old_number[]);

int main(int argc, char *argv[])
{
    if (argc == 3)
    {
        printf("Result: %s --> %s\n", argv[2], get_number(argv[1], argv[2]));
    }
    else if (argc > 3)
    {
        int i = 2;
        while (i < argc)
        {
            yellow();
            printf("Result: %s --> %s\n", argv[i], get_number(argv[1], argv[i]));
            reset();
            i++;
        }
    }
    else
    {
        printf("One argument expected.\n");
    }
}

int get_wage(char c)
{
    int i = 0;
    char wages[] = "0123456789XABCDEFGHIJKLMNOPRSTUWYZ";
    int length = sizeof(wages) / sizeof(wages[0]);
    for (i = 0; i < length; ++i)
    {
        if (wages[i] == c)
        {
            break;
        }
    }
    return i;
}

char *get_number(char court[], char old_number[])
{
    char *result;
    result = (char *)malloc(12 * sizeof(char));

    char full_number[11] = "\0";
    strcat(full_number, court);

    char filling[8];

    for (int i = 0; i < 8 - strlen(old_number); ++i)
    {
        filling[i] = '0';
        filling[i + 1] = '\0';
    }

    strcat(full_number, filling);
    strcat(full_number, old_number);

    int sum = 0;

    sum = sum + get_wage(full_number[0]) * 1;
    sum = sum + get_wage(full_number[1]) * 3;
    sum = sum + get_wage(full_number[2]) * 7;
    sum = sum + get_wage(full_number[3]) * 1;
    sum = sum + get_wage(full_number[4]) * 3;
    sum = sum + get_wage(full_number[5]) * 7;
    sum = sum + get_wage(full_number[6]) * 1;
    sum = sum + get_wage(full_number[7]) * 3;
    sum = sum + get_wage(full_number[8]) * 7;
    sum = sum + get_wage(full_number[9]) * 1;
    sum = sum + get_wage(full_number[10]) * 3;
    sum = sum + get_wage(full_number[11]) * 7;

    int number = sum % 10;

    char c_number[12];
    sprintf(c_number, "%d", number);

    strcat(result, court);
    strcat(result, "/");
    strcat(result, filling);
    strcat(result, old_number);
    strcat(result, "/");
    strcat(result, c_number);

    return result;
}