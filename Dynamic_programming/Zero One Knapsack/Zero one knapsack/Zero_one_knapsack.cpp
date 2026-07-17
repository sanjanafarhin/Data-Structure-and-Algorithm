#include "bits/stdc++.h"

using namespace std;

struct item_data
{
    int length;
    int value;
};

int main ()
{
    int items_amount=4;

   item_data PRODUCTS[items_amount]={{1,2},{2,5},{3,7},{4,8}};

   int capacity;
    cout << "CAPACITY (KG) :";
    cin >> capacity;
    cout << "\n";

    int DP_TABLE[items_amount][capacity+1];
    DP_TABLE[items_amount][0]={0};
    DP_TABLE[0][capacity]={0};

    for (int i=1;i<=items_amount;i++)
    {

        for (int j=1; j<=capacity;j++)
        {
            if (PRODUCTS[i-1].length <=j)
            {
                DP_TABLE[i][j]=max(PRODUCTS[i-1].value+DP_TABLE[i-1][j-PRODUCTS[i-1].length],DP_TABLE[i-1][j]);
            }
            else
            {
                DP_TABLE[i][j]=DP_TABLE[i-1][j];
            }
        }
    }

    cout << "profit : " << DP_TABLE[items_amount][capacity];


}
#include "bits/stdc++.h"

using namespace std;

struct item_data
{
    int length;
    int value;
};

int main ()
{
    int items_amount=4;

   item_data PRODUCTS[items_amount]={{1,2},{2,5},{3,7},{4,8}};

   int capacity;
    cout << "CAPACITY (KG) :";
    cin >> capacity;
    cout << "\n";

    int DP_TABLE[items_amount][capacity+1];
    DP_TABLE[items_amount][0]={0};
    DP_TABLE[0][capacity]={0};

    for (int i=1;i<=items_amount;i++)
    {

        for (int j=1; j<=capacity;j++)
        {
            if (PRODUCTS[i-1].length <=j)
            {
                DP_TABLE[i][j]=max(PRODUCTS[i-1].value+DP_TABLE[i-1][j-PRODUCTS[i-1].length],DP_TABLE[i-1][j]);
            }
            else
            {
                DP_TABLE[i][j]=DP_TABLE[i-1][j];
            }
        }
    }

    cout << "profit : " << DP_TABLE[items_amount][capacity];


}
