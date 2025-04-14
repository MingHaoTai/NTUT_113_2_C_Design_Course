#include<stdio.h>

typedef struct{
    int up, down, left, right, front, back;
} Dice;

void roll_forward(Dice* d){
    int temp = d->up;
    d->up = d->back;
    d->back = d->down;
    d->down = d->front;
    d->front = temp;
}

void roll_backward(Dice* d){
    int temp = d->up;
    d->up = d->front;
    d->front = d->down;
    d->down = d->back;
    d->back = temp;
}

void roll_right(Dice* d){
    int temp = d->up;
    d->up = d->left;
    d->left = d->down;
    d->down = d->right;
    d->right = temp;
}

void roll_left(Dice* d){
    int temp = d->up;
    d->up = d->right;
    d->right = d->down;
    d->down = d->left;
    d->left = temp;
}

void diceMove(int move_data[10][4], int n) {
    Dice dice_num[4];
    const Dice dice = {1, 6, 4, 3, 5, 2};
    for (int i = 0; i < 4; i++){
        dice_num[i] = dice;
    }    
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < n; j++){
            if (move_data[j][i] == 1) {
                roll_forward(&dice_num[i]);
            }
            else if (move_data[j][i] == 2) {
                roll_backward(&dice_num[i]);
            }
            else if (move_data[j][i] == 3) {
                roll_left(&dice_num[i]);
            }
            else if (move_data[j][i] == 4) {
                roll_right(&dice_num[i]);
            }
        }
    }
}
 
int main() {
    int n = 0;
    int move_data[10][4] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d %d %d %d", &move_data[i][0], &move_data[i][1], &move_data[i][2], &move_data[i][3]);
    }
    return 0;
}