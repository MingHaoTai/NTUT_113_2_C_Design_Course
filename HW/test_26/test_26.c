#include<stdio.h>

void dfs(int current, int n, int graph[10][10], int visited[10], int path[10], int all_path[10][10], int *path_index, int *count_path, int c, int a, int b) {
    int flag = 0;
    visited[current] = 1;
    path[*path_index] = current;

    if (*path_index >= c - 1) {
        flag = 1;
    }
    else{
        flag = 0;
    }
    (*path_index)++;
    printf("%d, %d %d %d %d %d, %d\n", *count_path, path[0] + 1, path[1] + 1, path[2] + 1, path[3] + 1, path[4] + 1, *path_index);

    for (int i = 0; i < n; i++){
        if (graph[current][i] == 1 && visited[i] == 0){
            if (flag == 1 && (path[*path_index - 1] + 1 == a || path[*path_index - 1] + 1 == b) && (i + 1 == a || i + 1 == b)) {
                continue;
            }
            dfs(i, n, graph, visited, path, all_path, path_index, count_path, c, a, b);
        }
    }
    if (*path_index == n - 1) {
        for (int i = 0; i < *path_index + 1; i++){
            all_path[*count_path][i] = path[i];
            printf("%d ", all_path[*count_path][i] + 1);
        }
        printf("\n");
        (*count_path)++;
    }
    visited[current] = 0;
    (*path_index)--;
}

void path_sort(int all_path[100][10], int count_path, int distance[10][10]){
    for (int i = 0; i < count_path; i++){
        for (int j = 0; j < count_path - i - 1; j++){
            int sum1 = 0, sum2 = 0;
            for (int k = 0; k < 10; k++){
                sum1 += distance[all_path[j][k]][all_path[j][k + 1]];
                sum2 += distance[all_path[j + 1][k]][all_path[j + 1][k + 1]];
            }
            if (sum1 > sum2){
                for (int k = 0; k < 10; k++){
                    int temp = all_path[j][k];
                    all_path[j][k] = all_path[j + 1][k];
                    all_path[j + 1][k] = temp;
                }
            }
        }
    }
}

int check_path(int path[10], int n, int graph[10][10]){
    int visited[10] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 10; j++){
            if (path[i] + 1 == visited[j]) {
                return 0;
            }
            else{
                visited[j] = path[i] + 1;
            }
        }
    }
    for (int i = 0; i < n - 1; i++){
        if (graph[path[i]][path[i + 1]] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n, c, a, b;
    int distance[10][10] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &distance[i][j]);
        }
    }
    scanf("%d", &c);
    scanf("%d %d", &a, &b);

    int graph[10][10] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (distance[i][j] != -1){
                graph[i][j] = graph[j][i] = 1;
            }
            else{
                graph[i][j] = graph[j][i] = 0;
            }
        }
    }
    
    int visited[10] = {0};
    int path[10] = {0};
    int all_path[100][10] = {0};
    int path_index = 0, count_path = 0;
    // for (int i = 0; i < n; i++){
    dfs(0, n, graph, visited, path, all_path, &path_index, &count_path, c, a, b);
    // }
    path_sort(all_path, count_path, distance);

    int index;
    // for (int i = 0; i < count_path; i++){
    //     index = i;
    //     if (check_path(all_path[i], c, a, b, n) == 1) {
    //         continue;
    //     }
    //     printf("%d %d %d %d %d\n", all_path[0][0] + 1, all_path[i][1] + 1, all_path[i][2] + 1, all_path[i][3] + 1, all_path[i][4] + 1);
    //     break;
    // }
    // for (int i = 0; i < 10; i++){
    //     for (int j = 0; j < n; j++){
    //         printf("%d ", all_path[i][j]+1);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < count_path; i++){
        if (check_path(all_path[i], n, graph) == 1) {
            for (int j = 0; j < n; j++){
                printf("%d ", all_path[i][j] + 1);
            }
            break;
        }
    }
    return 0;
}