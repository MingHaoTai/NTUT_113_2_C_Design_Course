#include <stdio.h>

#define MAX 100

typedef struct {
    int first;
    int second;
} Pair;

int main() {
    int N;
    int A[MAX];
    Pair inversions[MAX * MAX];
    int count = 0;

    // 輸入
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // 找反序並加入到 inversions 陣列中（避免重複）
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                // 檢查是否已存在
                int exists = 0;
                for (int k = 0; k < count; k++) {
                    if (inversions[k].first == A[i] && inversions[k].second == A[j]) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    inversions[count].first = A[i];
                    inversions[count].second = A[j];
                    count++;
                }
            }
        }
    }

    // 若沒有反序
    if (count == 0) {
        printf("0\n");
        return 0;
    }

    // 排序 (根據 first 升序，再來是 second 升序)
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (inversions[i].first > inversions[j].first ||
               (inversions[i].first == inversions[j].first && inversions[i].second > inversions[j].second)) {
                // 交換
                Pair temp = inversions[i];
                inversions[i] = inversions[j];
                inversions[j] = temp;
            }
        }
    }

    // 輸出結果
    for (int i = 0; i < count; i++) {
        printf("(%d,%d)\n", inversions[i].first, inversions[i].second);
    }

    return 0;
}
