//
// Created by 권오영 on 24. 9. 28.
//
#include<iostream>
#include <map>
#include<vector>

using namespace std;
map<int, int> mp;
int main() {
    vector<int> v{2, 2, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};
    for (int i : v) {
        if (mp[i]) {
            continue;
        } else {
            mp[i] = 1;
        }
    }

    vector<int> ret;
    for (auto it : mp) {
        ret.push_back(it.first);
    }
    for (int i : ret) cout << i << '\n';
}