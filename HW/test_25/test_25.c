#include<stdio.h>

int checkHorizontal(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start = j, end = j;
    while (start > 0 && start > j - 4) start--;
    while (end < 9 && end < j + 4) end++;
    // if (i == 0 && j == 8) {
    //     printf("%d %d\n", start, end);
    // }
    for (int k = start; k <= end; k++){
        if (data[i][k] == 1 || k == j) {
            if (k == start && start-1 >= 0 && data[i][start-1] == 1) {
                count++;
            }
            else if (k == end && end+1 <= 9 && data[i][end+1] == 1) {
                count++;
            }
            count++;
        }
        else{
            count = 0;
        }
        if (count == 5) {
            flag = 1;
        }
        else if (count > 5) {
            flag = 0;
        }
        // if (i == 0 && j == 8) {
        //     printf("%d %d %d %d\n", i, j, count, flag);
        // }
    }
    if (count <= 5 && flag == 1 ) {
        return 1;
    }
    return 0;
}

int checkVertical(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start = i, end = i;
    while (start > 0 && start > i - 4) start--;
    while (end < 9 && end < i + 4) end++;
    // if (i == 0 && j == 8) {
    //     printf("%d %d\n", start, end);
    // }
    for (int k = start; k <= end; k++){
        if (data[k][j] == 1 || k == i) {
            if (k == start && start-1 >= 0 && data[start-1][j] == 1) {
                count++;
            }
            else if (k == end && end+1 <= 9 && data[end+1][j] == 1) {
                count++;
            }
            count++;
        }
        else{
            count = 0;
        }
        if (count == 5) {
            flag = 1;
        }
        else if (count > 5) {
            flag = 0;
        }
        // if (i == 0 && j == 8) {
        //     printf("%d %d %d %d\n", i, j, count, flag);
        // }
    }
    if (count <= 5 && flag == 1) {
        return 1;
    }
    
    return 0;
}

int checkRightSlant(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start_i = i, end_i = i, start_j = j, end_j = j, start, end;
    while (start_i > 0 && start_i > i - 4 && start_j > 0 && start_j > j - 4) {
        start_i--;
        start_j--;
    }
    while (end_i < 9 && end_i < i + 4 && end_j < 9 && end_j < j + 4) {
        end_i++;
        end_j++;
    }
    // if (i == 8 && j == 3) {
    //     printf("%d %d %d %d\n", start_i, end_i, start_j, end_j);
    // }

    int a = start_i, b = start_j;
    while (a <= end_i && b <= end_j){
        if (data[a][b] == 1 || (a == i && b == j)) {
            if (a == start_i && start_i-1 >= 0 && start_j-1 >= 0 && data[start_i-1][start_j-1] == 1) {
                count++;
            }
            else if (a == end_i && end_i+1 <= 9 && end_j+1 <= 9 && data[end_i+1][end_j+1] == 1) {
                count++;
            }
            count++;
        }
        else{
            count = 0;
        }
        if (count == 5) {
            flag = 1;
        }
        else if (count > 5) {
            flag = 0;
        }
        a++;
        b++;
        // if (i == 8 && j == 3) {
        //     printf("%d %d %d %d\n", i, j, count, flag);
        // }
    }    
    if (count <= 5 && flag == 1) {
        return 1;
    }
    return 0;
}

int checkLeftSlant(int data[10][10], int i, int j){
    int count = 0, flag = 0;
    int start_i = i, end_i = i, start_j = j, end_j = j, start, end;
    while (start_i > 0 && start_i > i - 4 && start_j < 9 && start_j < j + 4){
        start_i--;
        start_j++;
    }
    while (end_i < 9 && end_i < i + 4 && end_j > 0 && end_j > j - 4){
        end_i++;
        end_j--;
    }
    // if (i == 2 && j == 4) {
    //     printf("%d %d %d %d\n", start_i, end_i, start_j, end_j);
    // }
 
    int a = start_i, b = start_j;
    while (a <= end_i && b >= end_j){
        if (data[a][b] == 1 || (a == i && b == j)) {
            if (a == start_i && start_i-1 >= 0 && start_j+1 <= 9 && data[start_i-1][start_j+1] == 1) {
                count++;
            }
            else if (a == end_i && end_i+1 <= 9 && end_j-1 >= 0 && data[end_i+1][end_j-1] == 1) {
                count++;
            }
            count++;
        }
        else{
            count = 0;
        }
        if (count == 5) {
            flag = 1;
        }
        else if (count > 5) {
            flag = 0;
        }
        // if (i == 2 && j == 4) {
        //     printf("%d %d %d %d\n", i, j, count, flag);
        // }
        a++;
        b--;
    }    
    if (count <= 5 && flag == 1) {
        return 1;
    }
    return 0;
}

void mySort(int line[20][3], int count_line){
    for (int i = 0; i < count_line - 1; i++){
        for (int j = 0; j < count_line - i - 1; j++){
            if (line[j][2] < line[j + 1][2]){
                int temp[3];
                for (int k = 0; k < 3; k++){
                    temp[k] = line[j][k];
                    line[j][k] = line[j + 1][k];
                    line[j + 1][k] = temp[k];
                }
            }
        }
    }
    int max = line[0][2];
    for (int i = max; i > 0; i--){
        for (int a = 0; a < count_line; a++){
            for (int b = 0; b < count_line - a - 1; b++){
                if (line[b][0] > line[b + 1][0] && line[b][2] == i && line[b + 1][2] == i) {
                    int temp[3];
                    for (int k = 0; k < 3; k++){
                        temp[k] = line[b][k];
                        line[b][k] = line[b + 1][k];
                        line[b + 1][k] = temp[k];
                    }
                }
            }
        }
    }
    for (int a = max; a > 0; a--){
        for (int i = 0; i < count_line; i++){
            for (int j = 0; j < count_line - i - 1; j++){
                if (line[j][0] == line[j + 1][0] && line[j][1] > line[j + 1][1] && line[j][2] == a && line[j + 1][2] == a) {
                    int temp[3];
                    for (int k = 0; k < 3; k++){
                        temp[k] = line[j][k];
                        line[j][k] = line[j + 1][k];
                        line[j + 1][k] = temp[k];
                    }
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
                // printf("%d %d\n", i, j);
                if (checkHorizontal(data, i, j) == 1) count++;
                if (checkVertical(data, i, j) == 1) count++;
                if (checkRightSlant(data, i, j) == 1) count++;
                if (checkLeftSlant(data, i, j) == 1) count++;
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
        scanf("%d %d %d %d %d %d %d %d %d %d", &data[i][0], &data[i][1], &data[i][2], &data[i][3], &data[i][4], &data[i][5], &data[i][6], &data[i][7], &data[i][8], &data[i][9]);
    }
    findSpace(data);
    return 0;
}