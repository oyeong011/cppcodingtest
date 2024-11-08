#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0,-1};
int R, C, K, visited[15][15], ret = 0;
char mp[15][15];
void dfs(int y, int x, int depth) {
    if (depth > K) return;
    if (y == 0 && x == C - 1 && depth == K) {
        ret++;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[ny][nx] || mp[ny][nx] == 'T')continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, depth + 1);
        visited[ny][nx] = 0;
    }
}

int main() {
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            mp[i][j] = s[j];
        }
    }

    visited[R-1][0] = 1;
    dfs(R-1, 0, 1);

    cout << ret;
}