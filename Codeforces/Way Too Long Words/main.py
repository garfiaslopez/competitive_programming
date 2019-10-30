n = int(input()) 

for i in range(0,n):
    word = str(input())
    length = len(word)
    if length > 10:
        first_letter = word[0]
        last_letter = word[-1]
        print (first_letter + str(length - 2) + last_letter)
    else:
        print(word)