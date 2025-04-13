#include<stdio.h>

int findMiniIndex(int a[], int n, int start){
    int miniIndex = start;
    for (int i = start + 1; i < n; i++){
        if (a[i] < a[miniIndex]){
            miniIndex = i;
        }
    }
    return miniIndex;
}

void selectionSort(int a[], int n){
    int compares = 0, swaps = 0;
    for (int i = 0; i < n; i++){
        int miniIndex = findMiniIndex(a, n, i);
        if (miniIndex != i){
            int temp = a[i];
            a[i] = a[miniIndex];
            a[miniIndex] = temp;
            swaps += 3;
        }
        compares += i;
    }
    printf("%d %d\n", compares, swaps);
}

void insertionSort(int a[], int n){
    int compares = 0, swaps = 0, j = 0, target = 0, flag = 0;
    for (int i = 1; i < n; i++){
        target = a[i];
        flag = 0;
        swaps++;
        j = i;
        while (1){
            if (j > 0) {
                compares += 2;
            }
            else {
                compares++;
            }
            
            if ((j > 0) && (a[j - 1] > target)) {
                a[j] = a[j - 1];
                swaps++;
                j--;
            }
            else {
                break;
            }
        }
        a[j] = target;
        swaps++;
    }
    printf("%d %d\n", compares, swaps);
}
 
int main() {
    int n = 0;
    scanf("%d", &n);
    int a[n];
    int b[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++){
        b[i] = a[i];
    }
    selectionSort(a, n);
    insertionSort(b, n);
    return 0;
}