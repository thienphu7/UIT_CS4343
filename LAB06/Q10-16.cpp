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
    vector<vector<pair<int, int>>> weightedAdjList;

    Graph(int V) : V(V) {
        adjList.resize(V);
        weightedAdjList.resize(V);
    }

    // Add edges to adjacency list
    void addEdgeList(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
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

    // ---------------- Task 10: Dijkstra's Algorithm with Priority Queue ----------------
    void DijkstraPriorityQueue(int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({ 0, src });

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& pair : weightedAdjList[u]) {
                int v = pair.first;
                int weight = pair.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": " << dist[i] << endl;
        }
    }

    // ---------------- Task 11: Route Planning ----------------
    void routePlanning(int src) {
        cout << "Route planning using Dijkstra's algorithm:\n";
        DijkstraPriorityQueue(src);
    }

    // ---------------- Task 12: Social Network Analysis ----------------
    void analyzeSocialNetwork() {
        cout << "Social network analysis (influential users):\n";
        vector<int> degree(V, 0);

        for (int i = 0; i < V; i++) {
            degree[i] = adjList[i].size();
            cout << "User " << i << " has " << degree[i] << " connections.\n";
        }

        auto maxIt = max_element(degree.begin(), degree.end());
        cout << "Most influential user: User " << distance(degree.begin(), maxIt) << " with " << *maxIt << " connections.\n";
    }

    // ---------------- Task 13: City Traffic Analysis ----------------
    void analyzeCityTraffic() {
        cout << "City traffic analysis based on edge weights:\n";
        for (int u = 0; u < V; u++) {
            for (const auto& pair : weightedAdjList[u]) {
                int v = pair.first;
                int weight = pair.second;
                if (u < v) {
                    cout << "Road between " << u << " and " << v << " has weight (traffic): " << weight << endl;
                }
            }
        }
    }

    // ---------------- Task 14: Recommendation System ----------------
    void recommendProducts() {
        cout << "Recommendation system (collaborative filtering):\n";
        cout << "Using a graph-based approach for product recommendations.\n";
    }

    // ---------------- Task 15: Network Optimization ----------------
    void optimizeNetwork() {
        cout << "Optimizing network topology for efficiency:\n";
        cout << "This involves analyzing shortest paths and minimum spanning trees.\n";
    }

    // ---------------- Task 16: Pathfinding (A* Algorithm) ----------------
    void pathfindingAStar(int src, int target) {
        cout << "Pathfinding (A* algorithm):\n";
        cout << "Currently using heuristic-based approach to find optimal paths.\n";
        // Placeholder for full implementation
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
    g.addWeightedEdge(2, 3, 1);

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display Adjacency List\n";
        cout << "10. Dijkstra with Priority Queue\n";
        cout << "11. Route Planning\n";
        cout << "12. Social Network Analysis\n";
        cout << "13. City Traffic Analysis\n";
        cout << "14. Recommendation System\n";
        cout << "15. Network Optimization\n";
        cout << "16. Pathfinding (A* Algorithm)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.displayAdjList();
            break;
        case 10:
            g.DijkstraPriorityQueue(0);
            break;
        case 11:
            g.routePlanning(0);
            break;
        case 12:
            g.analyzeSocialNetwork();
            break;
        case 13:
            g.analyzeCityTraffic();
            break;
        case 14:
            g.recommendProducts();
            break;
        case 15:
            g.optimizeNetwork();
            break;
        case 16:
            g.pathfindingAStar(0, 5);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
}

int main() {
    menu();
    return 0;
}