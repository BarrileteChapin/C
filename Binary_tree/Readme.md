Implementation of a binary tree with the following functions: 

-Traverse : print preorder, inorder, postorder traversal of the binary tree

-Height : print the height of the binary tree

-WeightSum : print the sum of all the node’s weight in the binary tree

-MaximumPathSum : print the maximum sum among all root to leaf paths of the binary tree

-BinaryTower : print the number of towers needed to defend the hole binary tree (parent and its children - this functionality needs to be improved)

-DeleteLeaf : delete all the leaves in the binary tree

-Foldable : Print “Yes” or “No” Depending on the binary tree foldable or not. **without double quotes**

-End : End of instructions of this question set.

-------------------------

Input is composed by several sets of questions

A set of question will start by a s-expression string, then followed by several instructions that end with the instruction “End”

First you’ll see an s-expression string. Then, you’ll see several instructions. Finally, you’ll see an “End” instruction, and after that you’ll see EOF or next s-expression string

Note :

The length of each s-expression is at most 10000000
The number of nodes in each tree is at most 1200000
Each nodes’ weight is between -100000 and 100000

-------------------

Example: 

°Input

(1(2(4()())(5()()))(3(6()())(7()())))

Traverse

Height

WeightSum

MaximumPathSum

BinaryTower

Foldable

DeleteLeaf

Traverse

End

°Output
1 2 4 5 3 6 7 

4 2 5 1 6 3 7 

4 5 2 6 7 3 1 

3

28

11

2

Yes

1 2 3 

2 1 3 

2 3 1

--------------

-Date: 11/2020
