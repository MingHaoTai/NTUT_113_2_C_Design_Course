#include<stdio.h>

int triangle(int data[3]){
    if (data[0] < 0 || data[1] < 0 || data[2] < 0 || data[0]+data[1] <= data[2] || data[0]+data[2] <= data[1] || data[1]+data[2] <= data[0]){
        return 0;
    }
    return 1;
}

int Equilateral(int data[3]){
    if (data[0] == data[1] && data[1] == data[2]){
        return 1;
    }
    return 0;
}

int Isosceles(int data[3]){
    if (data[0] == data[1] || data[1] == data[2] || data[0] == data[2]){
        return 1;
    }
    return 0;
}

int Obtuse(int data[3]){
    int index = 0, temp;
    for (int i = 1; i < 3; i++){
        if (data[i] > data[index]){
            index = i;
        }
    }
    if (index != 0){
        temp = data[index];
        data[index] = data[0];
        data[0] = temp;
    }
    if (data[0]*data[0] > data[1]*data[1]+data[2]*data[2]){
        return 1;
    }
    return 0;
}

int Acute(int data[3]){
    int index = 0, temp;
    for (int i = 1; i < 3; i++){
        if (data[i] > data[index]){
            index = i;
        }
    }
    if (index != 0){
        temp = data[index];
        data[index] = data[0];
        data[0] = temp;
    }
    if (data[0]*data[0] < data[1]*data[1]+data[2]*data[2]){
        return 1;
    }
    return 0;
}

int Right(int data[3]){
    int index = 0, temp;
    for (int i = 1; i < 3; i++){
        if (data[i] > data[index]){
            index = i;
        }
    }
    if (index != 0){
        temp = data[index];
        data[index] = data[0];
        data[0] = temp;
    }
    if (data[0]*data[0] == data[1]*data[1]+data[2]*data[2]){
        return 1;
    }
    return 0;
}

void deter(int n, int data[][3]){
    int flag = 0;
    for (int i = 0; i < n; i++){
        // printf("%d %d %d\n", data[i][0], data[i][1], data[i][2]);
        if (triangle(data[i]) == 0){
            printf("Not Triangle\n");
        }
        else{
            if (Equilateral(data[i]) == 1){
                printf("Equilateral Triangle\n");
            }
            if (Isosceles(data[i]) == 1){
                printf("Isosceles Triangle\n");
            }
            if (Obtuse(data[i]) == 1){
                printf("Obtuse Triangle\n");
            }
            if (Acute(data[i]) == 1){
                printf("Acute Triangle\n");
            }
            if (Right(data[i]) == 1){
                printf("Right Triangle\n");
            }
        }
        if (i < n-1){
            // printf("%d", n);
            for (int j = 0; j < n; j++){
                printf("*");
            }
            printf("\n");
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int data[10][3] = {};
    for (int i = 0; i < n; i++){
        scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
    }
    // printf("%d\n", n);
    deter(n, data);
    return 0;
}