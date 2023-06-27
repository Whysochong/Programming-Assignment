#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> countingSort(vector<int> &arr, long max, int length) {

    vector<int> output(length);
    
    vector<int> count(max + 1, 0);

    for (int i = 0; i < length; i++) {
        count[arr[i]]++;
    }

    // cumulative array
    for (int i = 1; i < max + 1; i++) {
        count[i] += count[i-1];
    }

    // sort the output array and decrement the count
    for (int i = length - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    return output;
} 

int main() {
    int TC;
    cin >> TC;
    
    for (int i = 0; i < TC; i++) {
       long long N, A, B, C, X, Y;
        cin >> N >> A >> B >> C >> X >> Y;

        vector<int> U(N);
        U[0] = A;

        for (int i = 1; i < N; i++) {
            U[i] = (A + U[i - 1] * B) % C;
        }

        long max = A >= C ? A : C;

        vector<int> S = countingSort(U, max, N);

        int hash_v = 77;
        for (int i = 0; i < N; i++) {
            hash_v = (hash_v * X + 7 * S[i]) % Y;
        }
        cout << hash_v << "\n";
    }
    return 0;
}