//T10_A0237756R
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long quickSelect(int center, vector<long long>& U) {
    nth_element(U.begin(), U.begin() + center, U.end());
    return U[center];
}

void medianFinder(int N, vector<long long>& U) {
    long long median = quickSelect(N / 2, U);
    bool odd = N % 2 == 1;
    if (odd) {
        cout << median;
    } else {
        long long median2 = quickSelect(N / 2 - 1, U);
        long long newmedian = (median + median2) / 2;


        if ((median + median2) % 2 == 0) {
            cout << newmedian;
        } else {
            cout << newmedian << ".5";
        }
    }
    return;
}

int main() {
    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        long long A, B, C, X, Y;
        int N;
        cin >> N >> A >> B >> C >> X >> Y;

        vector<long long> U(N);
        U[0] = A;

        for (int i = 1; i < N; i++) {
            U[i] = ((A + U[i - 1] % C * B) % C) * A;
        }
        medianFinder(N, U);
        cout << "\n";
    }

    return 0;
}