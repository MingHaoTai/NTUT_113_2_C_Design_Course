#include <stdio.h>
#include <math.h>

// 遞迴函式來計算格雷碼
void Gray(int n, int k) {
    if (n == 1) {
        printf("%d", k); // 基礎條件
        return;
    }

    int mid = pow(2, n - 1); // 2^(n-1)

    if (k < mid) {
        printf("0");
        Gray(n - 1, k);
    } else {
        printf("1");
        Gray(n - 1, (mid * 2 - 1 - k));
    }
}

int main() {
    int n, k;
    while (1) {
        scanf("%d", &n);
        if (n == -1) break;
        scanf("%d", &k);
        
        Gray(n, k);
        printf("\n"); // 換行輸出
    }
    return 0;
}
