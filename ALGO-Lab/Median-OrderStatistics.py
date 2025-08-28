"""
Name: Shubhajeet Das
Roll No.: 24AI10013
14 Aug 2025
"""

import sys
from collections import defaultdict
import time

def read_data_from_file(filename):
    data = []
    try:
        with open(filename, 'r') as f:
            for line in f:
                try:
                    # Split line into fields and take only the first two
                    fields = line.strip().split()[:2]
                    # Convert fields to integers and append as a tuple
                    data.append(tuple(map(int, fields)))
                except ValueError:
                    # Warning for lines that cannot be converted to integers
                    print(f"Warning: Could not convert '{line.strip()}' to integers in {filename}. Skipping line.")
                except IndexError:
                     # Warning for lines that don't have at least two fields
                     print(f"Warning: Line '{line.strip()}' does not have two fields in {filename}. Skipping line.")
    except FileNotFoundError:
        # Error and exit if the file is not found
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)
    except Exception as e:
        print(f"An unexpected error occurred during file reading: {e}")
        sys.exit(1)
    return data

def select_pivot(A, field=0):
    n = len(A)
    if n == 1:
        return A[0]

    def get_value(x):
        return x[field] if isinstance(x, (list, tuple)) else x

    medians = []
    for i in range(0, n, 5):
        group = A[i:i+5]
        for j in range(len(group)):
            k = j
            while k > 0 and get_value(group[k - 1]) > get_value(group[k]):
                group[k - 1], group[k] = group[k], group[k - 1]
                k -= 1
        medians.append(group[len(group) // 2])
    return select_pivot(medians, field)


def partition(A, l, r, pivot, field=0):
    def get_value(x):
        return x[field] if isinstance(x, (list, tuple)) else x
    pivot_value = get_value(pivot)

    for i in range(l, r + 1):
        if get_value(A[i]) == pivot_value:
            A[i], A[r] = A[r], A[i]
            break

    store_index = l
    for i in range(l, r):
        if get_value(A[i]) < pivot_value:
            A[i], A[store_index] = A[store_index], A[i]
            store_index += 1

    A[store_index], A[r] = A[r], A[store_index]
    return store_index


def mSmallest_MULTIDIM(A, l, r, m, field=0):
    if l == r:
        return A[l]

    pivot = select_pivot(A[l:r+1], field)
    q = partition(A, l, r, pivot, field)
    k = q - l + 1

    if m == k:
        return A[q]
    elif m < k:
        return mSmallest_MULTIDIM(A, l, q - 1, m, field)
    else:
        return mSmallest_MULTIDIM(A, q + 1, r, m - k, field)



def mSmallest_pairs(A, l, r, m):
    if l == r:
        return A[l]


    pivot = select_pivot(A[l:r+1], field=0)
    q = partition(A, l, r, pivot, field=0)
    k = q - l + 1

    if m == k:
        return A[q]
    elif m < k:
        return mSmallest_pairs(A, l, q - 1, m)
    else:
        return mSmallest_pairs(A, q + 1, r, m - k)


def kClosest_optimized(A, k, field=0):
    n = len(A)
    if k >= n: # If k is greater than or equal to the number of elements, return all elements
        return A[:]

    if n % 2 == 0:
        # For even number of elements, median is the average of the two middle elements
        m1_val = mSmallest_MULTIDIM(A[:], 0, n - 1, n // 2, field)[field]
        m2_val = mSmallest_MULTIDIM(A[:], 0, n - 1, n // 2 + 1, field)[field]
        median = (m1_val + m2_val) / 2
    else:
        # For odd number of elements, median is the middle element
        median = mSmallest_MULTIDIM(A[:], 0, n - 1, n // 2 + 1, field)[field]


    diff_pairs = []
    for item in A:
        # Handle potential floating point median for integer data
        diff = abs(item[field] - median)
        diff_pairs.append((diff, item)) # Store pair: (difference, original_element)

    mSmallest_pairs(diff_pairs, 0, n - 1, k)

    result = [pair[1] for pair in diff_pairs[:k]]

    return result

def main():
    try:
        filename = sys.argv[1]
        data = read_data_from_file(filename)
        k = int(sys.argv[2])
        closest_elements = kClosest_optimized(data, k, field=1)
        for r in closest_elements:
            print(r[0])
    except Exception as e:
        print("Error occured")

if __name__ == "__main__":
    main()