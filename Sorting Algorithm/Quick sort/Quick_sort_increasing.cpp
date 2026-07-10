#include <iostream>

using namespace std;

/*
NOTE 1.

How Quick Sort Works:

1.Choose a Pivot (any element — usually last or first highly prefered).

2.Partition the array:

Elements smaller than pivot → left side

Elements greater than pivot → right side

3.Recursively apply Quick Sort on left and right subarrays.
*/

/*
NOTE 2.

| Case       | Complexity |
| ---------- | ---------- |
| Best Case  | O(n log n) |
| Average    | O(n log n) |
| Worst Case | O(n²)      |

*/

/*
NOTE 3.

why it is different from merge sort?:

because it skip the part about combining and it happens in the exact same main array

*/

/*
NOTE 4.

worst case is when array is already sorted as

ex:
1 2 3 4 5 ;pivot-> 5 ; red =4
1 2 3 4 ;pivot-> 4 ; red=3
1 2 3 ;pivot->3 ; red=2
1 2 ; pivot->2 ; red=1
1 ;pivot->1; red=0;
quick sort fuction will happen n time;in the fuction the red will be iterate n times so n*n= O(n²)



*/

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
    int blue = low - 1; // Blue checking if Red indexed element is less than Pivot or not
    int red = low;      // checks the iteration

    while (red < high)
    {
        if (arr[red] < arr[pivot])
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
    cout << "how much indexes:" << endl;
    cin >> n;
    int Array[n];
    cout << "write a set of array:" << endl;
    for (int index = 0; index < n; index++)
    {
        cin >> Array[index];
    }
    Quick_sort(Array, 0, n - 1);

    cout << "After sorting" << endl;

    for (int index = 0; index < n; index++)
    {
        cout << Array[index] << ",";
    }

    return 0;
}