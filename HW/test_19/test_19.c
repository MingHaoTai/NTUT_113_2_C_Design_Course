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

void big_integer_div(char *s1, char *s2){
    int len1 = strlen(s1), len2 = strlen(s2), len = 0;
    int shift = 0;
    int count = 0;
    if (len1 >= len2){
        len = len1;
        shift = len1 - len2;
        if (shift > 0){
            str_shift(s2, shift);
        }
    }
    else{
        len = len2;
        shift = len2 - len1;
        str_shift(s1, shift);
    
    }

    while (strcmp(s1, s2) >= 0){
        count++;
        int carry = 0, digit1 = 0, digit2 = 0, digit_sum = 0;
        for (int i = len - 1; i > -1; i--){
            digit1 = (int)s1[i] - 48;
            digit2 = (int)s2[i] - 48;
            digit_sum = digit1 - digit2 - carry;
            if (digit_sum < 0){
                carry = 1;
                digit_sum += 10;
            }
            else{
                carry = 0;
            }
            s1[i] = (char)digit_sum + 48;
        }
    }  
    printf("%d\n", count);
    remove_zeros(s1);
    printf("%s\n", s1);
}
 
int main() {
    char s1[41] = {}, s2[41] = {};
    gets(s1);
    gets(s2);
    big_integer_div(s1, s2);
    return 0;
}