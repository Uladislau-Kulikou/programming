// Завдання: реалізувати функцію, що реалізує находження детермінанту матриці.
#define N 5
#include <math.h>

// Повертає мінор за елементом матриці
int *minor(int item, int size, int *array, int *min) {
  for (int y = 0; y < size - 1; y++) {
    for (int x = 0, j = 0; x < size; x++, j++) {
      if (x != item) {
        *(min + y * (size - 1) + j) = *(array + (y + 1) * size + x);

      } else {
        j--;
      }
    }
  }
  return min;
}

// Приймає необмежено велику матрицю та шляхом розбиття її на матриці 2х2, рахує детермінант
int determinant(int size, int *array) {
  int det = 0;

  if (size == 1){
    return *array;
  }
  if (size == 2){
    return (*(array + 0 * size + 0) * *(array + 1 * size + 1) -
            *(array + 0 * size + 1) * *(array + 1 * size + 0));
  }
  for (int k = 0; k < size; k++) {
    int next_matrix[size - 1][size - 1];
    det += *(array + 0 * size + k) * pow(-1, k + 2) * determinant(size - 1, minor(k, size, array, *next_matrix));
  }
  
  return det;
}

int main() {

  int nums[N][N] = {{1, 1, 1, 1, 1},
                    {1, 2, 2, 2, 2},
                    {1, 2, 3, 3, 3},
                    {1, 2, 3, 4, 4},
                    {1, 2, 3, 4, 9}}; // Вхідні дані

  int result = determinant(N, *nums); // Результат виконання

  return 0;
}

