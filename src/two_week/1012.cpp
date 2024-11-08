// //
// // Created by 권오영 on 24. 10. 16.
// //
// #include<bits/stdc++.h>
// using namespace std;
// const int MAX_K = 50;
// int T, N, M, K, a[MAX_K][MAX_K], nx, ny, x, y, cnt, visited[MAX_K][MAX_K];
//
// void dfs(int n, int m) {
//     if (a[n][m] == 0)return;
//     if (visited[n][m])return;
//
// }
//
// int main() {
//     cin.tie(NULL);cout.tie(NULL);
//     cin >> T;
//     for (int l = 0; l < 2; l++) {
//         cin >> N >> M >> K;
//         for (int i = 0; i < K; i++) {
//             int one, two;
//             cin >> one >> two;
//             a[one][two] = 1;
//         }
//
//
//
//
//     }
//
// }

#include<bits/stdc++.h>
using namespace std;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
int m,n,k,y,x,ret,ny,nx,t;
int a[51][51];
bool visited[51][51];
void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4;i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m)continue;
        if (a[ny][nx] == 1 && !visited[ny][nx]) {
            dfs(ny,nx);
        }
    }
}

int main() {
    cin.tie(NULL);cout.tie(NULL);
    cin >> t;
    while (t--) {
        fill(&a[0][0], &a[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        ret = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            a[y][x] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1 && !visited[i][j]) {
                    dfs(i,j);
                    ret++;
                }
            }
        }

        cout << ret << "\n";
    }
}