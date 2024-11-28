// #include<bits/stdc++.h>
// using namespace std;
// int n, m, a, ret;
// vector<int> vn, vm;
// int main() {
//     ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
//     cin >> n >> m;
//     vn.resize(n); vm.resize(m);
//     for (int i = 0; i < n; i++) {
//          cin >> a; vn.push_back(a);
//     }
//     for (int i = 0; i < m; i++) {
//         cin >> a; vm.push_back(a);
//     }
//     sort(vn.begin(), vn.end());
//     sort(vm.begin(), vm.end());
//
//     for (auto a : vn) {
//         int pos = lower_bound(vm.begin(), vm.end(), a) - vm.begin();
//         if (vm[pos] != a) ret++;
//     }
//
//     for (auto a : vm) {
//         int pos = lower_bound(vn.begin(), vn.end(), a) - vn.begin();
//         if (vn[pos] != a) ret++;
//     }
//     cout << ret << '\n';
// }
#include<bits/stdc++.h>
using namespace std;
int n, m, a, cnt;
map<int, int> _mp;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        _mp[a]++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> a;
        _mp[a]++;;
    }
    for (auto b : _mp) {
        if (b.second == 1) cnt++;
    }

    cout << cnt << '\n';
}

