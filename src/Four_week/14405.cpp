// #include<bits/stdc++.h>
// using namespace std;
// string s;
// int main() {
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin >> s;
//
//     bool flag = false;
//     for (int i = 0; i < s.size(); i++) {
//         if (s[i] == 'p') {
//             if (i < s.size() - 1 && s[i + 1] == 'i') {
//                 i++;
//                 continue;
//             }
//             flag = true;
//             break;
//         }
//         if (s[i] == 'k') {
//             if (i < s.size() - 1 && s[i + 1] == 'a') {
//                 i++;
//                 continue;
//             }
//             flag = true;
//             break;
//         }
//         if (s[i] == 'c') {
//             if (i < s.size() - 2 && s[i + 1] == 'h' && s[i + 2] == 'u') {
//                 i += 2;
//                 continue;
//             }
//             flag = true;
//             break;
//
//         }
//         flag = true;
//         break;
//     }
//
//     if (flag) cout << "NO" << "\n";
//     else cout << "YES" << "\n";
// }

#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=false;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka") i+=1;
        else if (i < s.size() - 2 && s.substr(i, 3) == "chu") i += 2;
        else flag = true;
    }
    if (flag) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}