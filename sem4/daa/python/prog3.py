def dfs(a,n,v,source):
    v[source]=1
    print("Vertex ",source," is visited.\n")
    for i in range(n):
        if a[source][i] == 1 and v[i]==0:
            dfs(a,n,v,i)

v = [0 for i in range(10)]
print("DFS Traversal\n")
n = int(input("Enter the number of vertices:"))
a = []
print("Enter the adjacency matrix:\n")
for i in range(n):
    x=[]
    for j in range(n):
        x.append(int(input()))
    a.append(x)

for i in range(n):
    for j in range(n):
        print(a[i][j],end=" ")
    print()

count = 0
for i in range(n):
    if v[i] == 0:
        dfs(a,n,v,i)
        count = count + 1

print(count)
