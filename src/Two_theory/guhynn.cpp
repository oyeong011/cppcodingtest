//
// Created by 권오영 on 24. 10. 1.
//
#include <iomanip>
#include<iostream>
#include<vector>
using namespace std;
int n, temp;
vector<int> v;
int main() {
    cin >> n;
    double b = 0;
    for ( int i = 0; i < n; i++) {
        cin >> temp;
        b += temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for (int i : v)cout << i << " ";
    cout << '\n';
    cout << fixed << setprecision(2) << (b / n) << '\n';
    return 0;
}
