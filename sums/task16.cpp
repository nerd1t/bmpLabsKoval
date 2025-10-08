#include<iostream>

using namespace std;

int main() {
    int n; cin >> n;
    double x; cin >> x;
    double sum = 0.0, denom = 1.0, numer = x;
    int c = 1;

    for (size_t i = 1; i <= n; i++)
    {
        c = c * (n - i + 1) / i;
        denom *= 2 * c;
        sum += (c * numer) / denom;
        numer *= x * x;
    }
    cout << sum;
}