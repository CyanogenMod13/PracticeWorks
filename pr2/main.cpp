#include <iostream>
#include <cstdlib>
#include <cmath>

double a(double x, double y);
double b(double x, double y);
double c(double x, double y);
double delta(double x, double y);

int main() {
    double x, y = 4;
    std::cout << "Input x=";
    std::cin >> x;
    std::cout << "delta = " << delta(x, y) << std::endl;
    system("pause");
    return 0;
}

double delta(double x, double y) {
    double temp = x * y;
    if (temp > 0) return a(x, y);
    if (temp < 0) return c(x, y);
    return b(x, y);
}

double a(double x, double y) {
    return pow(x, 2) + pow(y, 2) - sqrt(x * y);
}

double b(double x, double y) {
    return 2.0 / 3.0 * (pow(x, 2) + pow(y, 2)) + exp(2);
}

double c(double x, double y) {
    return pow(x + y, 2) * log(fabs(x * y));
}