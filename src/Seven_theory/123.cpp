#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll dp[10004] = {0};
    dp[0] = 1;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (j > i)dp[j] += dp[j - i];
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}