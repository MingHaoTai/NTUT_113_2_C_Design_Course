#include<stdio.h>
#include<math.h>

void calculus(int a, int b, int c){
    float equ, sol1, sol2; 
    equ = b*b - (4*a*c);
    if(equ >= 0){
        sol1 = (-b + sqrt(equ)) / (2*a);
        sol2 = (-b - sqrt(equ)) / (2*a);
        if(sol1 == sol2){
            printf("%.1f", sol1);
        }
        else{
            printf("%.1f\n%.1f", sol1, sol2);
        }
    }
    else{
        float r, i;
        r = (float)(-b) / (float)(2*a);
        i = sqrt(-equ) / (2*a);
        if(i < 0)
            i = -i;
        printf("%.1f+%.1fi\n%.1f-%.1fi", r, i, r, i);
    }
}

int main(){
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);    
    calculus(a, b, c);
    return 0;
}