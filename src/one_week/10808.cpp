//
// Created by 권오영 on 24. 10. 1.
//
#include<iostream>
#include<vector>
using namespace std;
int cnt[26];
string word;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    //영어 문자 받아서 배열로 받기
    cin >> word;
    for (char a : word) {
        cnt[a - 'a']++;
    }
    for (int i = 0; i < 26; i++) cout << cnt[i] << " ";

    return 0;
}
