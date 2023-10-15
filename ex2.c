#include <stdio.h>
#include<stdbool.h>


void possibilities(score){
    for(int i = 0; i <= score/2; i++){
        for(int j = 0; j <= score/3; j++){
            for(int k = 0; k <= score/6; k++){
                for(int l = 0; l <= score/7; l++){
                    for(int m = 0; m <= score/8; m++){
                        if ((i*2)+(j*3)+(k*6)+(l*7)+(m*8) == score){
                            printf("%-10s%-10d%-10s%-10d%-10s%-10d%-10s%-10d%-10s%d\n","Combinations: Saftey: ",i,"FG: ",j,"TD: ",k,"TD+1: ",l,"TD+2: ",m);
                        }
                    }
                }
            }
        }
    }
}

int main(){

bool repeat = true;
while(repeat){
    int score = 0;
    printf("Enter 0 or 1 if you want to quit, otherwise enter any NFL Score: ");
    scanf("%d",&score);
    if (score < 2){
        break;
    }
    else{
        possibilities(score);
    }
}
}
