#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class SocialGraph {
    // Menyimpan daftar teman untuk setiap user
    unordered_map<string, unordered_set<string>> adjList;

public:
    void addFriendship(string u1, string u2) {
        adjList[u1].insert(u2);
        adjList[u2].insert(u1);
    }

    void suggestFriends(string user) {
        if (adjList.find(user) == adjList.end()) {
            cout << "User tidak ditemukan!" << endl;
            return;
        }

        cout << "Rekomendasi teman untuk " << user << ":" << endl;
        
        unordered_set<string> myFriends = adjList[user];
        bool found = false;

        // Cek teman dari teman
        for (const string& friendOfUser : myFriends) {
            for (const string& fof : adjList[friendOfUser]) {
                // Syarat: Bukan diri sendiri, bukan teman yang sudah ada, dan bukan orang yang sama
                if (fof != user && myFriends.find(fof) == myFriends.end()) {
                    cout << "- " << fof << " (Teman dari " << friendOfUser << ")" << endl;
                    found = true;
                }
            }
        }

        if (!found) cout << "Tidak ada rekomendasi baru." << endl;
    }
};

int main() {
    SocialGraph sg;

    // Membangun graph sederhana
    sg.addFriendship("Budi", "Andi");
    sg.addFriendship("Budi", "Citra");
    sg.addFriendship("Andi", "Dedi");
    sg.addFriendship("Citra", "Eka");

    // Mencari rekomendasi untuk Budi
    // Budi berteman dengan Andi & Citra. Andi kenal Dedi, Citra kenal Eka.
    // Maka Dedi & Eka akan disarankan ke Budi.
    sg.suggestFriends("Budi");

    return 0;
}
