defines = [int(i) for i in input().split()]
n = defines[0]
k = defines [1]
scores = [int(i) for i in input().split()]

kth_score = scores[k-1]
next_participants = 0

for i in range(0, n):
    if scores[i] >= kth_score and scores[i] != 0:
        next_participants += 1
print(next_participants)

