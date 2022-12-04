#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int radky=0;

float determinant(float hodnoty[radky+2][radky+1]) {
    float det;

    det = hodnoty[1][1]*hodnoty[2][2]*hodnoty[3][3]+hodnoty[2][1]*hodnoty[3][2]*hodnoty[1][3]+hodnoty[3][1]*hodnoty[1][2]*hodnoty[2][3]-hodnoty[3][1]*hodnoty[2][2]*hodnoty[1][3]-hodnoty[2][1]*hodnoty[1][2]*hodnoty[3][3]-hodnoty[1][1]*hodnoty[3][2]*hodnoty[2][3];

    return det;
}

main()
{
 int a; char outputname[100]; char inputname[100]; char hodnoty[100]; FILE *f1, *f2;
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
                    printf("%4.2f ", hodnoty[m][l]);
                }
                printf("\n");
        }
    }


    if (metoda==2) {

            float polex[radky+2][radky+1];

            for (int l=1; l<=radky; l++) {
                for (int m=1; m<=radky+1; m++) {
                        polex[m][l]=hodnoty[m][l];
                }
            }

            for (int l=1; l<=radky; l++) {
                polex[1][l]=polex[4][l];
            }

////
            for (int l=1; l<=radky; l++) {
                for (int m=1; m<=radky+1; m++) {
                    printf("%4.2f ", polex[m][l]);
                }
                printf("\n");
            }
////

            float vysledek = determinant(polex)/determinant(hodnoty);
            printf ("\nPrvni promenna: %f", vysledek);


            for (int l=1; l<=radky; l++) {
                polex[1][l]=hodnoty[1][l];
            }

            for (int l=1; l<=radky; l++) {
                polex[2][l]=polex[4][l];
            }


            vysledek = determinant(polex)/determinant(hodnoty);
            printf ("\nDruha promenna: %f", vysledek);

            for (int l=1; l<=radky; l++) {
                polex[2][l]=hodnoty[2][l];
            }

            for (int l=1; l<=radky; l++) {
                polex[3][l]=polex[4][l];
            }

            vysledek = determinant(polex)/determinant(hodnoty);
            printf ("\nTreti promenna: %f", vysledek);
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

printf("\n%f\n", soubor[10]);

 for (o=1; o<radky+1; o++) {
        printf("\n%f\n", soubor[10]);
        for (p=1; p<radky+2; p++) {
                printf("\n%f\nxxx", soubor[10]);
                hodnoty[p][o] = soubor[i];
                for (int l=1; l<=50; l++) {
    printf("%f\n", soubor[l]);
 }
                i++;
                printf("\n%f\n", soubor[10]);
                printf("%4.2f ", hodnoty[p][o]);
                printf("%f ", soubor[i]);
        }
        printf("\n%f\n", soubor[10]);
        printf("\n");
        printf("\n%f\n", soubor[10]);
    }

     if (metoda==2) {

            float polex[radky+2][radky+1];

            for (int l=1; l<=radky; l++) {
                for (int m=1; m<=radky+1; m++) {
                        polex[m][l]=hodnoty[m][l];
                }
            }

            for (int l=1; l<=radky; l++) {
                polex[1][l]=polex[4][l];
            }

////
            for (int l=1; l<=radky; l++) {
                for (int m=1; m<=radky+1; m++) {
                    printf("\n%4.2f ", polex[m][l]);
                }
                printf("\n");
            }
////

            float vysledek = determinant(polex)/determinant(hodnoty);
            printf("%f\n%f", determinant(polex), determinant(hodnoty));
            printf ("\nPrvni promenna: %f", vysledek);


            for (int l=1; l<=radky; l++) {
                polex[1][l]=hodnoty[1][l];
            }

            for (int l=1; l<=radky; l++) {
                polex[2][l]=polex[4][l];
            }


            vysledek = determinant(polex)/determinant(hodnoty);
            printf ("\nDruha promenna: %f", vysledek);

            for (int l=1; l<=radky; l++) {
                polex[2][l]=hodnoty[2][l];
            }

            for (int l=1; l<=radky; l++) {
                polex[3][l]=polex[4][l];
            }

            vysledek = determinant(polex)/determinant(hodnoty);
            printf ("\nTreti promenna: %f", vysledek);
     }
 }
}
