#include <iostream>
using namespace std;

const int MAX = 10;
typedef char ch;
class Queue 
{
private:
  // declare array to hold queue elements,
  ch el[MAX];
  // integers to hold front and rear positions,
  int front; 
  int rear;
  // and another integer to keep track of the number of items in Queue
  int count;
public:
  Queue();
  void enqueue(ch let);
  void dequeue(ch &let);
  void displayAll() const;
  bool isEmpty() const;
  bool isFull() const;
};
// implement the public methods highlighted in bold here
Queue::Queue()
{rear = -1; front = 0; count = 0; }

void Queue::enqueue(ch let)
{
  if (isFull())
    cout << "The queue is full.\n";
  else
    {
      rear = (rear + 1) % MAX; // Calculate new rear position
      el[rear] = let; // Insert new item
      count++; // Update item count
    }
}

void Queue::dequeue(char &let)
{
  if (isEmpty())
    cout << "The queue is empty.\n";
  else
    {
      let = el[front];
      front = (front + 1) % MAX; // Move front
      count--; // Update item count
    }
}

bool Queue::isEmpty() const
{
  if(count==0)
    return true;
  else
    return false;
}

bool Queue::isFull() const
{
  if(count==MAX)
    return true;
  else
    return false;
}
void Queue::displayAll() const
{
  if(isEmpty())
    cout << "[ empty ]" << endl;
  else
    {
      for(int i = 0; i < count; i++)
        cout << el[i] << endl;
    }
}



int main ()
{
  Queue q;
  ch c;
  cout << " initial Queue contents" << endl;
  //  q.displayAll();
  q.dequeue(c);
  q.enqueue('a');
  cout << endl << " Queue contents after adding a: " << endl;
  //q.displayAll();
  /*  q.enqueue('b');
  q.enqueue('c');
  q.enqueue('d');
  q.enqueue('e');
  q.enqueue('f');
  cout << endl << " Queue contents after adding b-f: " << endl;
  q.displayAll();
  q.dequeue(c);
  cout << endl << c << endl;
  cout << endl << " Queue contents after removing one element: " << endl;
  q.displayAll();
  q.dequeue(c);
  cout << endl << " Removed element: " << c << endl;
  cout << endl << " Queue contents after removing another element: "<< endl;
  q.displayAll();
  q.enqueue('g');
  q.enqueue('h');
  q.enqueue('i');
  cout << endl << " Queue contents after adding g, h, i: " << endl;
  q.displayAll();
  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << " Queue contents after removing 4 elements: "<< endl;
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << " final Queue contents " << endl;
  q.displayAll();*/
  return 0;
}
