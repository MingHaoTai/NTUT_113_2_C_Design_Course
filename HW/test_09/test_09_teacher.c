#include<stdio.h>
#define START 0
#define IH 1 // Integer Head
#define IB 2 // Integer Body
#define ID 3 // Integer Defined
#define FI 4 // Float Integer Part
#define FP 5 // Float Point
#define FB 6 // Float Body
#define FD 7 // Float Defined
#define NEG 8 // Negative
#define STR 9 // STRING

int getState(int state, char key){
    if (state == START && key == '0') return FI;
    else if (state == START && key == '-') return NEG;
    else if (state == START && key >= '0' && key <= '9') return IH;
    else if (state == NEG && key == '0') return  FI;
    else if (state == NEG && key >= '0' && key <= '9') return IH;
    else if (state == FI && key == '.') return FP;
    else if (state == IH && key == '.') return FP;
    else if (state == IB && key == '.') return FP;
    else if (state == FP && key >= '0' && key <= '9') return FB;
    else if (state == FB && key >= '0' && key <= '9') return FB;
    else if (state == FB && key == '\n') return FD;
    else if (state == IH && key >= '0' && key <= '9') return IB;
    else if (state == IB && key >= '0' && key <= '9') return IB;
    else if (state == IH && key == '\n') return ID;
    else if (state == IB && key == '\n') return ID;
    else return STR;
}

double getfValue(char key, int fPoint){
    int num = (key-'0');
    double r = num;
    for (int i = 0; i < fPoint; i++){
        r = r / 10;
    }
    return r;
}

int checkInput(){
    char key;
    int state = START, neg = 1;
    int iPart = 0, fPoint = 0;
    float fPart = 0;
    printf(">");
    while(1){
        key = getchar();
        state = getState(state, key);
        if (state == STR){
            printf("string");
            break;
        }
        else if (state == FD){
            if (neg == -1){
                printf("negative ");
            }
            printf("float");
            break;
        }
        else if (state == ID){
            if (neg == -1){
                printf("negative ");
            }
            printf("integer");
            break;
        }
        else if (state == NEG){
            neg = -1;
        }
        else if (state == IH){
            iPart = key - '0';
        }
        else if (state == IB){
            iPart = iPart*10 + key-'0';
        }
        else if (state == FB){
            fPoint++;
            fPart = fPart + getfValue(key, fPoint);
        }
    }
    return state;
}

int main(){
    while (1){
        if (checkInput() == STR){
            break;
        }
    }    
    return 0;
}