path = '26.txt'

# 10837

with open(path) as f:
    arr = f.read().splitlines()
    D, E, N = map(int, arr[0].split())
    arr = list(map(int, arr[1:]))

print(D, E, N, arr)
d_filled, e_filled = 0, 0
arr.sort()
space_e = [x for x in arr if x <= 500]
space_d = [x for x in arr if x > 500]
n_e, n_d = 0, 0
last_e, last_d = None, None

for idx, elem in enumerate(space_e):
    if e_filled + elem <= E:
        e_filled += elem
        last_e = elem if last_e is None else last_e
        n_e += 1

for idx, elem in enumerate(space_d):
    if d_filled + elem <= D:
        d_filled += elem
        last_d = elem if last_d is None else last_d
        n_d += 1

clear_e, clear_d = E - last_e, D - last_d
max_e, max_d = None, None

for elem in space_e:
    if elem <= clear_e:
        max_e = elem
    else:
        break

for elem in space_d:
    if elem <= clear_d:
        max_d = elem
    else:
        break

n1 = n_e + n_d
n2 = max_e + max_d

print(n1, n2)
