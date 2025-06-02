#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_s {
    char name[50];
    int score;
} student_t;

void input(student_t s[], int n) {  // 輸入學生資料
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].score);
    }
}

void getHigh(student_t s[], int n, char name[], int *highScore) {   // 取得最高分與學生姓名
    *highScore = s[0].score;
    strcpy(name, s[0].name);
    for (int i = 1; i < n; i++) {
        if (s[i].score > *highScore) {
            *highScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

void getLow(student_t s[], int n, char name[], int *lowScore) { // 取得最低分與學生姓名
    *lowScore = s[0].score;
    strcpy(name, s[0].name);
    for (int i = 1; i < n; i++) {
        if (s[i].score < *lowScore) {
            *lowScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

int getAverage(student_t s[], int n) {  // 計算平均分（無條件捨去）
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += s[i].score;
    }
    return total / n;
}

int getMedian(student_t s[], int n) {   // 中位數計算（無條件捨去）
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = s[i].score;
    }
    for (int i = 0; i < n - 1; i++) {   // 簡單排序（冒泡排序）
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    int median;
    if (n % 2 == 1) {
        median = arr[n / 2];
    } else {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2;
    }
    free(arr);
    return median;
}

int main() {
    int n;
    scanf("%d", &n);
    student_t s[20];
    input(s, n);
    char highName[50], lowName[50];
    int highScore, lowScore;
    getHigh(s, n, highName, &highScore);
    getLow(s, n, lowName, &lowScore);
    int avg = getAverage(s, n);
    int med = getMedian(s, n);
    printf("%s %d\n", highName, highScore);
    printf("%s %d\n", lowName, lowScore);
    printf("%d\n", avg);
    printf("%d\n", med);
    return 0;
}