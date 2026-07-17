#include "bits/stdc++.h"

using namespace std;

struct data
{
    int count;
    vector <int> individual_count;
};

int main ()
{
    int coin_number,amount;

    cout << "ENTER COIN NUMBER :" <<endl;
    cin >> coin_number;

    cout << "ENTER AMOUNT : " <<endl;
    cin >> amount;

    vector <int> coin_set(coin_number);
    vector <data> DP(amount+1);

    cout << "COIN SET ENTRY: "<<endl;
    for (int &coin : coin_set)
    {
        cin >> coin;
    }

    for (int i=0; i<=amount ;i++)
    {
        DP[i].count=1e9;
    }

    DP[0].count=0;

    for (int i=0; i< coin_number ; i++)
    {
        for (int j=coin_set[i];j<=amount;j++)
        {
            if (DP[j].count >= DP[j-coin_set[i]].count+1)
            {
                DP[j].count=DP[j-coin_set[i]].count+1;
                DP[j].individual_count= DP[j-coin_set[i]].individual_count;
                DP[j].individual_count.push_back(coin_set[i]);
            }
        }
    }

    cout << "ALL COINS ARE :";
    for (int coins : DP[amount].individual_count)
    {
        cout << coins << " ";
    }
    cout << "MINIMUM COINS :" << DP[amount].count;
}
