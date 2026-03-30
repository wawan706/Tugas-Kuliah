// Kelompok 5 Teknik Informatika Kelas B

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return gcd(b, a % b);
}

int main() {
    int a = 48;
    int b = 18;

    cout << "--- Program Pencari GCD (Rekursif) ---" << endl;
    cout << "Mencari nilai GCD(" << a << ", " << b << ")" << endl;
    
    int hasil = gcd(a, b);
    
    cout << "Hasil akhir GCD   = " << hasil << endl;
    cout << "--------------------------------------" << endl;

    return 0;
}
