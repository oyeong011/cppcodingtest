// #include<bits/stdc++.h>
// using namespace std;
// string a, b;
// vector<int> v;
// int z;
// int main() {
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     cin >> a >> b;
//     if (a.length() > b.length()) {
//         swap(a, b);
//     }
//     for(int i = 0; i < a.length(); i++) {
//         int x = a[a.length() - 1 - i] - '0', y = b[b.length() - 1 - i] - '0';
//         int sum = x + y + z;
//         z = sum / 10;
//         v.push_back(sum % 10);
//     }
//     for (int i = a.length(); i < b.length(); i++) {
//         int y = b[b.length() - 1 - i] - '0';
//         int sum = y + z;
//         z = sum / 10;
//         v.push_back(sum % 10);
//     }
//     if (z > 0) v.push_back(z);
//     reverse(v.begin(), v.end());
//     for(int i = 0; i < v.size(); i++) {
//         cout << v[i];
//     }
// }
#include<bits/stdc++.h>
using namespace std;
string string_add(string a, string b) {
    int sum = 0;
    string ret;
    while(a.size() || b.size() || sum){
        if(a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string a, b;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    cout << string_add(a, b) << '\n';
    return 0;
}
