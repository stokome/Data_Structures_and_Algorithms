''' 
Trees are hierchial data strucutres

Why use Tree -
1. Used to store hierchial structures like File System in Linux
2. Traveral is better than linked list but slower than array
3. Insertion Deletion is better than array but slower than Linked List
4. Unlike arrays(like Linked Lists) Trees can have as many number of nodes they require.

Main applications of tree-
1. Manipulate hierchial data
2. Make information easy to search (Tree traversal)
3. Manipulate Sorted list of data
4. As a workflow for compositing digital imiges for visual effects.
5. Router Algorithms
6. Form of multistage descision-making



Binary Tree - Tree with each node having two or less child.

Binary Tree representation -
1. Data, 2. Pointer to the left node, 3. Pointer to the rigt node'''


from turtle import left
from sklearn.model_selection import PredefinedSplit


class TreeNode:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


#creating a basic tree 

root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

'''
Following tree would be formed
            1
       /       \
      2          3
    /   \       /  \
   4     5     6    7
  /  \  /  \  / \  /  \
None None  None None  None '''

'''
PROPERTIES OF THE BINARY TREES 

1. The maximum number of node at level 'l' is 2^l
2. The maximum no of nodes in a binary tree of height 'h' is 2^h-1
3. A Binary Tree with 'N' nodes, minimum height = log(N+1)
4. A Binary Tree with L leaves has a least Log(L)+1 levels
5. In a Binary Tree with each node having 0 or 2 children, the number of leaf nodes is always one more than nodes with two children


                                  L = T + 1
                                  Where L = Number of leaf nodes
                                  T = Number of internal nodes with two children
                                  Proof:
                                  No. of leaf nodes (L) i.e. total elements present at the bottom of tree = 
                                  2^(h-1) (h is height of tree)
                                  No. of internal nodes = {total no. of nodes} - {leaf nodes} = 
                                  { 2^h - 1 } - {2^(h-1)} = 2^(h-1)* (2-1) - 1 = 2^(h-1) - 1
                                  So , L = 2^(h-1)
                                      T = 2h-1 - 1
                                  Therefore L = T + 1
                                  Hence proved


TYPES OF BINARY TREE

1. Full Binary Tree - Every node has 0 or 2 children
2. Complete Binary Tree - All levels are completely fixed except last and last level elements are as left as possible 
3. Perfect Binary Tree - All nodes havetwo children and all leaf node are on same level
4. Degenerate Tree - All node have atmost 1 child. This tree is same as a linked lists.
5. Balanced Binary Trees - A Binary Tree is balanced if height of the tree is O(log(n)), where n is no of nodes in the tree. Balanced 
                           Binary Trees are performance-wise good as they provide O(log(n)) time for search, insert, delete.
                           Types of Balanced Binary Trees-
                           1. AVL Trees
                           2. Red-Black Trees

TREE TRAVERSAL
 
Tree is typically travesrsed in two ways-

1. Breadth First Traversal (BFS or Level Order Search)
2. Depth First Traversals (DFS)

Time Complexity - Time Complexity of both traversal is O(n) as all n nodes are to be visited.

Space Complexity - 1. Extra space required for BFS is O(w) where w is maximum width of the binary tree. Queue one by one 
                      stores nodes of different levels
                   2. Extra Space requried for DFS is O(h) where is the height of the binary tree. Stack(or function call stack) 
                      stores all ancestors of a node.

                Worst case space time complexity for BFS and DfS is O(n)    
'''

'''
Breadth First Traversal (BFS) or Level Order Search is simply traversing through the tree level by level, covering each level from left to right
'''
# Level Order Search
def levelOrderTraversal(rootNode):

  # Base Case
  if rootNode is None:
    return

  # initialize a queue
  queue = []

  # Enqueue root node
  queue.append(rootNode)

  while( len(queue) > 0):

    # Pop the queue
    print(queue[0].data)
    node = queue.pop(0)

    # enqueue left child
    if node.left is not None:
      queue.append(node.left)

    # enqueue right child
    if node.right is not None:
      queue.append(node.right)
'''
Depth First Traversal (DFS) can be achieved in three ways - 
1. InOrder Traversal - Left Subtree --> Root --> Right Subtree
'''
#InOrder
def inOrderTraversal(rootNode):
  if rootNode:

    #first left subtree traversal
    inOrderTraversal(rootNode.left)

    #then root ndoe
    print(rootNode.data, end = " ")

    #then right node
    inOrderTraversal(rootNode.right)


# InOrder Traversal without Recursion (with stack)
# Iterative InOrder Traversal
def inOrderStack(rootNode):

  # Set Current to root of banry tree
  current = rootNode
  stack = []  # initialize stack

  while True:

    # Reach the left most node of the left subtree of the binary tree
    if current is not None:

      # Saving pointer of all the nodes traversed in the stack
      stack.append(current)
      current = current.left

    # Backtrack from the empty subtreeand visit the Node at the top of the stack.
    # If the stack is empty, EXIT
    elif(stack):

      current = stack.pop()
      print(current.data, end = " ")

      # Node and left subtree is visited now its right subtree's turn
      current = current.right

    else:
      break

# InOrder Traversal without Recursion and Stack
# Morris Traversal

'''        
2. PreOrder Traversal - Root --> Left Subtree --> Right Subtree
'''
# PreOrder
def preOrderTraversal(rootNode):
  if rootNode:

    # first root node
    print(rootNode.data, end = " ")

    # then left subtree
    preOrderTraversal(rootNode.left)

    # then right subtree
    preOrderTraversal(rootNode.right)
# PreOrder Traversal without Recursion (with stack)
# Iterative PreOrder Traversal
def preOrderStack(rootNode):

  # Set current to root node
  current = rootNode
  stack = [] # Initailize a stack

  while True:

    if current is not None:

      stack.append(current)
      print(current.data, end = " ")
      current = current.left

    elif(stack):

      current = stack.pop()
      current = current.right

    else:
      break

                #OR

def iterativePreorder(rootNode):

  if rootNode is None:
    return

  stack = []
  stack.append(rootNode)

  while( len(stack) > 0):

    node = stack.pop()
    print(node.data, end = " ")

    if node.right is not None:
      stack.append(node.right)
    
    if node.left is not None:
      stack.append(node.left)

'''
3. PostOrder Traversal - Left Subtree -->Right Subtree --> Node
'''
# PostOrder
def postOrderTraversal(rootNode):
  if rootNode:

    # first left subtree
    postOrderTraversal(rootNode.left)

    # then right subtree
    postOrderTraversal(rootNode.right)

    # then root node
    print(rootNode.data, end = " ")

# PostOrder Traversal without Recursion (with stack)
# Iterative PostOrder Traversal
def postOrderStack(rootNode):

  # Base condition
  if rootNode is None:
    return

  # Initializing two stacks
  stack_1 = []  
  stack_2 = []

  stack_1.append(rootNode)


  while stack_1:

    # Taking out element from stack_1 and putting insitde stack_2
    node = stack_1.pop()
    stack_2.append(node)

    # Placing left node of poped element in stack_1
    if node.left is not None:
      stack_1.append(node.left)

    # Placing right node of popped element in stack_2
    if node.right is not None:
      stack_1.append(node.right)

  # printing out contents of stack_2
  while stack_2:

    node = stack_2.pop()
    print(node.data, end = " ")

    
'''
MORRIS TRAVERSAL - In this traversal we traverse without using stack or recursion. This traversal uses the concept of threded
                   Binary Tree. First the inorder/preorder/postorder predecessor of the node is found. then that predecessor is
                   made to point at the current node. When the treversal is done the thred between predecossor and the current node
                   is destroyed retoring the oringnal order of the binary tree.

                   Time Complexity - O(n)
                   Space Complexity - O(1) // overhead over other traversal techniches


        ALgo: 
              1. initialize current as root node
              
              2.While current is not NUL
                If current.left not exist:
                  visit(current)
                  current = current.right
                
                Else:
                  predecessor = find_predecessor(current)

                  If predecessor.right not exist:
                    predecessor.right = current
                    current  = current.left
                  
                  Else:
                    predecessor.right = NULL
                    visit(current)
                    current = current.right

'''

def inorder_Morris_Traversal(rootNode):
  
  # initialize current as root node
  current = rootNode

  while current is not None:

    # if left subtree dosent exist
    if current.left is None:

      print(current.data, end = " ")
      current  = current.right

    else:

      # find inorder predecessor of current (right most node on the left subtree)
      predecessor = current.left
      while predecessor.right is not None and predecessor.right is not current:
        predecessor = predecessor.right

      if predecessor.right is None:

        # make current as right child of its indorder predecessor
        predecessor.right = current
        current = current.left

      else:

        # destroy the thred created in above if statement when node are visited again and restore the orignal tree
        predecessor.right = None
        print(current.data, end = " ")
        current = current.right


def preOrder_Morris_traversal(rootNode):

  current = rootNode

  while current is not None:

    if current.left is None:
      print(current.data, end = " ")
      current = current.right

    else:
      
      predecessor = current.left
      while predecessor.right is not None and predecessor.right is not current:
        predecessor = predecessor.right

      if predecessor.right is None:

        predecessor.right = current
        print(current.data, end = " ")
        current = current.left

      else:

        predecessor.right = None
        current = current.right

# Diagnal Travesal
def diognal_traversal(rootNode):

  out = []
  node  = rootNode

  # queue to store left nodes
  left_q = []

  while node:

    out.append(node.data)

    # if left child exist, send it to left_q
    if node.left:
      left_q.append(node.left)

    # if right child exist, change the node
    if node.right:
      node  = node.right

    else:
      if len(left_q)>=1:
        node = left_q.pop(0)
      else:
        node = None
      
  print(out)


# InOrder Successor of a Node in Binary Tree
# Printer the Inorder Traversal in reverse order, we stop when we find target_node. InOrder Successor would be the node traversed before it.
def inOrderSuccessor(root, target_node):

  # if root is none then return
  if root is None:
    return

  inOrderSuccessor(root.right, target_node)

  global next
  # if target node is found
  if(root.data == target_node):

    # this will be true to the last node in inorder traversal i.e. rightmost node
    if(next == None):
      print("InOrder Successor of ", root.data, "is : None" )

    else:
      print("InOrder Successor of ", root.data, "is : ", next.data )

  
  next = root # storing the value of last node in a global variable
  inOrderSuccessor(root.left, target_node) # if left node exist check that also

next = None # global variable


'''
GENERATING TREES FROM TRAVERSALS

Binary Tree can be generated if and only if-
1. PreOrder adn InOrder is given
2. PostOrder and InOrder is given
'''


# Generate tree from preOrder and InOrder
# Parameters are-  1.inOrder array 2.preOrder array 3.start index of inOrder 4.end index of inOrder 

def buildTree(inOrder, preOrder, inOrderStart, inOrderEnd):

    if(inOrderStart > inOrderEnd):
      return None

    global preIndex, mp
    # Pick current node from preOrderarray using preIndex and increment the preIndex
    current = preOrder[preIndex]
    newNode = TreeNode(current)
    preIndex += 1

    # if this node as no children
    if inOrderStart == inOrderEnd:
      return newNode

    # Else seach this node in inOrder list
    # inIndex = search(inOrder, inOrderStart, inOrderEnd, newNode.data)
    inIndex = mp[current]

    # Using recursion to make left and right subtrees
    newNode.left = buildTree(inOrder, preOrder, inOrderStart, inIndex-1 )
    newNode.right = buildTree(inOrder, preOrder, inIndex+1, inOrderEnd)

    return newNode


# Search function helps in generation of Binary Tree
def search(arr, start, end, key):
  for i in range(start, end+1):
    if arr[i] == key:
      return i

'''
Time Complexity of the buildTree function can be improved by using hash tables to store indexes of InOrder list
so that search can be done O(1 time)
'''
def buildTreeHashed(inOrder, preOrder, len_inOrder):

  global mp

  # Store indexes of all items so that we
  # we can quickly find later
  # unordered_map<char, int> mp;

  for i in range(len_inOrder):
    mp[inOrder[i]] = i

  return buildTree(inOrder, preOrder, 0, len_inOrder-1)

'''
# Generate Binary Tree Using preOrder and inOrder Traversal
 
inorder = ['D', 'B', 'E', 'A', 'F', 'C']
preorder = ['A', 'B', 'D', 'E', 'C', 'F']
# Static variable preIndex
preIndex = 0
mp = {}
new_root = buildTreeHashed(inorder, preorder, len(inorder))

inOrderTraversal(new_root)
'''

# Height of a Tree
def heightTree(rootNode):
        
  current = rootNode
  
  if rootNode is None:
      return 0
  
  h = max(1+heightTree(current.left), 1+heightTree(current.right))
  return h


# Count of nodes

def countNodeTree(rootNode):

  if rootNode:
    return countNodeTree(rootNode.left)+countNodeTree(rootNode.right)+1
  return 0


# mirror image of a tree
# Method 1 creating a new mirror tree
def tree_mirror_func1(rootNode, mirror):

  if rootNode is None:
    mirror = None
    return mirror

  mirror = TreeNode(rootNode.data)

  mirror.right = tree_mirror_func1(rootNode.left, mirror.right)
  mirror.left = tree_mirror_func1(rootNode.right, mirror.left)

  return mirror
  
'''
mirror_tree = None
tree = tree_mirror_func1(root, mirror_tree)
inorder_Morris_Traversal(root)
print("")
inorder_Morris_Traversal(tree)
'''
# Method 2 by converting orignal tree into  mirror tree
def mirrorifyTree(rootNode):
  if rootNode is None:
    return rootNode

  mirrorifyTree(rootNode.left)
  mirrorifyTree(rootNode.right)

  rootNode.left, rootNode.right = rootNode.right, rootNode.left


'''
inorder_Morris_Traversal(root)
print(" ")
mirrorifyTree(root)
inorder_Morris_Traversal(root)
'''

# Vertical Order Traversal using hashing
def verticalOrderHashing(rootNode, hd, mp):

  if rootNode is None:
    return

  # store current node data in map mp
  try:
    mp[hd].append(rootNode.data)
  
  except:
    mp[hd] = [rootNode.data]

  
  verticalOrderHashing(rootNode.left, hd-1, mp)

  verticalOrderHashing(rootNode.right, hd+1, mp)

def verticalOrderTraversal(rootNode):

  mp = dict()
  hd = 0
  verticalOrderHashing(rootNode, hd, mp)

  for index,  value in enumerate(sorted(mp)):
    
    for i in mp[value]:
      print(i, end = " ")
    print("")




