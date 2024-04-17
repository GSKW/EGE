path = '../Downloads/262626.txt'
# path = './tests/transporter.txt'

# https://inf-ege.sdamgia.ru/problem?id=59821

with open(path, 'r') as file:
	arr = file.read().splitlines()
	N = int(arr[0])
	arr = [list(map(int, x.split())) for x in arr[1:]]
sorted_arr = []


for idx, (polish_time, dyeing_time) in enumerate(arr):
	if polish_time < dyeing_time:
		sorted_arr.append([polish_time, 0, idx])
	else:
		sorted_arr.append([dyeing_time, 1, idx])

sorted_arr.sort()

last_placed = None
n_polished = 0
last_type = None

for time, type_, idx in sorted_arr:
	if type_ == 0:
		n_polished += 1
	last_placed = idx
	last_type = type_
if last_type == 0:
	n_polished -= 1
print(last_placed + 1, n_polished)
