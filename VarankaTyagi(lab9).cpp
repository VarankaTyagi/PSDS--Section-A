#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    if (N == 1) {
        cout << abs(A[0]) << endl;
        return;
    }

    bool possible = true;

    for (int i = 1; i < N; i++) {
        if (A[i] != A[0]) {
            possible = false;
            break;
        }
    }

    if (possible)
        cout << abs(A[0]) << endl;
    else
        cout << -1 << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}