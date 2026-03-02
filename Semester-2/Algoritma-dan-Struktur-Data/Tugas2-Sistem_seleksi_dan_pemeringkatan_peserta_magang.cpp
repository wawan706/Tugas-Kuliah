// Algoritma Sistem seleksi dan pemeringkatan peserta magang

#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    int jumlah_valid = 0, jumlah_tidak_valid = 0, jumlah_lulus = 0;
    double total_nilai_akhir = 0;
    double max1 = -1.0, max2 = -1.0;

    string nama_list[100];
    double na_list[100];
    string status_list[100];

    cout << "Masukkan jumlah pelamar: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        string nama;
        double tulis, wawancara;

        cout << "\nInput Pelamar ke-" << i + 1 << endl;
        cout << "Nama: "; cin >> nama;
        cout << "Nilai Tulis: "; cin >> tulis;
        cout << "Nilai Wawancara: "; cin >> wawancara;

        nama_list[i] = nama;

        if (tulis < 0 || tulis > 100 || wawancara < 0 || wawancara > 100) {
            status_list[i] = "DATA TIDAK VALID";
            na_list[i] = 0;
            jumlah_tidak_valid++;
        } else {
            jumlah_valid++;
            double na = (0.6 * tulis) + (0.4 * wawancara);
            na_list[i] = na;
            total_nilai_akhir += na;

            if (na >= 75) {
                status_list[i] = "LULUS";
                jumlah_lulus++;

                if (na > max1) {
                    max2 = max1; 
                    max1 = na;   
                } else if (na > max2 && na < max1) {
                    max2 = na;   
                }
            } else {
                status_list[i] = "TIDAK LULUS";
            }
        }
    }

    cout << "\n========== HASIL SELEKSI ==========" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Peserta #" << i + 1 << endl;
        cout << "Nama         : " << nama_list[i] << endl;
        if (status_list[i] != "DATA TIDAK VALID") {
            cout << "Nilai Akhir  : " << na_list[i] << endl;
        } else {
            cout << "Nilai Akhir  : (Tidak dihitung)" << endl;
        }
        cout << "Status       : " << status_list[i] << endl;
        cout << "-----------------------------------" << endl;
    }

    cout << "RINGKASAN DATA:" << endl;
    cout << "Jumlah Valid       : " << jumlah_valid << endl;
    cout << "Jumlah Tidak Valid : " << jumlah_tidak_valid << endl;
    cout << "Jumlah Lulus       : " << jumlah_lulus << endl;
    
    if (jumlah_valid > 0) {
        cout << "Rata-rata Nilai    : " << total_nilai_akhir / jumlah_valid << endl;
    }

    cout << "\nDUA NILAI TERTINGGI (LULUS):" << endl;
    if (max1 != -1) cout << "1. " << max1 << endl;
    if (max2 != -1) cout << "2. " << max2 << endl;

    return 0;
}
