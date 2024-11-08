#include<bits/stdc++.h>
using namespace std;
const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
int R, C, alpha[26], ret = 0;
char mp[24][24];

void dfs(int y, int x, int depth) {
    ret = max(ret, depth);

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= R || nx >= C)continue;

        int alp = mp[ny][nx] - 'A';
        if (alpha[alp])continue;

        alpha[alp] = 1;
        dfs(ny, nx, depth + 1);
        alpha[alp] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < C; j++) {
            mp[i][j] = line[j];
        }
    }

    alpha[mp[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ret;


}



