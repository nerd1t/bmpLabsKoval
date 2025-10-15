#include<iostream>
#include<vector>

using namespace std;

void print(vector<int>, int);

vector<int> merge(vector<int>, int, vector<int>, int);
vector<int> merge_sort(vector<int>, int);

int findK(vector<int>, vector<int>, int);

int main() {
    cout << "Enter the number of segments: ";
    int a, b, n; cin >> n;
    vector<int> A(n), B(n);
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter segment (a, b) №" << i << ": ";
        cin >> a >> b;
        if (a < b) {
            A[i] = a;
            B[i] = b;
        }
        else {
            A[i] = b;
            B[i] = a;
        }
    }
    A = merge_sort(A, n);
    B = merge_sort(B, n);
    print(A, n);
    print(B, n);
    cout << "------\n";
    cout << "The max K is " << findK(A, B, n);
}

void print(vector<int> A, int n) {
    for (size_t i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

vector<int> merge(vector<int> A, int sizeA, vector<int> B, int sizeB) {
    int iA = 0, iB = 0, i = 0;
    vector<int> M(sizeA + sizeB);
    while (iA < sizeA && iB < sizeB)
    {
        if (A[iA] <= B[iB])
        {
            M[i] = A[iA];
            iA++;
            i++;
        }
        else
        {
            M[i] = B[iB];
            iB++;
            i++;
        }
    }

    while (iA < sizeA)
    {
        M[i] = A[iA];
        iA++;
        i++;
    }

    while (iB < sizeB)
    {
        M[i] = B[iB];
        iB++;
        i++;
    }

    return M;
}

vector<int> merge_sort(vector<int> Array, int n) {
    int size = n;
    if (size == 1)
    {
        return Array;
    }
    
    int sizeA = size / 2;
    int sizeB = size - sizeA;
    vector<int> A (&Array[0], &Array[0] + sizeA);
    vector<int> B (&Array[sizeA], &Array[sizeA] + sizeB);

    A = merge_sort(A, sizeA);
    B = merge_sort(B, sizeB);
    return merge(A, sizeA, B, sizeB);
}

int findK(vector<int> A, vector<int> B, int n) {
    size_t i = 0, j = 0, k = 0, max = 0;
    while (i < n)
    {
        if (A[i] <= B[j])
        {
            k++;
            if (max < k) max = k;
            i++;       
        }
        else {
            k--;
            j++;
        }
    }
    return max;
}