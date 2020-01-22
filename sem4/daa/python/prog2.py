def quick_sort(S):
    n = len(S)
    if n < 2:
        return
    p = S.first()
    queue


n = int(input("Enter number of elements : "))
arr = list(map(int, input("\nEnter the numbers : ").strip().split()))[:n]
print('Before sorting')
print(arr)
quick_sort(arr)
print('\n')
print('After sorting')
print(arr)
