#include <iostream>
#include <vector>

using namespace std;

void printStep(string algoName, int step, const vector<int>& arr) {
    cout << algoName << " - Iterasi " << step << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> arr) {
    cout << "\n--- BUBBLE SORT ---" << endl;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        printStep("Bubble Sort", i + 1, arr);
        if (!swapped) break;
    }
}

void selectionSort(vector<int> arr) {
    cout << "\n--- SELECTION SORT ---" << endl;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
        printStep("Selection Sort", i + 1, arr);
    }
}

void insertionSort(vector<int> arr) {
    cout << "\n--- INSERTION SORT ---" << endl;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printStep("Insertion Sort", i, arr);
    }
}

int partition(vector<int>& arr, int low, int high, int& stepCounter) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    stepCounter++;
    printStep("Quick Sort (Partition)", stepCounter, arr);
    return (i + 1);
}

void quickSortRecursive(vector<int>& arr, int low, int high, int& stepCounter) {
    if (low < high) {
        int pi = partition(arr, low, high, stepCounter);
        quickSortRecursive(arr, low, pi - 1, stepCounter);
        quickSortRecursive(arr, pi + 1, high, stepCounter);
    }
}

void quickSort(vector<int> arr) {
    cout << "\n--- QUICK SORT ---" << endl;
    int stepCounter = 0;
    quickSortRecursive(arr, 0, arr.size() - 1, stepCounter);
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(vector<int>& arr, int l, int r, int& stepCounter) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortRecursive(arr, l, m, stepCounter);
        mergeSortRecursive(arr, m + 1, r, stepCounter);
        merge(arr, l, m, r);
        stepCounter++;
        printStep("Merge Sort (Merge)", stepCounter, arr);
    }
}

void mergeSort(vector<int> arr) {
    cout << "\n--- MERGE SORT ---" << endl;
    int stepCounter = 0;
    mergeSortRecursive(arr, 0, arr.size() - 1, stepCounter);
    
    cout << "\n=====================================" << endl;
    cout << "HASIL AKHIR SORTING: ";
    for(int num : arr) cout << num << " ";
    cout << "\n=====================================" << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    vector<int> dataInput(n);
    cout << "Masukkan " << n << " data (pisahkan dengan spasi): ";
    for (int i = 0; i < n; i++) {
        cin >> dataInput[i];
    }

    cout << "\nData Awal: ";
    for(int num : dataInput) cout << num << " ";
    cout << endl;

    // Menjalankan semua algoritma dengan salinan data
    bubbleSort(dataInput);
    selectionSort(dataInput);
    insertionSort(dataInput);
    quickSort(dataInput);
    mergeSort(dataInput); // Menampilkan hasil akhir di fungsi ini

    return 0;
}