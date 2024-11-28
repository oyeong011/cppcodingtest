#include<bits/stdc++.h>
using namespace std;
int n;
double a[10001], ret, b;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    double b = a[0];
    ret = b;
    for (int i = 1; i < n; i++) {
        if (a[i] > b * a[i]) b = a[i];
        else b *= a[i];
        ret = max(ret, b);
    }

    cout << fixed << setprecision(3) << ret << "\n";
}