//
// Created by 권오영 on 24. 10. 4.
//
#include<iostream>
#include<stack>
using namespace std;
int n, ret;
string s;
int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        stack<char> stk;
        for (char a : s) {
            if (stk.size() && stk.top() == a)stk.pop();
            else stk.push(a);
        }
    }
    cout << ret << "\n";
}
