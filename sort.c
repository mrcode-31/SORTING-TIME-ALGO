#include <stdio.h>
#include <windows.h>

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    LARGE_INTEGER frequency, start, stop;
    double time_taken;
    QueryPerformanceFrequency(&frequency);

    // Bubble Sort
    int b_arr[n];
    for (int i = 0; i < n; i++) b_arr[i] = arr[i];

    QueryPerformanceCounter(&start);  // Start stopwatch
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (b_arr[j] > b_arr[j + 1]) {
                int temp = b_arr[j];
                b_arr[j] = b_arr[j + 1];
                b_arr[j + 1] = temp;
            }
        }
    }
    QueryPerformanceCounter(&stop);  // Stop stopwatch
    time_taken = (double)(stop.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Bubble Sort Time: %f sec\n", time_taken);

    // Selection Sort
    int s_arr[n];
    for (int i = 0; i < n; i++) s_arr[i] = arr[i];

    QueryPerformanceCounter(&start);  // Start stopwatch
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (s_arr[j] < s_arr[min_idx]) min_idx = j;
        }
        int temp = s_arr[i];
        s_arr[i] = s_arr[min_idx];
        s_arr[min_idx] = temp;
    }
    QueryPerformanceCounter(&stop);  // Stop stopwatch
    time_taken = (double)(stop.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Selection Sort Time: %f sec\n", time_taken);

    // Insertion Sort
    int i_arr[n];
    for (int i = 0; i < n; i++) i_arr[i] = arr[i];

    QueryPerformanceCounter(&start);  // Start stopwatch
    for (int i = 1; i < n; i++) {
        int key = i_arr[i], j = i - 1;
        while (j >= 0 && i_arr[j] > key) {
            i_arr[j + 1] = i_arr[j];
            j--;
        }
        i_arr[j + 1] = key;
    }
    QueryPerformanceCounter(&stop);  // Stop stopwatch
    time_taken = (double)(stop.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Insertion Sort Time: %f sec\n", time_taken);

    return 0;
}
