#include<stdio.h>

void getScore(int p[]){
    int score = 0, zero = 0;
    int state[3] = {0, 0, 0};
    for(int i = 0; i < 5; i++){
        if(p[i] == 0){
            zero++;
            if(zero == 3){
                for(int j = 0; j < 3; j++){
                    state[j] = 0;
                }
            }
        }
        else if(p[i] == 4){
            zero = 0;
            for(int j = 0; j < 3; j++){
                score += state[j];
                state[j] = 0;
            }
            score++;
        }
        else{
            int temp;
            for(int j = 0; j < p[i]; j++){
                score += state[2];
                state[2] = state[1];
                state[1] = state[0];
                state[0] = 0;
            }
            state[p[i]-1] = 1;
            
        }
    }
    printf("%d\n", score);
    for(int i = 0; i < 3; i++){
        printf("%d ", state[i]);
    }
}

int main(){
    int player[5];
    for(int i = 0; i < 5; i++){
        scanf("%d", &player[i]);
    }
    getScore(player);
    return 0; 
}