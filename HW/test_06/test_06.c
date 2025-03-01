#include<stdio.h>
#include<string.h>

float getScore(char data[3]){
    char card[13][3] = {{'A', '\0'}, {'2', '\0'}, {'3', '\0'}, {'4', '\0'}, {'5', '\0'}, {'6', '\0'}, {'7', '\0'}, {'8', '\0'}, {'9', '\0'}, {'1', '0', '\0'}, {'J', '\0'}, {'Q', '\0'}, {'K', '\0'}};
    float score[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0.5, 0.5, 0.5};
    int index;
    for (int i = 0; i < 13; i++){
        if (strcmp(data, card[i]) == 0){    // 字串比較，若相同則回傳0
            index = i;
        }
    }
    return score[index];
}

void print(float score){
    if (score - (int)score == 0){
        printf("%d\n", (int)score);
    }
    else{
        printf("%.1f\n", score);
    }
}

int main(){
    char data[6][3] = {};
    float score[2] = {0, 0};
    for (int i = 0; i < 6; i++){
        scanf("%s", &data[i]);
    }
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            score[i] += getScore(data[(i*3)+j]);
        }
        if (score[i] > 10.5){
            score[i] = 0;
        }
        print(score[i]);
    }
    if (score[0] > score[1]){
        printf("X Win");
    }
    else if (score[0] == score[1]){
        printf("Tie");
    }
    else{
        printf("Y Win");
    }
   return 0;
}