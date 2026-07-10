#include"bits/stdc++.h"
#include <vector>

using namespace std;

struct index_and_cross
{
    int cross;
    int left_index;
    int right_index;
};

index_and_cross Crossing_sum(vector<int>&datas,int low,int high,int mid)
{
    index_and_cross res;

    int left=mid;
    int right=mid+1;

    int high_left= INT_MAX;
    int high_right=INT_MAX;

    int left_sum=0;
    int right_sum=0;

    while(left >= low)
    {
        left_sum=left_sum + datas[left];
        if(left_sum < high_left)
        {
            high_left=left_sum;
            res.left_index=left;
        }
        left--;
    }

     while(right <= high)
    {
        right_sum=right_sum + datas[right];
        if(right_sum < high_right)
        {
            high_right=right_sum;
            res.right_index=right;
        }
        right++;
    }

    res.cross = high_left + high_right;

    return res;


}

index_and_cross Minimum_sub_array_sum(vector<int>&datas,int low,int high)
{
    index_and_cross sum;
    if(low==high)
    {
        sum.cross=datas[low];
        sum.left_index=low;
        sum.right_index=low;

        return sum;
    }
    else
    {
        int mid = (low+high)/2;

        index_and_cross left_cross=Minimum_sub_array_sum(datas,low,mid);
        index_and_cross right_cross=Minimum_sub_array_sum(datas,mid+1,high);
        index_and_cross cross_sum= Crossing_sum(datas,low,high,mid);

        if(left_cross.cross < cross_sum.cross && left_cross.cross < right_cross.cross )
        {
            return left_cross;
 
        }
        else if (right_cross.cross < cross_sum.cross && right_cross.cross < left_cross.cross)
        {
            return right_cross;
        }
        else{
            return cross_sum;
        }
    }
}

int main()
{
    int num, n;
    cout << "Number of datas: ";
    cin >> num;

    vector<int> datas(num);
    cout << "enter datas: ";
    for (int &data : datas)
    {
        cin >> data;
    }
 index_and_cross Minimum_subarray_sum = Minimum_sub_array_sum(datas, 0, num - 1);
    cout << "lowest sum Score: " << Minimum_subarray_sum.cross << endl;
    cout << "index range : (" << Minimum_subarray_sum.left_index << "," << Minimum_subarray_sum.right_index << ")";
}

