#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void menu();
double cal(double num1, double num2, char ch);
void bad_input();

int main()
{
    char ch;
    double num1;
    double num2;
    while(1)
    {
        menu();
        printf("enter the method\n");
        fflush(stdin);
        while(!(scanf("%c", &ch) && (ch == 'a'|| ch == 'm' || ch == 's' || ch == 'd' || ch == 'q')))
            bad_input();
        if(ch == 'q')
            break;
        printf("enter nums you want to calculate\n");
        fflush(stdin);
        while(scanf("%lf%lf", &num1, &num2) != 2)
            bad_input();
        printf("%lf\n",cal(num1, num2, ch));
    }
    printf("Bye");
    return 0;
}


void menu()
{
    printf("a.add         s.subtract\n");
    printf("m.multiply    d.divide\n");
    printf("q.quit\n");
}

double cal(double num1, double num2, char ch)
{
    switch(ch)
    {
        case 'a':
            return num1 + num2;
            break;
        case 's':
            return num1 - num2;
            break;
        case 'm':
            return num1 * num2;
        case 'd':
            while(num2 == 0 || !scanf("%lf", &num2))
            {
                fflush(stdin);
                printf("num2 can not be zero, please enter again\n");
                num2 = 1;
            }
            return num1 / num2;
        defalut:
            return;

    }
}

void bad_input()
{
    printf("invalid input, please try again\n");
    fflush(stdin);
}