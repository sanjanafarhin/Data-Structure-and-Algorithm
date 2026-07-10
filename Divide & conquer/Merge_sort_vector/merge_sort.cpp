#include<iostream>
#include<vector>

using namespace std;

void Merge (vector<int>&datas,int low,int high,int mid)
{
   vector<int>temp(high-low+1);
   int temp_index=0;
   int i=low;
   int j=mid+1;

   while(i<=mid && j<=high)
   {
    if(datas[i]<=datas[j])
    {
        temp[temp_index++]=datas[i++];
    }
    else
    {
       temp[temp_index++]=datas[j++]; 
    }
   }

   while(i<=mid)
   {
    temp[temp_index++]=datas[i++];
   }

   while(j<=high)
   {
    temp[temp_index++]=datas[j++];
   }

   temp_index=0;

   for(int a=low;a<=high;a++)
   {
    datas[a]=temp[temp_index++];
   }


}

void Merge_sort(vector<int>&Arr, int low, int high)
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
        Merge(Arr, low, high,mid);
    }
}

int main()
{
    int n;
    cout << "how much indexes:" << endl;
    cin >> n;
    vector<int>data(n);
    cout << "write a set of array:" << endl;
    for (int &number : data)
    {
        cin >> number;
    }
    Merge_sort(data, 0, n - 1);

    cout << "After sorting" << endl;

    for (int index : data)
    {
        cout << index << ",";
    }

    return 0;
}