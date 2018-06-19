#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int left, int right, int pivot){
    while(left <= right){
        while(*(arr + left) < pivot){
            left++;
        }
        
        while(*(arr + right) > pivot){
            right--;
        }
        
        if(left <= right){
            swap((arr+left), (arr+right));
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(int* arr, int left, int right){
    if(left >= right){
        return;
    }
    int pivot = *(arr + ((left + right)/2));
    int index = partition(arr, left, right, pivot);
    quicksort(arr, left, index - 1);
    quicksort(arr, index, right);
}

void insertionsort(int* arr, int size){
    for(int i = 1; i < size; i++){
        for(int j = i; j > 0; j--){
            if(*(arr + j) < *(arr + (j-1))){
                swap((arr+j), (arr+j-1));
            }
        }
    }
}

void sort(int* arr_ptr, int arr_sz){
    
    if(arr_sz > 10){
        quicksort(arr_ptr, 0, arr_sz - 1);
    }
    
    else{
        insertionsort(arr_ptr, arr_sz);
    }
    
}

int main()
{
    printf("In place sort\n");
    int a[11] = {3, 7, 1, 23, 4, 5, 2, 0, 6, 8, 11};
    sort(a, 11);
    for(int loop = 0; loop < 11; loop++){
      printf("%d ", a[loop]);
    }

    return 0;
}