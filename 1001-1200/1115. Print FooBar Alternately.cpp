
/*
Suppose you are given the following code:

class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:

thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.



Example 1:

Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.
Example 2:

Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.


Constraints:

1 <= n <= 1000
*/
class FooBar
{
private:
    int n;
    // make a semaphore for foo and bar
    sem_t semFoo;
    sem_t semBar;

public:
    FooBar(int n)
    {
        this->n = n;
        sem_init(&semFoo, 0, 1); // foo allowed first
        sem_init(&semBar, 0, 0); // bar blocked
    }

    void foo(function<void()> printFoo)
    {

        for (int i = 0; i < n; i++)
        {
            sem_wait(&semFoo); // wait until it's foo's turn

            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();

            sem_post(&semBar); // give turn to bar
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            sem_wait(&semBar); // wait until it's bar's turn

            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&semFoo); // give turn to foo
        }
    }
};