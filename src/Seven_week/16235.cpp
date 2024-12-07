#include<bits/stdc++.h>
using namespace std;
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m, k, A[14][14], ret, nour[14][14];
vector<int> v[14][14];
void springSummer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j].size() == 0)continue;
            int die_tree = 0;
            vector<int> temp;
            sort(v[i][j].begin(), v[i][j].end());
            for (int tree : v[i][j]) {
                if (nour[i][j] >= tree) {
                    nour[i][j] -= tree;
                    temp.push_back(tree + 1);
                } else {
                    die_tree += tree / 2;
                }
            }
            v[i][j] = temp;
            nour[i][j] += die_tree;
        }
    }
}

void fall() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j].size() == 0) continue;
            for (int tree : v[i][j]) {
                if (tree % 5 == 0) {
                    for (int d = 0; d < 8; d++) {
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if (ny < 0 || nx < 0 || ny >= n || nx >= n)continue;
                        v[ny][nx].push_back(1);
                    }
                }
            }
        }
    }
}
void winter() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nour[i][j] += A[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(&nour[0][0], &nour[0][0] + 14 * 14, 5);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z; x--; y--;
        v[x][y].push_back(z);
    }

    for (int i = 0; i < k; i++) {
        springSummer(); fall(); winter();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ret += v[i][j].size();
        }
    }

    cout << ret << "\n";
}