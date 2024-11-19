#include<bits/stdc++.h>
using namespace std;
long long s, e, n, a[100001];
bool visited[100001];
long long ret;
int main() {
    cin >> n;
    vector<int> a(n+1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
    }

    while(e < n){
        if(!visited[a[e]]){
            visited[a[e]] = true;
            e++;
        }else{
            ret += (e - s);
            visited[a[s]] = false;
            s++;
        }
    }
    ret += (long long)(e - s) * (e - s + 1) / 2;
    cout << ret << "\n";

}