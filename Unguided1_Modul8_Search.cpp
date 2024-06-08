#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Fungsi binary search untuk mencari huruf dalam string yang sudah diurutkan
int binarySearch(const string &str, char target) {
    int left = 0;
    int right = str.length() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (str[mid] == target) {
            return mid; // huruf ditemukan
        } else if (str[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // huruf tidak ditemukan
}

int main() {
    string kalimat;
    char huruf;

    // Input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Input huruf yang dicari
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> huruf;

    // Membuat salinan dari kalimat untuk diurutkan
    string sortedKalimat = kalimat;

    // Mengurutkan salinan kalimat
    sort(sortedKalimat.begin(), sortedKalimat.end());

    // Melakukan binary search pada kalimat yang sudah diurutkan
    int posisi = binarySearch(sortedKalimat, huruf);

    // Mengecek apakah huruf ditemukan atau tidak
    if (posisi != -1) {
        // Temukan posisi huruf di string asli
        int asliPosisi = kalimat.find(huruf);
        cout << "Huruf \"" << huruf << "\" ditemukan pada posisi " << asliPosisi + 1 << " dari kalimat." << endl;
    } else {
        cout << "Huruf \"" << huruf << "\" tidak ditemukan dalam kalimat." << endl;
    }

    return 0;
}
