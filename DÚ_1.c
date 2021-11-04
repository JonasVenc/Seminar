#include <stdio.h>
#include <stdlib.h>
main()
{
 int i=1;
 int a,b,c,d,m,n,g,p,prvni,druhe,rozdil;
 printf("Tento program po zadani dvou dat vypise, klolikaty den v roce kazde je a take kolik dni mezi nimi uplynulo\n");
 while (i==1)
 {


 printf("Zadej dve existujici data, tedy ctyri cisla, oddelena enterem ve tvrau napriklad: 1 5 26 6\n");
 printf("Tento priklad vyjadruje: 1. 5. a druhe datum je 26. 6.\n\n");
 scanf("%d%d%d%d",&a,&b,&c,&d);


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
    else if (b==12) m=334;


 if (d==1) n=0;
    else if (d==2) n=31;
    else if (d==3) n=59;
    else if (d==4) n=90;
    else if (d==5) n=120;
    else if (d==6) n=151;
    else if (d==7) n=181;
    else if (d==8) n=212;
    else if (d==9) n=243;
    else if (d==10) n=273;
    else if (d==11) n=304;
    else if (d==12) n=334;


 prvni=a+m;
 druhe=c+n;


 printf("\nPrvni datum je %d. den v roce.\n",prvni);
 printf("Druhe datum je %d. den v roce.\n\n",druhe);


 if (prvni>druhe) rozdil=prvni-druhe-1;
 else if (prvni==druhe) rozdil=prvni-druhe;
 else rozdil=druhe-prvni-1;


 printf("Mezi obema daty uplynulo %d dni.\n\n\n\n",rozdil);



 printf("Pokud chcete pokracovat pro dalsi data napiste 1 a potvrdte enterem, pokud ne zmacknete 0 a potvrdte enterem\n\n");
 scanf("%d",&g);

 if (g==0) break;
 else if (g==1) {
    i=1;
    printf("\n\n\n");
    }
 else {
    printf("Zadal/a jste neplatnou hodnotu (musi byt 1 nebo 2): %d\n\n\n", g);
    break;
    }

 }

 system("pause");
}
