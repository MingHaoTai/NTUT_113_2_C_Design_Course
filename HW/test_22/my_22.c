#include<stdio.h>

void drawSquare(char DF[], int *index, int x, int y, int size, int result[][2], int *count){
    char current = DF[(*index)++];

    if (current == '0') {
        return;
    }
    else if (current == '1') {
        for (int i = x; i < x + size; i++){
            for (int j = y; j < y + size; j++){
                result[*count][0] = i;
                result[*count][1] = j;
                (*count)++;
            }
        }
    }
    else if (current == '2') {
        int half = size / 2;
        drawSquare(DF, index, x, y, half, result, count);                   // 左上
        drawSquare(DF, index, x, y + half, half, result, count);           // 右上
        drawSquare(DF, index, x + half, y, half, result, count);           // 左下
        drawSquare(DF, index, x + half, y + half, half, result, count);    // 右下
    }
}
 
int main() {
    char DF[100];
    int n;
    scanf("%s", DF);
    scanf("%d", &n);
    int index = 0;
    int result[64][2];
    int count = 0;
    drawSquare(DF, &index, 0, 0, n, result, &count);
    if (count == 0) {
        printf("all white\n");
    }
    else{
        for (int i = 0; i < count; i++){
            for (int j = i + 1; j < count; j++){
                if (result[i][0] > result[j][0] || 
                    (result[i][0] == result[j][0] && result[i][1] > result[j][1])){
                    int temp0 = result[i][0], temp1 = result[i][1];
                    result[i][0] = result[j][0];
                    result[i][1] = result[j][1];
                    result[j][0] = temp0;
                    result[j][1] = temp1;
                }
                
            }
        }
        for (int i = 0; i < count; i++){
            printf("%d,%d\n", result[i][0], result[i][1]);
        }
    }
    return 0;
}