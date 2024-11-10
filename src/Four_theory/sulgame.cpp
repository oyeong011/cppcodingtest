// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//     string s[] = {"딸기", "당근", "수박", "참외", "메론"};
//     for (int i = 0; i < (1 << 5); i++) {
//         string ret = "";
//         cout << i << " : ";
//         for (int j = 0; j < 5; j++) {
//             if (i & (1 << j)) {
//                 ret += s[j] + " ";
//             }
//         }
//         cout << ret << "\n";
//     }
// }
#include<bits/stdc++.h>
using namespace std;
const string s[] = {"딸기", "당근", "수박", "참외", "메론"};
void go(int num) {
    string ans = "";
    for (int i = 0; i < (1 << s->size()); i++) {
        if (num & (1 << i)) {
            ans += s[i] + " ";
        }
    }
    cout << ans << "\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    for (int i = 1; i < (1 << 5); i = (i << 1) + 1) {
        go(i);
    }
}