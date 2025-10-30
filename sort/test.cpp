#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Вспомогательная функция для слияния двух отсортированных частей массива
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Создаём временные массивы для левой и правой части
    vector<int> leftArr(n1), rightArr(n2);
    
    // Копируем данные во временные массивы
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];
    
    int i = 0;  // Индекс для левого подмассива
    int j = 0;  // Индекс для правого подмассива
    int k = left;  // Индекс для результирующего массива
    
    // Объединяем временные массивы обратно в arr
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Копируем оставшиеся элементы leftArr, если есть
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Копируем оставшиеся элементы rightArr, если есть
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Основная функция итеративной сортировки слиянием
void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();
    
    // Итерируемся по подмассивам возрастающего размера
    for (int currSize = 1; currSize <= n - 1; currSize = 2 * currSize) {
        
        // Выбираем начальные точки различных подмассивов текущего размера
        for (int leftStart = 0; leftStart < n - 1; leftStart += 2 * currSize) {
            
            // Находим конечные точки подмассивов для слияния
            int mid = min(leftStart + currSize - 1, n - 1);
            int rightEnd = min(leftStart + 2 * currSize - 1, n - 1);
            
            // Сливаем подмассивы arr[leftStart...mid] и arr[mid+1...rightEnd]
            merge(arr, leftStart, mid, rightEnd);
        }
    }
}

int main() {
    vector<int> arr = {7, 22, 3, 15, 29, 11, 6, 18, 25, 14, 1, 30, 9};
    
    cout << "Исходный массив: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
    
    iterativeMergeSort(arr);
    
    cout << "Отсортированный массив: ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
    
    return 0;
}
