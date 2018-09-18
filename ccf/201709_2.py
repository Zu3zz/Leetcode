input_1 = input().split()
number = int(input_1[0])
row = int(input_1[1])
print(number,row)
teacher = []
state = []
for i in range(row):
    teacher.append(input().split())
teacher = sorted(teacher, key= lambda teacher: int(teacher[0]))
for i in range(row):
    state.append(int(teacher[i][1]))
    state.append(int(teacher[i][1]) + int(teacher[i][2]))
state = list(set(state))
print(state)