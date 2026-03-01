#include <iostream>

using namespace std;

/*

NOTE 1.

STEPS OF MERGE SORT
 1 . Divide
 2 . conquer
 3 . combine

*/

/*
Time complexity :

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    |   O(n log n)    |
| Average Case |   O(n log n)    |
| Worst Case   |   O(n log n)    |


Space Complexity :

Original array:   n elements
Temporary array:  n elements
----------------------------
Total extra space: n

as we are using extra temporary n array that's why space complexity o(n)

*/

void conquer(int Arr[], int low, int mid, int high)
{

    /*
    STEP 2.
    this part of merge sort is called conquer and combine where

    after dividing the array into small portions, each portion will get compare one by one

    then the elemens are placed into temporary array which are going to be shifted in main array

    */

    int Temp[high - low + 1];
    int index = 0;

    int part_one = low;
    int part_two = mid + 1;

    /*
    comparing portion where one part is from low to mid and another part is from mid+1
    to high
    */

    while (part_one <= mid && part_two <= high)
    {
        if (Arr[part_one] <= Arr[part_two])
        {
            Temp[index++] = Arr[part_one++];
        }
        else
        {
            Temp[index++] = Arr[part_two++];
        }
    }

    while (part_one <= mid)
    {
        Temp[index++] = Arr[part_one++];
    }

    while (part_two <= high)
    {
        Temp[index++] = Arr[part_two++];
    }

    index = 0;
    for (int i = low; i <= high; i++)
    {
        Arr[i] = Temp[index++];
    }
}

void Merge_sort(int Arr[], int low, int high)
{
    if (low < high)
    {

        /*
        STEP 1.

        Divide untill n=1;

        Level 1 → 8 elements
        Level 2 → 4 + 4
        Level 3 → 2 + 2 + 2 + 2
        Level 4 → 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1

        */
        int mid = (low + high) / 2;
        Merge_sort(Arr, low, mid);
        Merge_sort(Arr, mid + 1, high);

        // conquer and combine
        conquer(Arr, low, mid, high);
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
    Merge_sort(Array, 0, n - 1);

    cout << "After sorting" << endl;

    for (int index = 0; index < n; index++)
    {
        cout << Array[index] << ",";
    }
}