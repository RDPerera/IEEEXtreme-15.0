t=int(input())
for i in range(t):
    expression = input()
    try :
        print(eval(expression)%1000000007)
    except :
        print("invalid")