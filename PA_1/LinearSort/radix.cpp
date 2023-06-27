#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void countingSort(vector<int> &arr, int bitposition, long length) {

    int output[length];
    // 8 bits at a time (2^12 bins)
    int count[65536] = {0};

    // store occurence of each 12-bit number
    for (int i = 0; i < length; i++) {
        int number = (arr[i] / bitposition) % 65535;
        count[number]++;
    }

    // cumulative array
    for (int i = 1; i < 65536; i++) {
        count[i] += count[i-1];
    }

    // sort the output array and decrement the count
    for (int i = length - 1; i >= 0; i--) {
        int number = (arr[i]/ bitposition) % 65535;
        int index = count[number] - 1;
        output[index] = arr[i];
        count[number]--;
    }
    
    for (int i = 0; i < length; i++) {
        arr[i] = output[i];
    }
}

vector<int> radixSort(vector<int> &arr, long A, long C, long length) {

    long max = A >= C ? A : C;

    // left shift to work on the next 8 bits 
    // stop once bitposition is bigger than max
    for (int bitposition = 1; max / bitposition > 0; bitposition <<= 16) {
        countingSort(arr, bitposition, length);
    }

    return arr;
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

        vector<int> S = radixSort(U,A,C, N);

        int hash_v = 77;
        for (int i = 0; i < N; i++) {
            hash_v = (hash_v * X + 7 * S[i]) % Y;
        }
        cout << hash_v << "\n";
    }
    return 0;
}