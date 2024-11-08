// #include<bits/stdc++.h>
// using namespace std;
// int n, m, dp[54][54], visited[54][54], mx;
// const int dy[] = {-1, 0, 1, 0};
// const int dx[] = {0, 1, 0, -1};
// vector<pair<int, int>> landList;
// void dfs(int y, int x, int depth) {
//     visited[y][x] = depth;
//
//     for (int i = 0; i < 4; i++) {
//         int ny = y + dy[i], nx = x + dx[i];
//         if (nx <0 || ny < 0 || nx >= m || ny >= n || dp[ny][nx] == 0) continue;
//         if (visited[ny][nx] == -1 || visited[ny][nx] > depth + 1) {
//             dfs(ny, nx, depth + 1);
//         }
//     }
// }
// int getMaxdistance() {
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (visited[i][j] == -1)continue;
//             ans = max(ans, visited[i][j]);
//         }
//     }
//     return ans;
// }
// int main() {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++) {
//         string s;
//         cin >> s;
//         for (int j = 0; j < m; j++) {
//             if (s[j] == 'W')dp[i][j] = 0;
//             else if (s[j] == 'L') {
//                 dp[i][j] = 1;
//                 landList.push_back(make_pair(i, j));
//             }
//         }
//     }
//
//     for (auto a : landList) {
//         memset(visited, -1, sizeof(visited));
//         dfs(a.first, a.second, 0);
//         mx = max(mx, getMaxdistance());
//     }
//
//     cout << mx;
//
// }
#include<bits/stdc++.h>
using namespace std;
int n, m, mx, dp[54][54], visited[54][54];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char a[54][54];
void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    visited[y][x] = 1;
    queue<pair<int, int>> q;
    q.push({ y, x });
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
            if (visited[ny][nx])continue;
            if (a[ny][nx] == 'W')continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny, nx });
            mx = max(mx, visited[ny][nx]);
        }
    }
    return;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'L') bfs(i, j);
        }
    }
    cout << mx - 1 << "\n";
}