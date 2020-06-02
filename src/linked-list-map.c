/**
 * @file linked_list_map.c
 * @brief Simple implementation of a linked list.
 *
 * The implementation of the linked list.
 */

#include "linked-list-map.h"

// utilitary functions goes here
cell_map* go_to_position(const list_map* p_list, int pos) {
    cell_map* p_current_cell = *p_list;

    for (int i = 0; i < pos; i++) {
        p_current_cell = p_current_cell->next;
    }

    return p_current_cell;
}

// functions from the signature
void nil(list_map* p_list) {
    *p_list = NULL;
}


void cons(list_map* p_list, smap* p_map) {
    cell_map* p_new_cell = malloc(sizeof(cell_map));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in cons!\n");
    }
    p_new_cell->p_map = p_map;
    p_new_cell->next  = *p_list;
	

    *p_list = p_new_cell;
}

int size(const list_map* p_list) {
    int length = 0;
    cell_map* p_current_cell = *p_list;

    while (p_current_cell != NULL) {
        p_current_cell = p_current_cell->next;
        length++;
    }

    return length;
}

bool is_empty(const list_map* p_list) {
    return *p_list == NULL;
}

smap* get_element(const list_map* p_list, int pos) {
    // not very efficient to use size function but...
    int length = size(p_list);

    assert(p_list != NULL && pos >= 0 && pos < length);

    // go to position
    cell_map* p_cell = go_to_position(p_list, pos);

    return p_cell->p_map;
}

void insert_element(list_map* p_list, int pos, smap* p_map) {
    cell_map* p_current_cell = *p_list;

    // not very efficient to use size function but...
    int length = size(p_list);

    assert(pos >= 0 && pos <= length);

    if (pos == 0) {
        cons(p_list, p_map);

        return;
    }

    cell_map* p_new_cell = malloc(sizeof(cell_map));

    if (p_new_cell == NULL) {
        printf("problem with creating cell in insert_element!\n");
    }

    p_new_cell->p_map = p_map;

    p_current_cell = go_to_position(p_list, pos - 1);

    p_new_cell->next     = p_current_cell->next;
    p_current_cell->next = p_new_cell;
}

void remove_element(list_map* p_list, int pos) {
    cell_map* p_current_cell = *p_list;
    cell_map* p_old_cell     = NULL;

    // not very efficient to use size function but...
    int length = size(p_list);

    assert(p_list != NULL && pos >= 0 && pos < length);

    if (pos == 0) {
        *p_list = p_current_cell->next;
        free(p_current_cell);

        return;
    }

    p_current_cell       = go_to_position(p_list, pos - 1);
    p_old_cell           = p_current_cell->next;
    p_current_cell->next = p_old_cell->next;

    free(p_old_cell);
}

void deallocate_list(list_map* p_list) {
    cell_map* p_temp_cell    = NULL;
    cell_map* p_current_cell = *p_list;

    while (p_current_cell != NULL) {
        p_temp_cell    = p_current_cell;
        p_current_cell = p_current_cell->next;
        free(p_temp_cell);
    }
    p_list = NULL;
}

void print_list(const list_map* p_list) {
    cell_map* p_current_cell = *p_list;
	int i=0;
    printf("Début de liste\n\n");

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

    printf("Fin de liste\n\n");
}
