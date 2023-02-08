from texttable import Texttable



f = open("cv.in", "r")

x=f.read()
x.split("\n")
ans=[]
for t in x:
    t.strip()
    if t!=' ' and t!='\n':
        ans.append(int(t))

ans=sorted(ans, reverse=True)
i=1
for x in ans:
    print(i, x)
    i+=1




txt=Texttable()
# txt.add_    (["salu", 'gelu', "nelu"])
txt.header([""] + [ "salu", 'gelu', "nelu"])
txt.add_row([2, "salu", 'gelu', "nelu"])
txt.add_row([3, "salu", 'gelu', "nelu"])

print(txt.draw())

# txt.a
