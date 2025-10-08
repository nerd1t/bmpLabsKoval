#include<iostream>

void fx3(int a, int& b);

int main() {
    int a; std::cin >> a;
    int b;
    fx3(a, b);
    std::cout << b;
}

void fx3(int a, int& b) {
    b = a * a * a;
    return;
}