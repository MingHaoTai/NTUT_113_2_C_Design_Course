#include <stdio.h>
#include <math.h>

double f1(double x, double a) {
    return a * x * x;
}

double f2(double x, double a) {
    return a * x * x * x;
}

double trapezoid(double (*f)(double, double), double a, double p, double q, int n) {
    double h = (q - p) / n;
    double sum = (f(p, a) + f(q, a)) / 2.0;

    for (int i = 1; i < n; ++i) {
        sum += f(p + i * h, a);
    }

    return sum * h;
}

int main() {
    int type;
    while (scanf("%d", &type) == 1) {
        if (type == 0) break;

        double a, p, q;
        int err;

        if (type == 1 || type == 2) {
            scanf("%lf %lf %lf %d", &a, &p, &q, &err);
            double (*f)(double, double) = (type == 1) ? f1 : f2;

            int n = 1;
            double prev = trapezoid(f, a, p, q, n);
            double curr;

            double eps = pow(10.0, -err);

            while (1) {
                n *= 2;
                curr = trapezoid(f, a, p, q, n);
                if (fabs(curr - prev) < eps) break;
                prev = curr;
            }

            printf("%.12lf\n", curr);

        } else {
            printf("Invalid\n");
        }
    }

    return 0;
}
