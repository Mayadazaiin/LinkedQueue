// test linked queue class

#include <iostream>
#include <conio.h>
#include "lqueue.h"
#include "queue.h"
using namespace std;

void merge(LinkedQueue<int>& q1, LinkedQueue<int>& q3)
{
    while (!q1.IsEmpty())
    {
        int x = q1.First();
        q3.Add(x);
        q1.Delete(x);
    }
}

int main(void)
{
    LinkedQueue<int> Q1;
    LinkedQueue<int> Q2;
    LinkedQueue<int> Q3;
    int x;

    try
    {
        Q1.Add(1).Add(2).Add(3).Add(4);
        cout << "No queue add failed in Q1" << endl;
        Q2.Add(7).Add(9).Add(11).Add(25);
    }
    catch (NoMem)
    {
        cout << "A queue add failed" << endl;
    }
    cout << "Queue1 is now 1 2 3 4" << endl;
    cout << "Queue2 is now 7 9 11 25" << endl;

    Q1.Delete(x);
    cout << "Deleted " << x << endl;

    cout << Q1.First() << " is at front" << endl;
    cout << Q1.Last() << " is at end" << endl;


    
    merge(Q1, Q3);
    merge(Q2, Q3);


    cout << "the merge between two queues = " << endl;
    while (!Q3.IsEmpty())
    {
        cout << Q3.First() << " ";
        Q3.Delete(x);
    }
    try
    {

        Q1.Delete(x);
        cout << "Deleted " << x << endl;
        Q1.Delete(x);
        cout << "Deleted " << x << endl;
        Q1.Delete(x);
        cout << "Deleted " << x << endl;
        cout << "No queue delete failed " << endl;
        Q1.Add(1).Add(2).Add(3).Add(4); //refill the queue.
    }
    catch (OutOfBounds)
    {
        cout << endl << "A delete has failed" << endl;
    }
    
  return 0;
}

/*
The Output:
-----------
No queue add failed
Queue1 is now 1 2 3 4
Queue2 is now 7 9 11 25
Deleted 1
2 is at front
4 is at end
Deleted 2
Deleted 3
Deleted 4
No queue delete failed
*/