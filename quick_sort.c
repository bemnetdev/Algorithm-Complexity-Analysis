//QUESTION 01: Implement quick sort and calculate CPU time for each case.
#include <stdio.h> 
#include <time.h> 

void swap(int *a, int *b)
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int partition(int array[], int low, int high)
{ 
    int pivot = array[high];
    int i = (low - 1);
    
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main()
{
    clock_t start_time = clock();
    int data[] = {4,6,2,5,3,1};
    int n = sizeof(data) / sizeof(data[0]);
    printf("Unsorted Array\n");
    printArray(data, n);
    quickSort(data, 0, n - 1);
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
    clock_t end_time = clock();
    printf("cpu_time %f", double(end_time-start_time));
}