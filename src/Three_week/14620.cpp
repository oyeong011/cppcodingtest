#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, mp[14][14], visited[14][14], ret = INF;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

bool check(int y, int x) {
    if (visited[y][x]) return false;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (0 > ny || 0 > nx || nx >= n || ny >= n || visited[ny][nx])return false;
    }
    return true;
}
int chkVis(int y, int x) {
    int sum = 0;
    visited[y][x] = 1;
    sum += mp[y][x];
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        visited[ny][nx] = 1;
        sum += mp[ny][nx];
    }
    return sum;
}
void unChkVis(int y, int x) {
    visited[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        visited[ny][nx] = 0;
    }
}
void dfs(int cnt, int totalCost) {
    if (ret < totalCost) return;
    if (cnt == 3) {
        ret = min(ret, totalCost);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j)) {
                int cost = chkVis(i, j);
                dfs(cnt + 1, totalCost + cost);
                unChkVis(i, j);
            }
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
        }
    }

    dfs(0, 0);
    cout << ret;
}