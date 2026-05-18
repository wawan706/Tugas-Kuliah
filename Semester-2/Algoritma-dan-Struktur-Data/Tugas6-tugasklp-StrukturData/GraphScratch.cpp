#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        // 1. Membangun Undirected Graph & Adjacency List
        vector<vector<int>> graph(n);                   // untuk undirected graph, setiap edge [u, v] akan ditambahkan ke graph[u] dan graph[v]
        for (const vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);          // Karena graph tidak berarah, tambahkan juga koneksi sebaliknya
            graph[edge[1]].push_back(edge[0]);
        }

        // 2. Persiapan penelusuran
        queue<int> q;                                   // Queue untuk BFS (Breadth-First Search)
        vector<bool> visited(n, false);                 // Array untuk menandai node yang sudah dikunjungi (

        q.push(source);                                 // Mulai dari node sumber
        visited[source] = true;                         // Tandai node sumber sebagai sudah dikunjungi

        // 3. Eksekusi penelusuran melebar
        while (!q.empty()) {                            // Selama masih ada node yang akan diperiksa
            int currentNode = q.front();                // Ambil node terdepan dari queue
            q.pop();                                    // Hapus node tersebut dari queue

            if (currentNode == destination) {           // Jika node saat ini adalah tujuan, kita sudah menemukan jalur yang valid
                return true;
            }
 
            for (int neighbor : graph[currentNode]) {   // Periksa semua tetangga dari node saat ini
                if (!visited[neighbor]) {               // Jika tetangga belum dikunjungi, tambahkan ke queue untuk penelusuran selanjutnya
                    visited[neighbor] = true;           // Tandai tetangga sebagai sudah dikunjungi
                    q.push(neighbor);                   // Tambahkan tetangga ke queue untuk penelusuran selanjutnya
                }
            }
        }
        return false;                                   // Jika queue habis dan kita belum menemukan tujuan, berarti tidak ada jalur yang valid antara source dan destination
    }
};

int main(){
    Solution solver;

    // Contoh 1:
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {0, 2}};              // 
    int source1 = 0;
    int destination1 = 2;

    bool result = solver.validPath(n1, edges1, source1, destination1);
    cout << (result ? "Path exists" : "Path does not exist") << endl;

    // Contoh 2:
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}};
    int source2 = 0;
    int destination2 = 5;

    bool result2 = solver.validPath(n2, edges2, source2, destination2);
    cout << (result2 ? "Path exists" : "Path does not exist") << endl;
}
