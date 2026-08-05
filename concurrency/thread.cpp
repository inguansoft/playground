#include <iostream>
#include <thread>

using namespace std::chrono_literals;
void process_x(int x = 0)
{
  std::cout << "processing x = " << x << "\n";
}

class Sample
{
  int arc;

public:
  Sample() : arc(0) {}

  int get_arc() const
  {
    return arc;
  }

  void set_arc(int value)
  {
    arc = value;
  }

  void operator()()
  {
    std::cout << "Using function object ()\n";
  }
  int operator+(int number)
  {
    std::cout << "Using function object + " << number << "\n";
    return number + 100000;
  }
  static void func5secs()
  {
    std::cout << "Using static function , 5 sec sleep starts\n";
    std::this_thread::sleep_for(5s);
    std::cout << "Using static function , 5 sec sleep end\n";
  }

  void func_instance_call()
  {
    std::cout << "Using instance function ---- arc = " << arc << "\n";
  }

  void daemonThread()
  {
    int timeout = 20;
    std::cout << "Daemon thread starting...\n";
    while (timeout-- > 0)
    {
      std::cout << "Daemon thread is running...\n";
      std::this_thread::sleep_for(1s);
    }
    std::cout << "Daemon thread exiting...\n";
  }
};

int main()
{
  Sample a;
  a.set_arc(92);
  std::thread t1(process_x, 5),
      t2(process_x, 10),
      t3([]()
         { 
          std::cout << "Using lambda function , 5 sec sleep starts....... \n";
          std::this_thread::sleep_for(5s);    
          std::cout << "Using lambda function , 5 sec sleep end\n";
          std::cout << std::this_thread::get_id() << ":::Using lambda function\n"; 
          std::cout << "Using lambda function\n"; }),
      t4{Sample()},
      t5,
      t6(&Sample::func_instance_call, &a),
      t7(&Sample::daemonThread, &a);
  std::cout << "-- Is t5 joinable? before creation : " << t5.joinable() << std::endl;
  t5 = std::thread(&Sample::func5secs);
  std::cout << "-- Is t5 joinable? after creation : " << t5.joinable() << std::endl;
  std::cout << "-- Is t7 joinable before detach : " << t7.joinable() << std::endl;
  t7.detach();
  std::cout << "-- Is t7 joinable after detach : " << t7.joinable() << std::endl;

  int result = a + 5;
  std::cout << "---------- Processing main thread " << result << "\n";
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();
  t6.join();
  // t7.join();  t7 is not joinable because it was detached
  std::cout << "-- Is t5 joinable? after joined : " << t5.joinable() << std::endl;
  std::cout << "---------- Everybody joined!\n";
  return 0;
}
