

def solve():
    buff=input().split()
    n=int(buff[0])
    k=int(buff[1])
    sm=[0]*(52)
    for i in range(n):
        buff=input().split()
        l, r= int(buff[0]), int(buff[1])
        if (k>=l and k<=r):
            sm[l]+=1
            sm[r+1]-=1
    v=0
    kval=0
    for i in range(1,50+1):
        v+=sm[i]
        if i==k:
            kval=v
    # print(kval)
    # print(sm)
    v=0
    for i in range(1,51):
        v+=sm[i]
        if kval==v and k!=i:
            print("NO")
            return 
    print( "YEs")


t=int(input())
while t!=0:
    solve()
    t-=1
