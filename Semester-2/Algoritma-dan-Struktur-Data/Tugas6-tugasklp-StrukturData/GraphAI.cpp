#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> parent;

    // Fungsi untuk mencari 'akar' dari sebuah himpunan
    int findNode(int i) {
        if (parent[i] == i) return i;
        return parent[i] = findNode(parent[i]); // Path compression
    }

    // Fungsi untuk menyatukan dua himpunan
    void unite(int i, int j) {
        int root_i = findNode(i);
        int root_j = findNode(j);
        if (root_i != root_j) {
            parent[root_i] = root_j;
        }
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        // 1. Inisialisasi: setiap titik memimpin dirinya sendiri
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        // 2. Menyatukan semua titik yang memiliki koneksi
        for (const auto& edge : edges) {
            unite(edge[0], edge[1]);
            
            // Early exit: jika di tengah jalan sudah menyatu, hentikan proses
            if (findNode(source) == findNode(destination)) return true;
        }

        // 3. Cek final
        return findNode(source) == findNode(destination);
    }
};

int main(){
    Solution solver;

    // Contoh 1 :
    // Node: 0 <--> 1 <--> 2
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {0, 2}};
    int source1 = 0;
    int destination1 = 2;

    bool result = solver.validPath(n1, edges1, source1, destination1);
    cout << (result ? "Path exists" : "Path does not exist") << endl;

    // Contoh 2 :
    // Node: 0 <--> 1 <--> 2   dan   3 <--> 4 <--> 5
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4 }};
    int source2 = 0;
    int destination2 = 5;

    bool result2 = solver.validPath(n2, edges2, source2, destination2);
    cout << (result2 ? "Path exists" : "Path does not exist") << endl;
}
