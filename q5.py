import math
f=open('input5.txt','r')
lines = f.readlines()
a=[]
b=[]
x=0
for i in range(len(lines)):
    if(lines[i]=='\n'):
        x=i
        break
    a.append(lines[i].strip())
for i in range(x+1,len(lines)):
    b.append(lines[i].strip())
# print(a)
# print(b)
c=[]
d=[]

for i in range(len(b)):
    c.append(b[i].split(','))
# print(c)
e=[]
i=0
# while(i<len(c)):
#     j=0
#     while(j<len(c[i])-1):


for i in range(len(c)):
    for j in range(len(c[i])):
        for k in range(j+1,len(c[i])):
            d.append((c[i][k])+'|'+(c[i][j]))
    e.append(d)
    d=[]
# print(e)
# print()
# print(a)

flag = []
for i in range(len(b)):
    flag.append(0)
i=0
while(i<len(e)):
    count=0
    size = len(e[i])
    for j in range(len(e[i])):
        if(e[i][j] in a):
            break
        count = count + 1
    if(count==size):
        flag[i]=1
    i=i+1

# print(flag)

# print(c)
sum = 0
for i in range(len(b)):
    if(flag[i]==1):
        sum = sum + int(c[i][math.floor(len(c[i])/2) ])
        
print(sum)



wrong=[]
c=[]
e=[]
d=[]
for i in range(len(b)):
    if(flag[i]==0):
        wrong.append(b[i])

for i in range(len(wrong)):
    c.append(wrong[i].split(','))

for i in range(len(c)):
    for j in range(len(c[i])):
        for k in range(j+1,len(c[i])):
            d.append((c[i][k])+'|'+(c[i][j]))
    e.append(d)
    d=[]
l=0
m=[[1]]
while(True):
    total_empty=0
    i=0
    for k in m:
        if(k==[]):
            total_empty+=1
    if(total_empty==len(m)):
        break

    m=[]
    while(i<len(e)):
        l=[]
        for j in range(len(e[i])):
            if(e[i][j] in a):
                # print(e[i][j])
                l.append(e[i][j])
        m.append(l)        
        i=i+1
    # print(m)
    for i in range(len(m)):
        for j in range(len(m[i])):
            z=m[i][j].split('|')
            s1=c[i].index(z[0])
            s2=c[i].index(z[1])
            t=c[i][s2]
            c[i][s2]=c[i][s1]
            c[i][s1]=t
    e=[]
    for i in range(len(c)):
        for j in range(len(c[i])):
            for k in range(j+1,len(c[i])):
                d.append((c[i][k])+'|'+(c[i][j]))
        e.append(d)
        d=[]
    
sum2=0

for i in range(len(c)):
    sum2 = sum2 + int(c[i][math.floor(len(c[i])/2) ])

print(sum2)
# print(wrong)
# print(c)

f.close()