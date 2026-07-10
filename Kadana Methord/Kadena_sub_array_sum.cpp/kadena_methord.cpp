#include "bits/stdc++.h"
#include <vector>

using namespace std;

int Kadena_Method(vector<int>datas,int size)
{
    int Max_sum=datas[0];
    int sum=0;

    for(int i=0;i<size;i++)
    {
        sum=sum+datas[i];
        Max_sum=max(sum,Max_sum);
        if(sum<0)
        {
            sum=0;
        }
    }
    return Max_sum;
}

int main()
{
    int num,n;
    cout << "Number of datas: ";
    cin >> num;
    
    vector<int> datas(num);
    cout <<"enter datas: ";
    for (int &data : datas)
    {
        cin >> data;
    }
    int maximum_sub_array_sum=Kadena_Method(datas,num-1);

    cout << "longest sub array sum :" << maximum_sub_array_sum;
}
