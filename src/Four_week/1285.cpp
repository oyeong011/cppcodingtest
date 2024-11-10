// #include<bits/stdc++.h>
// using namespace std;
// const int INF = 1e9;
// int n, a[44], ret = INF;
// string s;
// void go(int here) {
//     if (here == n + 1) {
//         int sum = 0;
//         for (int i = 1; i <= (1 << (n - 1)); i *= 2) {
//             int cnt = 0;
//             for (int j = 1; j <= n; j++)if (a[j] & i)cnt++;
//             sum += cnt;
//         }
//         ret = min(ret, sum);
//         return;
//     }
//     go(here + 1);
//     a[here] = ~a[here];
//     go(here + 1);
// }
//
// int main() {
//     ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//     cin >> n;
//     for (int i = 1; i<=n ; i++) {
//         cin >> s;
//         int val = 1;
//         for (int j = 0; j < s.size(); j++) {
//             if (s[j] == 'T')a[i] |= val;
//             val *= 2;
//         }
//     }
//
//
//
//     go(1);
//     cout << ret << '\n';
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int n, a[44], ret = 1e9;
string s;
void go(int here){
    if(here == n + 1){
        int sum = 0;
        for(int i = 1; i <= (1 << (n - 1)); i *= 2){
            int cnt = 0;
            for(int j = 1; j <= n; j++)if(a[j] & i)cnt++;
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);
        return;
    }
    go(here + 1);
    a[here] = ~a[here];
    go(here + 1);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s;
        int val = 1;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == 'T')a[i] |= val;
            val *= 2;
        }
    }
    go(1);
    cout << ret << "\n";
    return 0;
}