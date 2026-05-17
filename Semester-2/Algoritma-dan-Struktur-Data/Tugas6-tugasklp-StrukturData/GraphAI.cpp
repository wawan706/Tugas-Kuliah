#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        // 1. Buat adjacency list untuk merepresentasikan graf
        vector<vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u); // Karena ini graf tak berarah (undirected)
        }

        // 2. Inisialisasi queue untuk BFS dan array untuk melacak visited node
        queue<int> q;
        vector<bool> visited(n, false);

        // 3. Mulai dari titik source
        q.push(source);
        visited[source] = true;

        // 4. Lakukan penelusuran graf
        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            // Jika kita sudah sampai di tujuan, return true
            if (currentNode == destination) {
                return true;
            }

            // Kunjungi semua tetangga dari node saat ini
            for (int neighbor : graph[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        // Jika queue habis dan tujuan tidak ditemukan
        return false;
    }
};

