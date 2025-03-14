#include<stdio.h>
#include<math.h>

int bin_to_dec(char b[9]){
    int sum = 0;
    for (int i = 0; i < 8; i++){
        if (b[i] == '1'){
            sum += pow(2, (7-i));
        }
    }
    return sum;
}

int C(int a, int count){
    if (a == 0 || a == 1){
        return count;
    }
    else if (a % 2 == 0){
        return C(a/2, ++count);
    }
    else if (a % 2 == 1){
        return C((a+1)/2, ++count);
    }
}

void dec_to_bin(int a, char* b){
    for (int i = 0; i < 4; i++){
        if (a % 2 == 1){
            b[3-i] = '1';
        }
        else{
            b[3-i] = '0';
        }
        a /= 2;
    }
    b[4] = '\0';
}

int main(){
    char data[10][9] = {};
    int i = 0;
    while (1){
        scanf("%s", data[i]);
        if (data[i][0] == '-' && data[i][1] == '1'){
            break;
        }
        i++;
    }
    for (int j = 0; j < i; j++){
        int dec = 0, count = 0;
        char bin[5] = {};
        dec = bin_to_dec(data[j]);
        count = C(dec, 0);
        dec_to_bin(count, bin);
        printf("%s\n", bin);
    }
    return 0;
}