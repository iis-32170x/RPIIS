def findCombs(l):
    a = []
    if len(l) == 2:
        a += [l]
        a += [[l[1], l[0]]]
    for i in range(len(l)):
        b = findCombs(l[:i] + l[i + 1:])

        for i1 in b:
            a += [[l[i]] + i1]
    return a

def findIsom(graph):
    kombs = findCombs([i for i in  range(len(graph))])
    kombGraphs = []

    for k in kombs:
        a = [[graph[i][j] for j in k] for i in k]
        kombGraphs.append(a)

    return [kombs, kombGraphs]

def isEqual(graph, patten, k):
    for i in range(len(patten)):
        for j in range(len(patten)):
            if patten[i][j] == 1 and graph[i + k][j + k] != patten[i][j]:
                return False
    return True


fileName = input("Enter file name: ")
# fileName = "test1"
with open(fileName) as f:
    n = int(f.readline())
    graph = []
    for i1 in range(n):
        graph.append([int(i) for i in f.readline().split()])

    n = int(f.readline())
    pattern = []
    for i1 in range(n):
        pattern.append([int(i) for i in f.readline().split()])

kombs = findIsom(graph)
res = []

for k in range(len(kombs[1])):
    for i in range(len(graph) - len(pattern) + 1):
        if isEqual(kombs[1][k], pattern, i):
            n = [[j1 + 1, kombs[0][k][j1 + i] + 1] for j1 in range(len(pattern))]
            if not n in res:
                res.append(n)

with open(fileName + "_exit", "w") as f:
    for i in res:
        for j in i:
            f.write(str(j[0]) + " -> " + str(j[1]) + "\n")
        f.write("\n")

