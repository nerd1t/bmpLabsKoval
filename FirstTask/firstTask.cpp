#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "Enter element";
    cin >> n;
    cout << "Enter x and y";
    int x, y;
    cin >> x >> y;
    switch (n)
    {
    case 0:
        cout << "Output: " << x;
        break;
    case 1:
        cout << "Output: " << y;
        break;
    default:
        for (size_t i = 2; i < n; i++)
        {
            int temp = y;
            y = 2 * y + x;
            x = temp;
        }
        cout << "Output: " << 2 * y + x;
        break;
    }
}