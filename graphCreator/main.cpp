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
    void remove_vertex(char label)
    {
        auto pair = label_list.find(label); // find pair in map
        if (pair == label_list.end())
            return;
        int vertex = pair->second; // find vertex index
        int vertices = adj_matrix.size();
        adj_matrix.erase(adj_matrix.begin() + vertex); // delete col
        for (auto &row : adj_matrix)                   // delete rows
        {
            row.erase(row.begin() + vertex);
        }
        label_list.erase(label);
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
    grapher.add_vertex('D');
    grapher.add_edge('A', 'B');
    grapher.add_edge('A', 'C');
    grapher.add_edge('B', 'D');
    grapher.print();
    grapher.remove_vertex('A');
    grapher.remove_vertex('B');
    grapher.print();
    return 0;
}