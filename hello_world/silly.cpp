#include <iostream>
#include <thread>

void hello()
{
  int c = 0;
  while (c < 5)
  {
    std::cout << " Hello concurrent world " << c << "...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    c++;
  }
}

void hello2()
{
  while (true)
  {
    std::cout << "  concurrent world 2...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}

class X
{
public:
  void do_lengthy_work()
  {
    while (true)
    {
      std::cout << "     class do_lengthy_work...\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
    }
  }
};

int main()
{
  int c = 0;
  std::cout << "real cocurrent capacity on system: **" << std::thread::hardware_concurrency() << "**\n";
  std::thread t(hello);
  std::thread t2(hello2);
  t2.detach();
  while (c < 2)
  {
    std::cout << "main thread " << c << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    c++;
  }
  std::cout << "blocked for join from concurrent thread...\n";
  t.join();
  std::cout << "thread arrived!\n";
  if (t.joinable())
  {
    t.join();
  }
  else
  {
    std::cout << "already joined!\n";
  }

  if (t2.joinable())
  {
    t2.join();
  }
  else
  {
    std::cout << "t2 detached not joinable anymore!\n";
  }

  X my_x;
  std::thread t3(&X::do_lengthy_work, &my_x);
  t3.detach();
  return 0;
}
