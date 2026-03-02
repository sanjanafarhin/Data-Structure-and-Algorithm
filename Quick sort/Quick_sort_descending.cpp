#include <iostream>

using namespace std;

void swipe(int arr[], int from, int to)
{
    int temp;
    temp = arr[from];
    arr[from] = arr[to];
    arr[to] = temp;
}

int pivot_index(int arr[], int low, int high)
{
    int pivot = high;
    int blue = low - 1;
    int red = low;

    while (red < high)
    {
        if (arr[red] > arr[pivot])
        {
            blue++;
            swipe(arr, blue, red);
            red++;
        }
        else
        {
            red++;
        }
    }
    blue++;
    swipe(arr, blue, pivot);

    return blue;
}

void Quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot_index_num = pivot_index(arr, low, high);
        Quick_sort(arr, low, pivot_index_num - 1);
        Quick_sort(arr, pivot_index_num + 1, high);
    }
}

int main()
{
    int n;
    cout << "how much indexes:" <<endl;
    cin >> n;
    int Array[n];
    cout << "write a set of array:" <<endl;
    for(int index=0; index<n; index++)
    {
        cin >> Array[index];
    }
    Quick_sort(Array,0,n-1);

    cout << "After sorting" <<endl;

    for(int index=0; index<n; index++)
    {
        cout << Array[index] <<"," ;
    }

}