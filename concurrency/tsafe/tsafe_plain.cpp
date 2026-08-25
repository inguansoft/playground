#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

std::queue<int> queue;
std::vector<int> myvector;
std::mutex mtx_queue, mtx_vector;
std::condition_variable cv_queue, cv_vector;

void queue_producer()
{
  int n = 0;
  while (true)
  {
    std::this_thread::sleep_for(100ms);
    std::lock_guard<std::mutex> lock(mtx_queue);
    queue.push(n++);
    cv_queue.notify_one(); // Notify one waiting thread that a new item is available
    // cv.notify_all(); // Notify all waiting threads that a new item is available
  }
}

void queue_consumer()
{
  while (true)
  {
    std::unique_lock<std::mutex> lock(mtx_queue);
    cv_queue.wait(lock, []
            { return !queue.empty(); }); // Wait until the queue is not empty
    int value = queue.front();
    queue.pop();
    std::cout << "q:"<< value << "\n";
    // std::this_thread::sleep_for(100ms);
  }
}

void vector_producer()
{
  int n = 0;
  while (true)
  {
    std::this_thread::sleep_for(100ms);
    std::lock_guard<std::mutex> lock(mtx_vector);
    myvector.push_back(n++);
    cv_vector.notify_one(); // Notify one waiting thread that a new item is available
    // cv_vector.notify_all(); // Notify all waiting threads that a new item is available
  }
}

void vector_consumer()
{
  while (true)
  {
    std::unique_lock<std::mutex> lock(mtx_vector);
    cv_vector.wait(lock, []
            { return !myvector.empty(); }); // Wait until the vector is not empty
    int value = myvector.back();
    myvector.pop_back();
    std::cout << "v:" << value << "\n";
    // std::this_thread::sleep_for(100ms);
  }
}

int main()
{
  int n = 0;
  std::thread prod_queue(queue_producer), cons_queue(queue_consumer),
  prod_vector(vector_producer), cons_vector(vector_consumer);
  prod_queue.join();
  cons_queue.join();
  prod_vector.join();
  cons_vector.join();
  return 0;
}