#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main(){}

//definování proměnných
int x=1; //celé číslo
float y=1.1; //desetinné číslo

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