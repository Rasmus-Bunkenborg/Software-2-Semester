/*
    This program estimates energy consumtions and cost
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char name[50];
    double price;
    double watt; 
    double hours;
    int days;
    double el_price;
    double price_per_year;
} Device;

void prompt();
void prompt_2();
void calculation();
int compare();
int profit();
void overview();


int main(void) {

    Device devices;
    prompt();

    return 0;
}

void prompt() {
    int n;
    int k;

    printf("\n\nWhat type of device would you like to estimate?");
    printf("\nType 1 for lightning");
    printf("\nType 2 for heating");
    printf("\nType 3 for air condition");
    printf("\nType 4 for smart sockets");
    printf("\nType 5 for security devices");
    printf("\nType 6 for curtains and blinds");
    printf("\nType 7 for other devices that uses a power outlet");
    
    scanf("%d", &n);

    switch(n) {
    case '1':
        k = 0;
        printf("\nType 1 for spotlights or type 2 for light bulbs");
        scanf("%d", &k);
        if (k == 1) {
            prompt_2();
            compare();
            overview();
        }
        else if (k == 2) {
            prompt_2();
            compare();
            overview();
        }
        break;
    case '2':
        k = 0; 
        printf("\nType 1 for electric floor heating and radiators, or type 2 for other heating systems");
        scanf("%d", &k);
        if (k == 1) {
            prompt_2();
            compare();
            overview();
        }
        else if (k == 2) {
            prompt_2();
            compare();
            overview();
        }
        break;
    case '3':
        prompt_2();
        compare();
        overview();
        break;
    case '4':
        prompt_2();
        compare();
        overview();
        break;
    case '5':
        prompt_2();
        compare();
        overview();
        break;
    case '6':
        k = 0;;
        printf("\nType 1 for curtains or type 2 for blinds");
        scanf("%d", &k);
        if (k == 1) {
            prompt_2();
            compare();
            overview();
        }
        else if (k == 2) {
            prompt_2();
            compare();
            overview();
        }
        break;
    case '7':
        k = 0;
        printf("\nChose one category to compare with");
        printf("\nType 1 for computer\nType 2 for fridge\nType 3 for flat-screen\nType 4 to add new device");
        scanf("%d", &k);
        if (k == 1) {
            prompt_2();
            compare();
            overview();
        }
        else if (k == 2) {
            prompt_2();
            compare();
            overview();
        }
        else if (k == 3) {
            prompt_2();
            compare();
            overview();
        }
        else if (k == 4) {
            //add_new_device();
            compare();
            overview();
        }
        break;
    }
}

void prompt_2(Device *devices) {
        printf("What is the name of the device?\n");
        scanf("%s", d.name);
        printf("How much does the device cost? (DKK)\n");
        scanf("%lf", &(d.price));
        printf("What is the wattage?\n");
        scanf("%lf", &(d.watt));
        printf("\nHow many hours is the devices used per day?\n");
        scanf(" %lf", &(d.hours));
        printf("\nHow many days is it used per year?\n");
        scanf(" %d", &(d.days));
        printf("\nWhat is the price per kwh?\n");
        scanf(" %lf", &(d.el_price));
    
}

void calculations(Device *devices) {
    d.kwh = 0;
    d.price_per_year = 0;
        *d.kwh = ((d.watt * d.hours * d.days) / 1000);
        *d.price_per_year = ((*d.kwh) * d.el_price);
}

int compare(const void *a, const void *b) {
    Device *S_device = (Device *) a;
    Device *SnS_device = (Device *) b;

    double diff = S_device->price_per_year - SnS_device->price_per_year; // pris forskell

    return diff;
}

int profit(Device *SnS_device, Device *S_device, double diff) {

    double plus; 
    if (diff < 0) {
        plus = (((SnS_device->price_per_year)-(S_device->price)) / S_device->price_per_year); 
    }
    return plus;
    
}

void overview(Device *devices, double diff, double plus) {

    Device d;

    if (diff < 0) { 
        printf("Your smart device %c is estimated to be more energy efficient compared to a standard non-smart device\n", d.name);
        printf("You are estimated to save %lf DKK every year\n", diff);
        printf("If the price of the device is included in the calculations, you are estimated to go in plus after %lf years\n", plus);
    }
    else if (diff > 0) {
        printf("Your smart device %c is estimated to be less energy efficient compared to a standard non-smart device\n", d.name);
        printf("You are estimated to loose %lf DKK every year\n", diff);
    }
    else if(diff == 0) {
        printf("Your smart device %c is estimated to use the same amount of energy as standard non-smart device\n", d.name);
    }
}




