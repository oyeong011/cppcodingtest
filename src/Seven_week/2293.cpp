#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, dp[10004], a;
int main(){
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a;
        if(a > 10000)continue;
        for(int j = a; j <= k; j++){
            dp[j] += dp[j - a];
        }
    }

    cout << dp[k];
    return 0;
}