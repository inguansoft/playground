## Inventory
### constexpr
instructs the compiler to evaluate the expression at compile time (if possible)
example:
```
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
```
# using a specific standard i.e. C++ 11
g++ -std=c++11 -o hellocpp hello.cpp
```

## Questions

1.  How to print asian and unicode characters in C & C++ ?
2. How to store long unicode like this one: //wchar_t sample = U'\U0001F37A';  how to declare this kind of unicode?
3. Analyze this code
```
std::string line;
std::getline(std::istringstream{str}, line);
string treeString;
getline(cin >> ws, treeString);
```
