path = '../../Downloads/26_last.txt'

# https://inf-ege.sdamgia.ru/problem?id=59776

with open(path, 'r') as file:
    arr = file.read().splitlines()
    N = int(arr[0])
    arr = [list(map(int, x.split('\t'))) for x in arr[1:]]
points = []
idx2start_end = {}
for idx, elem in enumerate(arr):
    points.append([elem[0], 1, idx])
    points.append([elem[0] + elem[1], -1, idx])
    idx2start_end[idx] = [elem[0], elem[0] + elem[1]]

points.sort()
last_good_meeting = None
meetings = []
num_meetings = 0
# mx = 0
for p, t, n in points:
    if t == -1:
        if last_good_meeting is not None:
            current_start = idx2start_end[n][0]
            last_good_end = idx2start_end[last_good_meeting][1]
            if current_start >= last_good_end:
                last_good_meeting = n
                num_meetings += 1
                meetings.append(n)

        else:
            last_good_meeting = n
            num_meetings += 1
            meetings.append(n)

last_start = idx2start_end[last_good_meeting][0]
prev_last_end = idx2start_end[meetings[-2]][1]
mx = last_start - prev_last_end

for p, t, n in points:
    if t == 1 and p > last_start:
        mx = max(mx, p - prev_last_end)

print(num_meetings, mx)

