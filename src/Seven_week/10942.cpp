#include<bits/stdc++.h>
using namespace std;
int n, m, arr[2001], dp[2001][2001];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        dp[i][i] = 1;
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] == arr[i + 1]){
            dp[i][i + 1] = 1;
        }
    }

    for(int len = 2; len <= n; len++){
        for(int start = 1; start <= n - len; start++){
            if(arr[start] == arr[start + len] && dp[start + 1][start + len - 1])dp[start][start + len] = 1;
        }
    }

    cin >> m;
    while(m--){
        int s, e; cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
    return 0;

}