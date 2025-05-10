#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 10
#define INF 1000000000

int N, C, blocked_u, blocked_v;
int dist[MAXN][MAXN];
int visited[MAXN], path[MAXN], best_path[MAXN];
int final_path[MAXN];
int best_cost = INF;
int final_cost = INF;

void input() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &dist[i][j]);
    scanf("%d", &C);
    scanf("%d %d", &blocked_u, &blocked_v);
    blocked_u--;  // convert to 0-indexed
    blocked_v--;
}

int calc_cost(int *p, int len) {
    int cost = 0;
    for (int i = 1; i < len; ++i) {
        int u = p[i - 1], v = p[i];
        if (dist[u][v] == -1) return INF;
        cost += dist[u][v];
    }
    return cost;
}

void dfs(int depth, int *p, int *best_p, int *min_cost, int exclude_start) {
    if (depth == N) {
        int cost = calc_cost(p, N);
        if (cost < *min_cost) {
            *min_cost = cost;
            memcpy(best_p, p, sizeof(int) * N);
        }
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i] && i >= exclude_start) {
            visited[i] = 1;
            p[depth] = i;
            dfs(depth + 1, p, best_p, min_cost, exclude_start);
            visited[i] = 0;
        }
    }
}

void dfs_partial(int depth, int start_city, int curr_cost, int *remains, int remains_len, int *p, int *best_p, int *min_cost) {
    if (depth == remains_len) {
        if (curr_cost < *min_cost) {
            *min_cost = curr_cost;
            memcpy(best_p, p, sizeof(int) * remains_len);
        }
        return;
    }

    for (int i = 0; i < remains_len; ++i) {
        if (!visited[remains[i]]) {
            int u = start_city, v = remains[i];
            if ((u == blocked_u && v == blocked_v) || (u == blocked_v && v == blocked_u)) continue;
            if (dist[u][v] == -1) continue;

            visited[remains[i]] = 1;
            p[depth] = remains[i];
            dfs_partial(depth + 1, v, curr_cost + dist[u][v], remains, remains_len, p, best_p, min_cost);
            visited[remains[i]] = 0;
        }
    }
}

int main() {
    input();

    // Step 1: Find initial best path from city 0
    memset(visited, 0, sizeof(visited));
    path[0] = 0;
    visited[0] = 1;
    dfs(1, path, best_path, &best_cost, 1);

    // Step 2: Check partial path up to city C
    int cost_so_far = 0;
    for (int i = 1; i < C; ++i) {
        int u = best_path[i - 1];
        int v = best_path[i];
        if (dist[u][v] == -1) {
            printf("無法完成初始路徑\n");
            return 1;
        }
        final_path[i - 1] = u;
        cost_so_far += dist[u][v];
    }
    final_path[C - 1] = best_path[C - 1];

    // Step 3: rebuild remaining path
    int remains[MAXN], remains_len = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < C; ++i) visited[best_path[i]] = 1;
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) remains[remains_len++] = i;
    }

    int rebuilt_path[MAXN], rebuilt_best[MAXN], rebuilt_cost = INF;
    memset(visited, 0, sizeof(visited));
    dfs_partial(0, best_path[C - 1], 0, remains, remains_len, rebuilt_path, rebuilt_best, &rebuilt_cost);

    // Step 4: print final path and cost
    for (int i = 0; i < C; ++i)
        printf("%d ", final_path[i] + 1);
    for (int i = 0; i < remains_len; ++i)
        printf("%d ", rebuilt_best[i] + 1);
    printf("\n");

    printf("%d\n", cost_so_far + rebuilt_cost);
    return 0;
}
