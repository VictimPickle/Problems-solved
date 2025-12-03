m , n = map(int , input().split())
for i in range(3*m):
    for j in range(3*n):
        if (i//m + j//n) %2 == 0:
            print("X",end="")
        else:
            print(".",end="")
    print()