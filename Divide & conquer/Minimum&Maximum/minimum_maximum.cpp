#include <iostream>
#include <vector>

using namespace std;

struct score
{
    int min_score;
    int max_score;
    int min_index;
    int max_index;
};

score compare(score left,score right)
{   
    score result; 
    if(left.max_score < right.max_score)
    {
        result.max_score=right.max_score;
        result.max_index=right.max_index;

    }
    else{
       result.max_score=left.max_score;
        result.max_index=left.max_index; 
    }

    if(left.min_score<right.min_score)
    {
        result.min_score=left.min_score;
        result.min_index=left.min_index;
    }
    else
    {
        result.min_score=right.min_score;
        result.min_index=right.min_index;
    }

    return result;
}
score sub_min_max(vector<int>&number, int low, int high,int index)
{
    score res;
    if (low == high)
    {
        res.max_score = number[low];
        res.min_score = number[low];
        res.max_index = index;
        res.min_index = index;

        return res;
    }

    if (low + 1 == high)
    {
        if (number[low] < number[high])
        {
            res.max_score = number[high];
            res.min_score = number[low];
            res.max_index = index;
            res.min_index = index;
        }
        else
        {
            res.max_score = number[low];
            res.min_score = number[high];
            res.max_index = index;
            res.min_index = index;
        }
        return res;
    }

    int mid=(low+high)/2;
    score left=sub_min_max(number,low,mid,index);
    score right=sub_min_max(number,mid+1,high,index);

    res=compare(left,right);
    return res;
}

score main_min_max(vector<vector<int>>datas,int low,int high)
{
    score finalresult;
    if(low==high)
    {
        finalresult=sub_min_max(datas[low],0,(datas[low].size()-1),low);
        return finalresult;
    }
    if(low+1==high)
    {
        score var_1=sub_min_max(datas[low],0,(datas[low].size()-1),low);
        score var_2=sub_min_max(datas[high],0,(datas[high].size()-1),high);

        if(var_1.max_score < var_2.max_score)
        {
            finalresult.max_score=var_2.max_score;
            finalresult.max_index=var_2.max_index;
        }
        else{
            finalresult.max_score=var_1.max_score;
            finalresult.max_index=var_1.max_index;
        }

         if(var_1.min_score > var_2.min_score)
        {
            finalresult.min_score=var_2.min_score;
            finalresult.min_index=var_2.min_index;
        }
        else{
            finalresult.min_score=var_1.min_score;
            finalresult.min_index=var_1.min_index;
        }

        return finalresult;
    }

    int mid=(low+high)/2;
    score left=main_min_max(datas,low,mid);
    score right=main_min_max(datas,mid+1,high);

    finalresult=compare(left,right);
    return finalresult;


}


int main()
{
    int n, m, num;
    cout << "enter the number of row:" << endl;
    cin >> n;
    cout << "enter the number of column:" << endl;
    cin >> m;

    vector<vector<int>> section(n);

    for (int i = 0; i < n; i++)
    {
        section[i].resize(m);
        cout << "enter the numbers in row : " << i;

        for (int j = 0; j < m; j++)
        {
            cin >> section[i][j];
        }
    }

    int size = section.size();
    score ans= main_min_max(section, 0, size - 1);
    
    cout << "\nHighest Score: " << ans.max_score;
    cout << " (Department: " << ans.max_index << ")" << endl;

    cout << "Lowest Score: " << ans.min_score;
    cout << " (Department: " << ans.min_index << ")" << endl;
}