#include <iostream>
using namespace std;
class IntBinaryTree
{
private:
 struct TreeNode
 {
   int value; // The value in the node
   TreeNode *left; // Pointer to left child node
   TreeNode *right; // Pointer to right child node
 };
  TreeNode *root; // Pointer to the root node

  // Private member functions
  void insert(TreeNode *&, TreeNode *&);
  void destroySubTree(TreeNode *);
  void deleteNode(int, TreeNode *&);
  void makeDeletion(TreeNode *&);
  void displayInOrder(TreeNode *) const;
  int countLeafNodes(TreeNode *&);
  int getTreeHeight(TreeNode *);
public:
  // Constructor
  IntBinaryTree() { root = NULL; }

  // Destructor
  ~IntBinaryTree() { destroySubTree(root); }

  // Binary tree operations
  void insertNode(int);
  bool searchNode(int);
  void remove(int);

  void displayInOrder() const { displayInOrder(root); }

  int numLeafNodes();
  int treeHeight();


};
//***********************************************************
// insert accepts a TreeNode pointer and a pointer to a node.
// The function inserts the node into the tree pointed to by
// the TreeNode pointer. This function is called recursively.
void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
  if (nodePtr == NULL)
    {
      nodePtr = newNode; // Insert the node.
    }
  else if (newNode->value < nodePtr->value)
    {
      insert(nodePtr->left, newNode); // Search the left branch
    }
  else
    {
      insert(nodePtr->right, newNode);// Search the right branch
    }
}
//**********************************************************
// insertNode creates a new node to hold num as its value,
// and passes it to the insert function.
void IntBinaryTree::insertNode(int num)
{
  TreeNode *newNode = NULL; // Pointer to a new node.
  // Create a new node and store num in it.
  newNode = new TreeNode;
  newNode->value = num;
  newNode->left = newNode->right = NULL;

  // Insert the node.
  insert(root, newNode);
}
//***************************************************
// destroySubTree is called by the destructor. It
// deletes all nodes in the tree.
void IntBinaryTree::destroySubTree(TreeNode *nodePtr)
{
  if (nodePtr)
    {
      if (nodePtr->left)
	{
	  destroySubTree(nodePtr->left);
	}

      if (nodePtr->right)
	{
	  destroySubTree(nodePtr->right);
	}

      delete nodePtr;
    }
}

//***************************************************
// searchNode determines if a value is present in
// the tree. If so, the function returns true.
// Otherwise, it returns false.
bool IntBinaryTree::searchNode(int num)
{
  bool status = false;
  TreeNode *nodePtr = root;
  while (nodePtr)
    {
      if (nodePtr->value == num)
	{
	  status = true;
	}
      else if (num < nodePtr->value)
	{
	  nodePtr = nodePtr->left;
	}
      else
	{
	  nodePtr = nodePtr->right;
	}
    }
  return status;
}
//**********************************************
// remove calls deleteNode to delete the
// node whose value member is the same as num.
void IntBinaryTree::remove(int num)
{
  deleteNode(num, root);
}
//********************************************
// deleteNode deletes the node whose value
// member is the same as num.
void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{
  if (num < nodePtr->value)
    {
      deleteNode(num, nodePtr->left);
    }
  else if (num > nodePtr->value)
    {
      deleteNode(num, nodePtr->right);
    }
  else
    {
      makeDeletion(nodePtr);
    }
}
//***********************************************************
// makeDeletion takes a reference to a pointer to the node
// that is to be deleted. The node is removed and the
// branches of the tree below the node are reattached.
void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
  // Define a temporary pointer to use in reattaching
  // the left subtree.
  TreeNode *tempNodePtr = NULL;
  if (nodePtr == NULL)
    {
      cout << "Cannot delete empty node.\n";
    }
  else if (nodePtr->right == NULL)
    {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left; // Reattach the left child
      delete tempNodePtr;
    }
  else if (nodePtr->left == NULL)
    {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right; // Reattach the right child
      delete tempNodePtr;
    }
  // If the node has two children.
  else
    {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
	{
	  tempNodePtr = tempNodePtr->left;
	}

      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
    }
}
//****************************************************************
// The displayInOrder member function displays the values
// in the subtree pointed to by nodePtr, via inorder traversal.
void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
}
//********************************************************
// numNodes Function: calls countLeafNodes and returns the number
// of leaf nodes in the tree
int IntBinaryTree::numLeafNodes()
{
}
//****************************************************************
// The countLeafNodes function uses recursion to count the number
// of leaf nodes in the tree. This function is called by the public
// member function numLeafNodes. It visits all the root nodes first
// (pre-order traversal)
int IntBinaryTree::countLeafNodes(TreeNode *&nodePtr)
{
}
//*************************************************************
// Function TreeHeight
// Calls getTreeHeight and displays the height or depth of tree.
int IntBinaryTree::treeHeight()
{
}
//*************************************************************
// Function getTreeHeight
// This function uses recursion to count the height of
// the tree.
int IntBinaryTree::getTreeHeight(TreeNode* nodePtr)
{
}
//********************************************************
int main()
{
  // Create a binary tree to hold integers.
  IntBinaryTree tree;
  // Show the initial height, with no nodes.
  cout << "Height: " << tree.treeHeight() << endl;
  cout << endl;
  // Insert some nodes into the tree.
  cout << "Inserting nodes.\n";
  tree.insertNode(5);
  tree.insertNode(8);
  tree.insertNode(3);
  tree.insertNode(12);
  tree.insertNode(9);
  cout << endl;
  // Display the nodes.
  cout << "Here are the values in the tree:\n";
  tree.displayInOrder();
  cout << endl;
  // Display the tree height.
  cout << "Height: " << tree.treeHeight() << endl;
  cout << endl;
  // Display the number of leaf nodes in tree.
  cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;
  // Delete some nodes.
  cout << "Deleting 8...\n";
  tree.remove(8);
  cout << "Deleting 12...\n";
  tree.remove(12);
  cout << endl;
  // Display the nodes that are left.
  cout << "Now, here are the nodes:\n";
  tree.displayInOrder();
  cout << endl;
  // Display the tree height.
  cout << "Height: " << tree.treeHeight() << endl;
  cout << endl;
  // Display the number of leaf nodes in tree.
  cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;
  return 0;
}
