#include "bits/stdc++.h"
using namespace std;
struct info
{
    int parent;
    int destination;
    int COST;
};

/* 

Definition:
Bellman-Ford is a shortest path algorithm that finds the
minimum distance from a source vertex to all other vertices.
It supports negative edge weights and can detect negative
weight cycles.

Algorithm Steps:
1. Initialize all vertex distances to INF.
2. Set the source vertex distance to 0.
3. Relax all edges (V - 1) times. 
(we do iteration v-1 times because we know to go from 1 to other vertex we need v-1 vertex)
4. Check all edges one more time.
5. If any distance is updated, a negative weight cycle exists.
6. Otherwise, print the shortest distances.

Time Complexity:
O(V × E)

Space Complexity:
O(V)

Where:
V = Number of Vertices
E = Number of Edges

*/
vector<int> BELLMAN_FORD(vector<info> &GRAPH, int Sources, int vertex)
{
    vector<int> distance(vertex, -1e9);  //initialize distances in infinity

    distance[Sources] = 0;                //initialize the source path to begin with

    for (int i = 0; i < vertex; i++)
    {
        for (info edge : GRAPH)
        {
            int parent = edge.parent;
            int destination = edge.destination;
            int PATHCOST = edge.COST;


            /*
            Path relaxation formula:

            distance[destination] < distance[parent] + PATHCOST)
            
            */

            if (distance[parent] != -1e9 && distance[destination] < distance[parent] + PATHCOST)
            {
                if (i == vertex - 1)
                {
                    cout << "Negative cycle!!!" << endl;

                    /*
                    when the path relaxation iteration is more than v-1
                    
                    */
                    return {-1};
                }
                distance[destination] = distance[parent] + PATHCOST;
            }
        }
    }
    return distance;
}
int main()
{
    int vertex, edge, source;
    cout << "ENTER VERTEX,EDGE AND SOURCE: " << endl;
    cin >> vertex >> edge >> source;
    vector<info> GRAPH(edge);

    for (int i = 0; i < edge; i++)
    {
        cin >> GRAPH[i].parent >> GRAPH[i].destination >> GRAPH[i].COST;
    }
    vector<int> DIS = BELLMAN_FORD(GRAPH, source, vertex);

    for (int i = 0; i < vertex; i++)
    {
        if (i != source)
        {
            cout << source << "--" << "cost :" << DIS[i] << "-->" << i << endl;
        }
    }
}
