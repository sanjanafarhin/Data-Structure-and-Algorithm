#include <iostream>
#include <vector>

using namespace std;

void merge_sort(vector<int> &datas,int low,int high,int mid)
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
        else{
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

void merge(vector<int> &datas,int low,int high)
{
    if(low < high)
    { 
        int mid=(low+high)/2;
        merge(datas,low,mid);
        merge(datas,mid+1,high);
        merge_sort(datas,low,high,mid);

    }
}

int kth_num_max(vector<int>datas,int low,int high,int k)
{
    merge(datas,low,high);
    return datas[high-k+1];
}

int kth_num_min(vector<int>datas,int low,int high,int k)
{
    merge(datas,low,high);
    return datas[k-1];
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
    
      cout << "kth: ";
      cin >> n;

      merge(datas,0,num-1);

       for (int data : datas)
    {
        cout <<  data << " ";
    }
    cout <<"\n";
    
    int number_max =kth_num_max (datas, 0, num - 1,n);
    int number_min= kth_num_min(datas,0,num-1,n);

   cout << n << "th " << "Highest Score: " << number_max << endl;
   cout << n << "th "  << "lowest Score: " << number_min << endl;
    
}
