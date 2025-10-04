#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE  20


int binarConverter(int input)
{
    int remainder,result = 0,multiplier = 1;
    while(input){
        remainder = input%2;
        result = remainder*multiplier + result;
        multiplier*=10;
        input/=2;
    }

    return result;
}


int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int* createSet(int arr[]){
    while (fgets(arr, sizeof (arr[]), stdin))
    {
        arr[strcspn(arr, "\n")] = '\0';
    }
    qsort(arr, sizeof(arr), sizeof(int), compareIntegers);
    return arr;
}

int* convertIntoBit(int arr[])
{
    char str1[20] = "";
    char str2[] = "";
    int temp = 0;
    for(int i = 0; i <= MAX_SIZE; i++)
    {
        temp = binarConverter(arr[i]);
        printf("%d \t", temp);
    }
    return arr;
}

int main()
{
    // printf("Enter the numbers to be included in the set");
    int a[] = {0,10,20,30};
    int arr[] = convertIntoBit(a);
    return 0;
}