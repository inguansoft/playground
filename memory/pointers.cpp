#include <iostream>
#include <memory>

class SuperThing
{
public:
  SuperThing(int x, int y) : x_(x), y_(y)
  {
    std::cout << x_ << "," << y_ << ": SuperThing constructed\n";
  }
  ~SuperThing()
  {
    std::cout << x_ << "," << y_ << ": SuperThing destructed\n";
  }
  int getValue() const { return 99; }

private:
  int x_, y_;
};

void process_data(std::unique_ptr<int> data)
{
  SuperThing st(3, 4);                       // Local object to demonstrate RAII
  SuperThing *st_ptr = new SuperThing(5, 6); // Dynamically allocated SuperThing
  std::cout << "Processing data: " << *data << std::endl;
  delete st_ptr; // Don't forget to free the dynamically allocated memory
}

int main()
{
  std::unique_ptr<int> ptr = std::make_unique<int>(42);
  {
    // std::unique_ptr<SuperThing> st_ptr = std::make_unique<SuperThing>(1, 2);
    SuperThing st_ptr(1, 2);
    // st_ptr->getValue(); // Accessing member function of SuperThing
    st_ptr.getValue(); // Accessing member function of SuperThing
  }
  {
    std::shared_ptr<SuperThing> shared_st_ptr = std::make_shared<SuperThing>(7, 8);
    {
      std::shared_ptr<SuperThing> shared_st_ptr2 = shared_st_ptr; // Shared ownership of the same SuperThing
      std::cout << "Shared SuperThing value: " << shared_st_ptr->getValue() << std::endl;
    }
    std::cout << "Shared SuperThing value should release now: " << shared_st_ptr->getValue() << std::endl;
  }
  process_data(std::move(ptr));
  //  ptr is now null after being moved
  return 0;
}