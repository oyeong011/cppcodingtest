#include<bits/stdc++.h>
using namespace std;
int main() {
    int idx, s;
    cin >> idx >> s;

    s &= ~(1 << idx);
    s ^= 1 << idx;
    int a = (1 << idx) - 1;
    s |= (1 << idx);
    

}