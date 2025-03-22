#include<stdio.h>
#include<string.h>
#include<math.h>

int char_to_num(char a){
    char eng[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 36; i++){
        if (a == eng[i]){
            return i; 
        }
    }
    return -1;
}

int a_to_dec(char* data, int m){
    int sum = 0, len = 0, num = 0;
    len = strlen(data);
    for (int i = 0; i < len; i++){
        num = char_to_num(data[i]);
        sum += num * (pow(m, len-i-1));
    }
    return sum;
}

void str_inverse(char* s){
    int len = strlen(s);
    char c;
    for (int i = 0; i < len/2; i++){
        c = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = c;
    }
    printf("%s", s);
}

char num_to_char(int a){
    char eng[36] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                    'U', 'V', 'W', 'X', 'Y', 'Z'};   
    return eng[a];
}

void dec_to_b(int dec, int n){
    char new_str[50] = {};
    int num = 0;
    char s[2] = {};
    while (dec > 0){
        num = dec % n;
        s[0] = num_to_char(num);
        strcat(new_str, s);
        dec /= n;
    }
    str_inverse(new_str);
}

int main(){
    int m = 0, n = 0, dec = 0;
    char data[11] = {};    
    scanf("%d", &m);
    scanf("%s", &data);
    scanf("%d", &n);
    dec = a_to_dec(data, m);
    if (dec == 0){
        printf("0");
        return 0;
    }
    dec_to_b(dec, n);
    return 0;
}