sum = 0
count = 0
in_str = input()
n = []
for i in in_str.split():
    n.append(int(i))
if (len(n) <= 30):
    for i in range(len(n)):
        if (n[i] == 0):
            sum += 0
        elif (n[i] == 1):
            sum += 1
            count = 0
        elif (n[i] == 2):
            count += 2
            sum += count
print(sum)
