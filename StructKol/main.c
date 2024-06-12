#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 100

struct Podaci{
float visina;
int tezina;
int pol;
float index;
int rbr;
};

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void sortiranje(struct Podaci a[], int n){
struct Podaci temp;
int zamena=0;
for(int i=0; i<n-1; i++){
    zamena=0;
    for(int j=0; j<n-1; j++){
        if(a[j].index>a[j+1].index){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            zamena=1;
        }
    }
    if(!zamena)
        break;
}

}

int brojacLjudi(struct Podaci struktura[]){
FILE *fp;
fp=fopen("T1.txt","r");
if(!fp) printf("\nGreska\n");
int broj=0;
float v;
int t,p,ind;
int rb=1;

while(fscanf(fp,"%f %d %d", &v,&t,&p)!=EOF)
{
    struktura[broj].visina=v;
    struktura[broj].tezina=t;
    struktura[broj].pol=p;
    struktura[broj].index=(t*1.0)/pow(struktura[broj].visina/100,2);
    struktura[broj].rbr=rb;
    rb++;
    broj++;

}
fclose(fp);
return broj;

}

void histogram(struct Podaci strukt[], int broj){
int underweight=0, normal=0, overweight=0, obese=0;

for(int i=0; i<broj; i++)
    {

        if (strukt[i].index<18.50)
            underweight++;

        else if (strukt[i].index>30.00)
            obese++;

        else if (strukt[i].index>25.00 && strukt[i].index<30.00)
            overweight++;

        else if (strukt[i].index>18.50 && strukt[i].index<30.00)
            normal++;

    }
    printf("Un: ");
    for (int i = 0; i < underweight; i++) {
        printf("*");
    }
    printf("\n");

    printf("No: ");
    for (int i = 0; i < normal; i++) {
        printf("*");
    }
    printf("\n");

    printf("Ov: ");
    for (int i = 0; i < overweight; i++) {
        printf("*");
    }
    printf("\n");

    printf("Ob: ");
    for (int i = 0; i < obese; i++) {
        printf("*");
    }
    printf("\n");
}
int main()
{
    struct Podaci p[N];
    int brLjudi;
    brLjudi=brojacLjudi(p);

    for(int i=0; i<brLjudi; i++){
        printf("Osoba br. %d: %.2f\n",p[i].rbr,p[i].index);
    }
    printf("\n\n");

    histogram(p,brLjudi);

    printf("\n\n");
    sortiranje(p,brLjudi);
    for(int i=0; i<brLjudi; i++){
        printf("Osoba br. %d: %.2f\n",p[i].rbr,p[i].index);
    }



    return 0;
}
