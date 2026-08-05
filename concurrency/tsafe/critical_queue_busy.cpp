#include "critical_queue.hpp"

void CriticalQueue::push(int value)
{
  std::lock_guard<std::mutex> lock(mtx);
  q.push(value);
}

int CriticalQueue::pop()
{
  std::lock_guard<std::mutex> lock(mtx);
  if (q.empty())
  {
    throw std::runtime_error("Queue is empty");
  }
  int value = q.front();
  q.pop();
  return value;
}

bool CriticalQueue::empty()
{
  std::lock_guard<std::mutex> lock(mtx);
  return q.empty();
}