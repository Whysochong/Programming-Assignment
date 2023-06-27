//T10_A0237756R

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
int minDiff(int S[], int n) {
    int sum = 0;

    for(int i = 0; i < n; i++) {
        sum += S[i];
    }
    
    bool dp[n + 1][sum + 1];
    
    // cant form subset of sum > 0
    for (int i = 1; i < sum + 1; i++) {
        dp[0][i] = false;
    }

    // form subset of sum 0
    for (int i = 0; i < n + 1; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            // check if its possible to form subset of sum j
            if(S[i-1] <= j) {
                dp[i][j] = dp[i-1][j] || dp[i - 1][j - S[i-1]];
            }
            else {
                // if not possible, then check if its possible to form subset of sum j without ith element
                dp[i][j] = dp[i-1][j];
            }
        }
    } 

    int diff = INT_MAX;
    // sum/2 as it guarantees that the other subset will have sum <= sum/2
    for (int i = 0; i <= sum/2; i++) {
        diff = dp[n][i] 
                ? min(diff, abs(sum - 2*i)) 
                : diff;
    }

    return diff;
}

int main() {
    int TC, N;
    cin >> TC;
    for (int i = 0; i < TC; i++) {
        cin.ignore();
        cin.ignore();
        cin >> N;

        int S[N];

        for (int j = 0; j < N; j++) {
            cin >> S[j];
        }

        int ans = minDiff(S, N);
        cout << ans << "\n";
    }
    return 0;
}
