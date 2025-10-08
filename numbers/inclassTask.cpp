#include <iostream>

using namespace std;

int main() {
    int n;
    double x, sum = 0;
    cin >> n >> x;
    for (size_t i = 1; n >= 0; n--, i++)
    {
        sum = sum * x + i;
    }
    cout << sum;
}