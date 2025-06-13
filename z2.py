def cost(v, n, h, c, currentC, currentV, offset):
    if currentV > v:
        return -1
    if offset == n:
        return currentC
    
    max = currentC
    for i in range(offset, n):
        t = cost(v,n,h,c, currentC + c[i], currentV + h[i], i+1)
        if t > max:
            max = t

    return max

print("Введите грузоподъемность и количество предметов")
v = int(input())
n = int(input())
print("Введите вес предметов")
h = []
for i in range(n):
    h.append(int(input()))
print("Введите стоимость предметов")
c = []
for i in range(n):
    c.append(int(input()))

print(cost(v,n,h,c,0,0,0))