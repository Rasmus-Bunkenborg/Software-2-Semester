#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char dag[4];
    char tidspunkt[12];
    char hold1[4];
    char hold2[4];
    int resultat;
    int tilskuere;
} kamp;

void udskriv_kamp(kamp p);
void laes_alle_kampe_fra_fil(kamp kampe[], FILE *fil);


int main (void) {

    printf("Hej Rasmus!");

    FILE *fil = fopen("kampe-2020-2021.txt", "r");
    if (fil == NULL){
        printf("Fil kunne ikke åbnes");
        exit(EXIT_FAILURE);
    }

    kamp kampe [133];

    laes_alle_kampe_fra_fil(kampe, fil);
    for (int i = 0; i < 134; i++){
        udskriv_kamp(kampe[i]);
    }
    fclose(fil);
    return 0;
}


void laes_alle_kampe_fra_fil(kamp kampe[], FILE *fil){
    kamp p;
    int i = 0;
    while (fscanf(fil, " %s %s %s %s %d %d ", p.dag, &(p.tidspunkt), &(p.hold1), &(p.hold2), &(p.resultat), &(p.tilskuere)) == 6){
        kampe[i] = p;
        i++;       
    }
}

void udskriv_kamp(kamp p){
    char *n = p.dag;
    char *m = p.tidspunkt;
    char *k = p.hold1;
    char *l = p.hold2;
    int j = p.resultat;
    int h = p.tilskuere;

    printf("Dag: %s ", n);
    printf("Tidspunkt: %s ", m);
    printf("Hold1: %s ", k);
    printf("Hold2: %s ", l);
    printf("Resultat: %d ", j);
    printf("Tilskuere: %d ", h);
    printf("\n");
}