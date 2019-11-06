#include <iostream>
#include <string>
using namespace std;

class Node
{
  friend class LL;

private:
  string firstName;
  string lastName;
  string phoneNum;
  Node* next;
};

class LL
{


private:
  Node* head;
public: 
  LL();
  void append(string fName, string lName, string phone);
  void insertAtBegin(string fName, string lName, string phone);
  void print();
  void insertAtPos(string fName, string lName, string phone, int pos);
  void searchByName(string fName, string lName);
  void updateNumber(string fName, string lName, string newPhone);
  void removeRecord(string fName, string lName);
  ~LL();
  void destroy();
  LL(const LL& source);
};

void LL::removeRecord(string fName, string lName)
{
  Node *nodeptr;
  Node *prevnode;
  nodeptr = head;
  if(!head)
    return;
  else if(head->firstName == fName && head->lastName == lName)
    {
      nodeptr = head->next;
      delete head;
      head = nodeptr;
    }
  else
    {
      nodeptr = head;
      int count=0;

      while(nodeptr->firstName != fName && nodeptr->lastName != lName && nodeptr != NULL)
	{
	  prevnode = nodeptr;
	  nodeptr = nodeptr->next;
	  cout << count++;
	}
	  //cout << " " << *nodeptr << endl;
      if(nodeptr)//->firstName == fName && nodeptr->lastName == lName)
	{
	  prevnode->next = nodeptr->next;
	  delete nodeptr;
	}
      else if(nodeptr == NULL)
	cout << "BIG ERROR!\n";
    }
}


LL::~LL()
{
  Node*nodeptr;
  Node * nextnode;
  nodeptr = head;
  while(nodeptr != NULL)
    {
      nextnode = nodeptr->next;
      delete nodeptr;
      nodeptr = nextNode;
    }
}

LL::LL(const LL& source)
{
  
}

//Past Functions Below ************************

void LL::insertAtPos(string fName, string lName, string phone, int pos)
{
  Node *prevnode = NULL;
  Node *nodeptr = new Node;
  Node *newnode = new Node;
  
  newnode->firstName = fName;
  newnode->lastName = lName;
  newnode->phoneNum = phone;

  if(!head)
    { 
      head = newnode;
      newnode->next = NULL;
    }
  else
    {
      nodeptr = head;
      for(int i = 1; i < pos; i++)
	{
	  prevnode = nodeptr;
	  nodeptr = nodeptr->next;
	}

      if(prevnode == NULL)
	{
	  head = newnode;
	  newnode->next = nodeptr;
	}
      else //insert after previous node
	{
	  prevnode->next = newnode;
	  newnode->next = nodeptr;
	}
    }
}
void LL::searchByName(string fName, string lName)
{
  Node* newNode = new Node;

  // newNode->firstName = fName;
  //newNode->lastName = lName;
  //newNode->phoneNum;
  //newNode->next = NULL;

  Node *nodeptr;
  nodeptr = head;
  
  while(nodeptr != NULL)
    {
      if(nodeptr->firstName == fName && nodeptr->lastName == lName)
	{	
	  cout << nodeptr->phoneNum << endl;
	}
      nodeptr = nodeptr->next;
	
    }
}
void LL::updateNumber(string fName, string lName, string newPhone)
{
  Node *nodeptr;
  nodeptr = head;
  int count = 0;
  while(nodeptr != NULL)
    {
      if(nodeptr->firstName == fName && nodeptr->lastName == lName)
        {
          nodeptr->phoneNum = newPhone;
	  count++;
	}
      nodeptr = nodeptr->next;
    }
  if(count==0)
    cout << "Error: person not found\n";
}

LL::LL()
{ head = NULL; }

void LL::insertAtBegin(string fName, string lName, string phone)
{
  //make a new node and pointer p points to it
  Node* p = new Node;
  //connect the new node to the beginning of the LL
  p->next = head;
  //move head to the new node
  head = p;
  //copy the information into the new node
  head->firstName = fName;
  head->lastName = lName;
  head->phoneNum = phone;
}

void LL::append(string fName, string lName, string phone)
{
  Node *nodePtr = new Node;
  Node* newNode = new Node;

  newNode->firstName = fName;
  newNode->lastName = lName;
  newNode->phoneNum = phone;

  newNode->next = NULL;

  if(!head)
    head = newNode;
  else
    nodePtr = head;
  
  while(nodePtr->next)
    nodePtr = nodePtr->next;
    
  nodePtr->next = newNode;

  
  
}

void LL::print()
{
  Node * p = new Node;
  p->next = head;
  p = p->next;
  cout << endl;

  while(p != NULL)
    {
      cout << (*p).firstName << " ";
      cout << (*p).lastName << ", ";
      cout << (*p).phoneNum << endl;
   
      p = p->next;
    }
  cout << endl;
}


int main()
{
  LL list1;

  list1.append("Mayssaa", "Najjar", "878-635-1234");
  list1.insertAtBegin("Jim", "Meyer", "337-465-2345");
  list1.append("Joe", "Didier", "352-654-1983");
  list1.insertAtPos("Adam", "James", "202-872-1010", 2);
  list1.insertAtBegin("Nancy", "Garcia", "617-227-5454");

  list1.print();

  list1.removeRecord("Mayssaa", "Najjar");
  list1.removeRecord("Jamie", "Najjar");
  list1.print();

  //LL list2(list1);
  //list2.print();

  return 0;
}
