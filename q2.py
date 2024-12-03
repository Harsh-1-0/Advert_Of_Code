a=[]
total=0
one_error=0
with open('input2.txt','r') as file:
    data = file.read()
    for line in data.split('\n'):
        a=line.split(" ")
        for i in range(len(a)):
            a[i]=int(a[i])
        asc=0
        dsc=0
        # print(a)
        for i in range(len(a)-1):
            if(a[i+1]==a[i]-1 or a[i+1]==a[i]-2 or a[i+1]==a[i]-3):
                dsc+=1
            if(a[i+1]==a[i]+1 or a[i+1]==a[i]+2 or a[i+1]==a[i]+3):
                asc+=1
       
        if(asc==len(a)-1 or dsc==len(a)-1):
            total+=1
            one_error+=1
        else:
            for i in range(len(a)):
                b=a.copy()
                b.pop(i)
                ascN=0
                dscN=0
                for j in range(len(b)-1):
                    if(b[j+1]==b[j]-1 or b[j+1]==b[j]-2 or b[j+1]==b[j]-3):
                        dscN+=1
                    if(b[j+1]==b[j]+1 or b[j+1]==b[j]+2 or b[j+1]==b[j]+3):
                        ascN+=1 
                if(ascN==len(b)-1 or dscN==len(b)-1):
                    one_error+=1
                    break      
        
print(total)
print(one_error)