list1 = []
list0 = []
for i in input().split():
    list0.append(int(i))
number = list0[0]
count = list0[1]
index = 1
list1 = list(range(1, number + 1))
while (len(list1) > 1):
    list2 = []
    if count == 1:
        list2.append(list1[-1])
        li = list2[:]
        break
    for i in range(len(list1)):
        if ((index % count == 0) or (index % 10 == count)):
            index += 1
        else:
            list2.append(list1[i])
            index+=1
    list1 = list2[:]
print(list1[0])
