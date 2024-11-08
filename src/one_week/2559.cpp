// //
// // Created by 권오영 on 24. 10. 3.
// //
// #include<iostream>
// #include<vector>
// using namespace std;
// int N, K, result, cnt = 0, temp = 0;
// int main() {
//     cin >> N >> K;
//     int arr[N];
//     for (int i = 0; i < N; i++) cin >> arr[i];
//
//     for (int i =0 ; i < N - K + 1 ; i++) {
//         for (int j = cnt; j < K + cnt ; j++) {
//             temp += arr[j];
//         }
//         if (result < temp) result = temp;
//         temp = 0;
//         cnt++;
//     }
//
//     cout << result << '\n';
// }

#include<iostream>
using namespace std;
typedef long long ll;
int n, k ,temp, psum[100001], ret = -1000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for ( int i = 1; i <= n; i++) {
        cin >> temp; psum[i] = psum[i - 1] + temp;
    }
    for (int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i - k]);
    }
    cout <<  ret << "\n";
    return 0;
}