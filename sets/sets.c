#include <stdio.h>
#include <stdlib.h>



void Union(int set1[], int set2[], int n){

    int newSet[n];
    for (int i = 0; i < n; i++)
    {
        if (set1[i] == 0 && set2[i] == 0)
        {
            newSet[i] = 0;
        }
        else{
            newSet[i] = 1;
        }
        
    }
    display(newSet,n);
    
}

void Intersection(int set1[], int set2[], int n)
{
    int newSet[n];

    for (int i = 0; i < n; i++)
    {
        if (set1[i] == 1 && set2[i] == 1)
        {
            newSet[i] = 1; 
        }
        else
        {
            newSet[i] = 0;
        }
    }

    display(newSet,n);
    
}

void Difference(int set1[], int set2[], int n){
    int newSet[n];
    for (int i = 0; i < n; i++)
    {
        if (newSet[i] == 1 && newSet[i] == 0)
        {
            newSet[i] = 1;
        }
        else{
            newSet[i] = 0;
        }
        
    }
    display(newSet, n);
    
}

void clearSet(int set[], int n){
    for (int i = 0; i < n; i++)
    {
        set[i] = 0;
    }
    
}


int isPresent(int set[], int n, int element){

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (set[i] == element)
        {
            flag = 1;
            return flag;
        }
    }
    return flag;
    
}


void makeSet(int universalSet[], int set[], int n, int bitstring[])
{
    for (int i = 0; i < n; i++)
    {
        if (isPresent(set, i, universalSet[i]) == 1){
            bitstring[i] = 1;
        }
        else{
            bitstring[i] = 0;
        }
    }
    
}


void createSet(int universalSet[], int n, int set[],int n1){

    clearSet(set,n);
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (n1 > n || n1 < 0)
        {
            printf("\n The size of the set is invalid ");
        }
        else
        {
            printf("\n Enter the element at %dth position : ",i+1);
            scanf("%d",&element);

            if (isPresent(set,n1,element) == 0 && isPresent(universalSet,n,element) == 1){
                set[i] = element;
            }
            else{
                printf("\n Can't allow duplicate elements ");
                i--;
            }
            
        }
    }
    

}


void display(int set[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d",set[i]);
    }
    
}

int main()
{
    int n,c,n1,n2;
    printf("Enter the No of elements of universal sets : ");
    scanf("%d",&n);
    int universalSet[n], set1[n], set2[n], bitString1[n], bitString2[n];
    
    clearSet(universalSet,n);

    for (int i = 0; i < n; i++)
    {
        printf("\n Enter the element of universal sets at %d position ",i+1);
        scanf("%d",&c);

        if (isPresent(universalSet, n, c) == 0){

            universalSet[i] = c;
        }
        else{

            printf("\n Duplicate elements not allowed ");
            i--;
        }
    }
    
    printf("\n Enter the number of elements of set 1 : ");
    scanf("%d",&n1);
    clearSet(set1,n1);
    createSet(universalSet,n,set1,n1);

    printf("\n Enter the number of elements of set 2 : ");
    scanf("%d", &n2);
    clearSet(set2,n2);
    createSet(universalSet,n,set2,n2);



    // creating bitstrings

    makeSet(universalSet, set1, n, bitString1);

    makeSet(universalSet, set2, n, bitString2);

    return 0;
}