#include<stdio.h>
#include<string.h>

void calculus(int a, int b, int x, int y, char m, int result[]){
    if (m == '+') {
        if (b == y) {
            result[0] = a + x;
            result[1] = b;
        }
        else{
            result[0] = a * y + x * b;
            result[1] = b * y;
        }
    }
    else if (m == '-') {
        if (b == y) {
            result[0] = a - x;
            result[1] = b;
        }
        else{
            result[0] = a * y - x * b;
            result[1] = b * y;
        }
    }
    else if (m == '*') {
        result[0] = a * x;
        result[1] = b * y;
    }
    else if (m == '/') {
        result[0] = a * y;
        result[1] = b * x;
    }
}

int gcd(int m, int n){
    if (n == 0) {
        return m;
    }
    else{
        return gcd(n, m % n);
    }
}

void output(int result[]){
    if (result[0] % result[1] == 0) {
        printf("%d\n", result[0] / result[1]);
    }
    else{
        int m = gcd(result[0], result[1]);
        if (m < 0) {
            m = -m;
        }
        if (m != 1) {
            result[0] /= m;
            result[1] /= m;
        }
        if ((result[0] < 0 && result[1] > 0) || (result[0] > 0 && result[1] < 0)) {
            printf("-");
        }
        if (result[0] < 0) {
            result[0] = -result[0];
        }
        if (result[1] < 0) {
            result[1] = -result[1];
        }

        if (result[0] < result[1]) {
            printf("%d/%d\n", result[0], result[1]);
        }
        else{
            int a = result[0] / result[1];
            result[0] = result[0] % result[1];
            printf("%d(%d/%d)\n", a, result[0], result[1]);
        }
    }
}
 
int main() {
    char s[10];
    int data[50][3];
    char symbol[50][2];
    int i = 0, count = 0;
    int result[2];
    while(1){
        scanf("%s", s);
        if (strcmp(s, "n") == 0) {
            break;
        }
        else if (strcmp(s, "y") == 0) {
            continue;
        }
        else{
            if (i % 2 == 0) {
                if (sscanf(s, "%d(%d/%d)", &data[i/2][0], &data[i/2][1], &data[i/2][2]) == 3) {
                    if (data[i/2][0] < 0) {
                        data[i/2][0] = -data[i/2][0];
                        data[i/2][1] += data[i/2][0] * data[i/2][2];
                        data[i/2][1] = -data[i/2][1];
                    }
                    else{
                        data[i/2][1] += data[i/2][0] * data[i/2][2];
                    }
                    // printf("%d\n", data[i/2][1]);
                }
                else if (sscanf(s, "%d/%d", &data[i/2][1], &data[i/2][2]) == 2) {
                    
                }
            }
            else{
                strcpy(symbol[i/2+1], s);
                count++;
            }
        }
        i++;
    }

    // printf("%s\n", symbol[0]);

    for (int i = 0; i < count * 2; i += 2){
        char m;
        if (strcmp(symbol[i+1], "+") == 0) {
            m = '+';
        }
        else if (strcmp(symbol[i+1], "-") == 0) {
            m = '-';
        }
        else if (strcmp(symbol[i+1], "*") == 0) {
            m = '*';
        }
        else if (strcmp(symbol[i+1], "/") == 0) {
            m = '/';
        }
        int a = data[i][1];
        int b = data[i][2];
        int x = data[i+1][1];
        int y = data[i+1][2];
        // printf("%d %d %d %d %c\n", a, b, x, y, m);
        if (b == 0 || y == 0) {
            printf("Error\n");
            continue;
        }
        calculus(a, b, x, y, m, result);
        if (result[1] == 0) {
            printf("Error\n");
            continue;
        }
        output(result);
    }
    return 0;
}