#include <stdio.h>
#include <string.h>

typedef enum { OUT, BASE_HIT } play_type_t;

typedef union {
    int base_hit;     // 1~4: number of bases
    char out_kind;    // 'F', 'S', 'G'
} play_result_t;

typedef struct {
    play_type_t type;
    play_result_t result;
} play_t;

typedef struct {
    int no;           // 打擊次數
    play_t data[5];   // 最多5次打擊
} basePlayer_t;

int main() {
    basePlayer_t players[9];
    char input[4];
    int stop_out;

    // 讀取球員資料
    for (int i = 0; i < 9; i++) {
        scanf("%d", &players[i].no);
        for (int j = 0; j < players[i].no; j++) {
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
                players[i].data[j].result.out_kind = input[0];
            }
        }
    }

    scanf("%d", &stop_out);

    int score = 0;
    int out_count = 0;
    int base[3] = {0}; // 一壘、二壘、三壘
    int cur_player = 0;
    int play_index[9] = {0};

    while (out_count < stop_out) {
        basePlayer_t *p = &players[cur_player];
        int idx = play_index[cur_player];
        play_t play = p->data[idx];

        if (play.type == OUT) {
            out_count++;
            if (out_count == stop_out) break;
        } else {
            int hit = play.result.base_hit;

            if (hit == 4) {
                // 全壘打：所有壘包上的人得分 + 打者
                for (int i = 0; i < 3; i++) {
                    if (base[i]) score++;
                    base[i] = 0;
                }
                score++; // 打者得分
            } else {
                int new_base[3] = {0};

                // 從三壘 ➝ 二壘 ➝ 一壘依序處理跑者
                for (int i = 2; i >= 0; i--) {
                    if (base[i]) {
                        int dest = i + hit;
                        if (dest >= 3) {
                            score++;
                        } else {
                            new_base[dest] = 1;
                        }
                    }
                }

                // 安打後打者上壘
                new_base[hit - 1] = 1;

                // 更新壘包
                for (int i = 0; i < 3; i++)
                    base[i] = new_base[i];
            }
        }

        // 更新打者資訊
        play_index[cur_player]++;
        if (play_index[cur_player] >= players[cur_player].no)
            play_index[cur_player] = 0;
        cur_player = (cur_player + 1) % 9;

        // 每三出局清空壘包
        if (out_count % 3 == 0 && out_count != 0) {
            base[0] = base[1] = base[2] = 0;
        }
    }

    printf("%d\n", score);
    return 0;
}

