#include <iostream>   // İstifadəçi ilə əlaqə üçün
#include <string>     // String tipini istifadə etmək üçün
#include <conio.h>    // _getch() funksiyası üçün
#include <cstdlib>    // rand() funksiyası üçün
#include <ctime>      // time() funksiyası üçün
#pragma warning(disable:4996) // Xətaları gizlətmək üçün
using namespace std;

int main() {
    // Test başlıqları və suallar üçün massivlər
    string testler[5];            // Maksimum 5 test başlığı
    string suallar[5][10];       // Hər test üçün maksimum 10 sual
    int sualSayisi[5] = { 0 };   // Hər testdəki sualların sayı
    int testSayisi = 0;          // Mövcud testlərin sayı
    int istifadeciNovu;          // İstifadəçi növü (Admin/Guest)

    // Random cavab seçimi üçün seed
    srand(time(0));  // Random sayıların təyin edilməsi

    do {
        cout << "1. Admin" << endl;    // Admin seçimi
        cout << "2. Guest" << endl;    // Guest seçimi
        cout << "Istifadeci novunu daxil edin : \n";
        istifadeciNovu = _getch(); // İstifadəçi növünü oxuyur

        if (istifadeciNovu == 49) {  // Admin seçimi (49 ASCII dəyəri)
            int secim;
            do {
                cout << "1. Yeni test yaratmaq" << endl;  // Yeni test yarat
                cout << "2. Testləri redaktə etmək" << endl; // Testləri redaktə et
                cout << "3. Çıxış etmək" << endl;          // Çıxış et
                cout << "Seçiminizi daxil edin: ";
                secim = _getch(); // İstifadəçinin seçimini oxuyur
                secim -= '0'; // ASCII dəyərini int tipinə çevirir

                if (secim == 1) { // Yeni test yaratma
                    if (testSayisi < 5) { // Test limiti yoxlanılır
                        cout << "Test başlığını daxil edin: ";
                        getline(cin, testler[testSayisi]); // Test başlığını oxu

                        char dahaCox = 'y'; // Daha çox sual əlavə etmək
                        while (dahaCox == 'y' && sualSayisi[testSayisi] < 10) {
                            cout << "Yeni sual daxil edin: ";
                            getline(cin, suallar[testSayisi][sualSayisi[testSayisi++]]);
                            // Sualı oxuyur və sual sayını artırır

                            if (sualSayisi[testSayisi] < 10) { // Sual limiti yoxlanılır
                                cout << "Daha çox sual əlavə edilsin? (y/n): ";
                                cin >> dahaCox; // İstifadəçidən daha çox sual əlavə edilməsi soruşulur
                            }
                            else {
                                cout << "Sual limitinə çatıldı!" << endl; // Limiti aşarsa xəbərdarlıq
                            }
                        }

                        testSayisi++; // Yeni test əlavə edilib
                        cout << "Test qeyd etdiniz!" << endl; // Uğur mesajı
                    }
                    else {
                        cout << "Test limitinə çatıldı!" << endl; // Test limiti aşılırsa xəbərdarlıq
                    }
                }
                else if (secim == 2) { // Testləri göstərmək
                    if (testSayisi == 0) {
                        cout << "Test yoxdur!" << endl; // Test olmadıqda xəbərdarlıq
                    }
                    else {
                        for (int i = 0; i < testSayisi; i++) {
                            cout << i + 1 << ". test: " << testler[i] << endl; // Test başlıqları göstərilir
                            if (sualSayisi[i] == 0) {
                                cout << "  Bu testdə sual yoxdur!" << endl;
                            }
                            else {
                                for (int j = 0; j < sualSayisi[i]; j++) {
                                    cout << "  " << j + 1 << ". " << suallar[i][j] << endl; // Sualları göstər
                                }
                            }
                        }
                    }
                }
                else if (secim == 3) { // Testləri redaktə etmək
                    if (testSayisi == 0) {
                        cout << "Test yoxdur!" << endl;
                    }
                    else {
                        for (int i = 0; i < testSayisi; i++) {
                            cout << i + 1 << ". test: " << testler[i] << endl; // Test başlıqları göstərilir
                            for (int j = 0; j < sualSayisi[i]; j++) {
                                cout << "  " << j + 1 << ". " << suallar[i][j] << endl; // Sualları göstər
                            }
                        }

                        int testIndex, sualIndex; // Dəyişdirmək üçün indekslər
                        string yeniSual; // Yeni sual üçün string

                        cout << "Dəyişiklik üçün test nömrəsini daxil edin: ";
                        cin >> testIndex;
                        testIndex--; // İndeksi sıfırdan başlayır

                        if (testIndex >= 0 && testIndex < testSayisi) {
                            for (int j = 0; j < sualSayisi[testIndex]; j++) {
                                cout << "  " << j + 1 << ". " << suallar[testIndex][j] << endl; // Testdəki sualları göstər
                            }

                            cout << "Dəyişiklik üçün sual nömrəsini daxil edin: ";
                            cin >> sualIndex;
                            sualIndex--; // İndeksi sıfırdan başlayır

                            if (sualIndex >= 0 && sualIndex < sualSayisi[testIndex]) {
                                cout << "Yeni sual daxil edin: ";
                                getline(cin, yeniSual); // Yeni sualı oxu
                                suallar[testIndex][sualIndex] = yeniSual; // Sualı yenilə
                                cout << "Sual yeniləndi!" << endl;
                            }
                            else {
                                cout << "Geçersiz sual nömrəsi!" << endl;
                            }
                        }
                        else {
                            cout << "Geçersiz test nömrəsi!" << endl;
                        }
                    }
                }
                else if (secim == 4) { // Çıxış etmək
                    cout << "Admin'dən çıxdı" << endl;
                }
                else {
                    cout << "Yanlış seçim! Yenidən cəhd edin." << endl;
                }
            } while (secim != 4); // Seçim 4 olmadıqca davam et
        }
        else if (istifadeciNovu == 50) {  // Guest seçimi
            int guestSecim;
            do {
                cout << "Mövcud testlər:" << endl;
                if (testSayisi == 0) {
                    cout << "Test yoxdur!" << endl;
                }
                else {
                    for (int i = 0; i < testSayisi; i++) {
                        cout << i + 1 << ". test: " << testler[i] << endl; // Test başlıqları göstərilir
                    }
                }

                // Seçimlər
                cout << "1. Testləri göstər" << endl;
                cout << "2. Çıxış etmək" << endl;
                cout << "Seçiminizi daxil edin: ";
                guestSecim = _getch(); // Guest seçimini oxuyur
                guestSecim -= '0'; // ASCII dəyərini int tipinə çevirir

                if (guestSecim == 1) { // Testləri göstərmək
                    if (testSayisi == 0) {
                        cout << "Test yoxdur!" << endl;
                    }
                    else {
                        for (int i = 0; i < testSayisi; i++) {
                            cout << i + 1 << ". test: " << testler[i] << endl; // Test başlıqları göstərilir
                            if (sualSayisi[i] == 0) {
                                cout << "  Bu testdə sual yoxdur!" << endl;
                            }
                            else {
                                for (int j = 0; j < sualSayisi[i]; j++) {
                                    cout << "  " << j + 1 << ". " << suallar[i][j] << endl; // Sualları göstər

                                    // Random cavab seçilməsi
                                    int randomCavab = rand() % 4 + 1;  // Random cavab 1-4 arasında
                                    cout << "  Cavab " << randomCavab << " seçildi." << endl;
                                }
                            }
                        }
                    }
                }
                else if (guestSecim == 2) { // Çıxış seçimi
                    cout << "Çıxış edilir..." << endl;
                }
                else {
                    cout << "Yanlış seçim! Yenidən cəhd edin." << endl;
                }
            } while (guestSecim != 2); // Seçim 2 olmadıqca davam et
        }
        else {
            cout << "Yanlış istifadeci növü! Yenidən cəhd edin." << endl;
        }
    } while (true); // Əbədi döngü

    return 0; // Proqramın sonu
}