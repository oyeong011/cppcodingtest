#include<bits/stdc++.h>
using namespace std;

const int MAX = 500000;
bool visited[2][MAX + 1];

int bfs(int n, int k) {
    queue<pair<int, int>> q;
    q.push({n, 0});
    
    while(!q.empty()) {
        int pos = q.front().first, time = q.front().second; q.pop();
        
        int brother = k;
        for(int i = 1; i <= time; i++) {
            brother += i;
            if(brother > MAX) return -1;
        }
        if(pos == brother) return time;
        if(brother + time + 1 > MAX) return -1;
        for(int next : {pos-1, pos+1, pos*2}) {
            if(next < 0 || next > MAX) continue;
            if(visited[time%2][next]) continue;
            
            visited[time%2][next] = true;
            q.push({next, time + 1});
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k;
    cin >> n >> k;
    if(n == k) {
        cout << 0;
        return 0;
    }
    cout << bfs(n, k);
    return 0;
}