#include <iostream>
using namespace std;

typedef char el_t;

class Queue 
{
private:

  struct QueueNode
  { el_t letter; // letter in the node
    QueueNode *next; // Pointer to the next node
  };
  
  // declare the following:
  // Pointer to the front of the Queue
  QueueNode * front;
  // Pointer to the rear of the Queue
  QueueNode * rear;
  // Number of items in Queue
  int * count;

public:
  Queue(); // Constructor
  ~Queue(); // Destructor
  // Queue operations
  void enqueue(el_t);
  void dequeue(el_t &);
  void displayAll() const;
  bool isEmpty() const;
};
// implement the public methods highlighted in bold here

Queue::Queue()
{ rear = front = NULL; count = 0; }

Queue::~Queue()
{ rear = front = NULL; count = 0; }

void Queue::enqueue(el_t let)
{
  QueueNode *newNode;

  newNode = new QueueNode;
  newNode->next = NULL;
  newNode->letter = let;

  //Change front and back pointers,
  //depending if the queue is empty or already contains data

  if (isEmpty())
    {
      front = newNode;
      rear = newNode;
    }
  else
    {
      rear->next = newNode;
      rear = newNode;
    }

}

}

void Queue::dequeue(el_t & let)
{
  if(isEmpty())
    cout << "The queue is empty.\n" << endl;
  else
    {					      
      front = front->next;
      //let = front;
      count--;
    }


  qNode *temp;

  if(isEmpty())
    {
      cout << "No data currently queued" << endl;
    }
  else
    {
      //Store data from front node in val
      val = front->data;
      //Remove front node, delete
      temp = front;
      front = front->next;
      delete temp;

      //Update queueNum
      queueNum--;
    }

}

void Queue::displayAll() const
{
  if(isEmpty())
    cout << " [ empty ] " << endl;
  else
    {
      cout << endl;

      QueueNode * p = new QueueNode;
      p->next = front;
      cout << front->letter << " ";
      p = p->next;
      cout << endl;
      

      while(rear != NULL)
	{
	  cout << p->letter << " ";
	  p = p->next;
	}

      cout << endl;
    }
}

bool Queue::isEmpty() const
{
  if(front==NULL)
    return true;
  else
    return false;
}

int main ()
{
  Queue q;
  el_t c;
  cout << " initial Queue contents " << endl;
  q.displayAll();
  q.dequeue(c);
  q.enqueue('a');
  cout << endl << " Queue contents after adding a: " << endl;
  q.displayAll();
  q.enqueue('b');
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
  cout << endl << " Queue contents after removing another element: " << endl;
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
  cout << endl << " Queue contents after removing 4 elements: " << endl;
  q.dequeue(c);
  q.dequeue(c);
  cout << endl << " final Queue contents : " << endl;
  q.displayAll();
  return 0;
}
