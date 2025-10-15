#include<iostream>
#include<vector> 

using namespace std;

int main() {
    vector<int> v {1, 3, 6, 643, 2, 2, 34};
    int *ptr = &v[5];
    cout << ptr[0] << " " << ptr[1];
}