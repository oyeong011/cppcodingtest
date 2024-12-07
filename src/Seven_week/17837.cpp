// #include<bits/stdc++.h>
// using namespace std;
//
// const int dy[] = {0, 0, -1, 1};
// const int dx[] = {1, -1, 0, 0};
//
// int n, k, a[14][14], ret;
// vector<int> board[14][14];
// pair<int,int> pos[11];
// int dirL[11];
//
// int findIdx(int y, int x, int num) {
//     auto& v = board[y][x];
//     for (int i = 0; i < v.size(); i++) {
//         if (v[i] == num) return i;
//     }
//     return -1;
// }
//
// bool check() {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             if (board[i][j].size() >= 4) return true;
//         }
//     }
//     return false;
// }
//
// void go() {
//     while (ret <= 1000) {
//         ret++;
//         for (int i = 0; i < k; i++) {
//             vector<int> temp;
//             int y = pos[i].first;
//             int x = pos[i].second;
//             auto& v = board[y][x];
//
//             int idx = findIdx(y, x, i);
//             for (int j = idx; j < v.size(); j++) {
//                 temp.push_back(v[j]);
//             }
//
//             int ny = y + dy[dirL[i]];
//             int nx = x + dx[dirL[i]];
//
//             if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2) {
//                 dirL[i] = dirL[i] ^ 1;
//                 ny = y + dy[dirL[i]];
//                 nx = x + dx[dirL[i]];
//                 if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2) {
//                     continue;
//                 }
//             }
//
//             if (a[ny][nx] == 1) {
//                 reverse(temp.begin(), temp.end());
//             }
//
//             v.erase(v.begin() + idx, v.end());
//             for (const auto& j : temp) {
//                 board[ny][nx].push_back(j);
//                 pos[j] = {ny, nx};
//             }
//
//             if (check()) return;
//         }
//     }
// }
//
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//
//     cin >> n >> k;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> a[i][j];
//         }
//     }
//
//     for (int i = 0; i < k; i++) {
//         int y, x, z; cin >> y >> x >> z; y--; x--; z--;
//         board[y][x].push_back(i);
//         pos[i] = {y, x};
//         dirL[i] = z;
//     }
//
//     go();
//     cout << (ret > 1000 ? -1 : ret) << '\n';
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int n, k, a[14][14], y, x, dir;
struct Point{
    int y, x, dir;
};
vector<int> v[14][14];
vector<Point> status;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
void move(int y, int x, int dir, int i){
    int ny = y + dy[dir];
    int nx = x + dx[dir];
    if(ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2){
        status[i].dir ^= 1;
        ny = y + dy[status[i].dir];
        nx = x + dx[status[i].dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || a[ny][nx] == 2) return;
    }
    vector<int> &here_v = v[y][x];
    vector<int> &next_v = v[ny][nx];
    auto pos = find(here_v.begin(), here_v.end(), i);
    if(a[ny][nx] == 1) reverse(pos, here_v.end());
	for(auto it = pos; it != here_v.end(); it++){
        next_v.push_back(*it);
        status[*it].y = ny;
        status[*it].x = nx;
    }
    here_v.erase(pos, here_v.end());
    return;
}
bool isOver(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i][j].size() >= 4){
                return 1;
            }
        }
    }
    return 0;
}
bool simul(){
    for(int i = 0; i < status.size(); i++){
        int y = status[i].y;
        int x = status[i].x;
        int dir = status[i].dir;
        move(y, x, dir, i);
        if(isOver()) return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        cin >> y >> x >> dir; y--; x--; dir--;
        v[y][x].push_back(i);
        status.push_back({y, x, dir});
    }

    int cnt = 0;
    bool flag = 0;
    while(cnt <= 1000){
        cnt++;
        if(simul()){
            flag = 1;
			break;
        }
    }
    if(flag) cout << cnt << "\n";
    else cout << -1 << "\n";
    return 0;
}
