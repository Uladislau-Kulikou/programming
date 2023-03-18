#include "det.h"
#include <math.h>

float determinant(int size, float matrix[][size]) {
  float det = 0.0f;
  if (size == 1) {
    return matrix[0][0];
  }
  if (size == 2) {
    return matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1];
  }
  for (int k = 0; k < size; k++) {
    float next_matrix[size - 1][size - 1];
    for (int y = 0; y < size - 1; y++)
      for (int x = 0, j = 0; x < size; x++, j++) {
        next_matrix[y][j] = matrix[y + 1][x];
        if (x == k)
          j--;
      }
    det += matrix[0][k] * pow(-1, k) * determinant(size - 1, next_matrix);
  }
  return det;
}