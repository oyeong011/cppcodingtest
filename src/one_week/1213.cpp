//
// Created by 권오영 on 24. 10. 4.
//
#include<iostream>
#include<map>
using namespace std;
int cnt[200], flag;
string s, ret;
char mid;

// void makePermutation(int n, int r, int depth) {
//     if (depth == r) {
//         return;
//     }
//     for (int i = depth; i < n; i++) {
//         swap(a[i], a[depth]);
//         makePermutation(n, r, depth+1);
//         swap(a[i], a[depth]);
//     }
//     return;
// }
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> s;
    for (char a : s)cnt[a]++;
    for (int i = 'Z'; i >= 'A'; i--) {
        if (cnt[i]) {
            // 홀수 체크하기
            if (cnt[i] & 1) {
                mid = char(i); flag++;
                cnt[i]--;
            }
            if (flag == 2)break;
            for (int j = 0; j < cnt[i]; j+=2) {
                ret = char(i) + ret;
                ret += char(i);
            }
        }
    }
    if (mid)ret.insert(ret.begin() + ret.size() / 2, mid);
    if (flag == 2)cout << " I'm Sorry Hansoo\n";
    else cout << ret << "\n";
}