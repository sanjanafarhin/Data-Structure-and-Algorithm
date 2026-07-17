#include "bits/stdc++.h"

using namespace std;

struct act
{
    int start;
    int end;
};

bool compare (act act1, act act2)
{
  return act1.end <act2.end;
}

void Activity_selection(vector <act> &durations)
{
    sort (durations.begin(),durations.end(),compare);
    int selected=1;
    int size= durations.size();
    int n=0;
    
    vector <act> selected_time;
    int last=0;
    selected_time.push_back(durations[last]);
    for(int i=1;i<size;i++)
    {
        if(durations[last].end < durations[i].start)
        {
            selected++;
            selected_time.push_back(durations[i]);
            last=i;
        }

    }
    cout << " selected : " << selected << endl;

    for (act t : selected_time)
    {
        cout << " ( start :" << t.start << " end : " << t.end << ")"; 
    }


}

int main()
{
    vector <act> times ={ {2,3},{3,7},{9,7},{5,6},{8,10}};
    Activity_selection(times);


    

}