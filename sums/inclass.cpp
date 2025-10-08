#include<iostream>

using namespace std;

int main() {
    int n; cin >> n;
    double x; cin >> x;
    double sum = 1, p = 1;

    for (size_t i = 1; i <= n; i++)
    {
        p *= (x * x) / ((2 * i) * (2 * i - 1));
        sum += p;
    }
    cout << sum;
}