n, q = map(int, input().split())
lastAnswer = 0
lst = [[] for _ in range(n)]
for _ in range(q) :
    a, x, y = map(int, input().split())
    if(a == 1) :
        index = (x^lastAnswer)%n
        lst[index].append(y)
    else :
        index = (x^lastAnswer)%n
        print(lst[index][y%len(lst[index])])
        lastAnswer = lst[index][y%len(lst[index])]