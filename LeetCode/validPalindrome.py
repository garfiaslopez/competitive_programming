import re

def isPalindrome(self, s: str) -> bool:
    if (len(s) <= 0):
        return True
    cleanedStr = re.sub(r'\W+', '', s).lower()
    reversedString = ''.join(cleanedStr[::-1])
    if (cleanedStr == reversedString):
        return True
    return False


isPalindrome({}, s='A man, a plan, a canal: Panama')

