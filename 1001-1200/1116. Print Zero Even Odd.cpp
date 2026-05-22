/*
You have a function printNumber that can be called with an integer parameter and prints it to the console.

For example, calling printNumber(7) prints 7 to the console.
You are given an instance of the class ZeroEvenOdd that has three functions: zero, even, and odd. The same instance of ZeroEvenOdd will be passed to three different threads:

Thread A: calls zero() that should only output 0's.
Thread B: calls even() that should only output even numbers.
Thread C: calls odd() that should only output odd numbers.
Modify the given class to output the series "010203040506..." where the length of the series must be 2n.

Implement the ZeroEvenOdd class:

ZeroEvenOdd(int n) Initializes the object with the number n that represents the numbers that should be printed.
void zero(printNumber) Calls printNumber to output one zero.
void even(printNumber) Calls printNumber to output one even number.
void odd(printNumber) Calls printNumber to output one odd number.


Example 1:

Input: n = 2
Output: "0102"
Explanation: There are three threads being fired asynchronously.
One of them calls zero(), the other calls even(), and the last one calls odd().
"0102" is the correct output.
Example 2:

Input: n = 5
Output: "0102030405"


Constraints:

1 <= n <= 1000
*/
#include <functional>
#include <semaphore.h>

class ZeroEvenOdd
{
private:
    int n;
    sem_t semZero;
    sem_t semEven;
    sem_t semOdd;

public:
    ZeroEvenOdd(int n) : n(n)
    {
        sem_init(&semZero, 0, 1); // zero allowed first
        sem_init(&semEven, 0, 0); // even blocked
        sem_init(&semOdd, 0, 0);  // odd blocked
    }

    void zero(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; ++i)
        {
            sem_wait(&semZero); // wait until it's zero's turn
            printNumber(0);     // print 0

            if (i % 2 == 1)
            {                      // next number is odd
                sem_post(&semOdd); // wake odd thread
            }
            else
            {                       // next number is even
                sem_post(&semEven); // wake even thread
            }
        }
    }

    void even(function<void(int)> printNumber)
    {
        for (int i = 2; i <= n; i += 2)
        {
            sem_wait(&semEven); // wait until zero signals even
            printNumber(i);     // print even number
            sem_post(&semZero); // give turn back to zero
        }
    }

    void odd(function<void(int)> printNumber)
    {
        for (int i = 1; i <= n; i += 2)
        {
            sem_wait(&semOdd);  // wait until zero signals odd
            printNumber(i);     // print odd number
            sem_post(&semZero); // give turn back to zero
        }
    }
};