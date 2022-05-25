#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
main()
{
//CONST delka1=20; delka2=40; poc_pre=15;
typedef struct {
         int rok1, rok2;
} DATUM;
typedef struct {
         char pre[40]; //predmet
         char tema[40];
         DATUM rok; //skolni rok
         char trida[40];
} SESIT;

FILE *f1, *p, *f2, *f3; SESIT z; int i,j,s1,s2,je_tam,a;
int pocpre=15, rok12, rok22; float pr1;
char prijmeni[20], prijmeni1[20], text_dut[20], t_nic[1]="", predmet[30], nazev[30], tema1[30], trida1[30];
f1=fopen("sesity.dat","r"); f2=fopen("vyber.dat","wb"); f3=fopen("sesity.dat","a");

printf("Pridani polozky do seznamu(k vyhledavani bude k dispozici az po opetovnem otevreni souboru)\n");
printf("Zadej nazev predmetu: ");
gets(nazev); strcat(nazev,"\n");
fprintf(f3,"%s",nazev);
printf("Zadej tema sesitu: ");
gets(tema1); strcat(tema1,"\n");
fprintf(f3,"%s",tema1);
printf("Zadej tridu sesitu: ");
gets(trida1); strcat(trida1,"\n");
printf("Zadej skolni rok (pouze rok pred /): ");
scanf("%d",&rok12);
fprintf(f3,"%d",rok12);
printf("Zadej skolni rok (pouze rok za /): ");
scanf("%d",&rok22);
fprintf(f3," %d",rok22);
fprintf(f3,"\n%s",trida1);
printf("");
gets(nazev); strcat(nazev,"\n");
fprintf(f3,"");

printf("Zadej predmet, podle ktereho se vyhledaji vechny sesity(napr. Chemie): ");
gets(predmet); strcat(predmet,"\n"); je_tam=0;
printf("\n");
//scanf("%s",prijmeni); tez pro precteni retezce - ale od do bileho znaku
do {
    //fscanf(f1,"%s",z.jme);
    fgets(z.pre,40,f1);
    fgets(z.tema,40,f1);
    //fscanf(f1,"%s",z.pri); tez pro precteni retezce ze souboru - ale od do bileho znaku
    fscanf(f1,"%d%d",&z.rok.rok1,&z.rok.rok2); getc(f1);
    fgets(z.trida,40,f1);
    //for (i=1; i<=2; i++) for (j=1; j<=pocpre; j++) fscanf(f1,"%d",&z.zna[i][j]);
    //fscanf(f1,"%c",&z.dut); getc(f1);
    if (strcmp(z.pre,predmet)==0) {
//     if (z.pri==prijmeni) takto porovnat retezce nelze
       fwrite(&z,sizeof(z),1,f2);
       //p=fopen("PREDMETY.DAT","r"); s1=0; s2=0;
       je_tam=1;
       printf("Tema: %s",z.tema);
       printf("Skolni rok: %d/%d\n",z.rok.rok1,z.rok.rok2);
       printf("Trida: %s",z.trida);
       printf("\n");
       /*for (i=1; i<=pocpre; i++) {
         fgets(predmet,30,p);
         printf("%s %d %d\n",predmet,z.zna[1][i],z.zna[2][i]);
         s1+=z.zna[1][i]; s2+=z.zna[2][i];
       } fclose(p); strcpy(text_dut,t_nic);
       switch (z.dut) {
          case 'N' : strcat(text_dut,"napomenuti tridniho"); break;
          case 'T' : strcat(text_dut,"tridni dutka"); break;
          case 'R' : strcat(text_dut,"reditelska dutka"); break;
          case 'V' : strcat(text_dut,"podminecne vylouceni"); break;
          case 'P' : strcat(text_dut,"pochvala tridniho"); break;
          case 'Q' : strcat(text_dut,"pochvala reditele"); break;
          default  : strcat(text_dut,"bez poznamek");
       }
       pr1=double(s1)/pocpre;
       printf("Prumery : %4.2f %4.2f\n",pr1,float(s2)/pocpre);
       printf("%s\n",text_dut);*/
    }
}
while (!feof(f1)); fclose(f1); fclose(f2);
if (!je_tam) {printf("Predmet %s nenalezen\n",predmet);}
//system ("pause");
}
