//
// Created by 권오영 on 24. 10. 4.
//
#include<iostream>
using namespace std;
int n, m, item[15004], cnt=0, temp=0;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> item[i];
    for (int i = 0; i <n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (item[i] + item[j] == m) {
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}
