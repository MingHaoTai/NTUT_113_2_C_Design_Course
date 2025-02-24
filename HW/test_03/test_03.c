#include<stdio.h>
#include<string.h>

int element_legal(char x){
    char E[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    for(int i = 0; i < 6; i++){
        if(x == E[i]){
            return 1;
        }
    }
    return 0;
}

void Dec_to_bin(int x, char* bin){
    int count_bit, count_E = 0;
    for(int i = 0; i < 6; i++){
        if(x%2 == 1){
            bin[i] = '1';
        }
        else{
            bin[i] = '0';
        }
        x /= 2;
    }
    bin[6] = '\0';
}

int deter1(char e, char bin[]){
    char E[7] = "abcdef";
    int index = 0;
    for(int i = 0; i < 6; i++){
        if(e == E[i]){
            index = i;
        }
    }
    if(bin[index] == '1'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int S0, S1;
    char e1, e2;
    int flag = 0;
    scanf("%d ", &S0);
    scanf("%d ", &S1);
    scanf("%c ", &e1);
    scanf("%c", &e2);
    if(S0 < 0 || S0 > 63){
        printf("S0 ERROR\n");
        flag = 1;
    }
    if(S1 < 0 || S1 > 63){
        printf("S1 ERROR\n");
        flag = 1;
    }
    if(element_legal(e1) == 0){
        printf("e1 ERROR\n");
        flag = 1;
    }
    if(element_legal(e2) == 0){
        printf("e2 ERROR\n");
        flag = 1;
    }
    if(flag == 1){
        return 0;
    }

    char E[7] = "abcdef";
    char bin0[7] = "", bin1[7] = "", bin2[7] = "";
    int index = 0;
    Dec_to_bin(S0, bin0);
    Dec_to_bin(S1, bin1);
    for(int i = 0; i < 6; i++){
        if(e1 == E[i]){
            index = i;
            break;
        }
    }    
    strcpy(bin2, bin1);
    bin2[index] = '1';
    
    if(deter1(e2, bin2) == 1){
        printf("Y\n");
    }
    else{
        printf("N\n");
    }
    
    return 0;
}