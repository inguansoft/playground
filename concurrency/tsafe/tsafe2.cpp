#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

using namespace std::chrono_literals;

std::vector<int> data;
std::shared_mutex data_shared_mutex;


int calculate_average()
{
  std::shared_lock<std::shared_mutex> lock(data_shared_mutex);
  if (data.empty())
  {
    return 0;
  }
  else
  {
    int sum = 0;
    for (const auto &val : data)
    {
      sum += val;
    }
    return sum / data.size();
  }
}

void acquire_data()
{
  int value = 0;
  while (value > -1) // Continue until a negative value is entered
  {
    std::cout << "Enter a value (negative to stop): ";
    std::cin >> value;
    std::cout << "Acquired value: " << value << std::endl;
    {
      std::unique_lock<std::shared_mutex> lock(data_shared_mutex);
      data.push_back(value); // Simulate data acquisition
    }
    std::cout << "\tAverage of current data: " << calculate_average() << std::endl;
  }
}

void consume_data()
{
  while (true)
  {
    std::this_thread::sleep_for(5s); // Simulate processing delay
    std::unique_lock<std::shared_mutex> lock(data_shared_mutex);
    if (!data.empty())
    {
      int value = data.back();
      data.pop_back();
      std::cout << "\n\tConsumed value: " << value << std::endl;
    }
    else
    {
      std::cout << "\n\tNo data to consume." << std::endl;
    }
  }
}


int main()
{
  std::thread t1(acquire_data);
  std::thread t2(consume_data);

  t1.join();
  t2.detach(); // Detach the consumer thread to allow it to run independently
  return 0;
}