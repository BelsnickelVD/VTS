#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define N 100
struct Ocene{
float prvi;
float drugi;
float treci;
float cetvrti;
float ukupno;
};

int brojac(struct Ocene niz[]){
    int broj=0;
    FILE *fp= fopen("T2.txt","r");
    if(!fp)printf("Greska");

    float p,d,t,c;
    float u;
    while(fscanf(fp,"%f %f %f %f", &p,&d,&t,&c)!=EOF)
    {
        niz[broj].prvi=p;
        niz[broj].drugi=d;
        niz[broj].treci=t;

        if(c==0)
        niz[broj].cetvrti=t;

        else  niz[broj].cetvrti=c;

        niz[broj].ukupno=(niz[broj].prvi+niz[broj].drugi+niz[broj].treci+niz[broj].cetvrti)*2;

    broj++;
    }
    fclose(fp);
    return broj;
}
void swap(float *a, float *b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
}
void sortiranje(struct Ocene o[], int broj){

    int zamena =0;
    for(int i=0; i<broj-1; i++){
        zamena=0;
        for(int j=0; j<broj-1; j++){
            if(o[j].ukupno>o[j+1].ukupno){
                swap(&o[j].ukupno,&o[j+1].ukupno);
                zamena=1;
            }
        }
        if(!zamena) break;

    }

}
void histogram(struct Ocene o[], int broj){

    int f=0,d=0,c=0,b=0,a=0;

    for(int i=0; i<broj; i++){

        if(o[i].ukupno<20) f++;

        else if(o[i].ukupno>=20 && o[i].ukupno<25) d++;

        else if(o[i].ukupno>=25 && o[i].ukupno<30) c++;

        else if(o[i].ukupno>=30 && o[i].ukupno<35) b++;

        else if(o[i].ukupno>=35) a++;
    }

    printf("\n\nA:");
    for(int i=0; i<a; i++) printf("*");

    printf("\nB:");
    for(int i=0; i<b; i++) printf("*");

    printf("\nC:");
    for(int i=0; i<c; i++) printf("*");

    printf("\nD:");
    for(int i=0; i<d; i++) printf("*");

    printf("\nF:");
    for(int i=0; i<f; i++) printf("*");

}
int main()
{
    struct Ocene o[N];
    int brojUcenika=brojac(o);

    for(int i=0; i<brojUcenika; i++){

        printf("Ucenik %d:  I: %.2f  II:%.2f  III:%.2f  IV:%.2f  // Ukupno: %.2f\n",i+1,o[i].prvi,o[i].drugi,o[i].treci,o[i].cetvrti,o[i].ukupno);
    }

    histogram(o,brojUcenika);
    sortiranje(o,brojUcenika);

    printf("\n\n");
    for(int i=0; i<brojUcenika; i++){

        printf("Ucenik %d:  I: %.2f  II:%.2f  III:%.2f  IV:%.2f  // Ukupno: %.2f\n",i+1,o[i].prvi,o[i].drugi,o[i].treci,o[i].cetvrti,o[i].ukupno);
    }
    return 0;
}
