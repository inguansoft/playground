----- constexpr
instructs the compiler to evaluate the expression at compile time (if possible)
example:
constexpr int isqrt(int n) {
  int i=1;
  while (i*i<n) ++i;
  return i-(i*i!=n);
}

int main() {
  constexpr int x = isqrt(1764); ➊
  printf("%d", x);
}
-----

//std::byte type permits bitwise logical operations

size_t type, also available in the <cstddef> header, to encode size of objects. The size_t objects guarantee that their maximum values are sufficient to represent the maximum size in bytes of all objects

 sizeof(float) returns the number of bytes of storage a float takes

size_t are %zu dec %zx hex


g++ -std=c++11 -o hellocpp hello.cpp
