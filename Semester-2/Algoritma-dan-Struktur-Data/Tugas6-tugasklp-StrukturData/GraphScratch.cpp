#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 1. Membangun peta sirkuit (Adjacency List)
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // 2. Persiapan penelusuran
        queue<int> q;
        vector<bool> visited(n, false);

        q.push(source);
        visited[source] = true;

        // 3. Eksekusi penelusuran melebar
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            if (currentNode == destination) {
                return true;
            }

            for (int neighbor : graph[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }
};

int main(){
    Solution solver;

    // Contoh 1:
    // Node: 0 <--> 1 <--> 2
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {0, 2}};
    int source1 = 0;
    int destination1 = 2;

    bool result = solver.validPath(n1, edges1, source1, destination1);
    cout << (result ? "Path exists" : "Path does not exist") << endl;

    // Contoh 2:
    // Node: 0 <--> 1 <--> 2   dan   3 <--> 4 <--> 5
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}};
    int source2 = 0;
    int destination2 = 5;

    bool result2 = solver.validPath(n2, edges2, source2, destination2);
    cout << (result2 ? "Path exists" : "Path does not exist") << endl;
}
