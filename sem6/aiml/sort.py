def insertion_sort(arr):
    for i in range(1,len(arr)):
        key = arr[i]
        j = i-1
        while j>=0 and key < arr[j] :
            arr[j+1] = arr[j]
            j = j-1

        arr[j+1] = key



def selection_sort(arr):

    # this loop will go from 0 to n-1
    for i in range(len(arr)):
        minele_index = i # assume that current is min as of now
        #now check for min in right side
        for j in range(i+1,len(arr)):
            if arr[minele_index] > arr[j]:
                minele_index = j
        #swap
        arr[i],arr[minele_index] = arr[minele_index],arr[i]




inp=[]
n = int(input("Enter the number of elements:"))

for i in range(0,n):
    ele = int(input())
    inp.append(ele)


temp = inp
insertion_sort(inp)

print('After insertion sort:')
print(*inp)

print('After selection sort:')
print(*temp)
