//Завдання: виявити чи є число простим
#include <stdbool.h>

//Перевірка на простоту. Повертає boolean
bool is_prime(int number) {
  for (int i = 2; i < number; i++) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  bool var = is_prime(31);

  return 0;
}
