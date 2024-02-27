#include <stdio.h>

int fibonacci(int n) {
  int a = 0, b = 1, tmp;
  
  while (n > 0) {
    tmp = b;
    b = a + b;
    a = tmp;
    n--;
  }
  return a;
}

int main() {
  for (int i=0; i < 10; i++) {
    printf("Fibonaci(%d) -> %d\n", i, fibonacci(i));
  }
}
