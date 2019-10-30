n = int(input())


total = 0

for i in range(0, n):
    s = str(input()).split()
    a = int(s[0])
    b = int(s[1])
    c = int(s[2])
    
    counts = 0
    if a == 1:
        counts += 1
    if b == 1:
        counts += 1
    if c == 1:
        counts += 1
    
    if counts >= 2:
        total += 1

print(total)


