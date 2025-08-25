"""
Name: Shubhajeet Das
Roll No.: 24AI10013
Algo lab Day 2
31 July 2025
QUICK SORT
"""
import random

def basicInsertionSort(A, low, high):
    for i in range(low, high + 1):
        j = i
        # error -> while j > 0 and A[j-1] > A[j]:
        while j > low and A[j-1] > A[j]:
            A[j-1], A[j] = A[j], A[j-1]
            j -= 1

def median(a, b, c):
    if a <= b:
        if c >= b:
            return b
        elif c <= a:
            return a
        else:
            return c
    else:
        if c >= a:
            return a
        elif c <= b:
            return b
        else:
            return c
        
class QuickSort:
    def __init__(self, A, threshold = 10):
        self.A = A
        self.threshold = threshold #threshold for insertion sort
        self.sorted, self.time = self.quickSort()
    def partition(self, A, low, high):
        i, j = low, high
        while (i < j):
            while i <= high - 1 and A[i] <= A[low]:
                i += 1
            while j >= low + 1 and A[j] > A[low]:
                j -= 1
            if i < j:
                A[i], A[j] = A[j], A[i]
        A[low], A[j] = A[j], A[low]
        return j
    def qs(self, A, low, high):
        if low < high:
            size = high - low + 1
            if size <= self.threshold:
                # error here -> basicInsertionSort(self.A, low, high)
                basicInsertionSort(A, low, high)
            else:
                num1 = random.randint(low, high)
                num2 = random.randint(low, high)
                num3 = random.randint(low, high)
                pivotId = median(num1, num2, num3)
                A[low], A[pivotId] = A[pivotId], A[low]
                pId = self.partition(A, low, high)
                if (pId - 1 - low < high - pId - 1) :
                    self.qs(A, low, pId - 1)
                    self.qs(A, pId + 1, high)
                else:
                    self.qs(A, pId + 1, high)
                    self.qs(A, low, pId - 1)
    def quickSort(self):
        import time
        low, high = 0, len(self.A) - 1
        B = self.A.copy()
        startTime = time.time()
        self.qs(B, low, high)
        endTime = time.time()
        return B, (endTime - startTime)

"""
def main():
    import sys
    n = 10000
    if len(sys.argv) > 1:
        try:
            n = int(sys.argv[1])
        except Exception as e:
            print("Expected number. Default n = 10000 choosen")
    print(f"Testing for n = {n}")
    rand_list = []
    random.seed(30)
    start = 1
    end = 1000000
    for _ in range(n):
        num = random.randint(start, end)
        rand_list.append(num)

    sorter = QuickSort(rand_list, 10)
    print(sorter.time)
"""

def main():
    test_cases = [
        [],
        [5],
        [1, 2, 3, 4],
        [5, 4, 3, 2, 1],
        [7, 7, 7],
        random.sample(range(1000), 100),
    ]
    for arr in test_cases:
        sorter = QuickSort(arr[:])
        assert sorter.sorted == sorted(arr), f"Failed on {arr}\nGiving {sorter.sorted} instead of {sorted(arr)}"
    print("All tests passed")
if __name__ == "__main__":
    main()