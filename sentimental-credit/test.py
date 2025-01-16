a = [1,2,3,4,5,6]
b = [1,2,3,4,5,6]

del a[-1::-2] #extracted
del b[-2::-2] #non extracted

print(a)
print(b)

print(sum(a)*2)
print(sum(b))





