// 1. Обмен
// 
// 2. Двумерные массивы: преставления в памяти, неготорые алгоритмы

#include <iostream>
#include <limits>

using namespace std;

int main()
{
  {
     int a = 25;
     int& b = a;
     cout << "b = " << b << endl;
     b = 41;
     cout << "a = " << a << endl;
  }
  // 1. Обмен значений переменных x и y типа double без использования дополнительной памяти
  double x = 5.5;
  double y = 8.25;
  //x^ y;
  cout << "sizeof(x) = " << sizeof(x) << " sizeof(unsigned long long) = " << sizeof(unsigned long long) << endl;
  unsigned long long& xll = *((unsigned long long*) &x);
  unsigned long long& yll = *((unsigned long long*) &y);

  yll ^= xll;
  xll ^= yll;
  yll ^= xll;
  cout << "x = " << x << " y = " << y << endl;

  // 2. Побайтный вывод содержимого памяти, занимаемой переменной типа int, в направлении от меньших адресов к большим
  {
    cout << "max value of int: " << numeric_limits<int>::max() << endl;
    cout << "max value of short: " << numeric_limits<short>::max() << endl;
    //                       ---- старший байт значения
    //                       |     ------------- младший байт значения
    //                       v     v
    int x = 521184544;  // 0x1F10A520;
    cout << "x = " << x << " " << hex << x << dec << endl;
    using KArr4 = unsigned char[4];
    KArr4& a = *((KArr4*)&x);
    for (auto& ch : a) { cout << (int)ch << " "; }
    cout << endl;
    for (auto& ch : a) { cout << hex << (int)ch << " "; }
    cout << endl;
    // Последний цикл выведет: 20 a5 10 1f
  }
}

