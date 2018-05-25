#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

int same(char *pc,char *ps,int i){
    char *pp=ps;
    while (*ps!='\0'){
        pc=pp;
        while (*pc!='\0'){
            if (*ps==*pc){
                i--;
            }
            if (i==0){
                return 1;
            }
            pc++;
        }
        ps++;
    }
    printf("%d ",i);
    if (i==0){
        return 1;
    }else{
        return 0;
    }
}

int charnumber(char *pc){
    int n=0;
    while (*pc!='\0'){
        n++;
        pc++;
    }
    return n;
}

int main(){
    int k=0,n=0,i=0;
    char *pc=(char *)malloc(sizeof(char)*50);
    char *ps=(char *)malloc(sizeof(char)*50);
    scanf("%s%s",pc,ps);
    n=charnumber(pc);
    i=charnumber(ps);
    //printf("%d %d",n,i);
    if (n>i){
        k=same(ps,pc,i);
    }else{
        k=same(pc,ps,n);
    }
    if (k){
        printf("YES");
    }else{
        printf("NO");
    }
    return 0;
}
