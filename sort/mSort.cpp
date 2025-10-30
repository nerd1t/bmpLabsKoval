#include<iostream>

using namespace std;


int min(int a, int b) {
    return a <= b ? a : b;
}
void print(vector<int>, int);
void merge(vector<int>&, int, int, int);
void sort(vector<int>&, int);
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

    sort(A, n);
    sort(B, n);

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

void merge(vector<int>& A, int left, int mid, int right) {
    int s1 = mid - left + 1;
    int s2 = right - mid;

    vector<int> first(s1), second(s2);
    for(size_t i = 0; i < s1; i++) {
        first[i] = A[left + i];
    }
    for(size_t i = 0; i < s1; i++) {
        second[i] = A[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < s1 && j < s2)
    {
        if (first[i] <= second[j])
        {
            A[k] = first[i];
            k++; i++;
        }
        else {
            A[k] = second[j];
            k++; j++;
        }
        
    }

    while (i < s1)
    {
        A[k] = first[i];
        k++; i++;
    }

    while (j < s2)
    {
        A[k] = second[j];
        k++; j++;
    }
}

void sort(vector<int>& A, int n) {
    for (size_t k = 1; k < n; k *= 2)
    {
        int l = 0;
        while (l < n - 1) {
            int r = min((l + 2 * k - 1), (n - 1));
            int m = min((l + k - 1), (n - 1));
            merge(A, l, m, r);
            l += 2 * k;
        }
    }
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