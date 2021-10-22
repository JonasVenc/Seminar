#include <stdio.h>
#include <stdlib.h>
main()
{
 int a,b,c,d,k,l,m;
 //poznamka
 printf("Tento program vypise, klolikate dny v roce jsou zadana dve data a take kolik dni mezi nimi uplynulo")
 printf("Zadej dve existujici data, tedy ctyri cisla, oddelena mezerou ve tvrau napriklad: 1 5 1 6\n");
 printf("Tento priklad vyjadruje: 1. 5. a druhe datum je 1. 6.")
 scanf("%d%d%d%d",&a,&b,&c,&d);
 k=30;
 l=31;
 if (a==1) m=0;
    else if (a==2) m=31;
    else if (a==3) m=59;
    else if (a==4) m=90;
    else if (a==5) m=120;
    else if (a==6) m=151;
    else if (a==6) m=181;
    else if (a==7) m=;
    else if (a==8) m=;
// if (a>b) if (a>c) if (b>c) m=b;
//                    else m=c;
//             else  m=a;
//     else if (b>c) if (a>c) m=a;
//                    else m=c;
//             else  m=b;
 printf("%d je prostredni\n",m);
 //system("pause");
}
