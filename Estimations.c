/*
    This program estimates energy consumtions and cost
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void prompt(char name[], double *watt, double *hours, int *days, double *price);
void calculations(double watt, double hours, int days, double price, double *kwh, double *price_per_year);
void result(char name[], double kwh, double price_per_year);

int main(void) 
{
    char name[50];
    double watt; 
    double hours;
    int days;
    double price;
    double kwh;
    double price_per_year;

prompt(name, &watt, &hours, &days, &price);

calculations(watt, hours, days, price, &kwh, &price_per_year);

result(name, kwh, price_per_year);

return 0;


}
void prompt(char name[], double *watt, double *hours, int *days, double *price) 
{
    printf("What is the name of the device?\n");
    scanf(" %s", name);
    printf("\nWhat is the wattage?\n");
    scanf(" %lf", watt);
    printf("\nHow many hours is the devices used per day?\n");
    scanf(" %lf", hours);
    printf("\nHow many days is it used per year?\n");
    scanf(" %d", days);
    printf("\nWhat is the price per kwh?\n");
    scanf(" %lf", price);
}

void calculations(double watt, double hours, int days, double price, double *kwh, double *price_per_year) {

    *kwh = ((watt * hours * days) / 1000);
    *price_per_year = ((*kwh) * price); 
}

void result(char name[], double kwh, double price_per_year) 
{
    printf("\n%s is estimated to use %lf kWh, which gives a total cost of %lf per year\n", name, kwh, price_per_year);
}

