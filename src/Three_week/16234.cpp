// #include<bits/stdc++.h>
// using namespace std;
// int n, l, r;
// int adj[54][54], visited[54][54], ret = 0;
// const int dy[] = {-1, 0, 1, 0};
// const int dx[] = {0, 1, 0, -1};
// vector<pair<int, pair<int, int>>> v;
//
// void dfs(int y, int x) {
//     if (visited[y][x]) return;  // 이미 방문한 경우 즉시 리턴
//     visited[y][x] = 1;
//     v.push_back({adj[y][x], {y, x}});
//
//     for (int i = 0; i < 4; i++) {
//         int ny = y + dy[i];
//         int nx = x + dx[i];
//         if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
//         if (abs(adj[y][x] - adj[ny][nx]) >= l && abs(adj[y][x] - adj[ny][nx]) <= r) {
//             dfs(ny, nx);
//         }
//     }
// }
//
// void makeUnion() {  // 함수 이름을 더 명확하게 변경
//     if (v.size() <= 1) return;  // 연합이 형성되지 않으면 리턴
//
//     int sum = 0;
//     for (auto& p : v) {
//         sum += p.first;
//     }
//     int avg = sum / v.size();
//
//     for (auto& p : v) {
//         adj[p.second.first][p.second.second] = avg;
//     }
// }
//
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//
//     cin >> n >> l >> r;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> adj[i][j];
//         }
//     }
//
//     while (true) {
//         bool moved = false;
//         memset(visited, 0, sizeof(visited));
//
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (!visited[i][j]) {
//                     v.clear();
//                     dfs(i, j);
//
//                     if (v.size() > 1) {
//                         makeUnion();
//                         moved = true;
//                     }
//                 }
//             }
//         }
//
//         if (!moved) break;  // 인구 이동이 없으면 종료
//         ret++;
//     }
//
//     cout << ret << '\n';
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int n, l, r, ret, adj[54][54], visited[54][54];
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
vector<pair<int, pair<int, int>>> v;

void dfs(int y, int x){
    visited[y][x] = 1;
    v.push_back({adj[y][x], {y, x}});
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i], nx = x + dx[i];
        if(ny < 0 || nx < 0 || nx >= n || ny >= n || visited[ny][nx])continue;
        if(abs(adj[y][x] - adj[ny][nx]) >= l && abs(adj[y][x] - adj[ny][nx]) <= r){
            dfs(ny, nx);
        }
    }
    return;
}
void makeAvg(){
    if(v.size() <= 1)return;
    int sum = 0;
    for(auto& a : v){
        sum += a.first;
    }
    sum = sum / v.size();
    for(auto& a : v){
        adj[a.second.first][a.second.second] = sum;
    }
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    while(true){
        memset(visited, 0, sizeof(visited));
        bool flag = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j]){
                    v.clear();
                    dfs(i, j);
                    if(v.size() > 1){
                        makeAvg();
                        flag = true;
                    }
                }
            }
        }

        if(flag)ret++;
        else break;
    }

    cout << ret;
}