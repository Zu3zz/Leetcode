n = input()
number = int(n)
value = []
n = input()
result = 999
for i in n.split():
    value.append(int(i))
i = 0
j = 0
value.sort()
result = []
for i in range(number - 1):
    result.append(abs(value[i]-value[i+1]))
print(min(result))
