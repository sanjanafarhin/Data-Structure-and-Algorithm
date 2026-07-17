#include <bits/stdc++.h>

using namespace std;

struct Tree
{
    vector<int> mst;
    int TOTALCOST;
};

/*
=========================================================
                  Prim's Algorithm
=========================================================

Definition:
Prim's Algorithm is a greedy algorithm used to find the
Minimum Spanning Tree (MST) of a connected, weighted,
undirected graph. It starts from any vertex and repeatedly
adds the minimum weight edge that connects a visited vertex
to an unvisited vertex.

Algorithm Steps:
1. Choose any vertex as the starting vertex.
2. Mark the source vertex as visited.
3. Add all adjacent edges of the source to a priority queue.
4. Select the edge with the minimum weight.
5. If the destination vertex is not visited:
   - Add the edge to the MST.
   - Mark the destination as visited.
   - Add all adjacent edges of that vertex.
6. Repeat until all vertices are visited.
7. Print the MST edges and total cost.

Time Complexity:
O(E log V)

Space Complexity:
O(V + E)

Where:
V = Number of Vertices
E = Number of Edges
=========================================================
*/

Tree Prims(vector<vector<int> > data_graph, int start, int vertex)
{
    // Priority Queue (Edge Cost, (Parent, Destination))
    priority_queue<
        pair<int, pair<int, int> >,
        vector<pair<int, pair<int, int> > >,
        greater<pair<int, pair<int, int> > >
    > EdgeContainer;

    // Visited Array
    vector<bool> VISITED(vertex, false);

    // Parent Array
    vector<int> Parents(vertex, 0);

    int Total = 0;

    VISITED[start] = true;
    Parents[start] = start;

    // Push all edges from the source vertex
    for (int i = 0; i < vertex; i++)
    {
        if (data_graph[start][i] > 0)
        {
            EdgeContainer.push(
                make_pair(data_graph[start][i], make_pair(start, i))
            );
        }
    }

    while (!EdgeContainer.empty())
    {
        pair<int, pair<int, int> > current = EdgeContainer.top();
        EdgeContainer.pop();

        int Edge_Cost = current.first;
        int parent = current.second.first;
        int destination = current.second.second;

        if (!VISITED[destination])
        {
            VISITED[destination] = true;
            Parents[destination] = parent;
            Total += Edge_Cost;

            start = destination;

            // Push adjacent edges of the new vertex
            for (int i = 0; i < vertex; i++)
            {
                if (data_graph[start][i] > 0)
                {
                    EdgeContainer.push(
                        make_pair(data_graph[start][i], make_pair(start, i))
                    );
                }
            }
        }
    }

    Tree res;
    res.mst = Parents;
    res.TOTALCOST = Total;

    return res;
}

int main()
{
    cout << "ENTER THE NUMBER OF VERTICES: ";
    int vertex;
    cin >> vertex;

    vector<vector<int> > Graph(vertex, vector<int>(vertex));

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < vertex; i++)
    {
        for (int j = 0; j < vertex; j++)
        {
            cin >> Graph[i][j];
        }
    }

    cout << "Enter the source vertex: ";
    int source;
    cin >> source;

    Tree res = Prims(Graph, source, vertex);

    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 0; i < vertex; i++)
    {
        if (i != res.mst[i])
        {
            cout << res.mst[i] << " --> " << i << endl;
        }
    }

    cout << "\nTotal Cost: " << res.TOTALCOST << endl;

    return 0;
}