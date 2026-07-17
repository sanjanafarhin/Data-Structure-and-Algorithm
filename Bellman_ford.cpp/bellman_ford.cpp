#include "bits/stdc++.h"
 using namespace std;
 struct info
 {
     int parent;
     int destination;
     int COST;
 };
 vector<int>BELLMAN_FORD(vector<info>&GRAPH, int Source, int vertex)
 {
     vector<int>distance(vertex,-1e9);
     distance[Source]=0;

     for (int i=0;i<vertex;i++)
     {
         for(info edge : GRAPH)
         {
             int parent=edge.parent;
             int destination=edge.destination;
             int PATHCOST=edge.COST;

             if (distance[parent]!=-1e9 && distance[destination] < distance[parent]+PATHCOST)
             {
                 if(i==vertex-1)
                 {
                     cout << "Negative cycle!!!" <<endl;
                     return {-1};
                 }
                 distance[destination]=distance[parent]+PATHCOST;
             }
         }
     }
     return distance;

 }
 int main()
 {
     int vertex,edge,source;
     cout << "ENTER VERTEX,EDGE AND SOURCE: "<<endl;
     cin>>vertex>>edge>>source;
     vector<info>GRAPH(edge);

     for(int i=0;i<edge;i++)
     {
         cin>>GRAPH[i].parent>>GRAPH[i].destination>>GRAPH[i].COST;
     }
     vector<int>DIS=BELLMAN_FORD(GRAPH,source,vertex);

     for (int i=0;i<vertex;i++)
     {
         if(i != source)
         {
             cout << source << "--" << "cost :" <<DIS[i] <<"-->"<< i <<endl;
         }
     }

 }
