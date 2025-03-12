#include<stdio.h>
#define START 0
#define IH 1    // Integer Head
#define IB 2    // Integer Body
#define ID 3    // Integer Defined
#define FH 4    // Float Head
#define FP 5    // Float Point
#define FF 6    // Float Float
#define FD 7    // Float Defined
#define NEG 8   // Negative
#define STR 9   // String
#define VH 10   // Variable Head
#define VB 11   // Variable Body
#define VD 12   // Variable Defined

int getState(int state, char key){
    if (state == START && key == '0') return FH;
    else if (state == START && key >= '0' && key <= '9') return IH;
    else if (state == START && key == '-')  return NEG;
    else if (state == START && (key == '_' || (key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))) return  VH;
    else if (state == NEG && key == '0') return STR;
    else if (state == IH && key >= '0' && key <= '9') return IB;
    else if (state == IH && key == '.') return FP;
    else if (state == IB && key == '.') return FP;
    else if (state == IB && key >= '0' && key <= '9') return IB;
    else if (state == IH && key == '\n') return ID;
    else if (state == FH && key == '\n') return ID;
    else if (state == IB && key == '\n') return ID;
    else if (state == NEG && key >= '0' && key <= '9') return IH;   // Integer done
    else if (state == FH && key == '.') return FP;
    else if (state == FH && key == '0') return STR;
    else if (state == FP && key >= '0' && key <= '9') return FF;
    else if (state == FF && key >= '0' && key <= '9') return FF;
    else if (state == FF && (key == '\n' || key == EOF)) return FD; // Float done
    else if (state == VH && (key == '_' || (key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key >= '0' && key <= '9'))) return VB;
    else if (state == VB && (key == '_' || (key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z') || (key >= '0' && key <= '9'))) return VB;
    else if (state == VH && key == '\n') return VD;
    else if (state == VB && key == '\n') return VD; // Variable done
    else if (key == EOF) return -1;
    else return STR;
}

int checkInput(){
    char key;
    int state = START;
    int count = 0;
    while (1){
        key = getchar();
        state = getState(state, key);
        // printf("%c,%d\n", key, state);
        if (key == EOF){
            break;
        }
        if (state == ID && key == '\n'){
            return 1;
        }
        else if (state == FD && key == '\n'){
            return 2;
        }
        else if (state == VD && key == '\n'){
            if (count > 10){
                return 4;
            }
            else{
                return 3;   
            }
        }
        else if (state == STR && key == '\n'){
            return 4;
        }
        else if (state == VH || state == VB){
            count++;
        }
    }
}

int main(){
    int n = 0, feedback[8] = {};
    char data[8][50] = {};
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++){
        feedback[i] = checkInput();
    }  
    for (int i = 0; i < n; i++){
        if (feedback[i] == 1){
            printf("integer\n");
        }
        else if (feedback[i] == 2){
            printf("float\n");
        }
        else if (feedback[i] == 3){
            printf("variable\n");
        }
        else{
            printf("string\n");
        }
    }
    return 0;
}