#!/usr/bin/env python3

gelu="salut eu sunt gelu"


class XClass:
    def __init__(self):
        self.var="variable"
        self.index=0
        self.arr=[5,6,3, 3, 5,6]

    def salut(self):
        print("hello my world")

    def __iter__(self):
        return self
        # return iter(self.arr)

    def __next__(self):
        if self.index==5:
            self.index=0
            raise StopIteration
        self.index+=1
        return self.arr[self.index]

class YClass:
    def __init__(self):
        self.xobj=XClass()

    def __iter__(self):
        return self.xobj


arr=["nelu", "gelu", "salut"]
print(next(iter(arr)))
print(next(iter(arr)))

print("")

xobj=XClass()
for x in xobj:
    print(x)

for x in xobj:
    print(x)

# for x in iter(yobj):
#     print(x)
