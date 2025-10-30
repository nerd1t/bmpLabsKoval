#include<iostream>

using namespace std;

void init(int**, int, int);
void del(int**, int);
void fill(int**, int, int);
void mul(int**, int**, int**, int, int, int);
void print(int**, int, int);

int main() {
    srand(time(0));

    int FS[2][3] {{2, 3, 6}, {1}};

    int n, m, k;
    cout << "Enter n, m, k: ";
    cin >> n >> m >> k;

    int **A = new int*[n];
    init(A, n, m);
    fill(A, n, m);
    print(A, n, m);

    int **B = new int*[m];
    init(B, m, k);
    fill(B, m, k);
    print(B, m, k);

    int **C = new int*[n];
    init(C, n, k);
    mul(A, B, C, n, m, k);
    print(C, n, k);

    del(A, n);
    del(B, n);
    del(C, n);
}

void init(int** A, int row, int col) {
    for (size_t i = 0; i < row; i++)
    {
        A[i] = new int[col];
    }
    
}

void del(int** A, int row) {
    for (size_t i = 0; i < row; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

void fill(int** A, int row, int col) {
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            A[i][j] = rand() % 10;
        }
        
    }
    
}

void mul(int** A, int** B, int** C, int N, int M, int K) {
    for (size_t n = 0; n < N; n++)
    {
        for (size_t k = 0; k < K; k++)
        {
            int sum = 0;
            for (size_t m = 0; m < M; m++)
            {
                sum += A[n][m] * B[m][k];
            }
            C[n][k] = sum;
        }
        
    }
    
}

void print(int** A, int row, int col) {
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }   
    
}   