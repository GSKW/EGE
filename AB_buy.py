path = '../../Downloads/26-15.txt'

# https://inf-ege.sdamgia.ru/problem?id=33771

with open(path, 'r') as f:
    arr = f.read().splitlines()
    N, M = map(int, arr[0].split())
    arr = [x.split() for x in arr[1:]]
    arr = [[int(x[0]), int(x[1]), x[2]] for x in arr]

arr_a, arr_b = [], []

for price, num, t in arr:
    if t == 'A':
        arr_a += ([price] * num)
    else:
        arr_b += ([price] * num)

arr_a.sort()
arr_b.sort()
curr_s = 0
n = 0
for price in arr_b:
    if curr_s + price <= M:
        curr_s += price
for price in arr_a:
    if curr_s + price <= M:
        curr_s += price
        n += 1

print(n, M - curr_s)
