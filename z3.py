def findglues(m,k,glues,materials,current,offset):
    covered = set()
    for glue in current:
        for e in glues[glue]:
            covered.add(e)
    
    if(materials.issubset(covered)):
        return current.copy()
    if offset == k:
        return []
    
    min = []
    for i in range(offset,k):
        current.append(i)
        t = findglues(m,k,glues,materials,current,i+1)
        if len(t) != 0 and ((len(t) < len(min)) or (len(min) == 0)):
            min = t
        current.pop()
    return min

print("Введите количество типов материалов")
m = int(input())
print("Введите количество типов клеев")
k = int(input())
glues = []
for i in range(k):
    print(f"Введите количество типов материалов для клея {i+1}")
    t = int(input())
    tmp = set()
    print(f"Введите {t} материалов(индексы с 1)")
    for j in range(t):
        tmp.add(int(input()))
    glues.append(tmp)

print("Введите количество материалов для склеивания")
p = int(input())
print(f"Введите {p} материалов")
materials = set()
for i in range(p):
    materials.add(int(input()))
minglues = findglues(m,k,glues,materials,[],0)
if len(minglues) != 0:
    print(f"Минимальное количество клеев = {len(minglues)}: ", end='')
    for glue in minglues:
        print(glue+1, end=' ')
else:
    print("Решение не найдено")