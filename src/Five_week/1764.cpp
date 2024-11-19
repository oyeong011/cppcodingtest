#include<bits/stdc++.h>
using namespace std;
int n, m;
map<string, int> mp;
vector<string> v;
string s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n + m; i++) {
        cin >> s;
        mp[s]++;
        if (mp[s] > 1) v.push_back(s);
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto i : v) {
        cout << i << "\n";
    }
}