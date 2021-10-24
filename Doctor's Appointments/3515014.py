def solve(a):
    d={}
    o=[]
    for i in range(len(a)):
        d[i+1]=a[i]
    h=sorted(d.items(), key=lambda d: d[1][1])
    days = [0] * len(h)
    
    for i in range(len(h)):
        flag = False
        for j in range(h[i][1][0], h[i][1][1]+1):
            if days[j-1] == 0:
                days[j-1] = h[i][0]
                flag = True
                break
        if(not flag):
            return "impossible";
    return days
    
t=int(input())
for z in range(t):
    c=int(input())
    a=[]
    for j in range(c):
        l=list(map(int,input().split()))
        a.append(l)
    s=solve(a)
    if(s=="impossible"):
        print("impossible")
    else:
        for x in s:
            print(x, end=" ")
        print("")