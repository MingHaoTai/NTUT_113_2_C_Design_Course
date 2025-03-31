#include <stdio.h>

typedef struct {
    int up, down, left, right, front, back;
} Dice;

void roll_forward(Dice* d) {
    // 向前滚动
    int temp = d->up;
    d->up = d->back;
    d->back = d->down;
    d->down = d->front;
    d->front = temp;
}

void roll_backward(Dice* d) {
    // 向后滚动
    int temp = d->up;
    d->up = d->front;
    d->front = d->down;
    d->down = d->back;
    d->back = temp;
}

void roll_right(Dice* d) {
    // 向右滚动
    int temp = d->up;
    d->up = d->left;
    d->left = d->down;
    d->down = d->right;
    d->right = temp;
}

void roll_left(Dice* d) {
    // 向左滚动
    int temp = d->up;
    d->up = d->right;
    d->right = d->down;
    d->down = d->left;
    d->left = temp;
}

void print_dice(Dice d) {
    printf("上: %d, 下: %d, 左: %d, 右: %d, 前: %d, 后: %d\n",
           d.up, d.down, d.left, d.right, d.front, d.back);
}

int main() {
    Dice dice = {1, 6, 5, 2, 4, 3}; // 初始状态

    printf("初始骰子状态:\n");
    print_dice(dice);

    int input;
    for (int i = 0; i < 4; i++) {
        printf("请输入滚动方向 (1: 前, 2: 后, 3: 右, 4: 左): ");
        scanf("%d", &input);

        // 根据输入滚动骰子
        switch (input) {
            case 1:
                roll_forward(&dice);
                break;
            case 2:
                roll_backward(&dice);
                break;
            case 3:
                roll_right(&dice);
                break;
            case 4:
                roll_left(&dice);
                break;
            default:
                printf("无效输入！\n");
                break;
        }

        // 输出每次滚动后的状态
        printf("当前骰子状态:\n");
        print_dice(dice);
    }

    return 0;
}
