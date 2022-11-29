#include <math.h>

typedef int bool;

double heron(double a, double b, double c) {
    double s = (a + b + c)/2.0;

    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

bool verify_triangle(double a, double b, double c) {
    int positive_lengths = (a > 0 && b > 0 && c > 0);
    int proper_construction = (a + b > c && a + c > b && b + c > a);
    return (positive_lengths && proper_construction);
}
