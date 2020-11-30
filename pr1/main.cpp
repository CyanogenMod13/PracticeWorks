#include <iostream>
#include <cstdlib>
#include <cmath>
//option 10

double B(double x, double y);
double D(double x, double y);
double A(double x, double y, double a);
double C(double x, double y, double a);
double E(double x, double y, double a);
double sigma(double x, double y, double a);

void logger(char* name, double value);

int main() {
    double x, y, a;

    std::cout << "Input x=";
    std::cin >> x;

    std::cout << "Input y=";
    std::cin >> y;

    std::cout << "Input a=";
    std::cin >> a;

    sigma(x, y, a);

    system("pause");
}

void logger(char* name, double value) {
    std::cout << name << " = " << value << ';' << std::endl;
}

double sigma(double x, double y, double a) {
    double sigma = log(fabs(A(x, y, a) / B(x, y))) + sqrt(C(x, y, a) / D(x, y)) + E(x, y, a);
    logger("sigma", sigma);
    return sigma;
}

double A(double x, double y, double a) {
    double A = 2 * a * pow(x, 3) - 3 * pow(a, 2) * x + y;
    logger("A", A);
    return A;
}

double B(double x, double y) {
    double B = 3 - sin(x + y) - cos(x - y);
    logger("B", B);
    return B;
}

double C(double x, double y, double a) {
    double C = pow(tan(x / a), 4) * pow(tan(y / a), 2) + 1;
    logger("C", C);
    return C;
}

double D(double x, double y) {
    double D = sqrt(fabs(3 + sin(x) - pow(cos(y), 3)));
    logger("D", D);
    return D;
}

double E(double x, double y, double a) {
    double E = -pow(tan(x / 2), 2) + cos(x) * tan(y) / exp(a * x);
    logger("E", E);
    return E;
}