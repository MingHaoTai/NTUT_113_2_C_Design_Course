#include <stdio.h>
#include <string.h>

#define MAX_LEN 105

void process_quadrant(char S[], int *index, int start_row, int start_col, int size, int result[][2], int *count) {
    char current = S[(*index)++];
    
    if (current == '0') {
        return;
    } else if (current == '1') {
        for (int i = start_row; i < start_row + size; ++i) {
            for (int j = start_col; j < start_col + size; ++j) {
                result[*count][0] = i;
                result[*count][1] = j;
                (*count)++;
            }
        }
    } else if (current == '2') {
        int half = size / 2;
        process_quadrant(S, index, start_row, start_col, half, result, count);                   // 左上
        process_quadrant(S, index, start_row, start_col + half, half, result, count);           // 右上
        process_quadrant(S, index, start_row + half, start_col, half, result, count);           // 左下
        process_quadrant(S, index, start_row + half, start_col + half, half, result, count);    // 右下
    }
}

int main() {
    char S[MAX_LEN];
    int N;

    scanf("%s", S);
    scanf("%d", &N);

    int result[64][2];
    int count = 0;
    int index = 0;

    process_quadrant(S, &index, 0, 0, N, result, &count);

    if (count == 0) {
        printf("all white\n");
    } else {
        for (int i = 0; i < count; ++i) {
            for (int j = i + 1; j < count; ++j) {
                if (result[i][0] > result[j][0] || 
                   (result[i][0] == result[j][0] && result[i][1] > result[j][1])) {
                    int tmp0 = result[i][0], tmp1 = result[i][1];
                    result[i][0] = result[j][0];
                    result[i][1] = result[j][1];
                    result[j][0] = tmp0;
                    result[j][1] = tmp1;
                }
            }
        }

        for (int i = 0; i < count; ++i) {
            printf("%d,%d\n", result[i][0], result[i][1]);
        }
    }

    return 0;
}
