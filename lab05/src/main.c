/*
Завдання №23
Визначити, чи є задане ціле число простим.
*/
#include <stdio.h>

int main() {
  int is_prime = 1; // Значення 0 - не є простим, 1 - просте число
  int number = 2; // Довільне число

  for (int i = 2; i < number; i++) {
    if (number % i ==
        0) { // Перевірка ділимості на кожне число діапвзону від 2 до n
      is_prime = 0;
      break; // Якщо дільник знайдений - нема сенсу продовдувати роботу цикла
    }
  }
  return 0;
}
