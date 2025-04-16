#include <stdio.h>

typedef struct {
    int front[3][3], back[3][3], left[3][3], right[3][3], up[3][3], down[3][3];
} Cube;

void rotate_face_clockwise(int face[3][3]) {
    int tmp[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tmp[j][2 - i] = face[i][j];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            face[i][j] = tmp[i][j];
}

void roll_10(Cube *a) {
    int tmp[3] = {a->back[0][0], a->back[1][0], a->back[2][0]};
    for (int i = 0; i < 3; i++) {
        a->back[i][0] = a->down[i][0];
        a->down[i][0] = a->front[i][0];
        a->front[i][0] = a->up[i][0];
        a->up[i][0] = tmp[i];
    }
    rotate_face_clockwise(a->left);
}

void roll_11(Cube *a) {
    int tmp[3] = {a->back[0][1], a->back[1][1], a->back[2][1]};
    for (int i = 0; i < 3; i++) {
        a->back[i][1] = a->down[i][1];
        a->down[i][1] = a->front[i][1];
        a->front[i][1] = a->up[i][1];
        a->up[i][1] = tmp[i];
    }
}

void roll_12(Cube *a) {
    int tmp[3] = {a->back[0][2], a->back[1][2], a->back[2][2]};
    for (int i = 0; i < 3; i++) {
        a->back[i][2] = a->down[i][2];
        a->down[i][2] = a->front[i][2];
        a->front[i][2] = a->up[i][2];
        a->up[i][2] = tmp[i];
    }
    rotate_face_clockwise(a->right);
}

void roll_20(Cube *a) {
    int tmp[3] = {a->left[0][0], a->left[0][1], a->left[0][2]};
    for (int i = 0; i < 3; i++) {
        a->left[0][i] = a->back[0][i];
        a->back[0][i] = a->right[0][i];
        a->right[0][i] = a->front[0][i];
        a->front[0][i] = tmp[i];
    }
    rotate_face_clockwise(a->up);
}

void roll_21(Cube *a) {
    int tmp[3] = {a->left[1][0], a->left[1][1], a->left[1][2]};
    for (int i = 0; i < 3; i++) {
        a->left[1][i] = a->back[1][i];
        a->back[1][i] = a->right[1][i];
        a->right[1][i] = a->front[1][i];
        a->front[1][i] = tmp[i];
    }
}

void roll_22(Cube *a) {
    int tmp[3] = {a->left[2][0], a->left[2][1], a->left[2][2]};
    for (int i = 0; i < 3; i++) {
        a->left[2][i] = a->back[2][i];
        a->back[2][i] = a->right[2][i];
        a->right[2][i] = a->front[2][i];
        a->front[2][i] = tmp[i];
    }
    rotate_face_clockwise(a->down);
}

void cubeMove(Cube *a, int move[], int n) {
    for (int i = 0; i < n; i++) {
        switch (move[i]) {
            case 10: roll_10(a); break;
            case 11: roll_11(a); break;
            case 12: roll_12(a); break;
            case 20: roll_20(a); break;
            case 21: roll_21(a); break;
            case 22: roll_22(a); break;
        }
    }
}

void printFront(Cube *a) {
    for (int i = 0; i < 3; i++) {
        printf("%d %d %d\n", a->front[i][0], a->front[i][1], a->front[i][2]);
    }
}

int main() {
    Cube cube = {
        .front = {{4,4,4},{4,4,4},{4,4,4}},    // 白色面
        .back = {{3,3,3},{3,3,3},{3,3,3}},     // 黃色面
        .left = {{5,5,5},{5,5,5},{5,5,5}},     // 橘色面
        .right = {{2,2,2},{2,2,2},{2,2,2}},    // 紅色面
        .up = {{1,1,1},{1,1,1},{1,1,1}},       // 藍色面
        .down = {{6,6,6},{6,6,6},{6,6,6}}      // 綠色面
    };

    int n;
    scanf("%d", &n);
    int move[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &move[i]);
    }
    cubeMove(&cube, move, n);
    printFront(&cube);
    return 0;
}
