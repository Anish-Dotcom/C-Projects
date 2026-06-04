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
    void add_edge(char l1, char l2, int weight)
    {
        int u = label_list[l1];
        int v = label_list[l2];
        adj_matrix[u][v] = weight;
    }
    void remove_vertex(char label)
    {
        auto pair = label_list.find(label); // find pair in map
        if (pair == label_list.end())
            return;
        int vertex = pair->second;                     // find vertex index
        adj_matrix.erase(adj_matrix.begin() + vertex); // delete row
        for (auto &row : adj_matrix)                   // delete rows
            row.erase(row.begin() + vertex);
        label_list.erase(label);
        for (auto &entry : label_list) // decrement indices
        {
            if (entry.second > vertex)
            {
                entry.second--;
            }
        }
    }
    void remove_edge(char l1, char l2)
    {
        int u = label_list[l1];
        int v = label_list[l2];
        adj_matrix[u][v] = 0;
    }
    vector<int> find_shortest_path(char l1, char l2)
    {
        int vertices = adj_matrix.size();
        int u = label_list[l1];
        int v = label_list[l2];
        priority_queue< // min heap with (distance, node) index pairs to sort by smallest distance
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>>
            pq;
        vector<int> dist(vertices, INT_MAX); // distance array with all distances set to inf
        dist[u] = 0;                         // distance from source to itself is 0
        pq.emplace(0, u);
        while (!pq.empty()) // process the queue until its empty
        {
            auto top = pq.top();        // get smallest distance
            pq.pop();                   // remove smallest dist
            int distance = top.first;   // get distance to smallest node
            int node = top.second;      // get smallest node
            if (distance <= dist[node]) // continue only if current distance is lower than chosen
            {
                for (int neighbor = 0; neighbor < vertices; neighbor++) // iterate through all neighbors of node
                {
                    int weight = adj_matrix[node][neighbor];  // get distance between node and neighbor
                    if (dist[node] + weight < dist[neighbor]) // if we find a shorter path to neighbor through node
                    {
                        dist[neighbor] = dist[node] + weight; // updata distance to neighbor
                        pq.emplace(dist[neighbor], neighbor); // add to pq
                    }
                }
            }
        }
        return dist;
    }

private:
    vector<vector<int>> adj_matrix;
    map<char, int> label_list;
};

int main()
{
    graph grapher(0);
    grapher.add_vertex('A');
    grapher.add_vertex('B');
    grapher.add_vertex('C');
    grapher.add_vertex('D');
    grapher.add_vertex('E');
    grapher.add_edge('A', 'B', 6);
    grapher.add_edge('B', 'A', 6);
    grapher.add_edge('A', 'D', 1);
    grapher.add_edge('D', 'A', 1);
    grapher.add_edge('B', 'D', 2);
    grapher.add_edge('D', 'B', 2);
    grapher.add_edge('B', 'C', 5);
    grapher.add_edge('C', 'B', 5);
    grapher.add_edge('B', 'E', 2);
    grapher.add_edge('E', 'B', 2);
    grapher.add_edge('C', 'B', 5);
    grapher.add_edge('B', 'C', 5);
    grapher.add_edge('D', 'E', 1);
    grapher.add_edge('E', 'D', 1);
    grapher.print();
    // grapher.remove_vertex('A');
    // grapher.remove_vertex('B');
    // grapher.remove_edge('A', 'B');
    vector<int> shortest_path = grapher.find_shortest_path('C', 'D');
    for (int i = 0; i < shortest_path.size(); i++)
    {
        cout << shortest_path[i];
    }
    cout << endl;
    // grapher.print();
    return 0;
}