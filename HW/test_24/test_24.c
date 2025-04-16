#include<stdio.h>

typedef struct {
    int front00, front01, front02, front10, front11, front12, front20, front21, front22;
    int back00, back01, back02, back10, back11, back12, back20, back21, back22;
    int left00, left01, left02, left10, left11, left12, left20, left21, left22;
    int right00, right01, right02, right10, right11, right12, right20, right21, right22;
    int up00, up01, up02, up10, up11, up12, up20, up21, up22;
    int down00, down01, down02, down10, down11, down12, down20, down21, down22;
} Cube;

void roll_10(Cube* a){
    int tmp0 = a->back00, tmp1 = a->back10, tmp2 = a->back20;
    a->back00 = a->down00;
    a->back10 = a->down10;
    a->back20 = a->down20;
    a->down00 = a->front00;
    a->down10 = a->front10;
    a->down20 = a->front20;
    a->front00 = a->up00;
    a->front10 = a->up10;
    a->front20 = a->up20;
    a->up00 = tmp0;
    a->up10 = tmp1;
    a->up20 = tmp2;
    int tmp[3][3] = {{a->left00, a->left01, a->left02},
                     {a->left10, a->left11, a->left12},
                     {a->left20, a->left21, a->left22}};
    a->left00 = tmp[0][2];
    a->left01 = tmp[1][2];
    a->left02 = tmp[2][2];
    a->left12 = tmp[2][1];
    a->left22 = tmp[2][0];
    a->left21 = tmp[1][0];
    a->left20 = tmp[0][0];
    a->left10 = tmp[0][1];
}

void roll_11(Cube* a){
    int tmp0 = a->back01, tmp1 = a->back11, tmp2 = a->back21;
    a->back01 = a->down01;
    a->back11 = a->down11;
    a->back21 = a->down21;
    a->down01 = a->front01;
    a->down11 = a->front11;
    a->down21 = a->front21;
    a->front01 = a->up01;
    a->front11 = a->up11;
    a->front21 = a->up21;
    a->up01 = tmp0;
    a->up11 = tmp1;
    a->up21 = tmp2;
}

void roll_12(Cube* a){
    int tmp0 = a->back02, tmp1 = a->back12, tmp2 = a->back22;
    a->back02 = a->down02;
    a->back12 = a->down12;
    a->back22 = a->down22;
    a->down02 = a->front02;
    a->down12 = a->front12;
    a->down22 = a->front22;
    a->front02 = a->up02;
    a->front12 = a->up12;
    a->front22 = a->up22;
    a->up02 = tmp0;
    a->up12 = tmp1;
    a->up22 = tmp2;
    int tmp[3][3] = {{a->right00, a->right01, a->right02},
                     {a->right10, a->right11, a->right12},
                     {a->right20, a->right21, a->right22}};
    a->right02 = tmp[0][0];
    a->right01 = tmp[1][0];
    a->right00 = tmp[2][0];
    a->right10 = tmp[2][1];
    a->right20 = tmp[2][2];
    a->right21 = tmp[1][2];
    a->right22 = tmp[0][2];
    a->right12 = tmp[0][1];
}

void roll_20(Cube* a){
    int tmp0 = a->left00, tmp1 = a->left01, tmp2 = a->left02;
    a->left00 = a->back00;
    a->left01 = a->back01;
    a->left02 = a->back02;
    a->back00 = a->right00;
    a->back01 = a->right01;
    a->back02 = a->right02;
    a->right00 = a->front00;
    a->right01 = a->front01;
    a->right02 = a->front02;
    a->front00 = tmp0;
    a->front01 = tmp1;
    a->front02 = tmp2;
    int tmp[3][3] = {{a->up00, a->up01, a->up02},
                     {a->up10, a->up11, a->up12},
                     {a->up20, a->up21, a->up22}};
    a->up02 = tmp[0][0];
    a->up01 = tmp[1][0];
    a->up00 = tmp[2][0];
    a->up10 = tmp[2][1];
    a->up20 = tmp[2][2];
    a->up21 = tmp[1][2];
    a->up22 = tmp[0][2];
    a->up12 = tmp[0][1];
}

void roll_21(Cube* a){
    int tmp0 = a->left10, tmp1 = a->left11, tmp2 = a->left12;
    a->left10 = a->back10;
    a->left11 = a->back11;
    a->left12 = a->back12;
    a->back10 = a->right10;
    a->back11 = a->right11;
    a->back12 = a->right12;
    a->right10 = a->front10;
    a->right11 = a->front11;
    a->right12 = a->front12;
    a->front10 = tmp0;
    a->front11 = tmp1;
    a->front12 = tmp2;
}

void roll_22(Cube* a){
    int tmp0 = a->left20, tmp1 = a->left21, tmp2 = a->left22;
    a->left20 = a->back20;
    a->left21 = a->back21;
    a->left22 = a->back22;
    a->back20 = a->right20;
    a->back21 = a->right21;
    a->back22 = a->right22;
    a->right20 = a->front20;
    a->right21 = a->front21;
    a->right22 = a->front22;
    a->front20 = tmp0;
    a->front21 = tmp1;
    a->front22 = tmp2;
    int tmp[3][3] = {{a->down00, a->down01, a->down02},
                     {a->down10, a->down11, a->down12},
                     {a->down20, a->down21, a->down22}};
    a->down00 = tmp[0][2];
    a->down01 = tmp[1][2];
    a->down02 = tmp[2][2];
    a->down12 = tmp[2][1];
    a->down22 = tmp[2][0];
    a->down21 = tmp[1][0];
    a->down20 = tmp[0][0];
    a->down10 = tmp[0][1];
}

void cubeMove(Cube* a, int move[], int n){
    for (int i = 0; i < n; i++){
        switch (move[i]){
            case 10: roll_10(a); break;
            case 11: roll_11(a); break;
            case 12: roll_12(a); break;
            case 20: roll_20(a); break;
            case 21: roll_21(a); break;
            case 22: roll_22(a); break;
        }
    }
    printf("%d %d %d \n%d %d %d \n%d %d %d \n", a->back00, a->back01, a->back02,
                                                a->back10, a->back11, a->back12,
                                                a->back20, a->back21, a->back22);
}

int main() {
    int n;
    scanf("%d", &n);
    int movedata[n];
    const Cube cube = {
        .front00 = 3, .front01 = 3, .front02 = 3,
        .front10 = 3, .front11 = 3, .front12 = 3,
        .front20 = 3, .front21 = 3, .front22 = 3,
        .back00 = 4, .back01 = 4, .back02 = 4,
        .back10 = 4, .back11 = 4, .back12 = 4,
        .back20 = 4, .back21 = 4, .back22 = 4,
        .left00 = 5, .left01 = 5, .left02 = 5,
        .left10 = 5, .left11 = 5, .left12 = 5,
        .left20 = 5, .left21 = 5, .left22 = 5,
        .right00 = 2, .right01 = 2, .right02 = 2,
        .right10 = 2, .right11 = 2, .right12 = 2,
        .right20 = 2, .right21 = 2, .right22 = 2,
        .up00 = 1, .up01 = 1, .up02 = 1,
        .up10 = 1, .up11 = 1, .up12 = 1,
        .up20 = 1, .up21 = 1, .up22 = 1,
        .down00 = 6, .down01 = 6, .down02 = 6,
        .down10 = 6, .down11 = 6, .down12 = 6,
        .down20 = 6, .down21 = 6, .down22 = 6
    };

    Cube a = cube;
    for (int i = 0; i < n; i++){
        scanf("%d", &movedata[i]);
    }
    cubeMove(&a, movedata, n);
    return 0;
}