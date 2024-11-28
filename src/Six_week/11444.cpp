#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n;
unsigned long long fibonacci(ll n) {
    if (n <= 0) return 0;
    if (n == 1 || n == 2) return 1;

    const long double sqrt5 = sqrt(5);
    const long double phi = (1 + sqrt5) / 2;
    const long double psi = (1 - sqrt5) / 2;

    return static_cast<unsigned long long>(round((pow(phi, n) - pow(psi, n)) / sqrt5));
}

int main() {
    cin >> n;
    cout << fibonacci(n) % 517691607 << endl;
}
