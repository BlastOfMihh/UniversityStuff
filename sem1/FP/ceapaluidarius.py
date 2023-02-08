import copy

def backt(k,current_sum, coin_values, target, sols, sol=[]):
    if current_sum==target:
        sols.append([coin_values[sol[x]] for x in range(0,k)])
    if k==len(coin_values):
        return
    if k==0:
        sol=[0]*len(coin_values)
        start=0
    else:
        start=sol[k-1]
    for i in range(start,len(coin_values)):
        v=coin_values[i]
        sol[k]=i
        current_sum+=v
        if current_sum<=target:
            backt(k+1, current_sum, coin_values, target, sols, sol)
        current_sum-=v

def main():
    coin_values=[1,5,3,4,2]
    coin_values.sort()
    target=6
    sols=[]
    backt(0, 0, coin_values, target, sols)
    for s in sols:
        print(s, sum(s))
    
main()
