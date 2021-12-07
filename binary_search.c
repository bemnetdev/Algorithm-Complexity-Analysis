/* QUESTION 2a: Write an efficient program to find out whether a sorted 
 input array contains two elements whose sum is exactly equal to 198. */

//(a) 100, 99, 98, ----, 3, 2,1

#include <stdio.h>

//I have used binary search algorithm to get the second number
int binarySearch(int arr[], int l, int r, int current_value)
{
    if (r >= l) 
    {
        int mid = l + (r - l) / 2;
        if (arr[mid]+current_value == 198)
        {
            if(mid!=current_value)
            {
                return mid;
            }
            else
            {
                return 0;
            }
        }

        if (arr[mid] +current_value> 198)
        {
            return binarySearch(arr, l, mid - 1, current_value);
            return binarySearch(arr, mid + 1, r, current_value);
        }
    }
    return 0;
}

int main(void)
{
    int arr[101];
    int j;

    for(j=100;j>0;j--)
    {
    arr[j]=j;
    }

    int n = sizeof(arr) / sizeof(arr[0]);
    int i,k=0;
    bool flag=false;
    for(i=100;i>0;i--)
    {
        k=k+1;
        if(binarySearch(arr,0,n-k,i))
        {
            printf("%d + %d = 198\n", binarySearch(arr,0,n-1,i),i);
            flag = true;
        }
    }

    if(flag)
    {
        printf("I have found Answer which meet the requirement. look above");
    }
    else{
        printf("I have not found any two element which meet the requirement.");
    }
    return 0;
}