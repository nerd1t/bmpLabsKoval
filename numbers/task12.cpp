#include <iostream>

using namespace std;

int main() {
    int n, sum = 1;
    cin >> n;
    for (int i = n/2; i > 1; i--)
    {
        if (n % i == 0)
        {
            sum += i;
        }
        
    }
    if(sum == n){
        cout << "It's a perfect number";
        return 0;
    }
    cout << "It's not a perfect number";
}