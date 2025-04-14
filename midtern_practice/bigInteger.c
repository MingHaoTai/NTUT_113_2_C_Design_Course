#include<stdio.h>
#include<string.h>

void strShift(char s[], int shift){
    int len = strlen(s);
    for (int i = len; i >= 0; i--){
        s[i + shift] = s[i];
    }
    for (int i = 0; i < shift; i++){
        s[i] = '0';
    }
}

void zeroRemove(char s[]){
    int i = 0;
    while(s[i] == '0') i++;
    if (s[i] == '\0') {
        s[0] = '0';
        s[1] = '\0';
        return;
    }
    memmove(s, s + i, strlen(s + i) + 1);
}

void Add(char n1[], char n2[], char result[]){
    int len1 = strlen(n1), len2 = strlen(n2), max_len = 0;
    int carry = 0, shift = 0, digit1 = 0, digit2 = 0, digit_sum = 0;
    if (len1 >= len2) {
        max_len = len1;
        shift = len1 - len2;
        strShift(n2, shift);
    }
    else{
        max_len = len2;
        shift = len2 - len1;
        strShift(n1, shift);
    }

    for (int i = max_len - 1; i >= 0; i--){
        digit1 = n1[i] - '0';
        digit2 = n2[i] - '0';
        digit_sum = digit1 + digit2 + carry;
        if (digit_sum >= 10) {
            carry = 1;
            digit_sum = digit_sum - 10;
        }
        else{
            carry = 0;
        }
        result[i] = digit_sum + '0';
    }
}

void Sub(char n1[], char n2[], char result[]){
    int len1 = strlen(n1), len2 = strlen(n2), max_len = 0;
    int borrow = 0, shift = 0, neg_flag = 0, digit1 = 0, digit2 = 0, digit_diff = 0;
    if (len1 >= len2) {
        max_len = len1;
        shift = len1 - len2;
        strShift(n2, shift);
    }
    else{
        max_len = len2;
        shift = len2 - len1;
        strShift(n1, shift);
    }

    for (int i = max_len - 1; i >= 0; i--){
        if (strcmp(n1 ,n2) < 0) {
            neg_flag = 1;
            digit1 = n2[i] - '0';
            digit2 = n1[i] - '0';
        }
        else{
            digit1 = n1[i] - '0';
            digit2 = n2[i] - '0';
        }
        digit_diff = digit1 - digit2 - borrow;
        if (digit_diff < 0) {
            borrow = 1;
            digit_diff = digit_diff + 10;
        }
        else{
            borrow = 0;
        }
        result[i] = digit_diff + '0';
    }
    if (neg_flag == 1) {
        strShift(result, 1);
        result[0] = '-';
    }
    printf("%s\n", result);
}

void Mul(char n1[], char n2[], char result[]){
    int len1 = strlen(n1), len2 = strlen(n2);
    int digit1 = 0, digit2 = 0, digit_mul = 0;
    int data[200] = {0};
    for (int i = len1 - 1; i >= 0; i--){
        for (int j = len2 - 1; j >= 0; j--){
            digit1 = n1[i] - '0';
            digit2 = n2[j] - '0';
            digit_mul = digit1 * digit2 + data[i + j + 1];
            data[i + j + 1] = digit_mul % 10;
            data[i + j] += digit_mul / 10;
        }
    }
    for (int i = 0; i < len1 + len2; i++){
        result[i] = data[i] + '0';
    }
    result[len1 + len2] = '\0';
    zeroRemove(result);
    printf("%s\n", result);
}

void Div(char n1[], char n2[], char result[]){
    int len1 = strlen(n1), len2 = strlen(n2);
    int borrow = 0, shift = 0, digit1 = 0, digit2 = 0, digit_diff = 0;
    if (len1 >= len2){
        shift = len1 - len2;
        strShift(n2, shift);
    }
    else{
        shift = len2 - len1;
        strShift(n1, shift);
    }
}
 
int main() {
    char n1[100], n2[100], result[200];
    scanf("%s", n1);
    scanf("%s", n2);
    // Add(n1, n2, result);
    // Sub(n1, n2, result);
    // Mul(n1, n2, result);
    return 0;
}