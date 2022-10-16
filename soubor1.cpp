#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main()
{
 int a; FILE *f1, *f2;      //deklarace souborù f1 a f2
 f1=fopen("vstup.dat","r"); //otevøení souboru f1 (vstup.dat) ke ètení
 f2=fopen("vystup.dat","w"); //otevøení souboru f2 (vystup.dat) k zápisu
 while (fscanf(f1,"%d",&a)==1)//cyklické ètení hodnoty a ze souboru f1 až do jeho konce
         fprintf(f2,"%d ",a*a); //zápis hodnoty a*a do souboru f2
 fclose(f1); fclose(f2); //uzavøení obou souborù f1 a f2
 system("pause");
}
