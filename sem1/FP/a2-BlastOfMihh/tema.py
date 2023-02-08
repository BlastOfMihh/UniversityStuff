#!/usr/bin/env python3
import random
import copy
import timeit
from texttable import Texttable

def random_list(n:int):
    """
    generates an array in a random fashion
    :param n: the le the length of the array
    :return:
    """
    result=[]
    for i in range(0,n):
        result.append(random.randint(0,100))
    return result

def cocktail_sort(a:list):
    """
    Sorts the given list a using the "cocktail sort" algorithm
    :param a: the list that is going the be sorted
    :return: void
    """
    start=0; end=len(a)
    sorted=False
    while sorted==False:
        sorted=True
        for i in range(start+1, end):
            if a[i]<a[i-1]:
                a[i], a[i-1] = a[i-1], a[i]
                sorted=False
        for i in range(end-2, start, -1):
            if a[i-1]>a[i]:
                a[i], a[i-1] = a[i-1], a[i]
                sorted=False
        start+=1
        end-=1

def merge(ar1, ar2):
    """
    :param ar1:
    :param ar2:
    :return: the merge of the 2 arrays
    """
    res=[]
    i=0; j=0
    while i<len(ar1) and j<len(ar2):
        if ar1[i]<=ar2[j]:
            res.append(ar1[i])
            i+=1
        else:
            res.append(ar2[j])
            j+=1
    while i<len(ar1):
        res.append(ar1[i])
        i+=1
    while j<len(ar2):
        res.append(ar2[j])
        j+=1
    return res

def strand_sort(a):
    """
    :param array: the array to be sorted
    :return:
    """
    if len(a) < 2:
        return a
    result = []
    while a:
        i = 0
        sublist = []
        sublist.append(a.pop())
        while i < len(a):
            num = a[i]
            if num > sublist[-1]:
                sublist.append(num)
                del a[i]
            else:
                i = i + 1
        result = merge(list(result), sublist)
    return result

def add_func2table(table, func, my_array, values_list):
    start_timer=timeit.default_timer()
    func(my_array)
    end_timer=timeit.default_timer()
    values_list[0]=end_timer-start_timer
    table.add_row(values_list)

def build_table():
    table = Texttable()
    table.add_row(['Lenght', 'Cocktail O(N^2)', 'Strand O(N^2)'])
    for length in [10, 100, 1000, 2000, 4000]:
        cocktail_start_timer=timeit.default_timer()
        cocktail_sort(list(range(length)))
        cocktail_end_timer=timeit.default_timer()
        str_start_timer=timeit.default_timer()
        strand_sort(list(range(length)))
        str_end_timer=timeit.default_timer()
        table.add_row([length, cocktail_end_timer-cocktail_start_timer, str_end_timer-str_start_timer])
    return table
def main():
    print(build_table().draw())
    #timeit.timeit(lambda: "-".join(map(str, range(100))), number=10000)

main()
