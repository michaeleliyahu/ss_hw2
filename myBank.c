#include "myBank.h"
#include <stdio.h>
#include <stdbool.h>

#define all_clount 50
double bank[50][2];

bool check_account(int x)
{
    if (bank[x][1] == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void open_account(double x)
{
    double money = x;
    for (int i = 0; i < all_clount - 1; i++)
    {
        if (bank[i][1] == 0)
        {
            bank[i][1] = 1;
            bank[i][2] = money;
            printf("New account number is: %d \n", i + 901);
            break;
        }
    }
}

void check_balance(int x)
{
    printf("The balance of account number %d is: %0.2lf\n", x + 901, bank[x][2]);
}

void deposit(int x, double y)
{
    bank[x][2] = bank[x][2] + y;
    printf("The new balance is: %0.2lf\n", bank[x][2]);
}
void withrawal(int x, double y)
{
    if (bank[x][2] < y)
    {
        printf("Cannot withdraw more than the balance:\n");
    }
    else
    {
        bank[x][2] = bank[x][2] - y;
        printf("The new balance is: %0.2lf\n", bank[x][2]);
    }
}

void close_account(int x)
{
    bank[x][1] = 0;
    printf("Closed account number %d\n", x+901);
}
void interest(double y)
{
    for (int i = 0; i < all_clount; i++)
    {
        if (bank[0][i] == 1)
        {
            bank[1][i] = bank[1][i] + bank[1][i] * (y / 100);
        }
    }
}
void printAccount()
{
    for (int i = 0; i < all_clount - 1; i++)
    {
        if (bank[i][1] == 1)
        {
            printf("The balance of account number %d is %0.2lf\n", i + 901, bank[i][2]);
        }
    }
}
void closeAllAccont()
{
    for (int i = 0; i < all_clount - 1; i++)
    {
        bank[i][1] = 0;
    }
}
