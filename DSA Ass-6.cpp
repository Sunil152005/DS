#include <iostream>
#include <climits>
using namespace std;

#define MAX_VERTICES 5 // Change this as needed

int choose(int dist[], int visited[]);
void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src)
{
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < MAX_VERTICES - 1; count++)
    {
        int u = choose(dist, visited);
        visited[u] = 1;
        for (int v = 0; v < MAX_VERTICES; v++)
        {
            if (!visited[v] && graph[u][v]!=0 && dist[u]!=INT_MAX && dist[u]+graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < MAX_VERTICES; i++)
    {
        cout << i << "\t" << dist[i] << endl;
    }
}


int choose(int dist[], int visited[])
{
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < MAX_VERTICES; v++)
    {
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}


int main()
{
    int graph[MAX_VERTICES][MAX_VERTICES];
    cout << "Enter the adjacency matrix:\n";

    for (int i = 0; i < MAX_VERTICES; i++)
    for (int j = 0; j < MAX_VERTICES; j++)
    cin >> graph[i][j];

    int src;
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra(graph, src);

    return 0;
}
