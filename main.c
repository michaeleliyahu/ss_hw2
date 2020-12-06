#include <stdio.h>
#include "myBank.h"
#include <stdbool.h>
bool safe_index(int x)
{
    if (x < 901 || x > 950)
    {
        printf("Failed to read the account number\n");
        return false;
    }
    else
    {
        return true;
    }
}
bool safe_account(int x)
{
    if (check_account(x) == false)
    {
        printf("This account is closed\n");
        return false;
    }
    else
    {
        return true;
    }
}
bool safe_money(int x)
{
    // if (x<0)
    // {
    //     printf("Cannot deposit a negative amount\n");
    //     return false;
    // }
    if (x == 0)
    {
        // printf("Failed to read the account number\n");
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{

    char ans;
    double money;
    int count_number;
    int correct_count;
    double inter;
    int num = 0;

    do
    {

        printf("\nPlease choose a transaction type:\n O-Open Account \n B-Balance Inquiry");
        printf("\n D-Deposit\n W-Withdrawal\n C-Close Account");
        printf("\n I-Interest\n P-Print \n E-Exit\n");
        // FILE *f1 = fopen("input.txt","rt");
        // char ch;
        // int chread;
        // char arr[50];
        // if (!f1)
        // {
        //     printf("error");
        // }
        // fgets(ch,99,stdin);

        // char first;
        // int sec;
        // int i =0;
        // while ((chread=fscanf(f1,"%c",&ch))==1)
        // {
        //     if (ch>=0&&ch<=9)
        //     {
        //         while
        //         {
        //             /* code */
        //         }

        //         arr[i]=ch;
        //     }

        //     printf("%c ",ch);
        // }

        scanf(" %c", &ans);

        switch (ans)
        {
        case 'O':
            printf("Please enter amount for deposit: ");
            money = 0;
            scanf(" %lf", &money);
            // printf("\n%lf\n",money);
            if (safe_money(money) == false)
            {
                printf("Failed to read the amount\n");
                break;
            }
            if (money < 0)
            {
                printf("Cannot deposit a negative amount\n");
                break;
            }

            open_account(money);
            break;

        case 'B':
            printf("Please enter account number: ");
            correct_count = 0;
            count_number = 0;
            scanf(" %d", &count_number);
            // printf("\n%d\n",count_number);
            if (safe_index(count_number) == false)
            {
                break;
            }

            correct_count = count_number - 901;

            if (safe_account(correct_count) == false)
            {
                break;
            }

            check_balance(correct_count);

            break;

        case 'D':
            money = 0;
            printf("Please enter account number: ");
            scanf(" %d", &count_number);
            // printf("\n%d\n",count_number);
            if (count_number < 901 || count_number > 950)
            {
                printf("Invalid account number\n");
                break;
            }

            correct_count = count_number - 901;
            count_number = 0;
            if (safe_account(correct_count) == false)
            {
                break;
            }

            printf("Please enter the amount to deposit: ");
            scanf(" %lf", &money);
            // printf("\n%lf\n",money);
            if (safe_money(money) == false)
            {
                printf("Failed to read the amount\n");
                break;
            }
            if (money < 0)
            {
                printf("Cannot deposit a negative amount\n");
                break;
            }
            deposit(correct_count, money);
            correct_count = 0;

            break;

        case 'W':
            printf("Please enter account number: ");
            scanf(" %d", &count_number);
            // printf("\n%d\n",count_number);
            if (safe_index(count_number) == false)
            {
                break;
            }

            correct_count = count_number - 901;
            count_number = 0;
            if (safe_account(correct_count) == false)
            {
                break;
            }

            printf("Please enter the amount to withdraw: ");
            scanf(" %lf", &money);
            // printf("\n%lf\n",money);
            if (safe_money(money) == false)
            {
                break;
            }

            withrawal(correct_count, money);
            correct_count = 0;
            money = 0;
            break;

        case 'C':
            printf("Please enter account number: ");
            scanf(" %d", &count_number);
            // printf("\n%d\n",count_number);
            if (safe_index(count_number) == false)
            {
                break;
            }
            correct_count = count_number - 901;
            count_number = 0;
            if (safe_account(correct_count) == false)
            {
                break;
            }

            close_account(correct_count);
            correct_count = 0;
            break;

        case 'I':
            printf("Please enter interest rate: ");
            inter = 0;
            scanf(" %lf", &inter);
            if (inter < 0)
            {
                printf("Invalid interest rate\n");
            }

            if (inter == 0)
            {
                printf("Failed to read the interest rate\n");
                break;
            }

            interest(inter);
            break;

        case 'P':
            printAccount();
            break;

        case 'E':
            num = 1;
            closeAllAccont();
            break;

        default:
            printf("Invalid transaction type\n");
            break;
        }

    } while (num != 1);
}