#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f1(double x, double a) {
    return a * x * x + 1;
}

double f2(double x, double a) {
    return a * x * x * x + x;
}

double trapezoidal(double (*f)(double, double), double a, double p, double q, int err) {
    int n = 1;
    double prev = 0.0;
    double epsilon = pow(10, -err);

    while (1) {
        double h = (q - p) / n;
        double sum = f(p, a) + f(q, a);
        for (int i = 1; i < n; i++) {
            double x = p + i * h;
            sum += 2 * f(x, a);
        }
        double result = sum * h / 2.0;

        if (fabs(result - prev) < epsilon) {
            return result;
        }
        prev = result;
        n *= 2;
    }
}

int main() {
    int type;
    while (scanf("%d", &type) == 1) {
        if (type == 0) break;

        double (*func)(double, double) = NULL;

        if (type == 1) func = f1;
        else if (type == 2) func = f2;
        else {
            printf("Invalid\n");
            continue;
        }

        double a, p, q;
        int err;
        if (scanf("%lf %lf %lf %d", &a, &p, &q, &err) != 4) {
            printf("Invalid\n");
            continue;
        }

        double result = trapezoidal(func, a, p, q, err);
        printf("%.12lf\n", result);
    }
    return 0;
}
