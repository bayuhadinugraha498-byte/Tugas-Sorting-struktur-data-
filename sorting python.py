def print_step(algo_name, step, arr):
    print(f"{algo_name} - Iterasi {step}: {arr}")

def bubble_sort(data):
    print("\n--- BUBBLE SORT ---")
    arr = data.copy()
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        print_step("Bubble Sort", i+1, arr)
        if not swapped:
            break
    return arr

def selection_sort(data):
    print("\n--- SELECTION SORT ---")
    arr = data.copy()
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[min_idx] > arr[j]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        print_step("Selection Sort", i+1, arr)
    return arr

def insertion_sort(data):
    print("\n--- INSERTION SORT ---")
    arr = data.copy()
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print_step("Insertion Sort", i, arr)
    return arr

def partition(arr, low, high, step_counter):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    
    step_counter[0] += 1
    print_step("Quick Sort (Partition)", step_counter[0], arr)
    return i + 1

def quick_sort_recursive(arr, low, high, step_counter):
    if low < high:
        pi = partition(arr, low, high, step_counter)
        quick_sort_recursive(arr, low, pi - 1, step_counter)
        quick_sort_recursive(arr, pi + 1, high, step_counter)

def quick_sort(data):
    print("\n--- QUICK SORT ---")
    arr = data.copy()
    step_counter = [0] # Menggunakan list agar mutable di dalam rekursi
    quick_sort_recursive(arr, 0, len(arr)-1, step_counter)
    return arr

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = arr[l:l+n1]
    R = arr[m+1:m+1+n2]

    i = j = 0
    k = l
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def merge_sort_recursive(arr, l, r, step_counter):
    if l < r:
        m = l + (r - l) // 2
        merge_sort_recursive(arr, l, m, step_counter)
        merge_sort_recursive(arr, m + 1, r, step_counter)
        merge(arr, l, m, r)
        
        step_counter[0] += 1
        print_step("Merge Sort (Merge)", step_counter[0], arr)

def merge_sort(data):
    print("\n--- MERGE SORT ---")
    arr = data.copy()
    step_counter = [0]
    merge_sort_recursive(arr, 0, len(arr)-1, step_counter)
    return arr

# MAIN PROGRAM
if __name__ == "__main__":
    try:
        n = int(input("Masukkan jumlah data: "))
        print(f"Masukkan {n} data (pisahkan dengan spasi): ", end="")
        data_input = list(map(int, input().split()))
        
        if len(data_input) != n:
            print("Jumlah data yang dimasukkan tidak sesuai!")
        else:
            print(f"\nData Awal: {data_input}")
            
            # Eksekusi semua algoritma sorting
            bubble_sort(data_input)
            selection_sort(data_input)
            insertion_sort(data_input)
            quick_sort(data_input)
            res_merge = merge_sort(data_input)
            
            print(f"\n=====================================")
            print(f"HASIL AKHIR SORTING: {res_merge}")
            print(f"=====================================")
            
    except ValueError:
        print("Input tidak valid. Harap masukkan angka.")