f=open("input6.txt","r")
a=[]
for lines in f:
    a.append(lines.strip())


for i in range(len(a)):
    for j in range(len(a[i])):
        if(a[i][j]=='^'):
            index=[i,j]
print(index)