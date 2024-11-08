//
// Created by 권오영 on 24. 10. 4.
//
#include<iostream>
#include<map>
using namespace std;
int n, t;
string a, b;
map<int, string> m;
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> t;

    while (t--) {
        map<string, int> _map;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            _map[b]++;
        }
        long long ret = 1;
        for (auto c : _map) {
            ret *= ((long long)c.second + 1);
        }
        ret--;
        cout << ret << '\n';
    }

}