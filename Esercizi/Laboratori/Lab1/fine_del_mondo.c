#include <stdio.h>
#include <limits.h>

#define FINE UINT_MAX

int main(){
    int totalDays=((FINE/60)/60)/24;

    int anni=totalDays/360;
    int mesi=(totalDays%360)/30;
    int giorni=(totalDays%360)%30;

    anni+=1970;
    if((++mesi)==12){
        mesi=1;
        anni++;
    }
    if((++giorni)==30){
        giorni=1;
        mesi++;
    }

    printf("%d/%d/%d\n", giorni, mesi, anni);
}