#include "lib.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.1415

void read_from_file(char *path, double* freq, double* ampl, char* ch){
  FILE *input_file = fopen(path, "r");
  if (input_file == NULL){
    printf("\033[1;35m warning\033[0m: \033[1mCould not open input file. Used default values.\033[0m\n");
    return;
  }
  fscanf(input_file, "%lf %lf %c", freq, ampl, ch);
  fclose(input_file);
}

void write_to_file(char *path, const int cols, const int rows, char** graph){
  FILE *output_file = fopen(path, "w");
  if (output_file == NULL){
    printf("\033[1;35m warning:\033[0m \033[1mOutput file not specified.\033[0m\n");
    return;
  }
  for (int y=0; y < rows; y++){
    for (int x=0; x < cols; x++){
      fprintf(output_file, "%c", graph[y][x]);
    }
    fprintf(output_file, "\n");
  }
  fclose(output_file);
}

char** init_graph(const int cols, const int rows) {
  char** graph = malloc((size_t)rows * sizeof(char*));
  for (int i = 0; i < rows; i++) {
    graph[i] = malloc((size_t)cols * sizeof(char));
    for (int j = 0; j < cols; j++) {
      graph[i][j] = ' ';
    }
  }
  return graph;
}

void calculate_points(const int cols, char** graph, double freq, double ampl, char ch) {
  double x = 0.0;
  int y;
  while (x <= cols - 1) {
    y = (int)(float)round(ampl - sin(2.0 * PI / freq * x) * ampl);
    graph[y][(int)(float)round(x)] = ch;
    x += 2.0 / (ampl + freq);
  }
}

void draw_graph(const int cols, const int rows, char** graph) {
  printf("\n\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%c", graph[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");
}

void delete_graph(const int size, char** graph) {
  for (int i = 0; i < size; i++)
    free(graph[i]);
  free(graph);
}
