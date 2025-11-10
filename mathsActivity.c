#include <stdio.h>
#include <math.h>

// console functionsn !!

void showFunction(double a, double b, double c, double d);
void showDerivative(double a, double b, double c);
void showSecondDerivative(double a, double b);

// functions !!

void criticalPoints(double a, double b, double c);
void intervals(double a, double b, double c);
void concavity(double a, double b);
void inflection(double a, double b);

//main function !

int main() {
    double a, b, c, d;  //declaration !!

    printf("Enter coefficients a, b, c, d for f(x) = ax^3 + bx^2 + cx + d:\n");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

    printf("\nFunction:\n");
    showFunction(a, b, c, d);

    printf("\nFirst Derivative:\n");
    showDerivative(a, b, c);

    printf("\nSecond Derivative:\n");
    showSecondDerivative(a, b);

    printf("\n--- Analysis ---\n");
    criticalPoints(a, b, c);
    intervals(a, b, c);
    concavity(a, b);
    inflection(a, b);

    return 0;
}

// Print function neatly 
void showFunction(double a, double b, double c, double d) {
    printf("f(x) = ");
    if (a != 0) printf("%.1lfx^3 ", a);
    if (b > 0) printf("+ %.1lfx^2 ", b);
    else if (b < 0) printf("- %.1lfx^2 ", -b);
    if (c > 0) printf("+ %.1lfx ", c);
    else if (c < 0) printf("- %.1lfx ", -c);
    if (d > 0) printf("+ %.1lf", d);
    else if (d < 0) printf("- %.1lf", -d);
    printf("\n");
}

// Print first derivative neatly 
void showDerivative(double a, double b, double c) {
    double A = 3*a, B = 2*b, C = c;
    printf("f'(x) = ");
    if (A != 0) printf("%.1lfx^2 ", A);
    if (B > 0) printf("+ %.1lfx ", B);
    else if (B < 0) printf("- %.1lfx ", -B);
    if (C > 0) printf("+ %.1lf", C);
    else if (C < 0) printf("- %.1lf", -C);
    printf("\n");
}

// Print second derivative neatly 
void showSecondDerivative(double a, double b) {
    double A = 6*a, B = 2*b;
    printf("f''(x) = ");
    if (A != 0) printf("%.1lfx ", A);
    if (B > 0) printf("+ %.1lf", B);
    else if (B < 0) printf("- %.1lf", -B);
    printf("\n");
}

// Find critical points 
void criticalPoints(double a, double b, double c) {
    double disc = (2*b)*(2*b) - 4*(3*a)*c;
    if (disc < 0) {
        printf("\nNo real critical points.\n");
        return;
    }


    double x1 = (-2*b + sqrt(disc)) / (6*a);
    double x2 = (-2*b - sqrt(disc)) / (6*a);

    if (x1 > x2) { double t = x1; x1 = x2; x2 = t; }

    printf("\nCritical Points:\n");
    double sd1 = 6*a*x1 + 2*b;
    double sd2 = 6*a*x2 + 2*b;

    printf("x = %.4lf : %s\n", x1, (sd1 > 0) ? "Local Minimum" : "Local Maximum");
    printf("x = %.4lf : %s\n", x2, (sd2 > 0) ? "Local Minimum" : "Local Maximum");
}

// Find increasing and decreasing intervals 
void intervals(double a, double b, double c) {
    double disc = (2*b)*(2*b) - 4*(3*a)*c;
    printf("\nIntervals of Increase/Decrease:\n");

    if (disc < 0) {
        if (3*a > 0)
            printf("Function is always increasing.\n");
        else
            printf("Function is always decreasing.\n");
        return;
    }

    double x1 = (-2*b + sqrt(disc)) / (6*a);
    double x2 = (-2*b - sqrt(disc)) / (6*a);
    if (x1 > x2) { double t = x1; x1 = x2; x2 = t; }

    if (a > 0) {
        printf("(-infinity , %.4lf) : Increasing\n", x1);
        printf("(%.4lf , %.4lf) : Decreasing\n", x1, x2);
        printf("(%.4lf , infinity) : Increasing\n", x2);
    } else {
        printf("(-infinity , %.4lf) : Decreasing\n", x1);
        printf("(%.4lf , %.4lf) : Increasing\n", x1, x2);
        printf("(%.4lf , infinity) : Decreasing\n", x2);
    }
}

// Concavity 
void concavity(double a, double b) {
    printf("\nConcavity:\n");
    if (a == 0) {
        printf("Not a cubic function.\n");
        return;
    }
    printf("If f''(x) > 0 : Concave Up\n");
    printf("If f''(x) < 0 : Concave Down\n");
}

// Inflection point 
void inflection(double a, double b) {
    printf("\nInflection Point:\n");
    if (a == 0) {
        printf("No inflection point.\n");
        return;
    }
    double x = -(2*b) / (6*a);
    printf("x = %.4lf is the inflection point.\n", x);
}
