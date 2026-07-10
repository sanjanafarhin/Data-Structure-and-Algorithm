#include "bits/stdc++.h"

using namespace std;

struct sum_index
{

    int high_sum;
    int left_index;
    int right_index;
};

sum_index crossing_sum(vector<int> datas, int low, int high, int mid)
{
    sum_index res;
    int left = mid;
    int right = mid + 1;
    int left_sum = 0;
    int right_sum = 0;
    int high_left_sum = INT_MIN; // to avoid any problem while having negative number as large
    int high_right_sum = INT_MIN;

    // left sum
    while (left >= low)
    {
        left_sum = left_sum + datas[left];

        if (left_sum > high_left_sum)
        {
            high_left_sum = left_sum;
            res.left_index = left;
        }

        left--;
    }

    // right sum
    while (right <= high)
    {
        right_sum = right_sum + datas[right];
        if (right_sum > high_right_sum)
        {
            high_right_sum = right_sum;
            res.right_index = right;
        }
        right++;
    }

    res.high_sum = high_left_sum + high_right_sum;
    return res;
}

sum_index Maximum_sub_array_sum(vector<int> datas, int low, int high)
{
    sum_index res;
    int cross;
    if (low == high)
    {
        res.high_sum = datas[low];
        res.left_index = low;
        res.right_index = low;
        return res;
    }
    else
    {
        int mid = (high + low) / 2;
        sum_index left = Maximum_sub_array_sum(datas, low, mid);       // left cross sum
        sum_index right = Maximum_sub_array_sum(datas, mid + 1, high); // right cross sum
        sum_index crossing_sums = crossing_sum(datas, low, high, mid); // cross sum

        if (left.high_sum > crossing_sums.high_sum && left.high_sum > right.high_sum)
        {
            return left;
        }
        else if (right.high_sum > crossing_sums.high_sum && right.high_sum > left.high_sum)
        {
            return right;
        }
        else
        {
            return crossing_sums;
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
    sum_index maximum_sum_index = Maximum_sub_array_sum(datas, 0, num - 1);
    cout << "Highest sum Score: " << maximum_sum_index.high_sum << endl;
    cout << "index range : (" << maximum_sum_index.left_index << "," << maximum_sum_index.right_index << ")";
}
