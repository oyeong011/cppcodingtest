// #include<bits/stdc++.h>
// #define fastio cin.tie(0);cout.tie(0);ios::sync_with_stdio(false)
// using namespace std;
// string s, t, ret;
// int main() {
//     fastio;
//     cin >> s >> t;
//     for (auto a : s) {
//         ret += a;
//         if (ret.size() >= t.size() && ret.substr(ret.size() - t.size(), t.size()) == t) {
//             ret.erase(ret.end() - t.size(), ret.end());
//         }
//     }
//
//     if (!ret.size()) {
//         cout << "FRULA";
//         return 0;
//     }
//     cout << ret << "\n";
// }

// #include<bits/stdc++.h>
// using namespace std;
// string str, bomb;
// int main(){
//     cin >>str>>bomb;
//     int m = bomb.size(), e = 0;
//     for(int i = 0; i < str.size(); i++){
//         str[e++] = str[i];
//         if(e - m < 0)continue;
//         bool flag = false;
//         for(int j = 0; j < m; j++){
//             if(str[e-m+j] != bomb[j]){
//                 flag = true;
//                 break;
//             }
//         }
//         if(flag)continue;
//         e = e-m;
//     }
//     if(!str.size()){cout << "FLAUE" << "\n";return 0;}
//     cout << str << "\n";
// }
#include<bits/stdc++.h>
using namespace std;
string s, t;
vector<char> v;
int main() {
    cin >> s >> t;
    for (auto a : s) {
        v.push_back(a);
        if (a == t[t.size() - 1] && v.size() >= t.size()) {
            string ss = "";
            for (auto b : t) {
                ss += v.back();
                v.pop_back();
            }
            reverse(ss.begin(), ss.end());
            if(t != ss){
                for(int i : ss){
                    v.push_back(i);
                }
            }
        }
    }

    if (v.empty()) {
        cout << "FRULA" << '\n';
        return 0;
    }
    for (auto a : v) {
        cout << a;
    }
}