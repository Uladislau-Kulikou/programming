#ifndef LIB_H
#define LIB_H

/**
 * @file lib.h
 */

/**
 * @brief Reads values from input file and assigns to other inputs
 * @param path Path to input file
 * @param freq Frequency
 * @param ampl Amplitude
 * @param ch Character
 */
extern void read_from_file(char *path, double* freq, double* ampl, char* ch);


/**
 * @brief Writes graph content to specified file. If no such - creates one
 * @param path Path to output file
 * @param rows Graph width
 * @param cols Graph height
 * @param graph Graph
*/
extern void write_to_file(char *path, const int rows, const int cols, char** graph);


/**
 * @brief Creates char 2D array with spaces
 * @param rows Width of graph-array
 * @param cols Height of graph-array
 */
extern char** init_graph(const int rows, const int cols);


/**
 * @brief Calculates sinusoid and reflects it in the graph-array
 * @param rows Width of graph-array
 * @param graph Char array to write results in
 * @param freq Frequency of the sinusoidal
 * @param ampl Amplitude of the sinusoidal
 * @param ch Character used to draw a graph
 */
extern void calculate_points(const int rows, char** graph, double freq, double ampl, char ch);


/**
 * @brief Prints the graph to console
 * @param rows Width of graph-array
 * @param cols Height of graph-array
 * @param graph Graph to be drawn
 */
extern void draw_graph(const int rows, const int cols, char** graph);


/**
 * @brief Automates 2D array memory freeing
 * @param size Input graph length (height)
 * @param graph Graph to be deleted
 */
extern void delete_graph(const int size, char** graph);

#endif
