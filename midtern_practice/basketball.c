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
 
int main() {
    int n;
    char team[10][2], race_score[10][4][2];
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%c %c", team[i][0], team[i][1]);
        for (int j = 0; j < 4; j++){
            scanf("%d %d", &race_score[i][j][0], &race_score[i][j][1]);
        }
    }   

    int win[3] = {0};
    for (int i = 0; i < n; i++){
        if (winner_team(race_score[i] == 0)) {
            if (team[i][0] == 'A') {
                win[0]++;
            } else if (team[i][0] == 'B') {
                win[1]++;
            } else {
                win[2]++;
                
            }
        }
        else{
            if (team[i][1] == 'A') {
                win[0]++;
            } else if (team[i][1] == 'B') {
                win[1]++;
            } else {
                win[2]++;
                
            }
        }
    }
    int max = 0, max_index = 0;
    for (int i = 1; i < 3; i++){
        if (win[i] > max) {
            max = win[i];
            max_index = i;
        }
    }
    return 0;
}