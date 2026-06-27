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


/*

ALGORITMA suggestFriends(targetUser)
INPUT: targetUser (string)
OUTPUT: Menampilkan daftar teman yang disarankan

1.  Dapatkan daftar teman langsung dari targetUser (sebut: myFriends)
2.  IF targetUser tidak ditemukan DALAM database:
        Tampilkan "User tidak ditemukan!"
        RETURN
    END IF

3.  Tampilkan "Rekomendasi teman untuk targetUser:"
4.  SET found = FALSE

5.  FOR EACH friendOfUser (teman dari targetUser) IN myFriends:
        
        // Ambil daftar teman dari teman tersebut
        Dapatkan daftar teman dari friendOfUser (sebut: potentialFriends)

        FOR EACH fof (friend-of-friend) IN potentialFriends:

            // Logika seleksi rekomendasi:
            // 1. fof bukan diri sendiri (targetUser)
            // 2. fof belum menjadi teman langsung (bukan bagian dari myFriends)
            
            IF fof != targetUser DAN fof TIDAK ADA DALAM myFriends:
                Tampilkan fof
                SET found = TRUE
            END IF

        END FOR
    END FOR

6.  IF found == FALSE:
        Tampilkan "Tidak ada rekomendasi baru."
    END IF

*/
