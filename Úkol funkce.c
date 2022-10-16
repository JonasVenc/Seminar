#include <stdio.h>
#include <math.h>

float y,v,v1,v2,v3;
float k,e,d,c;
float p,s,m,h,f,w1,w2,w3,g,g1,g2,g5,g6,g7,i,i1,i2,i3,i4;
float q,q1,q2,q3,q4;

double exchange(int n)
{
    printf("Vypocty jsou provadeny se zaokrouhlenym kurzem pro 10.02.2022\n");
    printf("Zadejte cela cisla\n");
    printf("Chcete smenit koruny? Pokud ano zadejte mnozstvi, pokud ne zadejte 0\n");
    scanf("%f",&k);
    if (k==0){
        printf("Chcete smenit eura? Pokud ano zadejte mnozstvi, pokud ne zadejte 0\n");
        scanf("%f",&e);
        if (e==0){
            printf("Chcete smenit dolary? Pokud ano zadejte mnozstvi, pokud ne zadejte 0\n");
            scanf("%f",&d);
            if (d==0){
                printf("Nebyla prevedena zadna mena\n");
            }
        }
    }
    if (k!=0){
        printf("Do jake cilove meny chcete koruny prevest? Zadejte a potvrtte 1 pro eura a 2 pro dolary\n");
        scanf("%f",&c);
        if (c==1){
            k=k/24.34;
        }
        else if (c==2){
            k=k/21.3;
        }
        return k;
    }
    else if (e!=0){
        printf("Do jake cilove meny chcete eura prevest? Zadejte a potvrtte 1 pro koruny a 2 pro dolary\n");
        scanf("%f",&c);
        if (c==1){
            e=e*24.34;
        }
        else if (c==2){
            e=e*1.14;
        }
        return e;
    }
    else if (d!=0){
        printf("Do jake cilove meny chcete dolary prevest? Zadejte a potvrtte 1 pro koruny a 2 pro eura\n");
        scanf("%f",&c);
        if (c==1){
            d=d*21.3;
        }
        else if (c==2){
            d=d/1.14;
        }
        return d;
    }
    else {
        return 0;
    }
}

double feeexhange(float n, float p){
    v=p/100;
    v1=v*n;
    v2=n-v1;
    return v2;
}

double sporeni(float n, float m, float h){
    w1=n/100*h;
    w2=w1*m;
    w3=h+w2;
    return w3;
}

double dobasplatek(float c, float u, float m){
    g5=u/100*c;
    g6=c+g5;
    g7=g6/m;
    return g7;
}

double inflace(float i, float c, float l){
    i3=i/100*c;
    i4=i3*l;
    return i4;
}

double prevod(float p, float h, float v){
    q3=p*h;
    q4=q3/v;
    return q4;
}



main(){
 int a,b,n; char x;
 printf("Je mozne provest tyto financni operace:\n1...pripocitani poplatku ke smene\n2...smena meny s poplakem\n3...vypocet uroku na sporicim uctu\n4...vypocet doby splaceni pujcky\n5...vypocet ztraty hodnoty diky inflaci\n6...prevod urciteho poctu hodnot na jinou hodnotu (napriklad prevod 45 dvacetikorun na dvoukoruny)\n");
 while (x!='n'){
    //printf("Tvuj zustatek korun: %d\n", k);
    //printf("Tvuj zustatek eur: %d\n", e);
    printf("\nZadej cislo financni operace:\n");
    scanf("%d",&a);

    if  (a==1){
        y=exchange(1);
        printf("Vysledna castka je: %f\n", y);
    }
    else if (a==2){
        printf("Jaka je vyse poplatku, napriklad 1 procento ... 1\n");
        scanf("%f",&v3);
        y=feeexhange(exchange(1),v3);
        printf("Vysledna castka je: %f\n", y);
    }
    else if (a==3){
        printf("Jaky je sporici urok za mesic? Zadej ve tvaru napriklad 2 procenta ... 2\n");
        scanf("%f",&s);
        printf("Kolik mesicu se bude urocit?\n");
        scanf("%f",&m);
        printf("Jaka je hodnota urocene castky?\n");
        scanf("%f",&h);
        f=sporeni(s,m,h);
        printf("\nCelkovy zustatek po %f mesicich je: %f\n", m, f);
    }
    else if (a==4){
        printf("Pujcena castka:\n");
        scanf("%f",&g);
        printf("Jaky je urok pujcky? Zadej ve tvaru napriklad 2 procenta ... 2\n");
        scanf("%f",&g1);
        printf("Jaka je vyse mesicni splatky?\n");
        scanf("%f",&g2);
        printf("\nTuto pujcku by se za techto podminek spacelo: %f\n", dobasplatek(g,g1,g2));
    }
    else if (a==5){
        printf("Zadej hodnotu rocni inflace, napriklad pro 4 procenta ... 4\n");
        scanf("%f",&i);
        printf("Zadej castku pro vypocet\n");
        scanf("%f",&i1);
        printf("Zadej pocet let\n");
        scanf("%f",&i2);
        printf("\nVlastni hodnota castky %f by za %f let ztratila %f ze sve hodnoty", i1, i2, inflace(i,i1,i2));
        printf("\nHodnota %f by tedy za %f let byla %f", i1, i2, i1-inflace(i,i1,i2));
    }
    else if (a==6){
        printf("Zadej pocet prvnich hodnot\n");
        scanf("%f",&q);
        printf("Zadej prvni hodnotu\n");
        scanf("%f",&q1);
        printf("Zadej druhou (vyslednou) hodnotu\n");
        scanf("%f",&q2);
        printf("%f minci s hodnotou %f lze rozmenit na %f s hodnotou %f\n", q, q1, prevod(q,q1,q2), q2);
        printf("Celkova hodnota techto minci je: %f\n", q*q1);
    }

    printf("\nPokracovat? (a/n) ");
    x=getchar(); x=getchar();
  }
}
