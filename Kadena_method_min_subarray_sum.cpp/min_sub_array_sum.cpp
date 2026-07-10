#include "bits/stdc++.h"
#include<vector>

using namespace std;

int Kadena_Method(vector<int>datas,int size)
{
    int min_sum=datas[0];
    int sum=datas[0];

    for(int i=0;i<size;i++)
    {
        sum=sum+datas[i];
        min_sum=min(sum,min_sum);
        sum=min(datas[i],sum);
        min_sum=min(min_sum,sum);
    }
    return min_sum;
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
    int maximum_sub_array_sum=Kadena_Method(datas,num);

    cout << "longest sub array sum :" << maximum_sub_array_sum;
}
