#include <iostream>
using namespace std;

#define MAX_VERTICES 10
#define MAX_EDGES 20

struct Edge {
int u, v, weight;
};

int visited[MAX_VERTICES];
Edge edges[MAX_EDGES];

void prims(int v, int nv, int visit[10], int cost[5][5])
{
    int sum = 0, p, temp, min, m, n;
    visit[v] = 1;
    for (int k = 0; k < nv - 1; k++)
    {
        temp = 999;
        for (int i = 0; i < nv; i++)
        {
            if (visit[i] == 1)
            {
                min = 999;
                for (int j = 0; j < nv; j++)
                {
                    if (cost[i][j] != 0)
                    {
                        if (min >= cost[i][j] && visit[j] == 0)
                        {
                            min = cost[i][j];
                            p = j;
                        }
                    }
                }
                if (min < temp)
                {
                    temp = min;
                    m = i;
                    n = p;
                }
            }
        }
        sum += cost[m][n];
        cout << "\nSelected edge is between " << m << " to " << n << " with cost " << cost[m][n];
        visit[m] = 1;
        visit[n] = 1;
    }
    cout << "\nMinimum weight is: " << sum << endl;
}


void kruskal(int vertices, int edges_count)
{
    int mst_weight = 0;
    int mst_edges = 0;
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }
    cout << "Edges in the MST:\n";
    for (int i = 0; i < edges_count; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        if (!visited[u] || !visited[v])
        {
            visited[u] = visited[v] = 1;
            cout << u << " - " << v << ": " << weight << endl;
            mst_weight += weight;
            mst_edges++;
        }
        if (mst_edges == vertices - 1)
        break;
    }
    cout << "Total weight of MST: " << mst_weight << endl;
}


int main()
{
    int choice;
    int nv, ne;
    int cost[5][5];
    int visit[10] = {0};
    cout << "Enter the number of vertices : ";
    cin >> nv;
    cout << "Enter the cost matrix :\n";
    for (int i = 0; i < nv; i++)
    {
        for (int j = 0; j < nv; j++)
        {
            cin >> cost[i][j];
        }
    }
    cout << "Enter the number of edges for Kruskal's algorithm: ";
    cin >> ne;
    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < ne; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    cout << "Choose algorithm:\n";
    cout << "1. Prim's Algorithm\n";
    cout << "2. Kruskal's Algorithm\n";
    cin >> choice;

    switch (choice)
    {
        case 1:
            cout << "Prim's Algorithm:\n";
            prims(0, nv, visit, cost);
            break;
        case 2:
            cout << "Kruskal's Algorithm:\n";
            kruskal(nv, ne);
            break;
        default:
            cout<<"Invalid choice\n";
    }
    return 0;
}
