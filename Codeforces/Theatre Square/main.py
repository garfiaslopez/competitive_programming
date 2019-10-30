import math

arr = [int(x) for x in input().split()] 

n = arr[0]
m = arr[1]
a = arr[2]

w = math.ceil(n/a)
h = math.ceil(m/a)

print(w*h)