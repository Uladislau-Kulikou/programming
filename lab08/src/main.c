#define N 3
#include <math.h>

/// Повертає мінор за елементом матриці
void minor(int item, int size, int matrix[][size], int min[][size-1]){
  for (int y = 0; y < size - 1; y++) 
    for (int x = 0, j = 0; x < size; x++, j++){
      min[y][j] = matrix[y+1][x];
      if (x == item)
        j--;
    } 
}

/// Приймає необмежено велику матрицю та шляхом розбиття її на матриці 2х2, рахує детермінант
int determinant(int size, int matrix[][size]) {
  int det = 0;
  if (size == 1){
    return matrix[0][0];
  }
  if (size == 2){
    return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
  }           
  for (int k = 0; k < size; k++) {
    int next_matrix[size-1][size-1];
    minor(k, size, matrix, next_matrix);
    det += matrix[0][k] * pow(-1, k) * determinant(size-1, next_matrix);
  }
  return det;
}

int main() {
  /// Вхідні дані
  int matrix[N][N] = {{1, 2, 9},
                      {4, 5, 6},
                      {7, 8, 9}}; 

  /// Результат виконання
  int result = determinant(N, matrix); 
  return 0;
}