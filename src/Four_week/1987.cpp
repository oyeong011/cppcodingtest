#include<bits/stdc++.h>
using namespace std;
int R, C, ret, ny, nx;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
char a[21][21];
void go(int y, int x, int num, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C)continue;
        int _next = (1 << (int)(a[ny][nx] - 'A'));
        if ((num & _next) == 0) go(ny, nx, num | _next, cnt + 1);
    }
}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }

    go(0, 0, 1 << (int)(a[0][0] - 'A'), 1);
    cout << ret << '\n';
    return 0;
}