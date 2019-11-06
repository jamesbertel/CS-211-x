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
  TreeNode *copyTree(TreeNode*);

public:
  // Constructor
  IntBinaryTree() { root = NULL; }

  // Copy constructor
  IntBinaryTree(const IntBinaryTree &);
  // Destructor
  ~IntBinaryTree() { destroySubTree(root); }

  // Binary tree operations
  void insertNode(int);
  bool searchNode(int);
  void remove(int);

  void displayInOrder() const { displayInOrder(root); }

  // Overloaded Assignment Operator
  IntBinarytree operator= (const IntBinaryTree & );
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
//destroySubTree is called by the destructor. It
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
  if (nodePtr)
    {
      if (nodePtr->left)
        {
          displayInOrder(nodePtr->left);
        }

      if (nodePtr->right)
        {
          displayInOrder(nodePtr->right);
        }

      //cout << *nodePtr << " ";
    }

  cout << endl;
}
//*********************************************************
// Copy Constructor
// calls the copyTree function
IntBinaryTree::IntBinaryTree (const IntBinaryTree &tree )
{
  TreeNode *node = tree.root;
}
//***********************************************
// Assignment Operator
// Hint: destroy all nodes in the old tree then use the
// copyTree function
IntBinaryTree::IntBinaryTree operator= ( const IntBinaryTree &tree )
{
  IntBinaryTree temp;
  //???
  copyTree();
}
//********************************************************
// copyTree Function: called by copy constructor and
// Assignment operator function. This function copies all tree nodes
// by visiting the root nodes first (pre-order traversal)
IntBinaryTree::TreeNode *IntBinaryTree::copyTree(TreeNode *nPtr)
{
  IntBinaryTree newtree;
  newtree.root = nPtr;
  TreeNode *newNode = NULL; // Pointer to a new node.
  newNode = new TreeNode;

  if (nPtr)
    {
      if (nPtr->left)
        {
          copyTree(nPtr->left);
        }

      if (nPtr->right)
        {
          copyTree(nPtr->right);
        }

      //something else...
    }
  
}
//********************************************************
int main()
{
  // Create two binary trees for holding integers.
  IntBinaryTree tree1, tree2;
  // Insert some nodes into tree1.
  tree1.insertNode(55);
  tree1.insertNode(5);
  tree1.insertNode(8);
  // Display the nodes in tree1.
  cout << "\nHere are the nodes of tree1:\n";
  tree1.displayInOrder();
  cout << endl;
  // Assign tree1 to tree2.
  tree2 = tree1;
  // Display the nodes in tree2.
  cout << "Now, here are the nodes of tree2:\n";
  tree2.displayInOrder();
  cout << endl;
  // Modify tree 1 by adding 3 nodes to tree 1
  tree1.insertNode(10);
  tree1.insertNode(3);
  tree1.insertNode(12);
  // Display the nodes in tree1.
  cout << "\nHere are the nodes of tree1 after adding 3 nodes:\n";
  tree1.displayInOrder();
  cout << endl;
  // Display the nodes in tree2.
  cout << "\nHere are the nodes of tree2:\n";
  tree2.displayInOrder();
  cout << endl;
  // Define another IntBinaryTree object and initialize it
  // with tree1. This will invoke the copy constructor.
  IntBinaryTree tree3 = tree1;
  // Display the nodes in tree3.
  cout << "Now, here are the nodes of tree3:\n";
  tree3.displayInOrder();
  cout << endl;
  // Remove one node from tree 1
  tree1.remove(5);
  // Display the nodes in tree1.
  cout << "\nHere are the nodes of tree1 after removing node 5:\n";
  tree1.displayInOrder();
  cout << endl;
  // Display the nodes in tree3.
  cout << "Now, here are the nodes of tree3:\n";
  tree3.displayInOrder();
  cout << endl;
  return 0;
}
