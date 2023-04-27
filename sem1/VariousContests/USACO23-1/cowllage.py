#!/usr/bin/env python3


n=int(input())
a=input().split()
a=[int(a[i]) for i in range(n)]

a.sort(reverse=True)

price = a[0]
bst_price = a[0]
maxi = -1

for i in range(n):
    if price>a[i]:
        price=a[i]
    if maxi <= price*(i+1):
        maxi=price*(i+1)
        bst_price=price

print(maxi, bst_price)
