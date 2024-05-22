path = '../../Downloads/26-134.txt'
# path = '../../Downloads/test.txt'

'''
№ 54642
Task 26
'''
with open(path, 'r') as file:
    arr = file.read().splitlines()
    N, T = map(int, arr[0].split())
    arr = [[*map(int, x.split()[:2]), x.split()[-1]] for x in arr[1:]]

G, W, M = [], [], []
type2arr = {
    'G': [],
    'W': [],
    'M': [],
}
n_dict = {
    'G': 0,
    'W': 0,
    'M': 0,
}

for start, dur, t in arr:
    type2arr[t].append([start, dur])

for val in type2arr.values():
    val.sort()

last = None
cur_time = 0

while cur_time <= T:
    last_g = type2arr['G'][0] if len(type2arr['G']) > 0 else None
    last_w = type2arr['W'][0] if len(type2arr['W']) > 0 else None
    last_m = type2arr['M'][0] if len(type2arr['M']) > 0 else None
    queue_g = not (len(type2arr['G']) <= 0)
    queue_w = not (len(type2arr['W']) <= 0)
    queue_m = not (len(type2arr['M']) <= 0)

    if queue_g and cur_time >= last_g[0]:
        cur_time += last_g[1]
        n_dict['G'] += 1
        type2arr['G'] = type2arr['G'][1:]
        last = 'G'

    elif queue_w and cur_time >= last_w[0]:
        cur_time += last_w[1]
        n_dict['W'] += 1
        type2arr['W'] = type2arr['W'][1:]
        last = 'W'

    elif queue_m and cur_time >= last_m[0]:
        cur_time += last_m[1]
        n_dict['M'] += 1
        type2arr['M'] = type2arr['M'][1:]
        last = 'M'

    else:
        cur_time += 1
print(sum([val for key, val in n_dict.items()]), n_dict[last])
