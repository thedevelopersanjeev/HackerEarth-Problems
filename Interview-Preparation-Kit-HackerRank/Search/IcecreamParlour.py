t = int(raw_input().strip())
for a0 in xrange(t):
    m = int(raw_input().strip())
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split(' '))

    # find matched number
    cost_map = {}
    for i, cost in enumerate(a):
        sunny = cost
        johnny = m - cost
        if johnny in cost_map.keys():
            print cost_map[johnny]+1, i+1
        else:
            cost_map[cost] = i