#include "critical_queue.hpp"
#include <iostream>
#include <thread>

int main()
{
  CriticalQueue queue;
  int n = 0;
  std::thread producer([&queue, &n]()
                       { 
                        while (true) {
                            queue.push(n++);
                            //std::this_thread::sleep_for(std::chrono::milliseconds(100));
                        } });
  std::thread consumer([&queue]()
                       { 
                        while (true) {
                            if (!queue.empty()) {
                                std::cout << queue.pop() << "\n";
                            }
                            //std::this_thread::sleep_for(std::chrono::milliseconds(150));
                        } });
  producer.join();
  consumer.join();
  return 0;
}