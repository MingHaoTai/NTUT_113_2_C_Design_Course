#include<stdio.h>
#include<math.h>

void Gray(int n, int k) {
    if (n == 1) {
        printf("%d", k); 
        return;
    }

    int mid = pow(2, n - 1); 

    if (k < mid) {
        printf("0");
        Gray(n - 1, k);
    } else {
        printf("1");
        Gray(n - 1, (mid * 2 - 1 - k));
    }
}

int main(){
    int data[10][2] = {};
    int i = 0;
    while (1){
        scanf("%d", &data[i][0]);
        if (data[i][0] == -1){
            break;
        }
        scanf("%d", &data[i][1]);
        i++;
    }
    for (int j = 0; j < i; j++){
        Gray(data[j][0], data[j][1]);
        printf("\n");
    }    
    return 0;
}