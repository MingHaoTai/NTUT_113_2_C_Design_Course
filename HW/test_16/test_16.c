#include<stdio.h>
#include<string.h>

void str_shift(char *s, int shift){
    int len = strlen(s);
    memmove(s + shift, s, len + 1);
    for (int i = 0; i < shift; i++){
        s[i] = '0';
    }
}

void remove_zeros(char *s){
    int i = 0;
    while (s[i] == '0') i++;
    if (s[i] == '\0'){
        s[0] = '0';
        s[1] = '\0';
        return;
    }
    memmove(s, s + i, strlen(s + i) + 1);
}

void big_integer_add(char* n1, char* n2, char *sum){
    int len1 = strlen(n1), len2 = strlen(n2), len = 0;
    int shift = 0, carry = 0, digit1 = 0, digit2 = 0, digit_sum = 0;
    if (len1 >= len2){
        len = len1;
        shift = len1 - len2;
        if (shift > 0){
            str_shift(n2, shift);
        }
    }
    else{
        len = len2;
        shift = len2 - len1;
        str_shift(n1, shift);
    }
    for (int i = len - 1; i > -1; i--){
        digit1 = (int)n1[i] - 48;
        digit2 = (int)n2[i] - 48;
        digit_sum = digit1 + digit2 + carry;
        if (digit_sum >= 10){
            carry = 1;
            digit_sum -= 10;
        }
        else{
            carry = 0;
        }
        sum[i] = (char)digit_sum + 48;
    }
}

void big_integer_sub(char *n1, char *n2, char *sum){
    int len1 = strlen(n1), len2 = strlen(n2), len = 0;
    int shift = 0, carry = 0, digit1 = 0, digit2 = 0, digit_sum = 0;
    int neg_flag = 0;
    if (len1 >= len2){
        len = len1;
        shift = len1 - len2;
        if (shift > 0){
            str_shift(n2, shift);
            neg_flag = 0;
        }
    }
    else{
        len = len2 - len1;
        str_shift(n1, shift);
        neg_flag = 1;
    }

    if (strcmp(n1, n2) < 0){
        neg_flag = 1;
    }

    for (int i = len - 1; i > -1; i--){
        if (neg_flag == 0){
            digit1 = (int)n1[i] - 48;
            digit2 = (int)n2[i] - 48;
            digit_sum = digit1 - digit2 - carry;
        }
        else{
            digit1 = (int)n2[i] - 48;
            digit2 = (int)n1[i] - 48;
            digit_sum = digit1 - digit2 - carry;
        }

        if (digit_sum < 0){
            carry = 1;
            digit_sum += 10;
        }
        else{
            carry = 0;
        }
        sum[i] = (char)digit_sum + 48;
    }
    printf("-");
}

void big_integer_mul(char *n1, char *n2, char *sum){
    
}

int main(){
    char n1[50] = {}, n2[50] = {}, sum[50] = {};
    gets(n1);
    gets(n2);

    big_integer_add(n1, n2, sum);
    printf("%s\n", sum);
    big_integer_sub(n1, n2, sum);
    remove_zeros(sum);
    printf("%s\n", sum);
    return 0;
}