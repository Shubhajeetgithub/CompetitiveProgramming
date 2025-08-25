"""
Name: Shubhajeet Das
Roll: 24AI10013
Date: 24 July 2025
ALGO LAB 1
"""

import time

class InsertionSort:
    def __init__(self, A):
        self.A = A
        self.sorted, self.t_basic = self.basic_insertionSort()
        self.B_sorted, self.t_bsearch = self.binarySearch_insertionSort()
        self.Bpair_sorted, self.t_bpairsearch = self.binarySearchPairing_insertionSort()
        self.pair_sorted, self.t_pairsearch = self.pairing_insertionSort()
    def basic_insertionSort(self):
        B = self.A.copy()
        startTime = time.time()
        for i in range(len(B)):
            j = i
            while j > 0 and B[j-1] > B[j]:
                B[j-1], B[j] = B[j], B[j-1]
                j = j - 1
        endTime = time.time()
        return B, endTime - startTime
    def binarySearch_insertionSort(self):
        B = self.A.copy()
        startTime = time.time()
        for i in range(1, len(B)):
            # Binary search to find insertion index
            s, e = 0, i - 1
            id = -1
            while s <= e:
                m = s + (e - s) // 2
                if B[m] <= B[i]:
                    id = m
                    s = m + 1
                else:
                    e = m - 1

            if id != i - 1:
                temp = B[i]
                for j in range(i, id + 1, -1):
                    B[j] = B[j - 1]
                B[id + 1] = temp
        endTime = time.time()
        return B, endTime - startTime
    def binarySearchPairing_insertionSort(self):
        B = self.A.copy()
        startTime = time.time()
        n = len(B)
        if n >= 2 and B[0] > B[1]:
            B[0], B[1] = B[1], B[0]

        for i in range(2, n, 2):
            if (i + 1) < n:
                if B[i] > B[i + 1]:
                    B[i], B[i + 1] = B[i + 1], B[i]

                min_val = B[i]
                max_val = B[i + 1]
                s, e = 0, i - 1
                id = -1
                while s <= e:
                    m = s + (e - s) // 2
                    if B[m] <= min_val:
                        id = m
                        s = m + 1
                    else:
                        e = m - 1

                if id != i - 1:
                    temp = B[i]
                    for j in range(i, id + 1, -1):
                        B[j] = B[j - 1]
                    B[id + 1] = temp

                s, e = id + 1, i
                id = -1
                while s <= e:
                    m = s + (e - s) // 2
                    if B[m] <= max_val:
                        id = m
                        s = m + 1
                    else:
                        e = m - 1

                if id != i:
                    temp = B[i+1]
                    for j in range(i+1, id + 1, -1):
                        B[j] = B[j - 1]
                    B[id + 1] = temp

            else: 
                val = B[i]
                j = i
                while j > 0 and B[j - 1] > val:
                    B[j] = B[j - 1]
                    j -= 1
                B[j] = val

        endTime = time.time()
        return B, endTime - startTime
    def pairing_insertionSort(self):
        B = self.A.copy()
        startTime = time.time()
        n = len(B)
        if n >= 2:
            if B[0] > B[1]:
                B[0], B[1] = B[1], B[0]
            for i in range(2, n, 2):
                maxNum = B[i]
                minNum = B[i]
                if (i + 1) < n:
                    maxNum = max(B[i], B[i+1])
                    minNum = min(B[i], B[i+1])
                    #now placing the maxNum then will place the minNum
                    j = i - 1
                    k = i + 1
                    while j >= 0 and B[j] > maxNum:
                        B[k] = B[j]
                        k -= 1
                        j -= 1
                    B[j + 2] = maxNum
                    B[j + 1] = minNum

                    #now placing the minimum number
                    l = j + 1
                    while l > 0 and B[l-1] > B[l]:
                        B[l-1], B[l] = B[l], B[l-1]
                        l -= 1
                else:
                    #place as usual
                    j = i
                    while j > 0 and B[j-1] > B[j]:
                        B[j-1], B[j] = B[j], B[j-1]
                        j = j - 1

        endTime = time.time()
        return B, endTime - startTime

import random
import sys
if __name__ == "__main__":
    n = 10000
    if len(sys.argv) > 1:
        try:
            n = int(sys.argv[1])
        except Exception as e:
            print("Expected number. Default n = 10000 choosen")
    print(f"Testing for n = {n}")
    rand_list = []
    start = 1
    end = 1000000
    for i in range(n):
        num = random.randint(start, end)
        rand_list.append(num)
    test2 = InsertionSort(rand_list)
    print(f"Normal(Without Binary Search): {test2.t_basic}")
    print(f"With binary search: {test2.t_bsearch}")
    print(f"With BSearch + pairing: {test2.t_bpairsearch}")
    print(f"Pairing: {test2.t_pairsearch}")