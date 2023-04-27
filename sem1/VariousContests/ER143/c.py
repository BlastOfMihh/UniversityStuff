from os import name
import sys

# sys.stdin=open("g.in", 'r')

def bs(v, a, st, dr):
    # st=0
    # dr=len(a)-1
    ans=dr+1
    while st<=dr:
        mid=(st+dr)//2
        # if a[mid]==v:
        #     return mid
        if a[mid]>=v:
            ans=mid
            dr=mid-1
        else:
            st=mid+1
    return ans

def solve():
    n=int(input())
    buff=input().split()
    water=[0]*n
    for i in range(n):
        water[i]=int(buff[i])
    buff=input().split()
    b=[0]*n
    for i in range(n):
        b[i]=int(buff[i])
    # reading done
    sums=[0]*(n+1)
    for i in range(n):
        ind=n-1-i
        ind=i
        sums[i]=b[ind]
        if i>0:
            sums[i]+=sums[i-1]
    rests=[0]*(n)
    wholes=[0]*(n)
    for i in range(n):
        end_ind=bs(water[i]+(sums[i-1] if i-1>=0 else 0), sums, i, len(sums)-1)
        wholes[i]+=1
        if end_ind<len(sums):
            wholes[end_ind]-=1
            rests[end_ind]+=sums[i-1]+water[i]-sums[end_ind-1]
        # print(i, water[i])
        # if end_ind<len(sums):
        #     print(end_ind, sums[end_ind])
        # else:
        #     print(end_ind)
        # print()
    # print("\nheyyy", end=" ")
    nrw=0
    for i in range(n):
        nrw+=wholes[i]
        print(b[i]*nrw+rests[i], end=" ")
    print()
    # print("wholes", wholes)
    # print("rests",rests)
    # print("sums", sums)

        

t=int(input())
while t!=0:
    solve()
    t-=1

