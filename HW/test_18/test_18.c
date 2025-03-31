#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_A 20
#define MAX_M 10

int compare_sequences(const void *a, const void *b) {
    int *seq1 = (int *)a;
    int *seq2 = (int *)b;
    for (int i = 0; i < MAX_M; i++) {
        if (seq1[i] != seq2[i]) return seq1[i] - seq2[i];
    }
    return 0;
}
int has_duplicate(int *arr, int m) {
    int count[10] = {0};
    for (int i = 0; i < m; i++) {
        if (count[arr[i]] > 0) return 1;
        count[arr[i]]++;
    }
    return 0;
}
int is_duplicate(int results[MAX_A][MAX_M], int *new_seq, int count, int m) {
    for (int i = 0; i < count; i++) {
        if (memcmp(results[i], new_seq, m * sizeof(int)) == 0) return 1;
    }
    return 0;
}
int main() {
    int m, i = 0,c=0;
    int sequence[MAX_A], length = 0;
    int results[MAX_A][MAX_M], result_count = 0;
    char input[100];
    scanf("%d", &m);
    getchar();
    fgets(input, sizeof(input), stdin);
    char *token = strtok(input, " ");
    while (token != NULL) {
        sequence[length++] = atoi(token);
        token = strtok(NULL, " ");
    }
    for (i = 0; i <= length - m; i++) {
        int temp[MAX_M];
        for (int j = 0; j < m; j++) temp[j] = sequence[i + j];
        if (!has_duplicate(temp, m)) {
            if (!is_duplicate(results, temp, result_count, m)) {
                memcpy(results[result_count], temp, m * sizeof(int));
                result_count++;
            }
            c++;
        }
    }
    qsort(results, result_count, sizeof(results[0]), compare_sequences);
    printf("%d\n", c);
    for (i = 0; i < result_count;i++){
        for (int j = 0; j < m; j++) printf("%d ", results[i][j]);
        printf("\n");
    }
    return 0;
}