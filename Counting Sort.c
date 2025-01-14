#include<stdio.h>
int main()
{
    int arr[1000], n, i;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Find the maximum element in the array
    int max = arr[0];//Range and max are exactly the same
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Create a count array to store the frequency of each element. Set all the value of the array to zero.
    int count[max + 1];
    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }


    // Store the count of each element in the count array.
    for (i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for(i = 1; i <= max; i++)
    {
        count[i]+=count[i-1];
    }

    int output[n];
    for(i=n-1; i >= 0; i--)
    {
        output[--count[arr[i]]] =arr[i];

    }

    printf("Sorted array in ascending order: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", output[i]);
    }

    return 0;
}
