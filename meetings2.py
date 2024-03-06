path = '../../Downloads/26-16.txt'

# https://inf-ege.sdamgia.ru/problem?id=61406

with open(path, 'r') as f:
    arr = f.read().splitlines()
    N = int(arr[0])
    arr = [list(map(int, x.split())) for x in arr[1:]]

id_to_meeting = {}
points = []
for idx, (start, end) in enumerate(arr):
    id_to_meeting[idx] = [start, end]
    points.append([end, 0, idx])
    points.append([start, 1, idx])

points.sort()

meetings = []

for p, t, idx in points:
    if t == 0:
        if len(meetings) == 0:
            meetings.append(idx)
        else:
            last_end = id_to_meeting[meetings[-1]][1]
            curr_start = id_to_meeting[idx][0]
            if curr_start - last_end >= 20:
                meetings.append(idx)


# last_good_meeting_end = id_to_meeting[meetings[-1]][1]
last_start = id_to_meeting[meetings[-1]][0]
before_last_end = id_to_meeting[meetings[-2]][1]
mx_delta = last_start - before_last_end
for idx, (start, end) in id_to_meeting.items():
    if start - before_last_end > mx_delta:
        mx_delta = start - before_last_end

print(len(meetings), mx_delta)


