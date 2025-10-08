#include<iostream>

using namespace std;

int main() {
    int a, b, n; cin >> n;
    int A[n], B[n], k = 1;
    for (size_t i = 0; i < n; i++)
    {
        cin >> a >> b;
        A[i] = min(a, b);
        B[i] = max(a, b);
    }
    for (size_t i = 0; i < n; i++)
    {
        int count = 0;
        for (size_t j = 0; i < n; i++)
        {
            if (A[j] >= A[i] && A[j] <= B[i])
            {
                count++;
            }
        }
        if (count > k)
        {
            k = count;
        }
        
    }
    
}