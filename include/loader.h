/**
 * @file loader.h
 *
 * @brief Main file for the loader
 *
 * @author Coline van Leeuwen
 *
 *
 */

#include "sokoban.h"

/**
 * @brief Loads a text file and creates a map with all the info in
 * 
 * @param filename a string containing the name of the file to open
 *
 * @return a pointer to the map newly created 
 */
smap* load_map(char* filename);
