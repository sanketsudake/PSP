def printno(n):
    if n:
        print n
        printno(n-1)

def jprintno(i,n):
    if i != n:
        print i
        jprintno(i+1, n)

a = input()
printno(a)
jprintno(1,a+1)
