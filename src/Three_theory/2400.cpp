#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;

    int i = 2400;
    for (;; i++) {
        if (to_string(i).find("2400") != string::npos) {
            n--;
            cout << i << "\n";
        }
        if (n == 0){cout << i << "\n"; return 0;}
    }
}