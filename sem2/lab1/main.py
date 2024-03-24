import mySet

a = mySet.mySet([1,2,3, [4,3,2]])
print(a)

b = mySet.mySet([3,4,5])
print(b)

a.add(b)
a.add(b)
print(a)
a.delete(b)
a.delete(b)
print(a)

c = mySet.mySet([1,2])

print(a != b)

inter = mySet.intersection(a,b)
print(inter)

comb = mySet.combining(a,b)
print(comb)

print(comb.contain(b))
print(comb.contain(a))


for i in comb:
    print(i, end=" ")

print()