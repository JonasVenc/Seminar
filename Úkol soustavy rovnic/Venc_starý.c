#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int x[], int amount)
{int i,j,p;
 for (i=1; i<=amount; i++)
      for (j=1; j<=amount-i; j++)
            if (x[j]>x[j+1]) {p=x[j]; x[j]=x[j+1]; x[j+1]=p;}
}

void straightselection(int x[], int amount)
{int i,j,k,minn;
 for (i=1; i<=amount; i++)
      {k=i;
       for (j=i+1; j<=amount; j++) if (x[j]<x[k]) k=j;
       minn=x[k]; x[k]=x[i]; x[i]=minn;
      }
}

void straightinsertion(int x[], int amount)
{int i,j,p,n;
 n=amount;
 for (i=2; i<=n; i++)
     {p=x[i]; x[0]=p; j=i-1;
      while (p<x[j]) {x[j+1]=x[j]; j--;}
      x[j+1]=p;
     }
}

//Prevzato ze souboru razeni_bs_ss_si_jen_funkce.cpp z vyukovych materialu ze site ghb

// Function to swap the the position of two elements
  void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }

  void heapify(int arr[], int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
      largest = left;

    if (right < n && arr[right] > arr[largest])
      largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }

  // Main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);

      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
  }

//Prevzato z internetovych stranek https://www.programiz.com/dsa/heap-sort

// function to find the partition position
int partition(int array[], int low, int high) {

  // select the rightmost element as pivot
  int pivot = array[high];

  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;

      // swap element at i with element at j
      swap(&array[i], &array[j]);
    }
  }

  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);

  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);

    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);

    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

//Prevzato z internetovych stranek https://www.programiz.com/dsa/quick-sort

// Shell sort
void shellSort(int array[], int n) {
    int m=1;
    while (m<n+1){
    m=m*2;
    }
    m=m-1;
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = m / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

//Prevzato z internetovych stranek https://www.programiz.com/dsa/shell-sort

main()
{
 int a; char outputname[100]; char inputname[100]; char values[100]; FILE *f1, *f2;   //deklarace souborù f1 a f2
 int prvky=0;
 int metoda=0;
 int zadani=0;

 while (metoda<1 || metoda>2) {
 printf("Vyberte metodu řešení soustavy rovnic:\n");
 printf("1...Gaussova eliminační metoda\n2...Cramerovo pravidlo\n");
 scanf("%d", &metoda);
 }

 while (zadani<1 || zadani>2) {
 printf("1...Zvolte pro rucni zadani hodnot\n");
 printf("2...Zvolte pro zadani hodnot ze souboru\n");
 scanf("%d", &zadani);
 }

 if (zadani==1) {
    printf("Zadejte pocet rovnic\n");
    scanf("%d", &prvky);

    int values[prvky+2][prvky+1];
    int nahodny=-1;

    while (nahodny<0 || nahodny>1) {
    printf("Chcete vlozit prvky nahodne? (ano...1/ne...0)\n");
    scanf("%d", &nahodny);
    }

    if (nahodny==0) {

    printf("Zadejte %d rovnice:\n", prvky);

    int j;
    int k;

    for (j=1; j<prvky+1; j++) {
            for (k=1; k<prvky+2; k++) {
                scanf("%d", &values[k][j]);
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
        for (l=1; l<=prvky; l++) {
                for (m=1; m<=prvky+1; m++) {
                    values[m][l]=(rand()%(maximum-minimum+1))+minimum;
                }
        }
    }

    clock_t t;
    t = clock();
    if (metoda==1) {
        bubblesort(values, prvky);
    }

    if (metoda==2) {
        straightselection(values, prvky);
    }

    if (metoda==3) {
        straightinsertion(values, prvky);
    }

    if (metoda==4) {
        for(int i=1; i<prvky+1; i++){
            values[i-1]=values[i];
        }
        heapSort(values, prvky);
        for(int i=prvky; i>0; i--){
            values[i]=values[i-1];
        }
    }

    if (metoda==5) {
        quickSort(values, 1, prvky);
    }

    if (metoda==6) {
        for(int i=1;i<prvky+1;i++){
            values[i-1]=values[i];
        }
        shellSort(values, prvky);
        for(int i=prvky;i>0;i--){
            values[i]=values[i-1];
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("V tomto pripade zvolena metoda razeni se vykonala za %f sekund.\n", time_taken);
    printf("Pri %d prvcich.\n", prvky);

    //Postup mereni casu prevzat z internetovych starnek https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/

    int vystup=-1;

    while (vystup<0 || vystup>3) {
        printf("Zvolte moznost vystupu:\n0...Nikam :(\n1...Pouze do okna\n2...Pouze do souboru\n3...Do okna i do souboru\n");
        scanf("%d", &vystup);
    }

    if (vystup==1) {

        int razeni=0;
        while (razeni<1 || razeni>2) {
        printf("Vyberte zpusob razeni:\n1...vzestupne\n2...sestupne\n");
        scanf("%d", &razeni);
        }

        if (razeni==1) {
            for (int pozice=1; pozice<prvky+1; pozice++) {
                printf("%d ", values[pozice]);
            }
        }

        if (razeni==2) {
            for (int pozice=prvky; pozice>0; pozice--) {
                printf("%d ", values[pozice]);
            }
        }
    }

    if (vystup==2) {

        printf("Zadejte nazev souboru, do ktereho se serazene prvky ulozi (s priponou napriklad .dat):\n");
        scanf("%s", &outputname);
        f2=fopen(outputname,"w");

        int razeni=0;
        while (razeni<1 || razeni>2) {
        printf("Vyberte zpusob razeni:\n1...vzestupne\n2...sestupne\n");
        scanf("%d", &razeni);
        }

        if (razeni==1) {
            for (int pozice=1; pozice<prvky+1; pozice++) {
                fprintf(f2, "%d ", values[pozice]);
            }
        }

        if (razeni==2) {
            for (int pozice=prvky; pozice>0; pozice--) {
                fprintf(f2, "%d ", values[pozice]);
            }
        }

        fclose(f2);
    }

    if (vystup==3) {

        printf("Zadejte nazev souboru, do ktereho se serazene prvky ulozi (s priponou napriklad .dat):\n");
        scanf("%s", &outputname);
        f2=fopen(outputname,"w");

        int razeni=0;
        while (razeni<1 || razeni>2) {
        printf("Vyberte zpusob razeni:\n1...vzestupne\n2...sestupne\n");
        scanf("%d", &razeni);
        }

        if (razeni==1) {
            for (int pozice=1; pozice<prvky+1; pozice++) {
                fprintf(f2, "%d ", values[pozice]);
            }
            for (int pozice=1; pozice<prvky+1; pozice++) {
                printf("%d ", values[pozice]);
            }
        }

        if (razeni==2) {
            for (int pozice=prvky; pozice>0; pozice--) {
                fprintf(f2, "%d ", values[pozice]);
            }
            for (int pozice=prvky; pozice>0; pozice--) {
                printf("%d ", values[pozice]);
            }
        }

        fclose(f2);
    }
 }

 if (zadani==2) {

 printf("Zadejte nazev pocatecniho souboru pro cetni\n");
 scanf ("%s", &inputname);

 f1=fopen(inputname,"r");

 while (fscanf(f1,"%d",&a)==1) {
    prvky++;
 }

 prvky = (-1+sqrt(1+4*prvky))/2;

 fclose(f1);
 f1=fopen(inputname,"r");

 float values[prvky+2][prvky+1];
 int radek[prvky+1];
 int i=1;

 while (fscanf(f1,"%d",&a)==1) {
        radek[i]=a;
        i++;
 }

 int o;
 int p;
 i = 1;

 for (o=1; o<=prvky; o++) {
        for (p=1; p<=prvky+1; p++) {
                values[p][o] = radek[i];
                i++;
        }
 }

    clock_t t;
    t = clock();
    if (metoda==1) {
        bubblesort(values, prvky);
    }

    if (metoda==2) {
        straightselection(values, prvky);
    }

    if (metoda==3) {
        straightinsertion(values, prvky);
    }

    if (metoda==4) {
        for(int i=1; i<prvky+1; i++){
            values[i-1]=values[i];
        }
        heapSort(values, prvky);
        for(int i=prvky; i>0; i--){
            values[i]=values[i-1];
        }
    }

    if (metoda==5) {
        quickSort(values, 1, prvky);
    }

    if (metoda==6) {
        for(int i=1;i<prvky+1;i++){
            values[i-1]=values[i];
        }
        shellSort(values, prvky);
        for(int i=prvky;i>0;i--){
            values[i]=values[i-1];
        }
    }
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("V tomto pripade zvolena metoda razeni se vykonala za %f sekund.\n", time_taken);
    printf("Pri %d prvcich.\n", prvky);

    //Postup mereni casu prevzat z internetovych starnek https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/

    int vystup=-1;

    while (vystup<0 || vystup>3) {
        printf("Zvolte moznost vystupu:\n0...Nikam :(\n1...Pouze do okna\n2...Pouze do souboru\n3...Do okna i do souboru\n");
        scanf("%d", &vystup);
    }

    if (vystup==1) {

        int razeni=0;
        while (razeni<1 || razeni>2) {
        printf("Vyberte zpusob razeni:\n1...vzestupne\n2...sestupne\n");
        scanf("%d", &razeni);
        }

        if (razeni==1) {
            for (int pozice=1; pozice<prvky+1; pozice++) {
                printf("%d ", values[pozice]);
            }
        }

        if (razeni==2) {
            for (int pozice=prvky; pozice>0; pozice--) {
                printf("%d ", values[pozice]);
            }
        }
    }

    if (vystup==2) {

        printf("Zadejte nazev souboru, do ktereho se serazene prvky ulozi (s priponou napriklad .dat):");
        scanf("%s", &outputname);
        f2=fopen(outputname,"w");

        int razeni=0;
        while (razeni<1 || razeni>2) {
        printf("Vyberte zpusob razeni:\n1...vzestupne\n2...sestupne\n");
        scanf("%d", &razeni);
        }

        if (razeni==1) {
            for (int pozice=1; pozice<prvky+1; pozice++) {
                fprintf(f2, "%d ", values[pozice]);
            }
        }

        if (razeni==2) {
            for (int pozice=prvky; pozice>0; pozice--) {
                fprintf(f2, "%d ", values[pozice]);
            }
        }

         fclose(f2);
    }

    if (vystup==3) {

        printf("Zadejte nazev souboru, do ktereho se serazene prvky ulozi (s priponou napriklad .dat):\n");
        scanf("%s", &outputname);
        f2=fopen(outputname,"w");

        int razeni=0;
        while (razeni<1 || razeni>2) {
        printf("Vyberte zpusob razeni:\n1...vzestupne\n2...sestupne\n");
        scanf("%d", &razeni);
        }

        if (razeni==1) {
            for (int pozice=1; pozice<prvky+1; pozice++) {
                fprintf(f2, "%d ", values[pozice]);
            }
            for (int pozice=1; pozice<prvky+1; pozice++) {
                printf("%d ", values[pozice]);
            }
        }

        if (razeni==2) {
            for (int pozice=prvky; pozice>0; pozice--) {
                fprintf(f2, "%d ", values[pozice]);
            }
            for (int pozice=prvky; pozice>0; pozice--) {
                printf("%d ", values[pozice]);
            }
        }

         fclose(f2);
    }

 fclose(f1);*/
 }

 system("pause");
}
