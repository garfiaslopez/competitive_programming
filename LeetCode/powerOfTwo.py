
## TLE Solution:
def isPowerOfTwoTLE(self, n: int) -> bool:
    if (n == 1):
        return True
    while((n % 2) == 0) :
        n = n/2
    if (n == 1):
        return True
    return False

print(isPowerOfTwo({},16))