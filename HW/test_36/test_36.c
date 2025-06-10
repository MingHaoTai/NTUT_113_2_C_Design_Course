#include <stdio.h>
#include <stdlib.h>

#define MAXM 100

// 鄰接串列節點
typedef struct Edge {
    int to;               // 目標節點編號
    struct Edge *next;    // 下一條邊
} Edge;

// 讀取一個整數
int readInt() {
    int x;
    if (scanf("%d", &x) != 1) exit(1);
    return x;
}

int main() {
    int N;  // 專案組數
    N = readInt();

    while (N--) {
        int M = readInt();  // 工作事項數
        // 動態配置／初始化
        Edge *head[MAXM+1] = {NULL};   // 1-based
        int indeg[MAXM+1] = {0};
        int dur[MAXM+1]   = {0};
        int dp[MAXM+1]    = {0};

        // 讀取圖資料，建構鄰接串列並計算入度
        for (int u = 1; u <= M; u++) {
            dur[u] = readInt();
            int K = readInt();
            while (K--) {
                int v = readInt();
                // 新增一條 u -> v
                Edge *e = malloc(sizeof(Edge));
                e->to   = v;
                e->next = head[u];
                head[u] = e;
                indeg[v]++;
            }
        }

        // 拓樸排序初始：將所有入度為 0 的節點入佇列
        int q[MAXM], qh = 0, qt = 0;
        for (int i = 1; i <= M; i++) {
            if (indeg[i] == 0) {
                q[qt++] = i;
                dp[i]   = dur[i];  // 沒前置工作，最早完成時間就是本身工期
            }
        }

        // 處理拓樸序，順便更新 dp
        while (qh < qt) {
            int u = q[qh++];
            for (Edge *e = head[u]; e; e = e->next) {
                int v = e->to;
                // 從 u 完成，到 v 開始：更新 v 的最早完成時間
                if (dp[v] < dp[u] + dur[v]) {
                    dp[v] = dp[u] + dur[v];
                }
                // 減少入度，若變成 0，加入佇列
                if (--indeg[v] == 0) {
                    q[qt++] = v;
                }
            }
        }

        // 找出最大完成時間
        int ans = 0;
        for (int i = 1; i <= M; i++) {
            if (dp[i] > ans) ans = dp[i];
        }

        printf("%d\n", ans);

        // 釋放記憶體
        for (int i = 1; i <= M; i++) {
            Edge *e = head[i];
            while (e) {
                Edge *tmp = e;
                e = e->next;
                free(tmp);
            }
        }
    }
    return 0;
}

//