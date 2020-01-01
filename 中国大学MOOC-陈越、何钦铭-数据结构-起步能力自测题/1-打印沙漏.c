#include <stdio.h>

int width = 1;
char symbol = '\0';

int width2sum(int width)
{
    if (width % 2 == 1)
    {
        int n = (width + 1) / 2;
        return 2 * n * n - 1;
    }
    else
        return 0;
}

int normalise(int N)
{
    int sum = width2sum(width);
    int sum_last = 1;
    while (sum <= N)
    {
        sum_last = sum;
        width += 2;
        sum = width2sum(width);
    }
    width -= 2;
    return sum_last;
}

void print_line(int width, int num)
{
    int space = (width - num) / 2;
    for (int i = 0; i < space; i++)
        printf(" ");
    for (int i = 0; i < num; i++)
        putchar(symbol);
    printf("\n");
}

void print_graph(char symbol)
{
    int num = width;
    for (; num >= 1; num -= 2)
    {
        print_line(width, num);
    }
    for (num = 3; num <= width; num += 2)
    {
        print_line(width, num);
    }
}

int main(int argc, char *argv[])
{
    int N;
    scanf("%d %c", &N, &symbol);
    int sum = normalise(N);
    print_graph(symbol);
    printf("%d", N - sum);
    return 0;
}
