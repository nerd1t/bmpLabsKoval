#include<iostream>

using namespace std;

double x;
int n;

double rec(double F1, double F0){
    double Fi = (2 * F1) + (3 * F0) + 4;
    if (::n == 2)
    {
        return Fi;
    }
    ::n--;
    return rec(Fi, F1) * ::x + Fi;
}

int main() {
    double P1 = 0, P2 = 0, f0 = 5, f1 = 6;
    cin >> ::x >> ::n >> f0 >> f1;

    switch (::n) {
    case 0:
        cout << "P1 = P2 = " << f0;
        break;

    case 1:
        P1 = f0 * ::x + f1;
        P2 = f1 * ::x + f0;
        cout << "P1 = " << P1 << '\n';
        cout << "P2 = " << P2;
        break;

    default:
        int sub0 = f0, sub1 = f1, t = ::n - 2;
        P1 = f0 * ::x + f1;
        for (double fi = 2 * sub1 + 3 * sub0 + 4; t >= 0; t--, fi = 2 * sub1 + 3 * sub0 + 4)
        {
            P1 = P1 * ::x + fi;
            sub0 = sub1;
            sub1 = fi;
        }

        P2 = rec(f1, f0);
        P2 = (P2 * x + f1) * x + f0;

        cout << "P1 = " << P1 << '\n';
        cout << "P2 = " << P2;
        break;
    }
}