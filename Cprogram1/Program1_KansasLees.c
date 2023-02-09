#include <stdio.h>
#include <stdlib.h>

#define MONTHS 12

float* read_data_from(char *file_name)
{
    float* month_sales_data = (float*)malloc(sizeof(float) * MONTHS);
    FILE *fp = fopen(file_name, "r+");
    for(int i = 0; i < MONTHS; i++)
    {
        fscanf(fp, "%f\n", &month_sales_data[i]);
    }
    return month_sales_data;
}

void print_data(const char *months[], const float *sales)
{
    printf("Month sales report for 2022\n");
    for(int i = 0; i < MONTHS; ++i)
    {
        printf("%10s %10f\n", months[i], sales[i]);
    }
}

void print_min(const float *sales)
{
    printf("\nSales summary: \n \n");
    printf("Minimum sales: ");
    float min = sales[0];
    for(int i = 0; i < MONTHS; ++i)
    {
        if(sales[i] < min)
        {
            min = sales[i];
        }
    }
    printf("%f \n", min);
}

void print_max(const float *sales)
{
    printf("Maximum sales: ");
    float max = sales[0];
    for(int i = 0; i < MONTHS; ++i)
    {
        if(sales[i] > max)
        {
            max = sales[i];
        }
    }
    printf("%f \n", max);
}

void print_avg(const float *sales)
{
    printf("Average sales: ");
    float total = 0;
    for(int i = 0; i < MONTHS; ++i)
    {
        total = total + sales[i];
    }
    float average = total / MONTHS;
    printf("%f \n", average);
}

void print_moving_avg(const char *months[], const float *sales)
{
    printf("\nSix-Month Moving Averager Report: \n \n");
    int start = 0;
    int end = 5;
    float total = 0;
    while(start < 7)
    {
        printf("%s    - %s   ", months[start], months[end]);
        for(int i = start; i <= end; i++)
        {
            total = total + sales[i];
        }
        float average = total / 6;
        printf("%f \n", average);
        start++;
        end++;
        total = 0;
    }
}

void print_high_low(const char *months[], const float *sales)
{
    printf("\n Sales Report (Highest to Lowest) \n \n");
    printf("Month        Sales \n");
    float max = 99999999999;
    float next = 0;
    int maxMonth;
    int counter = 0;
    while(counter < MONTHS)
    {
    for(int i = 0; i < MONTHS; i++)
    {
        if(sales[i] > next && sales[i] < max)
        {
            next = sales[i];
            maxMonth = i;
        }
    }
    printf("%s   %f \n", months[maxMonth], next);
    max = next;
    next = 0;
    counter++;
    }
}

int main()
{
    float* sales = read_data_from("data.txt");
    const char *months[] = {"January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    print_data(months, sales);
    print_min(sales);
    print_max(sales);
    print_avg(sales);
    print_moving_avg(months, sales);
    print_high_low(months, sales);
    return 0;
}