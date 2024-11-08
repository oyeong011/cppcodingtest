#include <iostream>
#include <vector>
#include <algorithm>
// 필요한 헤더 파일들을 추가

using namespace std;
int fact(int n) {
    if (n == 1 || n == 0) return 1;
    return n * fact(n - 1);
}

int fact1(int n) {
    int ret = 1;
    for (int i=1; i<=n; i++) {
        ret *= i;
    }
    return ret;
}

int f(int n) {
    if (n==100) return 1;
    return f(n + 1);
}
int fibo(int n) {
    if (n == 0 || n==1) return 1;
    return n * fibo(n - 1);
}

// void combi(int start, vector<int> b) {
//     if (b.size() == k) {
//         return;
//     }
//     for (int i = start + 1; i < n; i++) {
//         b.push_back(i);
//         combi(i, b);
//         b.pop_back();
//     }
// }

vector<string> split(const string & input, string delimiter) {
    auto start = 0;
    auto end  = input.find(delimiter);
    vector<string> result;
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start, end - start));
}





int n = 5;
int main() {

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cout << i << " : " << j << " : " << k << "\n";
            }
        }
    }
    return 0;
}