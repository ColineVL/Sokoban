/**
 * @file sokoban.h
 *
 * @brief Main file for the game
 *
 * @author Coline van Leeuwen
 *
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define BOY '@'
#define BOY_ON '+'
#define BOX '$'
#define BOX_ON '*'
#define PARK '.'
#define EMPTY ' '
#define WALL '#'

/**
 * @brief An alias to the structure representing the cells of
 *        the map.
 */
typedef struct scell scell;

/**
 * @brief An alias to the structure representing the map.
 */
typedef struct smap smap;

/** 
 * @brief The structure representing the cells of the map.
 */
struct scell {
	/** The column of the cell */
	int c;
	/** The line of the cell */
	int l;
	/** The char contained in the cell */
	char val;
};

/**
 *  @brief The structure representing the map.
 */
struct smap {
	/** The height of the map */ 
	int hei;
	/** The width of the map */
	int wid;
	/** The position of the player */
	scell player;
	/** The array containing the elements of the map */
	char* elts;
	/** The number of empty storage cells left */
	int storage;
};

bool is_in(int value, int* tableau, int len);

/**
 * @brief Gives the value of a given cell
 *
 * @param p_map a pointer to a map
 * 
 * @param pos the cell to read
 *
 * @return the content of the cell 
 */
char access_map(smap* p_map, scell cell);

/**
 * @brief Modifies a given cell 
 *
 * @param p_map a pointer to the map to modify
 * 
 * @param pos the cell to modify
 *
 * @param new a char representing the new value of the cell
 */
void modify_map(smap* p_map, scell cell, char new);

/**
 * @brief Prints a map on the console
 *
 * @param p_map a pointer to the map to print
 * 
 */
void print_map(smap* p_map);

/**
 * @brief Creates a new map, with exactly the same information as in the old one
 * 
 * @param map the map to copy
 *
 * @return the new map
 */
smap* create_doublon(smap map);

/**
 * @brief To use if the player goes in a box : moves the box according to the rules of the game
 *
 * @param p_map a pointer to a map
 * 
 * @param case_cible a cell representing the position of the box the player wants to go into
 * 
 * @param direction a char representing the direction of the movement 
 *
 * @param mvt_impossible a pointer to a bool
 */
void move_box(smap* p_map, scell goal_cell, char direction, bool* mvt_impossible);

/**
 * @brief Moves the player according to the rules of the game 
 *
 * @param p_map a pointer to the map
 *
 * @param direction a char representing the direction of the movement
 *
 * @return a pointer to the map after the player has moved, the previous map is deleted
 */
smap* move_player(smap* p_map, char direction);

/**
 * @brief Frees the map
 * 
 * @param p_map a pointer to the map to free
 */
void deallocate(smap* p_map);


/**
 * @brief Replays a map
 *
 * @param p_map  a pointer to the map to replay
 *
 * @param length  the length of the plan
 *
 * @param mvts a string representing the plan
 *
 * @return a pointer to the final map, when the player has moved according to the plan
 *
 */
smap* replay(smap* p_map,int length,char* mvts);
