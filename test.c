#include <stdio.h>

int* i_to_xy(int i)
{
    int arr[2];
    arr[0] = i/10;
    arr[1] = i%10;
    return &arr[0];
}

void main(){
    int *arr = i_to_xy(5);

    printf("x :%i, y :%i", arr[0], arr[1]);
}
