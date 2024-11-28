#include<bits/stdc++.h>
using namespace std;
int n, ret = 0, arr[15];
bool check(int level) {
    for (int i = 0; i < level; i++)
        if (arr[i] == arr[level] || abs(arr[level] - arr[i]) == level - i) return false;
    return true;
}
void dfs(int dep) {
    if (dep == n) {
        ret++;
    } else {
        for (int i = 0; i < n; i++) {
            arr[dep] = i;
            if (check(dep)) dfs(dep + 1);
        }
    }
}

int main() {
    cin >> n;
    dfs(0);

    cout << ret << "\n";
}