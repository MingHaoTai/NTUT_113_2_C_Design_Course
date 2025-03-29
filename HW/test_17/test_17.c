#include<stdio.h>

int winner_team(int score[4][2]){   // left team win => 0, else => 1
    int left = 0, right = 0;
    for (int i = 0; i < 4; i++){
        left += score[i][0];
        right += score[i][1];
    }
    if (left > right){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    int round;
    char team[10][2] = {};
    int score[10][4][2] = {};
    int winner = 0;
    int win[3] = {0};
    int all_score = 0;
    char win_team;
    scanf("%d", &round);
    for (int i = 0; i < round; i++){
        scanf(" %c %c", &team[i][0], &team[i][1]);
        for (int j = 0; j < 4; j++){
            scanf("%d %d", &score[i][j][0], &score[i][j][1]);
        }
    }

    for (int i = 0; i < round; i++){
        winner = winner_team(score[i]);
        if (team[i][winner] == 'A'){
            win[0]++;
        }
        else if (team[i][winner] == 'B'){
            win[1]++;
        }
        else{
            win[2]++;
        }
    }
    if (win[0] > win[1] && win[0] > win[2]){
        printf("A");
        win_team = 'A';
    }
    else if (win[1] > win[0] && win[1] > win[2]){
        printf("B");
        win_team = 'B';
    }
    else{
        printf("C");
        win_team = 'C';
    }

    for (int i = 0; i < round; i++){
        if (team[i][0] == win_team){
            for (int j = 0; j < 4; j++){
                all_score += score[i][j][0];
            }
        }
        else if (team[i][1] == win_team){
            for (int j = 0; j < 4; j++){
                all_score += score[i][j][1];
            }
        }
    }
    printf(" %d", all_score);
}