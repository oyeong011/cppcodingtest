#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int ret = -1e9;
int calc(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}
void dfs(int idx, int val) {
    if (idx >= n) {
        ret = max(ret, val);
        return;
    }
    char op = s[idx - 1];
    int nextVal = calc(val, s[idx] - '0', op);
    dfs(idx + 2, nextVal);

    if (idx + 2 < n) {
        int bracket = calc(s[idx] - '0', s[idx+2] - '0', s[idx+1]);
        int nextVal = calc(val, bracket, op);
        dfs(idx + 4, nextVal);
    }
}
int main() {
    cin >> n;
    cin >> s;
    dfs(2, s[0] - '0');
    cout << ret;
}