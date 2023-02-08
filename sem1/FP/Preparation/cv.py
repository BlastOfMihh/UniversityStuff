


class Xclass():

    def __init__(self):
        # print("initing")
        self.the_var="salut"

    def __del__(self): #TODO
        print("deketng")
        pass

# Attribute Magic Methods	Description
    def __getattr__(self, name):
        print(name, "nu exista")


    def __pos__(self): #TODO
        pass

    def __delattr__(self):
        print("just delling")

    def __del__(self):
        print("real delling")

    # def __setattr__(self, name):
    #     print
    #     pass

    def __repr__(self):
        return self.the_var

    def __hash__(self):
        return hash((self.the_var))

    def __eq__(self, x):
        return x.the_var==self.the_var

    def __index__(self):
        return 1

l=[i for i in range(1,10+1)]

print((l[-4:])[1:])

# x=Xclass()
# del x
# print(x)
# del x
# print(x)


# x=Xclass()
# y=Xclass()
# d={}
# d[x]=11
# d[x]=112
# d[y]=12
# print(d)
