#include<bits/stdc++.h>
using namespace std;
int n, r, l;
string s;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<char> v;
        for (auto c : s) {
            if (c == '(') {
                v.push_back(c);
            }else if (c == ')') {
                if (!v.empty() && v.back() == '(')v.pop_back();
                else v.push_back(c);
            }
        }
        if (v.empty())cout << "YES" <<"\n";
        else cout << "NO" <<"\n";
    }

}