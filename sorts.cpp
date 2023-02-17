#include "sorts.h"
#include <bits/stdc++.h>
using namespace std;

void Swap(int& a, int& b){
    int k = a;
    a = b;
    b = k;
}

void bubblesort(int*ar, int size){
    for (int j = 0; j < size; j++){
        for(int i = 0; i < size - 1 - j; i++){
            if (ar[i] > ar[i+1]){
                swap(ar[i], ar[i+1]);
            }
        }
    }
}

void insertionsort(int *arr, int size){
    int i, key, j;
    for (i = 1; i < size; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

    }
}

static void merge(int* ar, int size, int central) {
    int left = 0;
    int right = central;
    int* arTemp = new int [size];
    int indexTemp = 0;

    while (left < central && right < size) {
        while(ar[left] <= ar[right] && left < central) {
            arTemp[indexTemp++] = ar[left++];
        }
        while(ar[left] > ar[right] && right < size) {
            arTemp[indexTemp] = ar[right];
            indexTemp++;
            right++;
        }
    }

    while (left < central) {
        arTemp[indexTemp++] = ar[left++];
    }
    while (right < size) {
        arTemp[indexTemp++] = ar[right++];
    }

    memcpy(ar, arTemp, size * sizeof(int));

    delete [] arTemp;
}

void mergesort(int* ar, int size) {
    if (size <= 1) {
        return;
    }
    mergesort(&ar[0], size >> 1);
    mergesort(&ar[size >> 1], size - (size >> 1));

    merge(ar, size, size >> 1);
}

void fill(int* arr, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 201;
    }
}
void swaparr(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionsort(int* arr, int n){
    int i, j, min_idx;
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++){
                if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx!=i)
                swap(&arr[min_idx], &arr[i]);
    }
}
int partition(int* arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quicksort(int* arr, int start, int end)
{
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quicksort(arr, start, p - 1);
    quicksort(arr, p + 1, end);
}
void countsort(int array[], int size) {
    int output[10];
    int count[10];
    int max = array[0];
    for (int i = 1; i < size; i++) {
    if (array[i] > max)
        max = array[i];
    }
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}
