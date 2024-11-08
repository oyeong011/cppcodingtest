// #include <bits/stdc++.h>
// using namespace std;
// int n, temp;
// stack<pair<int, int>> s;
// int ret[1000004];
// int main() {
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> temp;
//         while(s.size() > 0 && s.top().second < temp) {
//             ret[s.top().first] = temp;
//             s.pop();
//         }
//         s.push({i, temp});
//     }
//     while (s.size() > 0) {
//         ret[s.top().first] = -1;
//         s.pop();
//     }
//     for (int i = 0; i < n; i++) {
//         cout << ret[i] << " ";
//     }
// }
#include <bits/stdc++.h>
using namespace std;
int n, a[1000004], ret[1000004];
stack<int> s;
int main(){
    cin >> n;
    memset(ret, -1, sizeof(ret));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i]){
            ret[s.top()] = a[i]; s.pop();
        }
        s.push(i);
    }
    for(int i = 0; i < n; i++) cout << ret[i] << " ";
}

