// T10_A0237756R
#include <iostream>
#include <vector>

using namespace std;

void matmul(int n, int x, int y, int m, vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C) {
    if (x != y) {
        cout << "Inner matrix dimensions must agree\n";
        return;
    }

    vector<vector<int>> result(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[i][j] = 0;

            for (int k = 0; k < y; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }

            if (result[i][j] != C[i][j]) {
                cout << "WA\n";
                return;
            }
            
        }
    }
    cout << "AC\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int n, x, y, m;
        cin >> n >> x >> y >> m;
        
        // fill Matrix A
        vector<vector<int>> A(n, vector<int>(x));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < x; j++) {
                cin >> A[i][j];
            }
        }

        // fill Matrix B
        vector<vector<int>> B(y, vector<int>(m));
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < m; j++) {
                cin >> B[i][j];
            }
        }
        // fill Matrix C
        vector<vector<int>> C(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> C[i][j];
            }
        }
        matmul(n, x, y, m, A, B, C);
    }
    return 0;
}