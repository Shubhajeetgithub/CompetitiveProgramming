# say A = [1, 3, 4, 5| 2, 6, 10, 15| 7, 8, 9, 11], here m = 4, n = 12
#          .           .             .
# create a MIN-HEAP

class CustomMinHeap:
    def __init__(self, A):
        self.A = A
        self._build_heap()

    def _parent(self, i):
        return (i - 1) // 2

    def _left_child(self, i):
        return 2 * i + 1

    def _right_child(self, i):
        return 2 * i + 2

    def _swap(self, i, j):
        self.A[i], self.A[j] = self.A[j], self.A[i]

    def _heapify_down(self, i):
        n = len(self.A)
        smallest = i
        left = self._left_child(i)
        right = self._right_child(i)

        if left < n and self.A[left][0] < self.A[smallest][0]:
            smallest = left
        if right < n and self.A[right][0] < self.A[smallest][0]:
            smallest = right

        if smallest != i:
            self._swap(i, smallest)
            self._heapify_down(smallest)

    def _build_heap(self):
        n = len(self.A)
        start_node = n // 2 - 1
        for i in range(start_node, -1, -1):
            self._heapify_down(i)

    def push(self, a):
        self.A.append(a)
        n = len(self.A)
        i = n - 1
        while i > 0 and self.A[self._parent(i)][0] > self.A[i][0]:
            self._swap(i, self._parent(i))
            i = self._parent(i)


    def pop(self):
        if len(self.A) == 0:
            return None
        if len(self.A) == 1:
            return self.A.pop()

        root = self.A[0]
        self.A[0] = self.A.pop()
        self._heapify_down(0)
        return root

    def top(self):
        if (len(self.A) == 0):
            print("Heap empty")
            return None
        else:
            return self.A[0]

    def isEmpty(self):
        return len(self.A) == 0


class PiecewiseSort:
    def __init__(self, A, m):
        self.A = A
        self.m = m
    def sort(self):
        n = len(self.A)
        num_pieces = n // self.m
        ids = [self.m * i for i in range(num_pieces)]
        maxBound = [self.m * (i + 1) for i in range(num_pieces)]

        # arr will store the initial elements for the heap: [value, piece_index]
        arr = []
        for i in range(num_pieces):
            if ids[i] < n:
                arr.append([self.A[ids[i]], i])

        heap = CustomMinHeap(arr)
        B = []
        while not heap.isEmpty():
            smallest_element_info = heap.pop()
            B.append(smallest_element_info[0])
            piece_index = smallest_element_info[1]

            ids[piece_index] += 1

            if ids[piece_index] < maxBound[piece_index] and ids[piece_index] < n:
                heap.push([self.A[ids[piece_index]], piece_index])

        return B


import sys
def read_integers_from_file(filename):
    """
    Reads integers from a specified file, one integer per line.
    """
    integers = []
    try:
        with open(filename, 'r') as f:
            for line in f:
                try:
                    integer_value = int(line.strip())
                    integers.append(integer_value)
                except ValueError:
                    print(f"Warning: Could not convert '{line.strip()}' to an integer in {filename}. Skipping.")
    except FileNotFoundError:
        print(f"Error: File '{filename}' not found.")
        sys.exit(1)
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
        sys.exit(1)
    return integers


def main():
    if len(sys.argv) > 1:
        try:
            filename = sys.argv[1]
            data = read_integers_from_file(filename)
            m = int(sys.argv[2])
            sorter = PiecewiseSort(data, m)
            B = sorter.sort()
            for b in B:
                print(b)
        except Exception as e:
            print("Unexpected command")
if __name__ == "__main__":
    main()