#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;

// Graph structure
class Graph {
public:
    int V;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;
    vector<vector<pair<int, int>>> weightedAdjList;

    Graph(int V) : V(V) {
        adjList.resize(V);
        adjMatrix.assign(V, vector<int>(V, 0));
        weightedAdjList.resize(V);
    }

    // Add edges to adjacency list
    void addEdgeList(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Add edges to adjacency matrix
    void addEdgeMatrix(int u, int v, int weight = 1) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    // Add weighted edges
    void addWeightedEdge(int u, int v, int weight) {
        weightedAdjList[u].emplace_back(v, weight);
        weightedAdjList[v].emplace_back(u, weight);
    }

    // ---------------- Task 1: Display Graph ----------------
    void displayAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int v : adjList[i]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void displayAdjMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // ---------------- Task 2: DFS Recursive ----------------
    void DFSRecursiveUtil(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                DFSRecursiveUtil(neighbor, visited);
            }
        }
    }

    void DFSRecursive(int start) {
        vector<bool> visited(V, false);
        cout << "DFS Recursive Traversal: ";
        DFSRecursiveUtil(start, visited);
        cout << endl;
    }

    // ---------------- Task 3: BFS ----------------
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
        cout << endl;
    }

    // ---------------- Task 4: Detect Cycles (Directed) ----------------
    bool detectCycleDirectedUtil(int v, vector<bool>& visited, vector<bool>& recStack) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor] && detectCycleDirectedUtil(neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }

        recStack[v] = false;
        return false;
    }

    bool detectCycleDirected() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i] && detectCycleDirectedUtil(i, visited, recStack))
                return true;
        }
        return false;
    }

    // ---------------- Task 5: Dijkstra ----------------
    void Dijkstra(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        set<pair<int, int>> s;
        s.insert({ 0, src });

        while (!s.empty()) {
            int u = s.begin()->second;
            s.erase(s.begin());

            for (const auto& pair : weightedAdjList[u]) {
                int v = pair.first;
                int weight = pair.second;

                if (dist[u] + weight < dist[v]) {
                    s.erase({ dist[v], v });
                    dist[v] = dist[u] + weight;
                    s.insert({ dist[v], v });
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    // ---------------- Task 6: Connected Components ----------------
    void connectedComponents() {
        vector<bool> visited(V, false);
        int componentId = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                componentId++;
                cout << "Component " << componentId << ": ";
                DFSRecursiveUtil(i, visited);
                cout << endl;
            }
        }
    }

    // ---------------- Task 7: Bridges ----------------
    void findBridgesUtil(int u, vector<bool>& visited, vector<int>& disc, vector<int>& low, vector<int>& parent) {
        static int time = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adjList[u]) {
            if (!visited[v]) {
                parent[v] = u;
                findBridgesUtil(v, visited, disc, low, parent);

                low[u] = min(low[u], low[v]);

                if (low[v] > disc[u]) {
                    cout << "Bridge found: " << u << " - " << v << endl;
                }
            }
            else if (v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    void findBridges() {
        vector<bool> visited(V, false);
        vector<int> disc(V, -1), low(V, -1), parent(V, -1);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                findBridgesUtil(i, visited, disc, low, parent);
            }
        }
    }

    // ---------------- Task 8: Community Detection ----------------
    void detectCommunities() {
        cout << "Community detection (clustering based on BFS):\n";
        connectedComponents();
    }

    // ---------------- Task 9: PageRank ----------------
    void pageRank(int iterations = 10, double damping = 0.85) {
        vector<double> rank(V, 1.0 / V);
        vector<int> outDegree(V, 0);

        for (int i = 0; i < V; i++) {
            outDegree[i] = adjList[i].size();
        }

        for (int iter = 0; iter < iterations; iter++) {
            vector<double> newRank(V, (1.0 - damping) / V);
            for (int u = 0; u < V; u++) {
                for (int v : adjList[u]) {
                    newRank[v] += damping * rank[u] / outDegree[u];
                }
            }
            rank = newRank;
        }

        cout << "PageRank values:\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << rank[i] << endl;
        }
    }

    // Placeholder task
    void placeholderTask(const string& taskName) {
        cout << "Executing " << taskName << "...\n";
    }
};

// ---------------- MENU ----------------
void menu() {
    Graph g(6); // Example graph with 6 nodes

    g.addEdgeList(0, 1);
    g.addEdgeList(1, 2);
    g.addEdgeList(2, 3);
    g.addEdgeList(3, 4);
    g.addWeightedEdge(0, 1, 5);
    g.addWeightedEdge(1, 2, 3);

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display Adjacency List\n";
        cout << "2. Perform DFS\n";
        cout << "3. Perform BFS\n";
        cout << "4. Detect Cycles (Directed)\n";
        cout << "5. Dijkstra\n";
        cout << "6. Connected Components\n";
        cout << "7. Find Bridges\n";
        cout << "8. Community Detection\n";
        cout << "9. PageRank\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.displayAdjList();
            break;
        case 2:
            g.DFSRecursive(0);
            break;
        case 3:
            g.BFS(0);
            break;
        case 4:
            cout << (g.detectCycleDirected() ? "Cycle detected.\n" : "No cycle detected.\n");
            break;
        case 5:
            g.Dijkstra(0);
            break;
        case 6:
            g.connectedComponents();
            break;
        case 7:
            g.findBridges();
            break;
        case 8:
            g.detectCommunities();
            break;
        case 9:
            g.pageRank();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            g.placeholderTask("Task " + to_string(choice));
            break;
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}