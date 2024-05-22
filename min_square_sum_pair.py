path = '../../Downloads/27-8b.txt'
with open(path, 'r') as file:
    arr = file.read().splitlines()
    N = int(arr[0])
    arr = list(map(int, arr[1:]))
mn = 1e9
ans = []
for i in range(len(arr) - 6):
    a, b = arr[i], arr[i+5]
    mn = min(a, mn)
    ans.append(b**2 + mn**2)
print(min(ans))
