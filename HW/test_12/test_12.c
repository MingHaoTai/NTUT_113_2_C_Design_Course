#include<stdio.h>
#include<string.h>

int legal(char* s, int len){
    if ((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_'){
        if ((s[len-1] >= 'a' && s[len-1] <= 'z') || (s[len-1] >= 'A' && s[len-1] <= 'Z') || s[len-1] == '_'){
            return 1;
        }
    }
    return 0;
}

void inverse(char* s, int len){
    for (int i = 0; i < len; i++){
        printf("%c", s[len-i-1]);
    }
    printf("\n");
}

int length(char* s){    // no space
    int i = 0, len = 0;;
    while(1){
        if (s[i] == '\0'){
            return len;
        }
        if (s[i] != '\0' && s[i] != ' '){
            len++;
        }
        i++;
    }
}

int main(){
    char s1[20] = {}, s2[20] = {};    
    int s1_l, s2_l;
    gets(s1);
    gets(s2);
    s1_l = strlen(s1);
    s2_l = strlen(s2);
    if (legal(s1, s1_l) == 0 || legal(s2, s2_l) == 0){
        printf("Error");
        return 0;
    }
    inverse(s1, s1_l);
    inverse(s2, s2_l);

    s1_l = length(s1);
    s2_l = length(s2);
    if (s2_l > s1_l){
        printf("%s", s2);
    }
    else{
        printf("%s", s1);
    }
    return 0;
}