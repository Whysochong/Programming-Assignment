// T10_A0237756R

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int N, M;
        cin >> N >> M;

        // Read Okabe's favorite virus
        vector<int> favorite(N);
        for (int i = 0; i < N; i++) {
            cin >> favorite[i];
        }

        
        int min_time = 0;
        
        for (int i = 0; i < M; i++) {
            vector<int> virus(N);
            for (int j = 0; j < N; j++) {
                cin >> virus[j];
            }

            int dp[N + 1][N + 1];

            // Initialize dp
            for (int i = 0; i < N + 1; i++) {
                for (int j = 0; j < N + 1; j++) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 0;
                    }
                }
            }

            // Fill dp
            for (int i = 1; i < N + 1; i++) {
                for (int j = 1; j < N + 1; j++) {
                    if (virus[j - 1] != favorite[i - 1]) {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                }
            }

        min_time += N - dp[N][N];
        }
        // No. of viruses to swap = N - LCS
        cout << min_time << endl;
    }
    return 0;
}