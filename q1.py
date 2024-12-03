a=[]
b=[]

with open('input.txt', 'r') as file:
        data = file.read()
        for line in data.split('\n'):
            # print(line.split("   ")[1])  
            a.append(int(line.split("   ")[0]))
            b.append(int(line.split("   ")[1]))
a.sort()
b.sort()
sum=0

for i in range(len(a)): 
    sum =sum+  abs(a[i]-b[i])
print(sum)

count_dict = {}

for i in range(len(a)): 
    if a[i] in b:
        count_dict[a[i]] = b.count(a[i])
print(count_dict)

total_dict=0

for i in range(0,len(a)):
    if a[i] in count_dict.keys():
        total_dict=total_dict+count_dict[a[i]]*a[i]

print()
print(total_dict)
