#include <ios>
#include <iostream>
//
// Created by 권오영 on 24. 10. 2.
//
using namespace std;
int num, CNT[26], result = 0;
string str, ret;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> str;
        CNT[str[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)if (CNT[i] >= 5) ret += (i + 'a');

    if (ret.size()) cout << ret << "\n";
    else cout << "PREDAJA" << "\n";
}