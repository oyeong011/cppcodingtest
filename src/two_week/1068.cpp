#include<bits/stdc++.h>
using namespace std;
int n, t, temp, root;
vector<int> adj[57];
int dfs(int here) {
    int ret = 0;
    int child = 0;
    for (int there : adj[here]) {
        if (there == t)continue;
        ret += dfs(there);
        child++;
    }
    if (child == 0) return 1;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == -1)root = i;
        else adj[temp].push_back(i);
    }
    cin >> t;
    if (t == root){cout << '0' << '\n'; return 0;}
    cout << dfs(root) << "\n";
    return 0;
}