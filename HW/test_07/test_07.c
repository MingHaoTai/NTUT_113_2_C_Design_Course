#include<stdio.h>

void graph1(int m){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m-i-1; j++){
            printf("#");
        }
        for (int j = 0; j < (i*2)+1; j++){
            if (j % 2 == 0){
                printf("*");
            }
            else{
                if (i % 3 == 1){
                    printf("A");
                }
                else if (i % 3 == 2){
                    printf("B");
                }
                else{
                    printf("C");
                }
            }
        }
        for (int j = 0; j < m-i-1; j++){
            printf("#");
        }
        printf("\n");
    }
}

void graph2(int m){
    for (int i = 0; i < m; i++){
        for (int j = i+1; j > 0; j--){
            printf("%d", j);
        }
        for (int j = 0; j < (m-i)*2; j++){
            printf("*");
        }
        for (int j = 1; j < i+2; j++){
            printf("%d", j);
        }
        printf("\n");
    }
}

int main(){
    int n, m;
    scanf("%d ", &n);
    scanf("%d", &m);
    if (n < 1 || n > 2 || m < 2 || m > 9){
        printf("error");
        return 0;
    }
    else{
        if (n == 1){
            graph1(m);
        }
        else{
            graph2(m);
        }
    }
    return 0;
}