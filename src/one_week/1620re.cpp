//
// Created by 권오영 on 24. 10. 4.
//
#include<iostream>
#include<vector>
using namespace std;
int n, m, a[15001],cnt;
void combi(int idx, vector<int> & v) {
    if (v.size() == 2) {
        int b = a[v[0]];
        int c = a[v[1]];
        if (b + c == m)cnt++;
        return;
    }
    for (int i = idx + 1; i <= n; i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    vector<int> v;
    combi(-1, v);
    cout << cnt << '\n';
}