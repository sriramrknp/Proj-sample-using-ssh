// Group 13
// CS20B1107, CHEERLA SRIRAM REDDY
// CS20B1111, PISARA THARAK
// CS20B1038, DADI PRANAYSAI

// DFS search, Test for Bipartiteness, Cycle testing
// and test for connectedness.
 
#include <iostream>
#include <vector>
using namespace std;

vector<bool> visited(100, false);

class DFS
{
private:
    int nodes, edges;
    int miss_edge, tree_test;

public:
    DFS(int Nodes, int Edges)
    {
        nodes = Nodes;
        edges = Edges;
        miss_edge = 0;
        tree_test = 0;
    }

    // DFS code
    void dfs(vector<int> adjList[], int s)
    {
        for (auto v : adjList[s])
        {
            if (!visited[v])
            {
                visited[v] = true;
                cout << " " << v;
                miss_edge++;
                dfs(adjList, v);
            }
        }
        tree_test++;
    }

    // Creating adjacency list
    void dfsSearch()
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

        visited[start_node] = true;
        cout << " " << start_node;
        dfs(adjList, start_node);

        if ((edges - (miss_edge - 1)) > 0)
            cout << endl
                 << "There exits cyclicity" << endl;
        else
            cout << endl
                 << "No cyclicity exits" << endl;

        if (tree_test == 1)
            cout << endl
                 << "Graph is connected" << endl;
        else
            cout << endl
                 << "Graph is not connected" << endl;
    }
};

int main()
{
    int _nodes, _edges;
    cout << "Enter the number of Nodes and Edges: " << endl;
    cin >> _nodes >> _edges;

    DFS b1(_nodes, _edges);
    b1.dfsSearch();
    cout << endl;

    return 0;
}