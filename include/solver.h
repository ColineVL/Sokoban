/**
 * @file solver.h
 *
 * @brief Main file for the solver
 *
 * @author Coline van Leeuwen
 *
 *
 */

# include "loader.h"
#include "linked-list-map.h"
#include "queue-map.h"

/**
 * @brief An alias to the structure representing the stats
 */
typedef struct stats stats;

/**
 *  @brief The structure representing the stats.
 */
struct stats {
	/** Is there a winning plan ? */ 
	bool exist;
	/** The corresponding plan */
	char plan[size_plan];
	/** The size of the plan */
	int size_plan;
};

