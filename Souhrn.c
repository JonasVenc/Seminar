#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <ctime>

main(){}

//definování proměnných
int x=1; //celé číslo
float y=1.1; //desetinné číslo

int a, b; //pro další příklady


//vypsání
printf("");

    //odskočení řádku (enter)
    printf("\n");
    //vypsání neznámé
    printf("Neznámá je: %d", x);
    //vypsání float, minimálně 4 číslice a z toho 2 desetinné ?
    printf("Float je: %4.2f\n",t);

//načtení proměnné do a
scanf("%d",&a);

//if, else
if (test expression1) {
   // statement(s)
}
else if(test expression2) {
   // statement(s)
}
else if (test expression3) {
   // statement(s)
}
.
.
else {
   // statement(s)
}

//while cyklus
while (testExpression) {
  // the body of the loop 
}

//for cyklus (počáteční hodnota, do kdy se to bude opakovat, jak se změní)
for (initializationStatement; testExpression; updateStatement)
{
    // statements inside the body of loop
}

//zápis druhé odmocniny
sqrt(x);

//kotrola, zda je to celé číslo
if (x==round(x)){
    //x je celé
}

//modulo (zbytek po dělení)
if (i%d==0){
    //i je násobek d
}

//x o minimální délce 11 číslic
printf("%11d", x);

//na konci pro to, aby se program hned nevypl
system("pause");

//fukce
void nazev(int z) //int pro vnější vstup (z se zde deklaruje)
                  //místo void lze použít například double nebo int
{
    //vnitřek funkce
    return z; //z je výsledek funkce, hodnotu uloží do původní rovnice
}

//volání funkce
a = b +nazev(y) //k b se přičte návratová hodnota funkce

//deklarace pole
int p[20]; //pole p o velikosti 20 znaků

int q[20][30]; //dvourozměrné pole

//práce s poli
p[5] = x; //na páté místo pole p uloží hodnotu x

//deklarace souboru
FILE *f1;
FILE *f2;

//otevření souboru
f1=fopen("vstup.dat","r"); //otevření souboru f1 (vstup.dat) ke čtení
f2=fopen("vystup.dat","w"); //otevření souboru f2 (vystup.dat) k zápisu

//čtení souboru
while (fscanf(f1,"%d",&a)==1)//cyklické čtení hodnoty a ze souboru f1 až do jeho konce

//zápis dat
fprintf(f2,"%d",a*a); //zápis hodnoty a*a do souboru f2

//uzavření souboru
fclose(f1); fclose(f2); //uzavření obou souborů f1 a f2