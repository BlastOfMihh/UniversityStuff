#!/usr/bin/env python3
import sys
# sys.stdin = open("g.in", "rt")

def solve():
    tokens=input().split()
    n, m = int(tokens[0]), int(tokens[1])
    s = input()
    ans=['.']*n
    lastG=-1
    lastH=-1
    nr=0
    for i in range(n):
        if s[i]=='G' and (lastG<i-m or lastG==-1):
            lastG=min(i+m, n-1)
            ans[lastG]='G'
            nr+=1
        if s[i]=='H' and (lastH<i-m or lastH==-1):
            lastH=min(i+m, n-1)
            if ans[lastH]!='.':
                lastH-=1
            ans[lastH]='H'
            nr+=1
    print(nr)
    print("".join(ans))


t = int(input())
# t=1
while t:
    solve()
    t-=1
