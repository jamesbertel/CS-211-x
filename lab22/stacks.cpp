#include <iostream>
using namespace std;

typedef char el_t;

class Stack 
{
private:

 struct StackNode
 { 
   el_t element; // letter in the node
   StackNode *next; // Pointer to the next node
 };
  StackNode *top; // Pointer to the stack top

public:
  // Constructor
  Stack() { top = NULL; }
  // Destructor
  ~Stack();
  // Stack operations
  void push(el_t place);
  void pop(el_t & place);
  void topp(el_t & plc);
  void displayAll() const;
  bool isEmpty() const;
  bool isFull() const;
};
//implement the public methods highlighted in bold here

bool Stack::isFull() const
{
  if(top==NULL)
    return true;
  else
    return false;
}

bool Stack::isEmpty() const
{
  if(top==NULL)
    return true;
  else
    return false;
}

void Stack::push(el_t place)
{
  if( isFull() )
    cout << " [ full ] " << endl;
  else
    {
     top++;
     //element[top] = place;
    }
}
/*
void Stack::pop(el_t & place)
{
  if(isEmpty())
    cout << " [ empty ] " << endl;
  else
    {
      element = el[top];
      top--;
    }
}

void Stack::topp(el_t & place)
{}

void Stack::displayAll() const
{
  if(isEmpty())
    cout << " [ empty ] " << endl;
  else
    ;//traverse the linked list
}

bool Stack::isEmpty() const
{
  if(top==-1)
    return true;
  else
    return false;
}
*/
int main ()
{
Stack s;
  el_t c;
  cout << " initial stack contents" << endl;
  s.displayAll();
  s.pop(c);
  s.push('a');
  cout << endl << " stack contents after pushing a: " << endl;
  s.displayAll();
  s.push('b');
  cout << endl << " stack contents after pushing b: " << endl;
  s.displayAll();
  s.push('c');
  s.push('d');
  s.push('e');
  s.push('f');
  s.push('g');
  cout << endl << " stack contents after pushing c-g: " << endl;
  s.displayAll();
  s.topp(c);
  cout << endl << "top elment is " << c << endl;
  s.pop(c);
  cout << endl << c << endl;
  cout << endl << " stack contents after popping one element: " << endl;
  s.displayAll();
  s.pop(c);
  cout << endl << " popped element: " << c << endl;
  cout << endl << " stack contents after popping another element: " << endl;
  s.displayAll();
  s.pop(c);
  s.pop(c);
  if (! isEmpty())
    {
      s.topp(c);
      cout << endl << "top elment is " << c << endl;
    }
  s.pop(c);
  cout << endl << " stack contents after popping 3 more elements: " << endl;
  s.displayAll();
  s.pop(c);
  s.pop(c);
  s.push('a');
  s.push('b');
  cout << endl << " final stack contents "<< endl;
  s.displayAll();
  return 0;
}

