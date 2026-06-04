#include <iostream>
#include <vector>
#include <queue>
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
    void find_shortest_path(char l1, char l2)
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
        vector<int> parent(vertices, -1);    // parent stores which node it came from
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
                    int weight = adj_matrix[node][neighbor]; // get distance between node and neighbor
                    if (weight > 0)
                    {
                        if (dist[node] + weight < dist[neighbor]) // if we find a shorter path to neighbor through node
                        {
                            dist[neighbor] = dist[node] + weight; // update distance to neighbor
                            parent[neighbor] = node;
                            pq.emplace(dist[neighbor], neighbor); // add to pq
                        }
                    }
                }
            }
        }
        if (dist[v] == INT_MAX) // no path exists
        {
            cout << "No path exists" << endl;
            return;
        }
        vector<int> path;     // vector to store path
        int current = v;      // start at final node
        while (current != -1) // while parent exists
        {
            path.push_back(current);   // push parent into path
            current = parent[current]; // backtrack
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
        {
            for (auto p : label_list)
            {
                if (p.second == path[i])
                {
                    cout << p.first;
                    break;
                }
            }
            if (i < path.size() - 1)
                cout << " -> ";
        }
        cout << endl;
        cout << "Total distance " << dist[v] << endl;
    }

private:
    vector<vector<int>> adj_matrix;
    map<char, int> label_list;
};

int main()
{
    bool running = true;
    graph grapher(0);
    char input[20];
    char labelA;
    char labelB;
    int weight;
    cout << "Commands: addV, addE, rmvV, rmvE, print, shortP" << endl;
    while (running)
    {
        cin >> input;
        if (!strcmp(input, "addV"))
        {
            cout << "Label(one char): ";
            cin >> labelA;
            grapher.add_vertex(labelA);
        }
        else if (!strcmp(input, "addE"))
        {
            cout << "Label A(one char): ";
            cin >> labelA;
            cout << "Label B(one char): ";
            cin >> labelB;
            cout << "Weight(num): ";
            cin >> weight;
            grapher.add_edge(labelA, labelB, weight);
        }
        else if (!strcmp(input, "rmvV"))
        {
            cout << "Label(one char): ";
            cin >> labelA;
            grapher.remove_vertex(labelA);
        }
        else if (!strcmp(input, "rmvE"))
        {
            cout << "Label A(one char): ";
            cin >> labelA;
            cout << "Label B(one char): ";
            cin >> labelB;
            grapher.remove_edge(labelA, labelB);
        }
        else if (!strcmp(input, "print"))
        {
            grapher.print();
        }
        else if (!strcmp(input, "shortP"))
        {
            cout << "Label A(one char): ";
            cin >> labelA;
            cout << "Label B(one char): ";
            cin >> labelB;
            grapher.find_shortest_path(labelA, labelB);
        }
        else if (!strcmp(input, "quit"))
        {
            running = false;
        }
        else
        {
            cout << "invalid" << endl;
        }
    }
    return 0;
}