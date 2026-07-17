#include "bits/stdc++.h"

using namespace std;

struct Tree
{
    vector<int> MST;
    int TOTALCOST;

};

Tree Prims(vector<vector<int>>data_graph, int start, int vertex)
{
    //creating priority queue
    priority_queue < pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > EdgeContainer;

    //VISITED ARRAY
    vector<bool>VISITED(vertex,false);

    //PARENTS
    vector<int>Parents(vertex,0);

    int Total=0;

    VISITED[start]=true;
    Parents[start]=start;

    for (int i=0; i<vertex; i++)
    {
        if(data_graph[start][i] > 0)
        {
            int Edge_Cost= data_graph[start][i];
            int parent = start;
            int destination = i;

            EdgeContainer.emplace(Edge_Cost, make_pair(parent,destination));
        }
    }

    while(!EdgeContainer.empty())
    {
        auto [Edge_Cost,edge]=EdgeContainer.top();
        int parent=edge.first;
        int destination=edge.second;

        if(VISITED[destination]==false)
        {
            VISITED[destination]=true;
            Parents[destination]=parent;
            Total+=Edge_Cost;
            start=destination;
            EdgeContainer.pop();

            for (int i=0; i<vertex; i++)
            {
                if(data_graph[start][i] > 0)
                {
                    int Edge_Cost= data_graph[start][i];
                    int parent = start;
                    int destination = i;

                    EdgeContainer.emplace(Edge_Cost, make_pair(parent,destination));
                }
            }
        }
        else
        {
            EdgeContainer.pop();
        }


    }

    Tree res;
    res.MST=Parents;
    res.TOTALCOST=Total;

    return res;
}

int main()
{
    cout << "ENTER THE NUMBER OF VERTEXES:" <<endl;
    int vertex;
    cin >> vertex;

    vector<vector<int>>Graph(vertex,vector<int>(vertex));
    for (int i=0; i<vertex; i++)
    {
        for(int j=0; j<vertex; j++)
        {
            cin >> Graph[i][j];
        }
    }

    int source;
    cout<< "source: " <<endl;
    cin >> source;
    Tree res = Prims(Graph,source,vertex);
    for(int i = 0; i < vertex; i++)
    {
        if(i != res.MST[i])
        {
            cout << res.MST[i] << " --> " << i << endl;
        }
    }

    cout << "Total cost : " << res.TOTALCOST;
}
