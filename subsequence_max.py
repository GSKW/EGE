path = '../../Downloads/27-19b.txt'

# 64977

with open(path) as file:
    arr = file.read().splitlines()
    N = int(arr[0])
    arr = list(map(int, arr[1:]))

arr_ = []
temp_pos = []
temp_neg = []
cur = 1
ans = []
for elem in arr:
    if elem == 0:
        arr_.append([temp_pos, temp_neg, cur])
        temp_pos = []
        temp_neg = []
        cur = 1
    else:
        cur *= elem
        if elem > 0:
            temp_pos.append(elem)
        else:
            temp_neg.append(elem)
if temp_pos or temp_neg:
    arr_.append([temp_pos, temp_neg, cur])

for pos, neg, prod in arr_:
    if prod > 0:
        ans.append(prod)
    else:
        ans.append(prod // max(neg))

print(max(ans))