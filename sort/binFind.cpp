#include"iostream"

using namespace std;

int main(){
    int A[6] = {1, 8, 22, 23, 53, 156}, x = 22;
    int l = 0, r = 5, m = 6 / 2;
    
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
        cout <<  l;
        return 0;
    }
    cout << "there is no such element as " << x;
}