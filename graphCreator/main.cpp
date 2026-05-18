#include <iostream>
#include <vector>
#include <map>
using namespace std;

class graph
{
public:
    graph(int n)
    {
        adj_matrix = vector<vector<int>>(
            n, vector<int>(n, 0)); // initialize a 2D vector
    }
    void print()
    {
        for (auto pair : label_list) // iterate through map
        {
            cout << pair.first << " ";
        }
        cout << endl;
        for (int i = 0; i < adj_matrix.size(); i++) // iterate through 2D vector
        {
            for (int j = 0; j < adj_matrix.size(); j++)
            {
                cout << adj_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void add_vertex(char label)
    {
        int vertices = adj_matrix.size();
        label_list[label] = vertices;
        for (int i = 0; i < vertices; i++)
        {
            adj_matrix[i].push_back(0);
        }
        adj_matrix.push_back(vector<int>(vertices + 1, 0));
    }
    void add_edge(char l1, char l2)
    {
        int u = label_list[l1];
        int v = label_list[l2];
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1;
    }
    void remove_vertex()
    {
        }

private:
    vector<vector<int>>
        adj_matrix;
    map<char, int> label_list;
};

int main()
{
    graph grapher(0);
    grapher.add_vertex('A');
    grapher.add_vertex('B');
    grapher.add_vertex('C');
    grapher.add_edge('A', 'B');
    grapher.print();
    return 0;
}