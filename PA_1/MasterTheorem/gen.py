from itertools import product

a = [1, 2, 3, 4, 7, 8, 76] # usual branching factors + large
b = [1.5, 2.0, 3.0, 4.0, 76.0] # usual reduction factor of n + large
c = [0.1, 1.0, 7.7, 76.0] # random constant factors
d = [0.0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 76.0] # usual powers of n^d in f(n) + large
k = [0, 1, 2, 3, 76] # usual powers of log^k in f(n) + large

combinations = list(product(a, b, c, d, k))

with open('test.in', 'w') as f:
    print(len(combinations), file=f) # will be more than 77 test cases, ignore this limit'
    for tc in combinations:
        print(*tc, file=f) 