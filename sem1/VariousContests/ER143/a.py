
def solve():
    input()
    a=input()
    b=input()
    a=a+b[::-1]
    splits=0
    for i in range(0, len(a)-1):
        if a[i]==a[i+1]:
            splits+=1
    # print("")
    # print(a, splits)
    if splits>1:
        print("NO")
    else:
        print("YES")


t=int(input(""))
while t!=0:
    solve()
    t-=1



