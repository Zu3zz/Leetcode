n = input()
lst = []
for i in n.split():
    lst.append(int(i))
rule_number = lst[0]
start_date = lst[1]
end_date = lst[2]
def date(self):
    year = self[:3]
    month = self[3:7]
    day = self[7:10]