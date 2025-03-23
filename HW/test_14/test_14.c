#include<stdio.h>
#include<string.h>

int mixedToImproper(int num[3]){   // get improper's numerator
    int neg_f = 0;
    int a, b;
    if (num[0] < 0){
        neg_f = 1;
    }
    if (neg_f == 0){
        num[1] += num[0] * num[2];
    }
    else{
        num[1] = -num[1] + num[0]*num[2];
    }
    return num[1];
}

int* calculus(int a, int b, int x, int y, char m){
    static int sum[2];
    int data[4];
    if (m == '+'){
        if (b == y){
            sum[0] = a + x;
            sum[1] = b;
        }
        else{
            sum[1] = b * y;
            a *= y;
            x *= b;
            sum[0] = a + x;
        }
    }
    else if (m == '-'){
        if (b == y){
            sum[0] = a - x;
            sum[1] = b;
        }
        else{
            sum[1] = b * y;
            a *= y;
            x *= b;
            sum[0] = a - x;
        }
    }
    else if (m == '*'){
        sum[0] = a * x;
        sum[1] = b * y;
    }
    else if (m == '/'){
        sum[0] = a * y;
        sum[1] = b * x;
    }
    return sum;
}

int gcd(int m, int n){
    if (n == 0){
        return m;
    }
    else{
        return gcd(n, m % n);
    }
}

void toMixed(int sum[2]){
    int a = 0;
    a = sum[0] / sum[1];
    sum[0] = sum[0] % sum[1];
    printf("%d(%d/%d)\n", a, sum[0], sum[1]);
}

void output(int sum[2]){
    int m;
    if (sum[0] % sum[1] == 0){
        printf("%d\n", sum[0]/sum[1]);
    }
    else{
        m = gcd(sum[0], sum[1]);
        if (m < 0){
            m = -m;
        }
        if ((sum[0] < 0 && sum[1] > 0) || (sum[1] > 0 && sum[1] < 0)){
            printf("-");
            if (sum[0] < 0){
                sum[0] = -sum[0];
            }
            else{
                sum[1] = -sum[1];
            }
        }
        if (sum[0] < sum[1]){
            printf("%d/%d\n", sum[0]/m, sum[1]/m);
        }
        else{
            sum[0] = sum[0] / m;
            sum[1] = sum[1] / m;
            toMixed(sum);
        }
    }
}

int main(){
    int i = 0, count = 0;
    int num_data[10][3] = {};
    char math_data[10][3] = {}, s[10] = "";
    int error_f = 0;
    while (1){
        gets(s);
        if (strcmp(s, "n") == 0){
            break;
        }
        else if (strcmp(s, "y") == 0){
            i++;
            continue;
        }
        else{
            if (i % 2 == 0){
                if (sscanf(s, "%d(%d/%d)", &num_data[i/2][0], &num_data[i/2][1], &num_data[i/2][2]) == 3){
                    num_data[i/2][1] = mixedToImproper(num_data[i/2]);
                }
                else{
                    sscanf(s, "%d/%d", &num_data[i/2][1], &num_data[i/2][2]);
                }
            }
            else{
                strcpy(math_data[i/2+1], s);
                count++;
            }
        }
        i++;
    }

    int j = 0, m_j = 1;
    int a = 0, b = 0, x = 0, y = 0, *sum;
    char m;
    while (j < count*2){
        a = num_data[j][1];
        b = num_data[j][2];
        x = num_data[j+1][1];
        y = num_data[j+1][2];
        // printf("%d, %d, %d, %d, %d, %s\n", j, a, b, x, y, math_data[m_j]);
        if (strcmp(math_data[m_j], "+") == 0){
            m = '+';
        }
        else if (strcmp(math_data[m_j], "-") == 0){
            m = '-';
        }
        else if (strcmp(math_data[m_j], "*") == 0){
            m = '*';
        }
        else if (strcmp(math_data[m_j], "/") == 0){
            m = '/';
        }
        if (b == 0 || y == 0){
            printf("Error\n");
            j += 2;
            m_j += 2;
            continue;
        }
        sum = calculus(a, b, x, y, m);
        if (sum[1] == 0){
            printf("Error\n");
            j += 2;
            m_j += 2;
            continue;
        }
        output(sum);
        // printf("%d, %d\n", sum[0], sum[1])j/2+1;
        j += 2;
        m_j += 2;
    }
    
    return 0;
}