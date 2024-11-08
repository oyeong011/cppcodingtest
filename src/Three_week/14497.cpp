// #include<bits/stdc++.h>
// using namespace std;
// const int dy[] = {-1, 0, 1, 0};
// const int dx[] = {0, 1, 0, -1};
// #define y1 a
// int n, m, x1, y1, x2, y2, ret = 0, visited[304][304];
// char mp[304][304];
// bool flag = false;
// void dfs(int y, int x) {
//     visited[y][x] = 1;
//     for (int i = 0; i < 4; i++) {
//         int ny = y + dy[i], nx = x + dx[i];
//         if (0 > ny || 0 > nx || ny >= n || nx >= m || visited[ny][nx])continue;
//         if (mp[ny][nx] == '1') {visited[ny][nx] = 1; mp[ny][nx] = '0';continue;}
//         if (mp[ny][nx] == '#'){flag = true;return;}
//         dfs(ny, nx);
//     }
// }
// int main() {
//     cin >> n >> m >> x1 >> y1 >> x2 >> y2;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> mp[i][j];
//         }
//     }
//
//     while (!flag) {
//         memset(visited, 0, sizeof(visited));
//         flag = false;
//         ret++;
//         dfs(x1 - 1, y1 - 1);
//     }
//
//     cout << ret;
// }
#include <stdio.h>
#include<algorithm>
#include <iostream>
#include<queue>
#define y1 gg
using namespace std;
char a[301][301];
int n, m, x1, y1, x2, y2, visited[301][301], ret;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
queue<int> q;
int main(){
    cin >> n >> m;
    cin >> x1 >> y1 >> x2 >> y2;
    y1--, x1--, y2--, x2--;
    for(int i = 0; i < n; i++){
        scanf("%s", a[i]);
    }
    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1;
    int cnt = 0;
    while(a[y2][x2] != '0'){
        cnt++;
        queue<int> temp;
        while(q.size()){
            int y = q.front() / 1000;
            int x = q.front() % 1000;
            q.pop();
            for(int i = 0; i < 4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
                visited[ny][nx] = cnt;
                if(a[ny][nx] != '0'){
                    a[ny][nx] = '0';
                    temp.push(1000 * ny + nx);
                }
                else q.push(1000 * ny + nx);
            }
        }
        q = temp;
    }
    printf("%d\n", visited[y2][x2]);
}