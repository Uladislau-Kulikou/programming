/*
Лабораторна робота №6
Завдання №26
Помножити матрицю N x N на саму себе.
*/

#include <stdio.h>
#define N 3

int main() {
  int A[N][N]; // Матриця N х N
  int B[N][N]; // Результат множення

  // Заповнення матриці послідовними числами
  for (int x = 0, i = 0; x < N; x++) {
    for (int y = 0; y < N; y++, i++) {
      A[x][y] = i;
    }
  }

  // Перемноження матриць
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      B[x][y] = 0;
      for (int k = 0; k < N; k++) {
        B[x][y] += A[x][k] * A[k][y];
      }
    }
  }

  return 0;
}
