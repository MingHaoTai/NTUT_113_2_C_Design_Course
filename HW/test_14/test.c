#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 計算最大公因數 (GCD)
int gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

// 結構來存儲分數
typedef struct {
    int numerator;
    int denominator;
} Fraction;

// 解析輸入的分數字串
Fraction parseFraction(char *input) {
    Fraction f = {0, 1};
    int whole = 0, num = 0, den = 1;
    char *p = strchr(input, '(');
    
    if (p) { // 帶分數格式
        sscanf(input, "%d(%d/%d)", &whole, &num, &den);
        f.numerator = abs(whole) * den + num;
        if (whole < 0) f.numerator = -f.numerator;
        f.denominator = den;
    } else { // 真分數或假分數
        sscanf(input, "%d/%d", &num, &den);
        f.numerator = num;
        f.denominator = den;
    }
    return f;
}

// 簡化分數
Fraction simplify(Fraction f) {
    if (f.denominator == 0) return f; // 避免除以 0
    int g = gcd(f.numerator, f.denominator);
    f.numerator /= g;
    f.denominator /= g;
    if (f.denominator < 0) { // 確保負號在分子上
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
    return f;
}

// 四則運算
Fraction operate(Fraction f1, Fraction f2, char op) {
    Fraction result = {0, 1};
    if (f1.denominator == 0 || f2.denominator == 0) {
        result.denominator = 0; // Error
        return result;
    }
    switch (op) {
        case '+':
            result.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
            result.denominator = f1.denominator * f2.denominator;
            break;
        case '-':
            result.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
            result.denominator = f1.denominator * f2.denominator;
            break;
        case '*':
            result.numerator = f1.numerator * f2.numerator;
            result.denominator = f1.denominator * f2.denominator;
            break;
        case '/':
            if (f2.numerator == 0) {
                result.denominator = 0; // Error
            } else {
                result.numerator = f1.numerator * f2.denominator;
                result.denominator = f1.denominator * f2.numerator;
            }
            break;
    }
    return simplify(result);
}

// 輸出結果
void printFraction(Fraction f) {
    if (f.denominator == 0) {
        printf("Error\n");
        return;
    }
    if (f.numerator % f.denominator == 0) { // 整數
        printf("%d\n", f.numerator / f.denominator);
    } else if (abs(f.numerator) > f.denominator) { // 帶分數
        int whole = f.numerator / f.denominator;
        int rem = abs(f.numerator) % f.denominator;
        printf("%d(%d/%d)\n", whole, rem, f.denominator);
    } else { // 真分數
        printf("%d/%d\n", f.numerator, f.denominator);
    }
}

int main() {
    char input1[20], input2[20], op, choice;
    do {
        scanf("%s", input1);
        getchar();
        scanf("%c", &op);
        getchar();
        scanf("%s", input2);
        getchar();
        
        Fraction f1 = parseFraction(input1);
        Fraction f2 = parseFraction(input2);
        Fraction result = operate(f1, f2, op);
        printFraction(result);
        
        scanf(" %c", &choice);
    } while (choice == 'y');
    return 0;
}
