#include<bits/stdc++.h>
using namespace std;
int n, m, result = 987654321, mid;
int arr[300000];
bool search(int estimate_val) {
    int ret = 0;
    for (int i =0; i < m; i++) {
        ret += arr[i] / estimate_val;
        if (arr[i] % estimate_val) ret++;
    }
    return ret <= n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int left = 1, right = 0;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        right = max(right, arr[i]);
    }

    while (left <= right) {
        mid = (left+right)/2;

        if (search(mid)) {
            result = min(result, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << '\n';
}