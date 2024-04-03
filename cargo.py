path = '../../Downloads/26-22.txt'

# https://inf-ege.sdamgia.ru/problem?id=33198

def find_cargo(sorted_arr, n):
    num = None
    sorted_arr.sort()
    for elem in sorted_arr:
        if elem <= n:
            num = elem
        else:
            break
    return num


with open(path, 'r') as f:
    arr = f.read().splitlines()
    n, m = map(int, arr[0].split())
    arr = list(map(int, arr[1:]))

arr.sort()

s = 0
k = 0
chosen = []
chosen_fixed = []
ban = []
for i in range(len(arr)):
    if 200 <= arr[i] <= 210:
        chosen_fixed.append(arr[i])
        ban.append(i)
        s += arr[i]
        k += 1
for i in range(len(arr)):
    if s + arr[i] <= m and i not in ban:
        s += arr[i]
        k += 1
        chosen.append(arr[i])
        ban.append(i)

available = [arr[i] for i in range(len(arr)) if i not in ban]

chosen.sort()
chosen.reverse()
for i in range(len(chosen)):
    if s < m:
        found_cargo = find_cargo(available, chosen[i] + (m - s))
        if found_cargo is None:
            continue
        s = s - chosen[i] + found_cargo
        available.append(chosen[i])
        chosen[i] = found_cargo
        available.remove(chosen[i])
    else:
        break
print(k, s)