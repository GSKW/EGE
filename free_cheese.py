path = '../Downloads/26262626.txt'
# path = './tests/free_cheese.txt'

# https://inf-ege.sdamgia.ru/problem?id=59851

with open(path, 'r') as file:
	arr = list(map(int, file.read().splitlines()))
	N = arr[0]
	arr = arr[1:]
n = len(arr) // 3
free_goods_sum = sum(arr[2::3])
arr.sort()
s = sum(arr)
print(s - sum(arr[-n:]), s - sum(arr[-3::-3]))
# print(s - sum(arr[:n]), s - free_goods_sum)

# 1 2 3 4

# 1 2 3    4

# 1    2 3 4

