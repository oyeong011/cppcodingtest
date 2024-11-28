// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// ll n, mp[1000004], len, num;
// int main() {
//     ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         if (num == 0) {
//             auto lowerPos = lower_bound(mp, mp+len, num);
//         }
//         auto lowerPos = lower_bound(mp, mp+len, num);
//         if (*lowerPos != num) len++;
//         *lowerPos = num;
//         for (int j = 0; j < n; j++) {
//             cout << mp[j] << ' ';
//         }
//         cout << "\n";
//     }
//
//     cout << len << "\n";
//     for (int j = 0; j < len; j++) {
//         cout << mp[j] << ' ';
//     }
//     return 0;
//
//
// }
// #include<bits/stdc++.h>
// using namespace std;
// int n, lis[1000004], len, num;
// pair<int, int> ans[1000004];
// stack<int> stk;
// const int INF = 1e9 + 4;
// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//     fill(lis, lis + 1000004, INF);
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         cin >> num;
//         auto lowerPos = lower_bound(lis, lis + len, num);
//         int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
//         if (*lowerPos == INF) len++;
//         *lowerPos = num;
//         ans[i].first = _pos;
//         ans[i].second = num;
//     }
//
//     cout << len << '\n';
//     for (int i = n - 1; i >= 0; i--) {
//         if (ans[i].first == len - 1) {
//             stk.push(ans[i].second); len--;
//         }
//     }
//     while (stk.size()) {
//         cout << stk.top() << '\n'; stk.pop();
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int n, lis[1000004], num, len;
pair<int, int> ans[1000004];
stack<int> stk;
const int INF = 1e9 + 4;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(lis, lis + 1000004, INF);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num);
        int _pos = (int)(lower_bound(lis, lis + len, num) - lis);
        if(*lowerPos == INF) len++;
        *lowerPos = num;
        ans[i].first = _pos;
        ans[i].second = num;
    }

    cout << len << "\n";
    for(int i = n - 1; i >= 0; i--){
        if(ans[i].first == len - 1) {
            stk.push(ans[i].second); len--;
        }
    }

    while (stk.size()){
        cout << stk.top() << ' '; stk.pop();
    }
}
// lower_bound를 이용해서 하나씩 위치와 lis에다가 숫자를 채워감
// 이 함수는 자기보다 크거나 같은 숫자의 위치를 추적해주는 이터레이터
// 만약 이터레이터가 없다면 (INF라면) len을 늘려가서 용량을 늘려서 갯수 추가
// 그래서 이 위치를 포인터를 이용해서 num값으로 업데이트
// 거꾸로 반복문을 돌려서 len가 똑같은길이의 값을 스택에 입력
// 이렇게 되면 len이 아닌 작은것들은 걸러져서 진짜 배열만남음