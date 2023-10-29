#include <stdio.h>
#define DIM 30

void prob_5(int v[DIM] ,int n);


int main()
{


    int w[DIM],v[DIM],y[DIM],n;
    int m[30][30],l,c;
    prob_5(v,n);
    //prob_7(w,n);
    //prob_8(y,n);
    //prob_9(m,l,c);
    //3prob_11(m,l,c);
    //prob_12(m,l,c);
    //prob_14(m,l,c);
    return 0;
}

void prob_5 (int v[DIM],int n){
    int i,j,min;
    do
    {
        printf("nr. elemente: ");
        scanf("%d",&n);
    }
    while((n<2)||(n>DIM));

    for(i=0; i<n; i++) scanf("%d",&v[i]);

    for(i=0; i<n; i++) printf("%3d ",v[i]);
    printf("\n\n");

    for(i=0; i<n; i++)
    {
        min=0;
        for(j=0; j<n; j++)
        {
            if(v[j]<v[i])
                min++;
        }
        printf("%3d %%%3.2f",v[i],((float)min/(float)n)*100.0);
    }


}

void prob_7(int w[DIM],int n){

     int i=0,j=0,k=0,min;
     int t1[30],t2[30];

    do
    {
        printf("nr. elemente: ");
        scanf("%d",&n);
    }
    while((n<2)||(n>DIM));

    for(i=0;i<n;i++) t1[i]=0;
    for(i=0;i<n;i++) t2[i]=0;

    for(i=0; i<n; i++) scanf("%d",&w[i]);

    for(i=0; i<n; i++) printf("%3d ",w[i]);
    printf("\n\n");
    i=0;
   while(i<n){
        if(w[i]<0){
            t1[j]=w[i];
            j++;
        }
        if(w[i]>0)
        {
            t2[k]=w[i];
            k++;
        }
    i++;
    }
    printf("\n");
    i=0;
    for(i=0;i<j;i++) printf("%3d ",t1[i]);
    printf("\n");
    for(i=0;i<k;i++) printf("%3d ",t2[i]);

    //pozitii elemente
    printf("\n\nPozitii elemente pare/impare\n");
    int t3[DIM],t4[DIM];
    i=j=k=0;
    while(i<n){
        if(w[i]<0){
            t3[j]=i;
            j++;
        }
        if(w[i]>0)
        {
            t4[k]=i;
            k++;
        }
    i++;
    }
    printf("\n");
    //i=0;
    for(i=0;i<j;i++) printf("%3d ",t3[i]);
    printf("\n");
    for(i=0;i<k;i++) printf("%3d ",t4[i]);





}

void prob_8(int y[DIM], int n){

    int i,j,k,neg=0;
    int aux;
    int a[DIM];
    do
    {
        printf("nr. elemente: ");
        scanf("%d",&n);
    }
    while((n<2)||(n>DIM));

    for(i=0; i<n; i++) scanf("%d",&y[i]);

    for(i=0; i<n; i++) printf("%3d ",y[i]);
    printf("\n\n");

    while(i<n){
        if(y[i]<0){
            neg=0;
            for(j=i;(j<n) && (y[j]<0);j++) neg++;
            if(neg>aux){
                aux=neg;
                k=0;
                j=i;
                while((k<aux)&&(j<(aux+i))){
                    a[k]=y[j];
                    k++;
                    j++;
                }

            }
        i+=aux;
        }
        else
        i++;
    }

    for(i=0;i<aux;i++) printf("%3d ",a[i]);

}

void prob_9(int m[30][30],int l,int c){

   int a,b,IndL[30],IndC[30];
    int i,j,k=0;

    do{
        printf("nr. linii:");
        scanf("%d",&l);
    }while((l<2)||(l>30));
    fflush(stdin);

    do{
        printf("nr. coloane:");
        scanf("%d",&c);
    }while((c<2)||(c>30));

    printf("a=");
    scanf("%d",&a);
    printf("b=");
    scanf("%d",&b);
    printf("\n\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }
    printf("\n\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%3d ",m[i][j]);
        }
    printf("\n");
    }
    printf("\n\n");
    //verificare
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            if((m[i][j]>=a)&&(m[i][j]<=b)){
               IndL[k]=i;
               IndC[k]=j;
               k++;
            }
        }
    }

    for(i=0;i<k;i++) printf("%3d ",IndL[i]);
    printf("\n");
    for(i=0;i<k;i++) printf("%3d ",IndC[i]);

}

void prob_11(int m[30][30],int l,int c){

    int l1,c1;
    int i,j,k=0;

    do{
        printf("nr. linii:");
        scanf("%d",&l);
    }while((l<2)||(l>30));
    fflush(stdin);

    do{
        printf("nr. coloane:");
        scanf("%d",&c);
    }while((c<2)||(c>30));

    do{
        printf("linie eliminata=");
        scanf("%d",&l1);
    }while((l1<0)||(l1>l));

    do{
        printf("coloana eliminata=");
        scanf("%d",&c1);
    }while((c1<0)||(c1>c));

    printf("\n\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }
    printf("\n\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%3d ",m[i][j]);
        }
    printf("\n");
    }
    printf("\n\n");
    //eliminare
    for(i=l1;i<l;i++){
        for(j=0;j<c;j++){
            m[i][j]=m[i+1][j];
        }
    }

    for(i=0;i<l;i++){
        for(j=c1;j<c;j++){
            m[i][j]=m[i][j+1];
        }
    }

    printf("\n");

    for(i=0;i<l-1;i++){
        for(j=0;j<c-1;j++){
            printf("%3d ",m[i][j]);
        }
    printf("\n");
    }


}

void prob_12(int m[30][30],int l,int c){

    int i,j,k,q;

    do{
        printf("nr. linii:");
        scanf("%d",&l);
    }while((l<2)||(l>30));
    fflush(stdin);

    do{
        printf("nr. coloane:");
        scanf("%d",&c);
    }while((c<2)||(c>30));

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }
    printf("\n\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%3d ",m[i][j]);
        }
    printf("\n");
    }
    printf("\n\n");


    //verificare

    int temp,si,sj;
    for(i=0;i<l;i++){
        for(j=i+1;j<l;j++){
            si=0;sj=0;
            for(q=0;q<c;q++){

                si+=m[i][q];
                sj+=m[j][q];
            }

           if(si>sj){
            for (k = 0; k < c; k++) {
                    temp = m[i][k];
                    m[i][k] = m[j][k];
                    m[j][k] = temp;
           }


            }
        }

    }

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%3d ",m[i][j]);
        }
    printf("\n");
    }
}

void prob_14(int m[30][30],int l,int c){

    int i,j,k,q;

    do{
        printf("nr. linii:");
        scanf("%d",&l);
    }while((l<2)||(l>30));
    fflush(stdin);

    do{
        printf("nr. coloane:");
        scanf("%d",&c);
    }while((c<2)||(c>30));

    printf("\n\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            scanf("%d",&m[i][j]);
        }
    }
    printf("\n\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%3d ",m[i][j]);
        }
    printf("\n");
    }
    printf("\n");

    //eliminare
    i=0;
    int aux=l;
    int zero,indice=0;
    while(i<l){
        zero=0;
        for(j=0;j<c;j++){
            if (m[i][j]==0) zero++;
        }
        if (zero!=0){
                l--;
                for(k=i;k<l;k++){
                        for(q=0;q<c;q++){
                            m[k][q]=m[k+1][q];
                        }
                }
        }
        else
        {
         i++;
        }
    }

    printf("\n");

    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%3d ",m[i][j]);
        }
    printf("\n");
    }




}



