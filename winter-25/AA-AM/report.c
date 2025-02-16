#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b);

int main(void){
    int n,b;
    scanf("%d%d",&n,&b);
    int books[n];
    for(int i=0;i<n;i++){
        scanf("%d",&books[i]);
    }
    qsort(books,n,sizeof(int),compare);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=books[i];
        if(sum>=b){
            printf("%d",i+1);
            break;
        }
    }
    

    return 0;
}

int compare(const void *a,const void *b){
    int *A=(int *)a,*B=(int *)b;
    return (*B-*A);
}