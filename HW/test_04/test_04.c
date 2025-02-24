#include<stdio.h>
#include<math.h>

int data_legal(float w, float h){
    if (w < 20 || w > 100 || h < 1 || h > 2){
        return 0;
    }
    return 1;
}

int calculus_BMI(float w, float h){
    float bmi;
    bmi = w / (h*h);
    if ((int)(bmi*10)%10 < 5){
        bmi = (int)bmi;
    }
    else if ((int)(bmi*10)%10 > 5){
        bmi = (int)bmi + 1;
    }
    else if ((int)(bmi*10)%10 == 5 && (int)bmi%2 == 0){
        bmi = (int)bmi + 1;
    }
    else{
        bmi = (int)bmi;
    }
    return (int)bmi;
}

void BMI(int bmi){
    if (bmi < 18){
        printf("too low");
    }
    else if (bmi > 24){
        printf("too high");
    }
}

int main(){
    float weight, height, height_cm;
    int bmi;
    scanf("%f", &weight);
    scanf("%f", &height_cm);
    height = height_cm / 100;
    if (data_legal(weight, height) == 0){
        printf("ERROR");
        return 0;
    }
    bmi = calculus_BMI(weight, height);
    printf("%d\n", bmi);
    BMI(bmi);
    return 0;
}