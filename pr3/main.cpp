#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() {
    double x_n, x_k, a;
    long n;

    cout << "Input x_n=";
    cin >> x_n;

    cout << "Input x_k=";
    cin >> x_k;

    cout << "Input a=";
    cin >> a;

    cout << "Input n=";
    cin >> n;

    const double dx = (x_k - x_n) / (n - 1);

    double x = x_n;
    for (int i = 1; i <= n; i++, x += dx) {
        cout << i << ". x = " << x << ", mu";

        double A = 3 * pow(cos(x), 4) - 3.0 / 5.0 * pow(x, 3);
        if (A < 0) {
            cout << " not exist (A < 0);" << endl;
            continue;
        }

        double mu = pow(2, -a * x) + 3.0 / 5.0 * pow(a, sqrt(fabs(x - a))) * trunc(sqrt(A) - exp(x + a));
        cout << " = " << mu << ';' << endl;
    }
    system("pause");
}