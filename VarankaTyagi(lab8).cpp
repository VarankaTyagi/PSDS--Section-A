//QUESTION 1

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;

    cout << "Enter N and K: ";
    cin >> N >> K;

    vector<int> arr(N);

    cout << "Enter array elements: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sum = 0;

    for (int i = 0; i < K; i++) {
        sum += arr[i];
    }

    int maxSum = sum;

    for (int i = K; i < N; i++) {
        sum += arr[i];       
        sum -= arr[i - K];   

        maxSum = max(maxSum, sum);
    }

    cout << "Maximum sum: " << maxSum << endl;

    return 0;
}


//QUESTION 2

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    string S;

    cout << "Enter a string: ";
    cin >> S;

    unordered_set<char> st;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < S.length(); right++) {

        while (st.find(S[right]) != st.end()) {
            st.erase(S[left]);
            left++;
        }

        st.insert(S[right]);

        int length = right - left + 1;

        maxLength = max(maxLength, length);
    }

    cout << "Longest substring length: "
         << maxLength << endl;

    return 0;
}


//QUESTION 3

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

int main() {
    int N, M, K;

    cout << "Enter N, M and K: ";
    cin >> N >> M >> K;

    vector<Edge> edges;

    cout << "Enter edges (u v weight):" << endl;

    for (int i = 0; i < M; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        edges.push_back({u, v, weight});
    }

    const int INF = 1e9;

    vector<int> dp(N + 1, INF);
    dp[1] = 0;

    for (int e = 1; e <= K; e++) {

        vector<int> nextDP = dp;

        for (auto edge : edges) {

            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (dp[u] != INF) {
                nextDP[v] = min(nextDP[v],
                                dp[u] + weight);
            }

            if (dp[v] != INF) {
                nextDP[u] = min(nextDP[u],
                                dp[v] + weight);
            }
        }

        dp = nextDP;
    }

    if (dp[N] == INF) {
        cout << "Minimum path weight: -1" << endl;
    } else {
        cout << "Minimum path weight: "
             << dp[N] << endl;
    }

    return 0;
}