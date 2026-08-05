

#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

class CriticalQueue
{
private:
  std::queue<int> q;
  std::mutex mtx;
  std::condition_variable cv;

public:
  /**
   * Pushes a value into the queue in a thread-safe manner.
   * @param value The integer value to be pushed into the queue.
   */
  void push(int value);

  /**
   * Pops a value from the queue in a thread-safe manner.
   * @return The integer value popped from the queue.
   */
  int pop();

  /**
   * Checks if the queue is empty in a thread-safe manner.
   * @return True if the queue is empty, false otherwise.
   */
  bool empty();
};