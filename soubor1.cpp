#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main()
{
 int a; FILE *f1, *f2;      //deklarace soubor� f1 a f2
 f1=fopen("vstup.dat","r"); //otev�en� souboru f1 (vstup.dat) ke �ten�
 f2=fopen("vystup.dat","w"); //otev�en� souboru f2 (vystup.dat) k z�pisu
 while (fscanf(f1,"%d",&a)==1)//cyklick� �ten� hodnoty a ze souboru f1 a� do jeho konce
         fprintf(f2,"%d ",a*a); //z�pis hodnoty a*a do souboru f2
 fclose(f1); fclose(f2); //uzav�en� obou soubor� f1 a f2
 system("pause");
}
