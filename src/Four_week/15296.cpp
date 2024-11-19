// #include<bits/stdc++.h>
// using namespace std;
// string s;
// stack<int> stk;
// int n, cnt, ret, d[200001];
// int main() {
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin >> n >> s;
//     for(int i = 0; i < n; i++) {
//         if (s[i] == '(')stk.push(i);
//         else if (stk.size()) {
//             d[i] = d[stk.top()] = 1;
//             stk.pop();
//         }
//     }
//
//     for (int i = 0; i < n; i++) {
//         if (d[i]) {
//             cnt++;
//             ret = max(ret, cnt);
//         } else cnt = 0;
//
//     }
//     cout << ret << '\n';
// }
#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> v;
int n, cnt, ret;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if (s[i] == '(')v.push_back(s[i]);
        else if (s[i] == ')' && v.size() > 0 && v.back() == '(') {
            v.pop_back(); cnt += 2;
        }
        else if (s[i] == ')') {
            v.clear();
            ret = max(ret, cnt);
            cnt = 0;
        }
    }
    ret = max(cnt, ret);
    cout << ret << '\n';
}