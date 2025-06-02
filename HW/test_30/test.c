#include <stdio.h>
#include <string.h>

typedef enum {OUT, BASE_HIT} play_type_t;

typedef union {
    int base_hit;  // 1~4 bases
    char out_kind; // 'F', 'S', 'G'
} play_result_t;

typedef struct {
    play_type_t type;
    play_result_t result;
} play_t;

typedef struct {
    int no; // 打擊次數
    play_t data[5];
} basePlayer_t;

int main() {
    basePlayer_t players[9];
    char input[5];
    int i, j;
    for (i = 0; i < 9; i++) {   // 讀入每位球員的資料
        scanf("%d", &players[i].no);
        for (j = 0; j < players[i].no; j++) {
            scanf("%s", input);
            if (strcmp(input, "1B") == 0) {
                players[i].data[j].type = BASE_HIT;
                players[i].data[j].result.base_hit = 1;
            } else if (strcmp(input, "2B") == 0) {
                players[i].data[j].type = BASE_HIT;
                players[i].data[j].result.base_hit = 2;
            } else if (strcmp(input, "3B") == 0) {
                players[i].data[j].type = BASE_HIT;
                players[i].data[j].result.base_hit = 3;
            } else if (strcmp(input, "HR") == 0) {
                players[i].data[j].type = BASE_HIT;
                players[i].data[j].result.base_hit = 4;
            } else {
                players[i].data[j].type = OUT;
                players[i].data[j].result.out_kind = input[0]; // 'F', 'S', 'G'
            }
        }
    }
    int target_outs;
    scanf("%d", &target_outs);
    int score = 0;
    int base[3] = {0}; // 1壘、2壘、3壘
    int outs = 0;
    int batter_index = 0;
    int batter_counts[9] = {0};
    while (outs < target_outs) {
        basePlayer_t *batter = &players[batter_index];
        int hit_index = batter_counts[batter_index];
        if (hit_index >= batter->no) {
            batter_index = (batter_index + 1) % 9;
            continue;
        }
        play_t play = batter->data[hit_index];
        batter_counts[batter_index]++;
        if (play.type == OUT) {
            outs++;
            if (outs == target_outs) 
                break;
            if (outs % 3 == 0) {    // 三出局清空壘包
                base[0] = base[1] = base[2] = 0;
            }
        } else {
            int k = play.result.base_hit;
            for (int i = 2; i >= 0; i--) {  // 跑壘員跑壘
                if (base[i]) {
                    int new_base = i + k;
                    if (new_base >= 3) {
                        score++;
                    } else {
                        base[new_base] = 1;
                    }
                    base[i] = 0;
                }
            }
            if (k == 4) {   // 打者上壘
                score++;
            } else {
                base[k - 1] = 1;
            }
        }
        batter_index = (batter_index + 1) % 9;
    }
    printf("%d\n", score);
    return 0;
}
