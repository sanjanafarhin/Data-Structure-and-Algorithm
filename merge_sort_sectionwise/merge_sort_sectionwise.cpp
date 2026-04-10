#include<iostream>
#include <vector>

using namespace std;

void Merge (vector<int>&datas,int low,int high,int mid)
{
   vector<int>temp(high-low+1);
   int temp_index=0;
   int i=low;
   int j=mid+1;

   while(i<=mid && j<=high)
   {
    if(datas[i]<datas[j])
    {
        temp[temp_index++]=datas[i++];
    }
    else
    {
       temp[temp_index++]=datas[j++]; 
    }
   }

   for(;i<=mid;)
   {
    temp[temp_index++]=datas[i++];
   }

   for(;j<=high;)
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

void merge_vector(vector<vector<int>> &datas,int number)
{
    for(int i=0; i<number;i++)
    {
        Merge_sort(datas[i],0,3);
    }
    cout << "\n" ;
}

int main()
{
    int number;

    cout<< "enter the number of department: " <<endl;
    cin >> number;

    vector<vector<int>>section(number);

    for(int i=0;i<number;i++)
    {
        section[i].resize(4);

        for(int j=0; j<4; j++)
        {
            cin >> section[i][j];
        }

    }

    merge_vector(section,number);

    for(int i=0;i<number;i++)
    {
        for(int j=0; j<4; j++)
        {
            
        }

    }




    



}