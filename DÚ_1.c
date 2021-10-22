#include <stdio.h>
#include <stdlib.h>
main()
{
 int a,b,c,d,k,l,m,prvni,druhe;
 //poznamka
 printf("Tento program vypise, klolikate dny v roce jsou zadana dve data a take kolik dni mezi nimi uplynulo")
 printf("Zadej dve existujici data, tedy ctyri cisla, oddelena mezerou ve tvrau napriklad: 1 5 1 6\n");
 printf("Tento priklad vyjadruje: 1. 5. a druhe datum je 1. 6.")
 scanf("%d%d%d%d",&a,&b,&c,&d);
 k=30;
 l=31;
 if (b==1) m=0;
    else if (b==2) m=31;
    else if (b==3) m=59;
    else if (b==4) m=90;
    else if (b==5) m=120;
    else if (b==6) m=151;
    else if (b==7) m=181;
    else if (b==8) m=212;
    else if (b==9) m=243;
    else if (b==10) m=273;
    else if (b==11) m=304;
    else if (b==12) m=330;


 if (d==1) m=0;
    else if (d==2) m=31;
    else if (d==3) m=59;
    else if (d==4) m=90;
    else if (d==5) m=120;
    else if (d==6) m=151;
    else if (d==7) m=181;
    else if (d==8) m=212;
    else if (d==9) m=243;
    else if (d==10) m=273;
    else if (d==11) m=304;
    else if (d==12) m=330;
 
 
 prvni=a+b;
 druhe=c+d

 // if (a>b) if (a>c) if (b>c) m=b;
 //                    else m=c;
 //             else  m=a;
 //     else if (b>c) if (a>c) m=a;
 //                    else m=c;
 //             else  m=b;
 printf("První datum je %d. den v roce",prvni);
 printf("Druhé datum je %d. den v roce",druhe);
 system("pause");
}
