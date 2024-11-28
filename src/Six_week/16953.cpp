#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll A, B, ret = 1e9;
void dfs(ll val, ll dep) {
    if (val > B) return;
    if (val == B) {
        ret = min(dep, ret);
        return;
    }

    dfs(val * 10 + 1, dep + 1);
    dfs(val * 2, dep + 1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> A >> B;
    dfs(A, 1);
    if (ret == 1e9) {
        cout << -1 << '\n';
    } else cout << ret << '\n';
}