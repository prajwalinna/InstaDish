/* Algorithm
    for i=0 to n-2
        for j=0 to n-2-i
        if a[j+1] < a[j]
            swap(a[j],a[j+1])
*/
#include <stdio.h>
#include <stdlib.h>
// writing function defination for the calls
// int bubSort(int, int);

int main()
{
    int n, a[10];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubSort(n, a); // function invoked
    printf("Sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

int bubSort(int n, int a[])
{
    int i, j;
    for (i = 0; i < n - 2; i++)
    {
        for (j = 0; j < n - 2 - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}