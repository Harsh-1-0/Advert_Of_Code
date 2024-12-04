f = open("input4.txt", "r")
import re
a=[]
file = f.read()
#cheking for XMAS and SAMX in rows using regx
b = re.findall(r"XMAS",file)
d = re.findall(r"SAMX",file)
f.seek(0)

lines = f.readlines()

for i in range(len(lines)):
    a.append(lines[i].split()[0])

sum = 0
#chcking in columns
for i in range(len(a)-3):
    for j in range(len(a[i])):
        if a[i][j] == 'X' and a[i+1][j] == 'M' and a[i+2][j] == 'A' and a[i+3][j] == 'S':
            sum=sum+1
        if a[i][j] == 'S' and a[i+1][j] == 'A' and a[i+2][j] == 'M' and a[i+3][j] == 'X':
            sum=sum+1

#checking in right diagonals
for i in range(len(a)-3):
    for j in range(len(a[i])-3):
        if a[i][j]=='X' and a[i+1][j+1]=='M' and a[i+2][j+2]=='A' and a[i+3][j+3]=='S':
            sum=sum+1
        if a[i][j]=='S' and a[i+1][j+1]=='A' and a[i+2][j+2]=='M' and a[i+3][j+3]=='X':
            sum=sum+1

#checking in left diagonals
for i in range(len(a)-3):
    for j in range(3,len(a[i])):
        if a[i][j]=='X' and a[i+1][j-1]=='M' and a[i+2][j-2]=='A' and a[i+3][j-3]=='S':
            sum=sum+1
        if a[i][j]=='S' and a[i+1][j-1]=='A' and a[i+2][j-2]=='M' and a[i+3][j-3]=='X':
            sum=sum+1
sum = sum + len(b) + len(d)
print(sum)

sum2=0
#hour glass type structure
for i in range(len(a)-3+1):
    for j in range(len(a[i])-2):
        if(((a[i][j]=='M'and a[i+2][j+2]=='S')or(a[i][j]=='S'and a[i+2][j+2]=='M')) and (a[i+1][j+1]=='A')and ((a[i+2][j]=='M'and a[i][j+2]=='S')or(a[i+2][j]=='S'and a[i][j+2]=='M'))):
            sum2=sum2+1
print(sum2)