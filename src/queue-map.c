#include "queue-map.h"

void nil_queue(queue_map* p_queue) {
	p_queue->first = NULL;
	p_queue->last = NULL;
}

cell_queue* create_first_mother(smap* p_map) {
	cell_queue* p_cell = NULL;
	p_cell = malloc(sizeof(cell_queue));
	if (p_cell==NULL) { printf("Erreur de malloc"); }
	
	p_cell->p_map = p_map;
	p_cell->next = NULL;
	p_cell->p_mother = NULL;
	p_cell->action = '0';
	p_cell->depth = 0;
	return p_cell;
}

void enqueue(queue_map* p_queue, smap* p_map, cell_queue* p_mother, char action) {
	cell_queue* p_cell = NULL;
	p_cell = malloc(sizeof(cell_queue));
	if (p_cell==NULL) { printf("Erreur de malloc"); }
	
	p_cell->p_map = p_map;
	p_cell->next = NULL;
	p_cell->p_mother = p_mother;
	p_cell->action = action;
	p_cell->depth = 1 + p_mother->depth;
	
	if (is_empty(p_queue)) {
		p_queue->last = p_cell;
		p_queue->first = p_cell;
	} else {
		p_queue->last->next = p_cell;
		p_queue->last = p_cell;
	}
}

void dequeue(queue_map* p_queue) {
	cell_queue* p_cell = p_queue->first;
	p_queue->first = p_cell->next;
	free(p_cell);
	}

/**int size(const queue_map* p_queue){
	
}*/


bool is_empty(queue_map* p_queue) {
	return p_queue->first == NULL;
}


/**void deallocate_queue(queue_map* p_queue);*/


void print_queue(queue_map* p_queue) {
	
    cell_queue* p_current_cell = p_queue->first;
	int i=0;
    printf("Début de queue (récent)\n");

    while (p_current_cell != NULL) {
        printf("Cell number %d :\n",i);
        print_map(p_current_cell->p_map);

        if (p_current_cell->next != NULL) {
			i += 1;
            p_current_cell = p_current_cell->next;
        } else {
            break;
        }
    }

    printf("Fin de queue\n\n");
}

