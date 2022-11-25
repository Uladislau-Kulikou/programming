//Завдання: помножити матрицю саму на себе
#define N 3

// Заповнює матрицю послідовними числами
void fill_matrix(unsigned int size, int *matrix) {
  for (int x = 0, i = 0; x < size; x++) {
    for (int y = 0; y < size; y++, i++) {
      *(matrix + y * size + x) = i;
    }
  }
}

int *mult_matrix_byself(unsigned int size, int *array1, int *array2) {
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      *(array2 + x * size + y) = 0;
      for (int k = 0; k < size; k++) {
        *(array2 + x * size + y) += *(array1 + x * size + k) * *(array1 + k * size + y);
      }
    }
  }
  return array2;
}

int main() {
  int A[N][N]; // Матриця N х N
  int B[N][N]; // Результат множення

  fill_matrix(N, *A);
  print(N, mult_matrix_byself(N, *A, *B));

  return 0;
}
