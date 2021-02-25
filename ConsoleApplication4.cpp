#include <iostream>
#include <cmath>

using namespace std;

void task1();
void task2();

long random(long, long);
float randomf(long, long, long);

#define formatting(i, k)    cout << "; ";       \
                            if ((i + 1) % k == 0)   \
                                cout << endl;       \
                            

int main()
{
    cout << "Choose the number of task(1-2): ";
    int number;
    cin >> number;
    switch (number)
    {
        case 1: task1(); break;
        case 2: task2(); break;
    }
}

void task1()
{
    long n;
    long m;
    long k;

    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter k: ";
    cin >> k;

    for (int i = 0; i < m; i++)
    {
        cout << random(-10, 10);
        formatting(i, k)
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << randomf(-1, 1, 100);
        formatting(i, k)
    }
}

void task2()
{
    long a;
    long b;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    const long n = 20;
    long arr[n];

    cout << "Elements: ";
    for (int i = 0; i < n; i++)
        cout << (arr[i] = random(a, b)) << "; ";
    cout << endl;

    long min_val = labs(arr[0]);
    for (int i = 1; i < n; i++)
        min_val = min(min_val, labs(arr[i]));
    cout << "Min value is " << min_val << endl;

    long sum = 0;
    bool is_add = false;
    for (int i = 0; i < n; i++)
    {
        long element = arr[i];
        if (is_add)
            sum += labs(element);
        if (!element)
            is_add = true;
    }
    if (is_add)
        cout << "Sum of element is " << sum;
    else
        cout << "Zero element not found";
    cout << endl;
}

inline long random(long start, long end)
{
    return start + (rand() + 1) % (end - start + 1);
}

inline float randomf(long start, long end, long dec)
{
    return roundf((start + (rand() / (float) RAND_MAX) * (end - start)) * dec) / dec;
}