//
// Created by 권오영 on 24. 10. 1.
//
#include<iostream>
typedef long long ll;
int a[100004], b, c, psum[100004], n, m;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for ( int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b >> c;
        cout << psum[c] - psum[b - 1] << "\n";
    }
    return 0;
}