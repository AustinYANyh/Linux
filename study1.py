a = [1,5,7,3,2]
b=[]

def Sort():
    for i in range(0,len(a)):
        b.append(GetMin(a))
        a.remove(GetMin(a))
    return b

def GetMin(array):
    min = array[0]
    for i in range(0,len(array)):
        if min > a[i]:
            min = a[i]
    return min

Sort()
print(b)