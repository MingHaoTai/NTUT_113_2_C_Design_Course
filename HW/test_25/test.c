#include<stdio.h>

int checkHorizontal(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start = j, end = j;
    while (start > 0 && start > j - 4) start--;
    while (end < 9 && end < j + 4) end++;
    for (int k = start; k <= end; k++){
        if (k == j || data[i][k] == 1) count++;
        else count = 0;
        if (count == 5) flag = 1;
        else if (count > 5) flag = 0;
    }
    return (count <= 5 && flag == 1);
}

int checkVertical(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start = i, end = i;
    while (start > 0 && start > i - 4) start--;
    while (end < 9 && end < i + 4) end++;
    for (int k = start; k <= end; k++){
        if (k == i || data[k][j] == 1) count++;
        else count = 0;
        if (count == 5) flag = 1;
        else if (count > 5) flag = 0;
    }
    return (count <= 5 && flag == 1);
}

int checkRightSlant(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start_i = i, end_i = i, start_j = j, end_j = j;
    while (start_i > 0 && start_i > i - 4 && start_j > 0 && start_j > j - 4) {
        start_i--; start_j--;
    }
    while (end_i < 9 && end_i < i + 4 && end_j < 9 && end_j < j + 4) {
        end_i++; end_j++;
    }
    int a = start_i, b = start_j;
    while (a <= end_i && b <= end_j){
        if ((a == i && b == j) || data[a][b] == 1) count++;
        else count = 0;
        if (count == 5) flag = 1;
        else if (count > 5) flag = 0;
        a++; b++;
    }
    return (count <= 5 && flag == 1);
}

int checkLeftSlant(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start_i = i, end_i = i, start_j = j, end_j = j;
    while (start_i > 0 && start_i > i - 4 && start_j < 9 && start_j < j + 4) {
        start_i--; start_j++;
    }
    while (end_i < 9 && end_i < i + 4 && end_j > 0 && end_j > j - 4) {
        end_i++; end_j--;
    }
    int a = start_i, b = start_j;
    while (a <= end_i && b >= end_j){
        if ((a == i && b == j) || data[a][b] == 1) count++;
        else count = 0;
        if (count == 5) flag = 1;
        else if (count > 5) flag = 0;
        a++; b--;
    }
    return (count <= 5 && flag == 1);
}

void mySort(int line[20][3], int count_line){
    for (int i = 0; i < count_line - 1; i++){
        for (int j = 0; j < count_line - i - 1; j++){
            if (line[j][2] < line[j + 1][2] ||
                (line[j][2] == line[j + 1][2] &&
                (line[j][0]*10 + line[j][1]) > (line[j + 1][0]*10 + line[j + 1][1]))) {
                int temp[3];
                for (int k = 0; k < 3; k++) {
                    temp[k] = line[j][k];
                    line[j][k] = line[j + 1][k];
                    line[j + 1][k] = temp[k];
                }
            }
        }
    }
}

void findSpace(int data[10][10]){
    int count, count_line = 0;
    int line[20][3] = {0};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            count = 0;
            if (data[i][j] == 0) {
                if (checkHorizontal(data, i, j)) count++;
                if (checkVertical(data, i, j)) count++;
                if (checkRightSlant(data, i, j)) count++;
                if (checkLeftSlant(data, i, j)) count++;
                if (count != 0) {
                    line[count_line][0] = i;
                    line[count_line][1] = j;
                    line[count_line][2] = count;
                    count_line++;
                }
            }
        }
    }
    mySort(line, count_line);
    for (int i = 0; i < count_line; i++){
        printf("%d%d %d\n", line[i][0], line[i][1], line[i][2]);
    }
}

int main() {
    int data[10][10] = {0};
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            scanf("%d", &data[i][j]);
        }
    }
    findSpace(data);
    return 0;
}
