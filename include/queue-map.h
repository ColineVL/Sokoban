/**
 * @file queue_map.h
 *
 * @brief Simple definition of queue containing `map` values
 *
 * @author Coline van Leeuwen
 * 
 */

#ifndef QUEUE_MAP_H
#define QUEUE_MAP_H

#include "loader.h"

/**
 * @brief An alias for the structure representing the cells
 */
typedef struct cell_queue cell_queue;

/**
 * @brief The structure representing the cells of the queue
 */
struct cell_queue {
    /** the value in the cell */
    smap*      p_map;
    /** a pointer to the next cell in the queue */
    cell_queue* next;
    /** a pointer to the mother cell */
    cell_queue* p_mother;
    /** the action that generated the considered cell */
    char action;
    /** the depth of the cell in the search tree, ie 1+depth of the mother cell */
    int depth;
};

/**
 * @brief An alias for the structure representing the
 *        queue
 */
typedef struct queue_map queue_map;

/**
 * @brief The structure representing the queue
 */
struct queue_map {
    /** a pointer to the first cell of the queue */
	cell_queue*     first;
    /** a pointer to the last cell in the queue */
    cell_queue* 	last;
};


/**
 * @brief Creates an empty queue
 *
 * @param p_queue  a pointer to the queue to be set to nil
 *
 */
void nil_queue(queue_map* p_queue);

/** 
 * @brief Creates a cell without any mother
 * 
 * @param p_map a pointer to the original map
 * 
 */
cell_queue* create_first_mother(smap* p_map);

/**
 * @brief Enqueue an element at the tail of a queue
 *
 * @param p_queue  a pointer to the queue to be modified
 * @param cell   the cell to be added in the queue
 */
void enqueue(queue_map* p_queue, smap* p_map, cell_queue* p_mother, char action);

/**
 * @brief Dequeue the element at the head of a queue
 *
 * @param p_queue  a pointer to the queue to be modified
 * @param cell   the cell to be added in the queue
 */
void dequeue(queue_map* p_queue);

/**
 * @brief The length of a list
 *
 * @param p_queue  a pointer to the queue whose length is wanted
 *
 * @return the length of the queue (i.e. the number of distinct cells
 *         in the queue)
 */
/**int size(const queue_map* p_queue);*/

/**
 * @brief Is the queue empty?
 *
 * @param p_queue  a pointer to the queue
 *
 * @return true is the queue is empty, false else
 */
bool is_empty(queue_map* p_queue);

/**
 * @brief Deallocate a queue
 *
 * @param p_queue  a pointer to the queue to be deallocated
 *
 * @post After the call to `deallocate_queue`, all cells composing `queue`
 *       are deallocated AND the structure representing the queue is also
 *       deallocated. `p_queue` is `NULL` after the call.
 */
/**void deallocate_queue(queue_map* p_queue);*/

/**
 * @brief Print a queue
 *
 * @param p_queue  a pointer to the queue to be printed
 *
 * @post After the call to `print_queue`, the queue is printed on the console
 *       in classical format using `[]`.
 */
void print_queue(queue_map* p_queue);

#endif


