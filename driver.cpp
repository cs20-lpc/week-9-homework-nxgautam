#include <iostream>
#include <cstdlib>
#include "QueueFactory.hpp"
#include <ctime>

using namespace std;

void simulateSmallTicketCounter()
{
    cout << "Simluation 1: Ticket Counter" << endl;

    Queue<int>* queue = QueueFactory<int>::GetQueue(10);
    srand(time(0));

    for(int i = 0; i < 100; ++i)
    {
        int randNum = rand() % 3 - 1;

        try
        {
            if(randNum < 0)
            {
                queue->dequeue();
            }else
            {
                queue->enqueue(i);
            }
        }catch(string& e)
        {

        }

    }

    cout << "Final Queue Length: " << queue->getLength() << endl;
    delete queue;

}


void simulateBankServiceLine()
{
    cout << "Simulation 2: Bank Service Line" << endl;

    Queue<int>* queue = QueueFactory<int>::GetQueue();
    srand(time(0)+1);

    for(int i = 0; i < 100; ++i)
    {
        int randNum = rand() % 4 -1;

        try{
            if(randNum < 0)
            {
                queue->dequeue();
            }
            else{
                queue->enqueue(i);
            }
        }
        catch(string& e)
        {

        }
    }

    cout << "Final Queue Length: " << queue->getLength() << endl;
    delete queue;
}

int main()
{
    simulateSmallTicketCounter();
    cout << "------------------------" << endl;
    simulateBankServiceLine();
    return 0;

}