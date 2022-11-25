//Завдання 1: Реалізувати функцію, що визначає,
//скільки серед заданої послідовності чисел таких пар, у котрих перше число
//менше наступного, використовуючи функцію з варіативною кількістю аргументів.
#define N 5

int get_pairs_amount(unsigned int size, int array[]) {
  int count = 0;
  for (int i = 0; i < size - 1; i++) {
    if (array[i] > array[i + 1])
      count++;
  }
  return count;
}

int main() {
  int nums[] = {3, 2, 4, 3, 1}; // Вхідні дані
  int result = get_pairs_amount(N, nums); // Результат виконання

  return 0;
}
