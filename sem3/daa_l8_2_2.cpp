// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// BFS search, Test for Bipartiteness, Cycle testing
// and test for connectedness.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int nodes = 5;

class BFS
{
private:
    int edges;

public:
    BFS(int Nodes, int Edges)
    {
        edges = Edges;
    }

    // BFS code
    bool Bipartite(int adjMat[][nodes + 1], int s, int colour[])
    {
        colour[s] = 1;
        queue<int> q;
        q.push(s);

        int v;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            if (adjMat[f][f] == 1)
                return false;

            for (v = 1; v <= nodes; ++v)
            {
                if (adjMat[f][v] && colour[v] == -1)
                {
                    colour[v] = 1 - colour[f];
                    q.push(v);
                }

                else if (adjMat[f][v] && colour[v] == colour[f])
                    return false;
            }
        }
        cout << endl;

        return true;
    }

    // Creating adjacency list
    bool bfsSearch()
    {
        int edge1, edge2, i;
        int adjMat[nodes + 1][nodes + 1];

        for (int i = 0; i <= nodes; i++)
        {
            for (int j = 0; j <= nodes; j++)
            {
                adjMat[i][j] = 0;
            }
        }

        // Filling adjancy list
        for (i = 0; i < edges; i++)
        {
            cout << "Enter edges: " << endl;
            cin >> edge1 >> edge2;
            adjMat[edge1][edge2] = 1;
            adjMat[edge2][edge1] = 1;
        }

        /*
        for (int i = 0; i <= nodes;i++)
        {
            for (int j = 0; j <= nodes; j++)
            {
                cout << " " << adjMat[i][j];
            }
            cout << endl;
        }
        */

        int colour[nodes];
        for (i = 0; i < nodes; ++i)
            colour[i] = -1;

        // This code is to handle disconnected graoh
        for (i = 0; i < nodes; i++)
        {
            if (colour[i] == -1)
                if (Bipartite(adjMat, i, colour) == false)
                    return false;
        }

        return true;
    }
};

int main()
{
    int _nodes, _edges;
    cout << "Enter the number of Nodes and Edges: " << endl;
    cin >> _nodes >> _edges;

    BFS b1(_nodes, _edges);
    if (b1.bfsSearch() == true)
    {
        cout << "The graph is a Bipartite" << endl;
    }
    else
        cout << "The graph is not a Bipartite" << endl;

    cout << endl;

    return 0;
}