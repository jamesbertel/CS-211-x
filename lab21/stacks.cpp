#include <iostream>
using namespace std;

const int MAX = 5;
typedef char el;

class Stack 
{
private:
  // declare an array of chars with MAX slots
  char el[MAX];
  // and an integer to hold the index of the top element
  int top;
public:
  // Write the prototype of the following public methods
  Stack();
  void push(char elem);
  void pop(char &elem);
  void displayAll() const;
  bool isEmpty() const;
  bool isFull() const;
};

// implement the public methods here
Stack::Stack()
{
  top = -1;
}

bool Stack::isEmpty() const
{
  if(top==-1)
    return true;
  else
    return false;
}

bool Stack::isFull() const
{
  if(top==MAX-1)
    return true;
  else
    return false;
}

void Stack::push(char elem)
{
  if(isFull())
    cout << " [ full ] " << endl;
  else
    {
      top++;
      el[top] = elem;
    }
}

void Stack::pop(char & elem)
{
  if(isEmpty())
    cout << " [ empty] " << endl;
  else
    {
      elem = el[top];
      top--;
    }
}

void Stack::displayAll() const
{
  if(isEmpty())
    cout << "[ empty ]" << endl;
  else
    {
      for(int i = top; i >= 0; i--)
	cout << el[i] << endl;
    }
}

int main ()
{
  Stack s;
  char c;
  cout << "initial stack contents" << endl;
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
  s.pop(c);
  cout << endl << c << endl;
  cout << endl << " stack contents after popping one element: " << endl;
  s.displayAll();
  s.pop(c);
  cout << endl << " popped element: " << c << endl;
  cout << endl << " stack contents after popping another element: "<< endl;
  s.displayAll();
  s.pop(c);
  s.pop(c);
  s.pop(c);
  cout << endl << " stack contents after popping 3 more elements: " << endl;
  s.displayAll();
  s.pop(c);
  s.push('a');
  s.push('b');
  cout << endl << " final stack contents "<< endl;
  s.displayAll();
  return 0;
}
