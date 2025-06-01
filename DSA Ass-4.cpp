#include <iostream>
using namespace std;

int q[20];
int f = -1;
int r = -1;

void enq(int temp)
{
    if (r < 19) // Prevent overflow
    {
        r = r + 1;
        q[r] = temp;
    }
    else
    {
        cout << "Queue Overflow\n";
    }
}

int dq()
{
    int temp;
    if (f < r)
    {
        f++;
        temp = q[f];
        return temp;
    }
    return -1; // return invalid value if queue is empty
}

int isempty()
{
    if (f == r)
        return 1;
    else
        return 0;
}

void DFS(int G[8][8], int v[10], int no, int start)
{
    cout << start << " ";
    v[start] = 1;
    for (int i = 0; i < no; i++)
    {
        if (G[start][i] == 1 && !v[i])
        {
            DFS(G, v, no, i);
        }
    }
}

void BFS(int G[8][8], int v[10], int no, int start)
{
    int temp;
    f = -1; // Reset queue pointers before BFS
    r = -1;
    enq(start);
    v[start] = 1;
    while (!isempty())
    {
        temp = dq();
        if (temp != -1)
        {
            cout << temp << " ";
            for (int i = 0; i < no; i++)
            {
                if (G[temp][i] == 1 && !v[i])
                {
                    enq(i);
                    v[i] = 1;
                }
            }
        }
    }
}

int main()
{
    int no;
    cout << "Enter the number of vertices: ";
    cin >> no;

    int G[8][8];
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < no; i++)
    {
        for (int j = 0; j < no; j++)
        {
            cin >> G[i][j];
        }
    }
    int ch=0;

    do
    {
        int v[10]={0};
        int start;
        cout << "Enter the starting vertex ";
        cin >> start;

        if (start < 0 || start >= no)
        {
            cout << "Invalid starting vertex.\n";
            continue;
        }

        cout << "1. DFS\n";
        cout << "2. BFS\n";
        cin >> ch;

        switch (ch)
        {
            case 1:
                cout << "DFS Traversal: ";
                DFS(G, v, no, start);
                cout << endl;
                break;
            case 2:
                cout << "BFS Traversal: ";
                BFS(G, v, no, start);
                cout << endl;
                break;
        }
    }
    while(ch>0);

    cout << endl;
    return 0;
}
