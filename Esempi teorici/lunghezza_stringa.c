#include <stdio.h>

int main(){
    char *s="hi";
    int l;
    for(l=0; *s!='\0';s++)l++;
    printf("lunghezza: %d\n", l);
}