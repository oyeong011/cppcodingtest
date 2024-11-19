#include<bits/stdc++.h>
using namespace std;
bool che[4000001];
int n, a[2000001], p;
int lo, hi, ret, sum;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if (che[i])continue;
        for (int j = 2*i; j <= n; j += i) che[j] = true;
    }

    for(int i = 2; i < n; i++) {
        if (!che[i]) a[p++] = i;
    }
    while (1) {
        if (sum >= n) sum -= a[lo++];
        else if (hi == p) break;
        else sum += a[hi++];
        if (sum == n) ret++;
    }
}