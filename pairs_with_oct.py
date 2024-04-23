# 10837

def get_diff(ost, by, count, diff):
    arr = []
    if count == 1:
        mn = 1e9
        for elem in diff:
            if elem % by == ost:
                mn = min(mn, elem)
        arr.append(mn)
    elif count == 2:
        mn_1 = 1e9
        mn_2 = 1e9
        for elem in diff:
            if elem % by == ost:
                if elem <= mn_1:
                    mn_2 = mn_1
                    mn_1 = elem
                elif elem <= mn_2:
                    mn_2 = elem
        arr.append(mn_1)
        arr.append(mn_2)
    return sum(arr)


path = '27a.txt'

with open(path, 'r') as f:
    arr = f.read().splitlines()
    N = int(arr[0])
    arr = [list(map(int, x.split())) for x in arr[1:]]

mx = sum([max(x) for x in arr])
diff = [abs(x[0] - x[1]) for x in arr]
ans = []
# A
# ans.append(get_diff(7, 8, 1, diff))
# ans.append(get_diff(6, 8, 1, diff) + get_diff(1, 8, 1, diff))
# ans.append(get_diff(5, 8, 1, diff) + get_diff(2, 8, 1, diff))
# ans.append(get_diff(4, 8, 1, diff) + get_diff(3, 8, 1, diff))

# B
# ans.append(get_diff(2, 8, 1, diff))
# ans.append(get_diff(1, 8, 2, diff))
# ans.append(get_diff(5, 8, 2, diff))
# ans.append(get_diff(6, 8, 1, diff) + get_diff(4, 8, 1, diff))
# ans.append(get_diff(7, 8, 1, diff) + get_diff(3, 8, 1, diff))

print(mx - min(ans))
