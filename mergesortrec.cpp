#include<stdlib.h>
#include<stdio.h>
#include <time.h>

void ordenar(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    k = l;
    j = 0;
    i = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeArre(int arr[], int l, int r)
{
    if (l < r)
    {

        int m = l+(r-l)/2;

        mergeArre(arr, l, m);
        mergeArre(arr, m+1, r);

        ordenar(arr, l, m, r);
    }
}

void printArre(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[1000] = {0};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    srand (time(NULL));
    int i=0, n=1000;
    for(i=0;i<n;i++)
    {
        arr[i]=rand()%1000+1;
    }

    printf("============================================================\nEl arreglo dado es: \n\n============================================================\n");
    printArre(arr, arr_size);

    mergeArre(arr, 0, arr_size - 1);

    printf("============================================================\nEl arreglo ordenado es: \n\n============================================================\n");
    printArre(arr, arr_size);
    return 0;
}
