import re 

sum = 0
sum2 = 0
with open('input3.txt','r') as file:
    data = file.read()
    # print(data)
    #  reading the data from the file with mul(x,y) this will give me value of x and y as a list
    a=re.findall(r"mul\((\d+),(\d+)\)",data)
    print(a)
    # in a loop got the value of x and y and multiplied them and added them to sum
    for i in a:
        sum += int(i[0])*int(i[1])
    
    
    # got the indices in which mul, do and don't is present 
    mul_indices = [m.start() for m in re.finditer(r"mul\((\d+),(\d+)\)", data)]
    do_indices = [m.start() for m in re.finditer(r"do\(\)", data)]
    dont_indices = [m.start() for m in re.finditer(r"don't\(\)", data)]
    # got a valid invalid list which is initilized to all valid mul
    p=[]
    for i in range(len(mul_indices)):
        p.append(1)
    i=0
    j=0
    print(do_indices)
    print(dont_indices)
    while i<len(do_indices) and j<len(dont_indices):
        # checking one by one all the mul is valid after a do and invalid after a dont
        if do_indices[i]<dont_indices[j]:
            for k in range (len(mul_indices)):
                if mul_indices[k]>do_indices[i]:
                    p[k]=1
            i=i+1
        else:  
            for k in range (len(mul_indices)):
                if mul_indices[k]>dont_indices[j]:
                    p[k]=0
            j=j+1
    # clearing the left out indecies
    while i<len(do_indices):
        for k in range (len(mul_indices)):
            if mul_indices[k]>do_indices[i]:
                p[k]=1
        i=i+1
    while j<len(dont_indices):
        for k in range (len(mul_indices)):
            if mul_indices[k]>dont_indices[j]:
                p[k]=0
        j=j+1
    #checking the valid mul taking the value form that dict and adding them to sum2
    for i in range(len(mul_indices)):
        if p[i]==1:
            sum2 += int(a[i][0])*int(a[i][1])


print(sum)
print(sum2)