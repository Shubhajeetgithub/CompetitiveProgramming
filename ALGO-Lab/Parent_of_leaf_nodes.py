"""
Name: Shubhajeet Das
Roll No.: 24AI10013
21 Aug 2025
BST
"""

def debug_print(str):
    print(f"Working: {str}")

#DEFINING BINARY TREE NODE
class Node:
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

#ADDING ELEMENT
def add_to_BST(head: Node, node: Node):
    if head is None:
        return node
    if node.val == head.val:
        return head #as duplicate elements need not be added
    elif node.val < head.val:
        #move to left half
        head.left = add_to_BST(head.left, node)
    else:
        #move to right half
        head.right = add_to_BST(head.right, node)
    return head

#printing inorder traversal to check BST formation
def inorder_traversal(head: Node):
    if head is None:
        return
    inorder_traversal(head.left)
    print(head.val)
    inorder_traversal(head.right)

#Our goal is to find the nodes just above leaf nodes and store that in an array
def find_parent_of_leaf(head: Node, arr):
    if head is None or (head.left is None and head.right is None):
        return
    left_next = head.left
    right_next = head.right
    if left_next is None and right_next is not None:
        if right_next.left is None and right_next.right is None:
            arr.append(head)
        else:
            find_parent_of_leaf(right_next, arr)
    elif right_next is None and left_next is not None:
        if left_next.left is None and left_next.right is None:
            arr.append(head)
        else:
            find_parent_of_leaf(left_next, arr)
    elif left_next.left is None and left_next.right is None and right_next.left is None and right_next.right is None:
        arr.append(head)
    else:
        find_parent_of_leaf(head.left, arr)
        find_parent_of_leaf(head.right, arr)



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
    #taking input from file
    if len(sys.argv) > 1:
        try:
            filename = sys.argv[1]
            data = read_integers_from_file(filename)
            root = Node(data[0])
            for i in range(1, len(data)):
                node = Node(data[i])
                root = add_to_BST(root, node)
            arr = []
            find_parent_of_leaf(root, arr)
            for a in arr:
                print(f"{a.val} 1")
        except Exception as e:
            print("Unexpected command")
    """
    data = read_integers_from_file("input.txt")
    root = Node(data[0])
    for i in range(1, len(data)):
        node = Node(data[i])
        root = add_to_BST(root, node)
    arr = []
    find_parent_of_leaf(root, arr)
    for a in arr:
        print(f"{a.val} 1")
    """


if __name__ == "__main__":
    main()

