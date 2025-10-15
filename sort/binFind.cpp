#include<iostream>

using namespace std;

int main(){
    const int n = 6;
    /*cout << "Enter the size: ";
    cin >> n;*/
    int A[n] {2, 4, 7, 12, 56, 77};
    /*for (size_t i = 0; i < n; i++)
    {
        cout << "Enter element under the index " << i << ": ";
        cin >> A[i];
    }*/
    int l = 0, r = n - 1, m = (l + r) / 2;
    int x = 9; //cin >> x;
    
    while (l != r)
    {
        if (x > A[m]) {
            l = m + 1;
        }
        else {
            r = m;
        }
        m = (l + r) / 2;
    }
    if (A[l] == x)
    {
        cout << "Element " << x << " was found on the index " << l;
        return 0;
    }
    cout << "there is no such element as " << x;
    //delete[] A;
}