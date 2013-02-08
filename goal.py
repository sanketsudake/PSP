"""
Executing code

python3 goal.py < input.txt
"""

T  = int(input())
for i in range(T):
    N = int(input())
    entries = []
    for j in range(N):
        """
        accepts no of entries.
        Eg. 4 5
        and enters it in main list
        as [4,1],[5,0] so that entering and leaving
        points can be differentiated.
        """
        val1, val2 = input().split(' ')
        val1 = int(val1)
        val2 = int(val2)
        entry1 = []
        entry1.append(val1)
        entry1.append(1)
        entry2 = []
        entry2.append(val2)
        entry2.append(0)
        entries.append(entry1)
        entries.append(entry2)

    entries.sort(key = lambda entry : entry[0])
    #Sort according to first element of entry
    count, max = 0, 0
    for k in entries:
        if k[1] == 1:
            count = count + 1
        else:
            count = count - 1
        if max < count:
            max = count
    if max < count:
        max = count
    print(max)
