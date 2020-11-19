string = str(input())

new_string = ""

for i in range(0, len(string)):
    if string[i] != 'A' and string[i] != 'a' and string[i] != 'E' and string[i] != 'e' and string[i] != 'I' and string[i] != 'i' and string[i] != 'O' and  string[i] != 'o' and  string[i] != 'U' and  string[i] != 'u' and  string[i] != 'Y' and  string[i] != 'y':
        new_string += '.' + string[i].lower()
print(new_string)