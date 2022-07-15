N, K = map(int, input().split())

sum_value = [0]*(K+1)
items = []

for _ in range(N):
    w, v = map(int, input().split())
    items.append((w, v))

for item in items:
    w, v = item 

    for i in range(K, w-1, -1):
        sum_value[i] = max(sum_value[i], sum_value[i-w]+v)

print(sum_value[-1])