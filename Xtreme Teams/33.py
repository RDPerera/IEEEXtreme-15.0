t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    metrix=[]
    for j in range(n):
        metrix.append(input())
    count=0
    for i in range(n):
        for j in range(i+1,n):
            for k in range(j+1,n):
                can=True
                for l in range(m):
                    #print("X : (",i,j,k,")",metrix[i][l],metrix[j][l],metrix[k][l])
                    if metrix[i][l]=='n' and metrix[j][l]=='n' and metrix[k][l]=='n':
                        can=False
                if can:
                    count+=1
    print(count)