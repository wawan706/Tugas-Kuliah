#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m, N;
    cout << "m (total uang): ";
    cin >> m;
    cout << "N (jumlah eskrim): ";
    cin >> N;

    cout << "masukkan harga eskrim" << endl;
    vector<int> eskrim(N);
    for (int i = 0; i < N; i++){
        cout << "harga eskrim " << i + 1 << ": ";
        cin >> eskrim[i];
    }

    cout << "===============" << endl;

    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (eskrim[i] + eskrim[j] == m){
                cout << "indeks ke " <<  i + 1 << " & " << j + 1;
                return 0;
            }
        }
    }
}
