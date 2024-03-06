path = '../../Downloads/26-14.txt'

# https://inf-ege.sdamgia.ru/problem?id=46984

with open(path, 'r') as f:
    arr = f.read().splitlines()
    N = int(arr[0])
    arr = [list(map(int, x.split(' '))) for x in arr[1:]]

main_arr = [[] for _ in range(10001)]

for y, x in arr:
    main_arr[y].append(x)

for i, row in enumerate(main_arr):
    main_arr[i] = sorted(set(main_arr[i]))

mx_len = 0
mx_num = 0


'''
N = 5
4x4 
arr = [[1,1], [1,2], [1,1], [2,1], [2, 2]]
main_arr = [[], [1, 2, 1], [2, 1], []]
main_arr = [[], [1, 2], [1, 2], []]

mx_len = 0
mx_num = 0
curr_len = 0
prev = 0

pass

1, 1
mx_len = 0
mx_num = 0
curr_len = 1
prev = 1

1, 2
mx_len = 0
mx_num = 0
curr_len = 2
prev = 2

mx_len = 2
mx_num = 1
curr_len = 2
prev = 2

2, 1
mx_len = 2
mx_num = 1
curr_len = 0
prev = 0

mx_len = 2
mx_num = 1
curr_len = 1
prev = 1

2, 2
mx_len = 2
mx_num = 2
curr_len = 0
prev = 0

'''

for i, row in enumerate(main_arr):
    if len(row) == 0:
        continue
    curr_len = 0
    prev = row[0] - 1
    for elem in row:
        if (elem - prev) == 1:
            curr_len += 1
        else:
            if curr_len >= mx_len:
                mx_len = curr_len
                mx_num = i
                curr_len = 1
        prev = elem
    if curr_len >= mx_len:
        mx_len = curr_len
        mx_num = i

print(mx_num, mx_len)




