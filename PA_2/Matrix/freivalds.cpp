//T10_A0237756R
#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

vector<int> crossproduct(vector<vector<int>> A, vector<int> random) {
    int row = A.size();
    vector<int> vec(row);
    for (int i = 0; i < row; i++) {
        int result = 0;
        for (int j = 0; j < A[0].size(); j++) {
            result += A[i][j] * random[j];
        }
        vec[i] = result;
    }
    return vec;
}

vector<int> monteCarloVect(int size) {

    vector<int> rrandom(size);
    default_random_engine gen(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, 1);
    for (int i = 0; i < size; i++) {
        rrandom[i] = dist(gen);
    }
    return rrandom;
}


bool freivalds(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C, int n, int m) {
    vector<int> rrandom = monteCarloVect(m);
    vector<int> Br = crossproduct(B, rrandom);
    vector<int> ABr = crossproduct(A, Br);
    vector<int> Cr = crossproduct(C, rrandom);


    for (int i = 0; i < n; i++) {
        if (ABr[i] - Cr[i] != 0) {
            return false;
        } 
    }
    return true;
}

void kfreivalds(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> C, int k, int n, int m) {
    for (int i = 0; i < k; i++) {
        if (!freivalds(A, B, C, n, m)) {
            cout << "WA\n";
            return;
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
        std::string line;
        std::getline(std::cin, line);
        int n, x, y, m;
        cin >> n >> x >> y >> m;


        if (x != y) {
            cout << "Inner matrix dimensions must agree\n";
            for (int i = 0; i < (n + n + y); i++) {
                std::string line;
                std::getline(std::cin, line);
            }
            continue;
        }
        
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

        kfreivalds(A, B, C, 7, n, m);
    }
    return 0;
}