// #include<bits/stdc++.h>
// using namespace std;
// const int dy[] = {0, -1, 0, 1};
// const int dx[] = {1, 0, -1, 0};
// int n, x, y, dir, g, visited[104][104], ret;
//
// void curve(int y, int x, int dir, int g) {
//     vector<int> dirL;
//     visited[y][x] = 1;
//     dirL.push_back(dir);
//
//     for(int k = 0; k < g; k++) {
//         int size = dirL.size();
//         for(int i = size-1; i >= 0; i--) {
//             int newDir = (dirL[i] + 1) % 4;
//             dirL.push_back(newDir);
//         }
//     }
//
//     int ny = y, nx = x;
//     for(int d : dirL) {
//         ny += dy[d];
//         nx += dx[d];
//         if(ny < 0 || ny >= 100 || nx < 0 || nx >= 100) return;
//         visited[ny][nx] = 1;
//     }
// }
// void cnt_sq() {
//     for (int i = 0; i < 99; i++) {
//         for (int j = 0; j < 99; j++) {
//             if (!visited[i][j] || !visited[i+1][j] || !visited[i][j+1] || !visited[i+1][j+1]) continue;
//             ret++;
//         }
//     }
// }
//
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n;
//
//     for (int i = 0; i < n; i++) {
//         cin >> x >> y >> dir >> g;
//         curve(y, x, dir, g);
//     }
//
//     cnt_sq();
//     cout << ret << "\n";
// }

#include<bits/stdc++.h>
using namespace std;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
vector<int> dragon[4][11];
int cnt, n, x, y, d, g, a[101][101];
void go(int x, int y, int d, int g) {
    a[x][y] = 1;
    for (int i = 0; i <= g; i++) {
        for (int dir : dragon[d][i]) {
            x += dx[dir];
            y += dy[dir];
            a[x][y] = 1;
        }
    }
    return;
}
void makeDragon() {
    for (int i = 0; i < 4; i++) {
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i+1) % 4);
        for (int j = 2; j <= 10; j++) {
            int n = dragon[i][j - 1].size();
            for (int k = n - 1; k >= 0; k--) dragon[i][j].push_back((dragon[i][j - 1][k] + 1) % 4);
            for (int k = 0; k < n; k++) dragon[i][j].push_back(dragon[i][j - 1][k]);
        }
    }
    return;
}

int main() {
    cin >> n;
    makeDragon();
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> d >> g;
        go(x, y, d, g);
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1])cnt++;
        }
    }
    cout << cnt << "\n";
}