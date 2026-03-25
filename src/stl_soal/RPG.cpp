
#include <iostream>
#include <string>
#include <vector>
#include <map>


using namespace std;

int main () {
    int jml_paket = 0;
    int x = 0;

    cin >> jml_paket;

    vector <long long> koord (jml_paket);
    vector <int> ID (jml_paket);

    for (int i = 0; i < jml_paket; i++) {
        cin >> koord[i];
    }

    for (int i = 0; i < jml_paket; i++) {
        cin >> ID[i];
    }

    map <long long, int> data;

    for (int i = 0; i < jml_paket; i++) {
        data[ID[i]] =  koord[i];
    }

   cout << data.size() << endl;


    return 0;
}