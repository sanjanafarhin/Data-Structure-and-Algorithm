#include <iostream>
#include <vector>
#include<algorithm>


using namespace std;


struct product
{
    double weight;
    double price;
    double price_per_weight;

};

bool compare(product one, product two)
{
  double com1=one.price_per_weight ;
  double com2=two.price_per_weight ;

  return com1 > com2;
}

double Knapsack(vector<product> &items, int capacity)
{
    sort(items.begin(),items.end(),compare);

    double total_profit=0.0;

    for (product &item : items)
    {
        if(capacity >= item.weight)
        {
            total_profit=item.price + total_profit;
            capacity=capacity-item.weight;
        }
        else{
            total_profit=(capacity* item.price_per_weight)+total_profit;

            capacity=0;

            break;
        }
    }

    return total_profit;

}
int main()
{
    int n,capacity;
    cout << "enter the number of items: " ;
    cin >> n;
    vector <product> datas(n);

    cout << "enter the amount of capacity: " ;
    cin >> capacity;
    int N=1;


    for(product &index : datas)
    {
        cout << "item No " << N << " weight :" <<endl;
        cin >> index.weight;

        cout << "item No " << N << " price :" <<endl;
        cin >> index.price;

        index.price_per_weight = index.price/ index.weight;

        N++;
    }
    double PROFIT =Knapsack(datas,capacity);

    cout << "Total gained : " << PROFIT;

    return 0;

}
