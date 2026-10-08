#include<stdio.h>
//Quick Sort Algo

void QuickSort(int i, int j, int arr[]) {

    int pivot = arr[i];
    int left = i;
    int right = j;

    for (int k = 0; k < 9; k++) {
        printf("%d ", arr[k]);
    } printf("\n");
    for (int k = 0; k < 9; k++) {
        if(k==i) {
            if(arr[k]==pivot) printf("ip ");
            else printf("i  ");
            
        }
        else if(k==j) printf("j  ");
        else printf("   ");
    } printf("\n\n");

    

    while (left < right) {
        while (arr[left] <= pivot && left < j) {
            left++;
        }
        while (arr[right] > pivot) {
            right--;
        }


        

        if (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;

        //Print Array after swap
        for (int k = 0; k < 9; k++) {
            if(k==right) printf("%d ", arr[right]);
            else if(k==left) printf("%d ", arr[left]);
            else printf("   ");
        } printf("R<->L\n\n"); 
        }

        /*Print Array after swap 
        for (int k = 0; k < 9; k++) {
            if(k==right) printf("%d ", arr[right]);
            else if(k==left) printf("%d ", arr[left]);
            else printf("   ");
        } printf("\n\n");*/
    }

    //Print Array after swap
    for (int k = 0; k < 9; k++) {
        if(k==i) printf("%d ", arr[i]);
        else if(k==right) printf("%d ", arr[right]);
        else if(arr[k]==pivot) printf("%d ", arr[pivot]);
        else printf("   ");
    } printf("R<->P\n\n"); 
    
    arr[i] = arr[right];
    arr[right] = pivot;

    for (int k = 0; k < 9; k++) {
        printf("%d ", arr[k]);
    } printf("\n");
    for (int k = 0; k < 9; k++) {
        if(k==right) printf("r  ");
        else if(k==left) printf("l  ");
        else if(arr[k]==pivot) printf("%d ", arr[pivot]);
        else printf("   ");
    } printf("\n\n");

    if (i < right - 1) {
        QuickSort(i, right - 1, arr);
    }
    if (right + 1 < j) {
        QuickSort(right + 1, j, arr);
    }

   
}

int main() {
    int arr[9] = {54, 26, 93, 17, 77, 31, 44, 55, 20};

    int n = sizeof(arr) / sizeof(arr[0]);
    QuickSort(0, n - 1, arr);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
    return 0;
}