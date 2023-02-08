import copy

def max_cross_sum(a, l, r):
    mid=(l+r)//2
    curr=ans=a[mid]
    for i in range(mid+1, r):
        curr+=a[i]
        ans=max(curr, ans)
    curr=ans
    for i in range(len(a)-1, mid-1, -1):
        curr+=a[i]
        ans=max(curr, ans)
    return ans


def divide(a, l, r):
    if l>=r:
        return a[l]
    mid=(l+r)//2
    return max([divide(a,l,mid-1), divide(a,mid,r), max_cross_sum(a,mid)])


def naive(a):
    ans=a[0]
    for i in range(0, len(a)):
        sum=0
        for j in range(i, len(a)):
            sum+=a[j]
            ans=max(sum, ans)
    return ans

a = [-2, -5, 6, -2, -3, 1, 5, -6]
# print(naive(a))
print(divide(a,0,len(a))-1)
