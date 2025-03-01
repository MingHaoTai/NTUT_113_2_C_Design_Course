#include<stdio.h>

int findLower(float data[5]){
    float plan[3][11] = {{500, 400, 300, 10, 15, 0.08, 0.1393, 0.1349, 1.1287, 1.4803, 183},
                    {600, 500, 400, 20, 25, 0.07, 0.1304, 0.1217, 1.1127, 1.2458, 383},
                    {700, 600, 500, 30, 35, 0.06, 0.1087, 0.1018, 0.9572, 1.1243, 983}};
    float excess[5] = {0, 0, 0, 0, 0};
    float total[3] = {0, 0, 0};
    float mini = 100000;
    int mini_index = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            if (data[j] > plan[i][j]){
                excess[j] = data[j] - plan[i][j];
            }
            else{
                excess[j] = 0;
            }

        }
        for (int j = 5; j < 10; j++){
            total[i] += excess[j-5] * plan[i][j];
        }
       if (total[i] < plan[i][10]){
            total[i] = plan[i][10];
        }
    } 
    for (int i = 0; i < 3; i++){
        if (total[i] < mini){
            mini = total[i];
            mini_index = i;
        }
    }
    printf("%d \n%d", (int)mini, (int)plan[mini_index][10]);
    return 0;
}

int main(){
    float data[5] = {0, 0, 0, 0, 0};
    scanf("%f %f %f %f %f", &data[0], &data[1], &data[2], &data[3], &data[4]);
    findLower(data);
    return 0;
}