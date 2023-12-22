## Concepts
### Explicit Initialization on constructor
```cpp
MathHelper(InputHandler &input_handler_parameter) : input_handler(input_handler_parameter)
{
   // More constructor code
}
```
### Pointers vs References
|           | Declared | assign                     | null               | acccesing methods |
|:----------|:---------|:---------------------------|:-------------------|:------------------|
| Pointer   | *        | assigned as much as needed | YES: can be null   | x->x_method();    |
| Reference | &        | assigned only once         | NO: cannot be null | x.x_method();     |

Diff from pointers to reference example:
https://github.com/inguansoft/playground/commit/7cf8621b21cee0e15feb3a616d5e19f0c4c689b3

## Inventory
### constexpr
instructs the compiler to evaluate the expression at compile time (if possible)
example:
```cpp
constexpr int isqrt(int n) {
  int i=1;
  while (i*i<n) ++i;
  return i-(i*i!=n);
}

int main() {
  constexpr int x = isqrt(1764);
  printf("%d", x);
}
````

### std::byte 
type permits bitwise logical operations

### size_t
size_t type, also available in the <cstddef> header, to encode size of objects. 
The size_t objects guarantee that their maximum values are sufficient to represent 
the maximum size in bytes of all objects. 
sizeof(float) returns the number of bytes of storage a float takes
size_t are %zu dec %zx hex

## Build
### Basic build examples
```bash
# using a specific standard i.e. C++ 11
g++ -std=c++11 -o hellocpp hello.cpp
```

## Questions

1.  How to print asian and unicode characters in C & C++ ?
2. How to store long unicode like this one: //wchar_t sample = U'\U0001F37A';  how to declare this kind of unicode?
3. Analyze this code
```cpp
std::string line;
std::getline(std::istringstream{str}, line);
string treeString;
getline(cin >> ws, treeString);
```
