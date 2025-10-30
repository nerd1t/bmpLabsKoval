// Msc60_Array2D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  /* 
             /  a00    a01  ...   a0(m-1)      \               /  b00    b01  ...   b0(k-1)      \
   A(n,m) = |   a10    a11  ...   a1(m-1)       |   B(m,k) =  |   b10    b11  ...   b1(k-1)       |
            |           ...                     |             |              ...                  |
             \ a(n-1)0 a(n-1)1 ... a(n-1)(m-1) /               \ b(m-1)0 b(m-1)1 ... b(m-1)(k-1) /   
  
                                                                         m-1
   C(n,k) = A(n,m) x B(m,k), т.е., C(n,k) = (cij) i=0,n-1, j=0,k-1, cij = ∑ait*btj
                                                                         t=0
  */
  setlocale(LC_ALL, "rus");
  constexpr int n = 3, m = 4, k = 2;
  int a[n][m] = { {1, 2, 3, 4},
                  {4, 5, 6, 7},
                  {8, 9,10,11} 
                };
  int b[m][k] = { {10,20},
                  {11,12},
                  {13,14},
                  {14,15}
                };
  int c[n][k];
  // Вычислим произведение матриц a и b
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k; ++j)
      { int s = 0;
        for (int t = 0; t < m; ++t)
          s += a[i][t] * b[t][j];
        c[i][j] = s;
      }

  for (int i = 0; i < n; ++i)
    {for (int j = 0; j < k; ++j)
       { cout << c[i][j] << " "; }
     cout << endl;
    }
  // 2. Двумерный динамический массив
  {// Способ 1
   int n, m;
   cout << "Enter n, m: ";
   cin >> n >> m;
   int * p2D = new int[n*m];
   cout << "Введи матрицу размера " << n << " на " << m << ":" << endl;
   for (int i = 0; i < n*m; ++i)
     { cin >> p2D[i]; }
   cout << endl;
   // Вывод матрицы
   int k = 0;
   for (int i = 0; i < n; ++i)
     {for (int j = 0; j < m; ++j)
	    cout << p2D[k++] << " ";
      cout << endl;
     }
   delete[]p2D;
  }
  {// Способ 2
   int n, m;
   cout << "Enter n, m: ";
   cin >> n >> m;
   int** pa = new int* [n];
   for (int i = 0; i < n; ++i)
     pa[i] = new int[m];
   cout << "Введи матрицу размера " << n << " на " << m << ":" << endl;
   for (int i = 0; i < n; ++i)
     for (int j = 0; j < m; ++j)
       cin >> pa[i][j];
   cout << endl;

   for (int i = 0; i < n; ++i)
     {for (int j = 0; j < m; ++j)
        cout << pa[i][j] << " ";
      cout << endl;
     }   
  }
}

