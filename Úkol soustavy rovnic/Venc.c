#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

main()
{
 int a; char outputname[100]; char inputname[100]; char hodnoty[100]; FILE *f1, *f2;
 int radky=0;
 int metoda=0;
 int zadani=0;

 while (metoda<1 || metoda>2) {
 printf("Vyberte metodu reseni soustavy rovnic:\n");
 printf("1...Gaussova eliminacni metoda\n2...Cramerovo pravidlo\n");
 scanf("%d", &metoda);
 }

 while (zadani<1 || zadani>2) {
 printf("1...Zvolte pro rucni zadani hodnot\n");
 printf("2...Zvolte pro zadani hodnot ze souboru\n");
 scanf("%d", &zadani);
 }

 if (zadani==1) {
    printf("Zadejte pocet radku\n");
    scanf("%d", &radky);

    float hodnoty[radky+2][radky+1];
    int nahodny=-1;

    while (nahodny<0 || nahodny>1) {
    printf("Chcete vlozit radky nahodne? (ano...1/ne...0)\n");
    scanf("%d", &nahodny);
    }

    if (nahodny==0) {

    printf("Zadejte jedotlive radky (%d) vcetne pravych stran:\n", radky);

    int j;
    int k;

    for (j=1; j<radky+1; j++) {
            for (k=1; k<radky+2; k++) {
                scanf("%d", &hodnoty[k][j]);
            }
    }

    }

    if (nahodny==1) {
        int minimum;
        int maximum;
        printf("V jakem rozmezi maji byt hodnoty vygenerovany?\n");
        printf("Zadejte spodni hranici hodnot:\n");
        scanf("%d", &minimum);
        printf("Zadejte horni hranici hodnot:\n");
        scanf("%d", &maximum);

        int l;
        int m;
        srand(time(0));
        for (l=1; l<=radky; l++) {
                for (m=1; m<=radky+1; m++) {
                    hodnoty[m][l]=(rand()%(maximum-minimum+1))+minimum;
                    printf("%4.2f", hodnoty[m][l]);
                }
        }
    }
 }

 if (zadani==2) {

 printf("Zadejte nazev pocatecniho souboru pro cteni\n");
 scanf ("%s", &inputname);

 f1=fopen(inputname,"r");

 radky = 0;

 while (fscanf(f1,"%d",&a)==1) {
    radky++;
 }
 printf("%d\n", radky);

 radky = (-1+sqrt(1+4*radky))/2;

 printf("%d\n", radky);

 fclose(f1);
 f1=fopen(inputname,"r");

 float hodnoty[radky+2][radky+1];
 float soubor[radky+1];
 int i=1;

 while (fscanf(f1,"%d",&a)==1) {
        soubor[i]=a;
        i++;
 }

 int o;
 int p;
 i = 1;

 for (o=1; o<=radky; o++) {
        for (p=1; p<=radky+1; p++) {
                hodnoty[p][o] = soubor[i];
                i++;
                printf("%4.2f ", hodnoty[p][o]);
        }
    }
 }
}
