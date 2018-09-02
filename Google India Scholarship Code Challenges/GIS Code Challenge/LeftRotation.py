def array_left_rotation(a, n, k):
    k = k%n
    b = []
    for _ in range(n) :
        b.append(0)
    b[n-k:n] = a[:k]
    b[:n-k] = a[k:]
    return b
   
n, k = map(int, input().strip().split(' '))
a = list(map(int, input().strip().split(' ')))
answer = array_left_rotation(a, n, k);
print(*answer, sep=' ')