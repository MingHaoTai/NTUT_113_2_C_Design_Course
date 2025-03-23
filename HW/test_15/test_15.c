#include<stdio.h>

int gcd(int m, int n){
    if (n == 0){
        return m;
    }
    else{
        return gcd(n, m % n);
    }
}

int* reduction(int data[2]){
    int a = gcd(data[0], data[1]);
    static int back[2];
    if (a < 0){
        a = -a;
    }
    back[0] = data[0] / a;
    back[1] = data[1] / a;
    return back;
}

int* getM(int data[4]){
    int m[2], *new_m;
    static int back[2];
    m[0] = data[1] - data[3];
    m[1] = data[0] - data[2];
    new_m = reduction(m);
    if ((new_m[0] > 0 && new_m[1] < 0) || (new_m[0] < 0 && new_m[1] < 0)){
        new_m[0] = -new_m[0];
        new_m[1] = -new_m[1];
    }
    back[0] = new_m[0];
    back[1] = new_m[1];
    return back;
}

int* getB(int data[4]){
    int b[2], *new_b;
    static int back[2];
    b[0] = data[1] * data[2] - data[0] * data[3];
    b[1] = data[2] - data[0];
    new_b = reduction(b);
    if ((new_b[0] > 0 && new_b[1] < 0) || (new_b[0] < 0 && new_b[1] < 0)){
        new_b[0] = -new_b[0];
        new_b[1] = -new_b[1];
    }
    back[0] = new_b[0];
    back[1] = new_b[1];
    return back;
}

int main(){
    int n, *m, *b;
    int data[10][4];
    scanf("%d", &n);    
    for (int i = 0; i < n; i++){
        scanf("%d %d %d %d", &data[i][0], &data[i][1], &data[i][2], &data[i][3]);
    }

    for (int i = 0; i < n; i++){
        m = getM(data[i]);
        b = getB(data[i]);
        if (m[0] == 0){
            if (b[1] == 1){
                printf("y = %d\n", b[0]);
            }
            else{
                printf("y = %d/%d\n", b[0]/b[1]);
            }
        }
        else{
            if (b[0] < 0){
                if (m[1] != 1 && b[1] != 1){
                    printf("y = %d/%dx - %d/%d\n", m[0], m[1], -b[0], b[1]);
                }
                else if (m[1] != 1 && b[1] == 1){
                    printf("y = %d/%dx - %d\n", m[0], m[1], -b[0]);
                }
                else if (m[1] == 1 && b[1] != 1){
                    if (m[0] == 1 || m[0] == -1){
                        if (m[0] == -1){
                            printf("y = -x - %d/%d\n", -b[0], b[1]);
                        }
                        else{
                            printf("y = x - %d/%d\n", -b[0], b[1]);
                        }
                    }
                    else{
                        printf("y = %dx - %d/%d\n", m[0], -b[0], b[1]);
                    }
                }
                else if (m[1] == 1 && b[1] == 1){
                    if (m[0] == 1 || m[0] == -1){
                        if (m[0] == -1){
                            printf("y = -x - %d\n", -b[0]);
                        }
                        else{
                            printf("y = x - %d\n", -b[0]);
                        }
                    }
                    else{
                        printf("y = %dx - %d\n", m[0], -b[0]);
                    }
                }
            }
            else if (b[0] > 0){
                if (m[1] != 1 && b[1] != 1){
                    printf("y = %d/%dx + %d/%d\n", m[0], m[1], b[0], b[1]);
                }
                else if (m[1] != 1 && b[1] == 1){
                    printf("y = %d/%dx + %d\n", m[0], m[1], b[0]);
                }
                else if (m[1] == 1 && b[1] != 1){
                    if (m[0] == 1 || m[0] == -1){
                        if (m[0] == -1){
                            printf("y = -x + %d/%d\n", b[0], b[1]);
                        }
                        else{
                            printf("y = x + %d/%d\n", b[0], b[1]);
                        }
                    }
                    else{
                        printf("y = %dx + %d/%d\n", m[0], b[0], b[1]);
                    }            }
                else if (m[1] == 1 && b[1] == 1){
                    if (m[0] == 1 || m[0] == -1){
                        if (m[0] == -1){
                            printf("y = -x + %d\n", b[0]);
                        }
                        else{
                            printf("y = x + %d\n", b[0]);
                        }
                    }
                    else{
                        printf("y = %dx + %d\n", m[0], b[0]);
                    }            
                }
            }
            else{
                if (m[1] != 1){
                    printf("y = %d/%dx\n", m[0], m[1]);
                }
                else{
                    if (m[0] == 1 || m[0] == -1){
                        if (m[0] == -1){
                            printf("y = -x\n");
                        }
                        else{
                            printf("y = x\n");
                        }
                    }
                    else{
                        printf("y = %dx\n", m[0]);
                    }
                }
            }
        }
    }
    // m = getM(data[0]);
    // b = getB(data[0]);
    // printf("y = %d/%dx + %d/%d", m[0], m[1], b[0], b[1]);
    return 0;
}