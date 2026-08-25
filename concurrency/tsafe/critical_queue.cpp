#include "critical_queue.hpp"

void CriticalQueue::push(int value)
{
  std::lock_guard<std::mutex> lock(mtx);
  //std::unique_lock<std::mutex> lock(mtx);
  q.push(value);
  cv.notify_one(); // Notify one waiting thread that a new item is available
  //cv.notify_all(); // Notify all waiting threads that a new item is available
}

int CriticalQueue::pop()
{
  std::unique_lock<std::mutex> lock(mtx);
  cv.wait(lock, [this] { return !q.empty(); }); // Wait until the queue is not empty
  int value = q.front();
  q.pop();
  return value;
}

bool CriticalQueue::empty()
{
  std::unique_lock<std::mutex> lock(mtx);
  return q.empty();
}