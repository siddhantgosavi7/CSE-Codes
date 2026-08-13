num = input("jsegfd")
t=24
l = []

for e in num:
    if e=="0":
        e = "1"
    l.append(int(e))

ans=[]

for x in range(len(l)):
    p =1
    for a in l:
        if a==l[len(l)-1]:
            continue
        p=p*a
    k =p 
    for y in range(l[len(l)-1],9):
        k = p*y
        if p%t==0:
            ans = l 
        k = p  
