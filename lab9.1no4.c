#include <stdio.h>

//function prototype
void swapValue(int *a, int *b, int *c);
void swapArray(int a[], int b[], int size);

int main() {

    int a = 1, b = 2, c = 3;

    printf("Before swap function: a=%d, b=%d, c=%d\n", a, b, c);

    swapValue(&a, &b, &c);

    printf("After swap function: a=%d, b=%d, c=%d\n", a, b, c);

    //calling swapArray()
    int arr1[3] = {1,2,3};
    int arr2[3] = {4,5,6};
    int size = 3;
    int i;

    printf("\nBefore swapArray\n");
    for(i=0;i<size;i++){
        printf("arr1[%d]=%d  arr2[%d]=%d\n", i, arr1[i], i, arr2[i]);
    }

    swapArray(arr1, arr2, size);

    printf("\nAfter swapArray\n");
    for(i=0;i<size;i++){
        printf("arr1[%d]=%d  arr2[%d]=%d\n", i, arr1[i], i, arr2[i]);
    }

    return 0;
}

void swapValue(int *a, int *b, int *c){

    int temp = *a;

    *a = *b;
    *b = *c;
    *c = temp;
}

void swapArray(int a[], int b[], int size){

    int temp;
    int i;

    for(i=0;i<size;i++){
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
