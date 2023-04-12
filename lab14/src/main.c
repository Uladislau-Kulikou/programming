#include "lib.h"

int main(int argc, char* argv[]) {
  double frequency = 40.0;
  double amplitude = 5.0;
  char ch = '*';

  read_from_file(argv[1], &frequency, &amplitude, &ch);
  const int cols = 40;
  const int rows = amplitude * 2 + 1;

  char** output = init_graph(cols, rows);
  calculate_points(cols, output, frequency, amplitude, ch);
  draw_graph(cols, rows, output);
  write_to_file(argv[2], cols, rows, output);
  delete_graph(rows, output);

  return 0;
}
