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
 

vector<bool> visited(100, false);

class BFS
{
private:
    int nodes, edges;
    int count, tree_test;

public:
    BFS(int Nodes, int Edges)
    {
        nodes = Nodes;
        edges = Edges;
        count = 0;
        tree_test = 0;
    } 

    // BFS code
    void bfs(vector<int> adjList[], int u)
    {
        queue<int> q;

        q.push(u);
        visited[u] = true;

        if (tree_test == 0)
            cout << "The BFS is: " << endl;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            cout << f << " ";
            count++;

            // Enqueue all adjacent of f and mark them visited
            for (auto i = adjList[f].begin(); i != adjList[f].end(); i++)
            {
                if (!visited[*i])
                {
                    q.push(*i);
                    visited[*i] = true;
                }
            }
        }

        tree_test++;
    }

    // Creating adjacency list
    void bfsSearch()
    {
        int edge1, edge2;
        vector<int> adjList[nodes + 1];

        // Filling adjancy list
        for (int i = 0; i < edges; i++)
        {
            cout << "Enter edges: " << endl;
            cin >> edge1 >> edge2;
            adjList[edge1].push_back(edge2);
            adjList[edge2].push_back(edge1);
        }

        int start_node;
        cout << "Enter the start node: " << endl;
        cin >> start_node;

        for (int i = start_node; i < nodes; i++)
        {
            if (!visited[i])
                bfs(adjList, i);
        }

        if (tree_test == 1)
            cout << endl
                 << "Graph is connected" << endl;
        else
            cout << endl
                 << "Graph is not connected" << endl;

        if ((edges - (count - 1)) > 0)
        {
            cout << endl
                 << "There exists a cyclicity" << endl;
        }
        else
        {
            cout << endl
                 << "No cycle exits" << endl;
        }
    }
};

int main()
{
    int _nodes, _edges;
    cout << "Enter the number of Nodes and Edges: " << endl;
    cin >> _nodes >> _edges;

    BFS b1(_nodes, _edges);
    b1.bfsSearch();

    cout << endl;

    return 0;
}