#include "sokoban.h"

bool is_in(int value, int* tableau, int len) {
	for (int i=0; i<len; i++) {
		if (value==tableau[i]) {
			return true;
		}
	}
	return false;
}

char access_map(smap* p_map, scell cell) {
	char* p_elements = p_map->elts;
	char elt = p_elements[cell.l*p_map->wid+cell.c];
	return elt;
}

void modify_map(smap* p_map, scell cell, char new) {
	int width = p_map->wid;
	(p_map->elts)[cell.l*width+cell.c] = new;
}	

void print_map(smap* p_map) {
	int height = p_map->hei;
	int width = p_map->wid;
	
	printf("\n");
	for (int i=0; i<height; i++) {
		for (int j=0; j<width; j++) {
			scell cell_to_print;
			cell_to_print.l = i;
			cell_to_print.c = j;
			cell_to_print.val = access_map(p_map, cell_to_print);
			printf("%c",cell_to_print.val);
		}
		printf("\n");
	}
	printf("\n");
}

smap* create_doublon(smap map) {
	smap* p_new_map = NULL;
	int width = map.wid;
	int height = map.hei;
	p_new_map = malloc(sizeof(smap) + width*height*sizeof(char));
	if (p_new_map==NULL) { printf("ERREUR MALLOC");}
	p_new_map->elts = (char*)(p_new_map+1);
	p_new_map->hei = height;
	p_new_map->wid = width;
	scell cell = map.player;
	p_new_map->player = cell;
	char* temp = map.elts;
	for (int i=0;i<width*height;i++) {
		p_new_map->elts[i] = temp[i];
	}
	p_new_map->storage = map.storage;
	return p_new_map;
}

void move_box(smap* p_map, scell goal_cell, char direction, bool* p_mvt_impossible){
	scell next_cell = goal_cell;
	if (direction=='N') { next_cell.l -= 1; }
	if (direction=='S') { next_cell.l += 1; }
	if (direction=='E') { next_cell.c += 1; }
	if (direction=='W') { next_cell.c -= 1; }
	next_cell.val = access_map(p_map, next_cell);
	if ( next_cell.val == WALL || next_cell.val == BOX || next_cell.val == BOX_ON) {
		*p_mvt_impossible = true;
		deallocate(p_map);
	}
	
	if (next_cell.val == PARK) {
		modify_map(p_map, next_cell, BOX_ON);
		p_map->storage -= 1;
	}
	
	if (next_cell.val == EMPTY) {
		modify_map(p_map, next_cell, BOX);
	}
	
	if (goal_cell.val == PARK || goal_cell.val == BOX_ON) {
		p_map->storage += 1;
	}	
		
}

smap* move_player(smap* p_map, char direction) {

	smap* p_new_map = create_doublon(*p_map);
	
	// je stocke les anciennes valeurs et les positions concernées
	scell old_player = p_new_map->player;
	old_player.val = access_map(p_new_map, old_player);
	
	scell new_player = p_new_map->player;
	if (direction=='N') { new_player.l -= 1; }
	if (direction=='S') { new_player.l += 1; }
	if (direction=='E') { new_player.c += 1; }
	if (direction=='W') { new_player.c -= 1; }
	new_player.val = access_map(p_new_map, new_player);
	
	// j'expédie le cas mouvement impossible car on rentre dans le mur
	if (new_player.val == WALL) {
		deallocate(p_new_map);
		return p_map;  }
	// si je veux pousser une box : verifier que je peux, et deplacer la boite
	// appel à fonction auxiliaire move_box
	if (new_player.val == BOX_ON || new_player.val == BOX) {
		bool mvt_impossible = false;
		move_box(p_new_map, new_player, direction, &mvt_impossible);
		if (mvt_impossible) {
			return p_map;
		}
	}
	
	// je modifie l'ancienne case
	if (old_player.val == BOY) {
		modify_map(p_new_map, old_player, EMPTY);
	}
	if (old_player.val == BOY_ON) {
		modify_map(p_new_map, old_player, PARK);
	}
	
	// je modifie la nouvelle case
	if (new_player.val == EMPTY) {
		modify_map(p_new_map, new_player, BOY);
		
	}
	
	if (new_player.val == BOX) {
		modify_map(p_new_map, new_player, BOY);
	}
	
	if (new_player.val == BOX_ON) {
		modify_map(p_new_map, new_player, BOY_ON);
	}
	
	if (new_player.val == PARK) {
		modify_map(p_new_map, new_player, BOY_ON);
	}
	
	new_player.val = access_map(p_new_map, new_player);
	
	p_new_map->player = new_player;
	
	return p_new_map;
}

void deallocate(smap* p_map) {
	free(p_map);              
}

smap* replay(smap* p_map,int length,char* mvts) {
	for (int i=0; i<length; i++) {
		smap* p_map_temp = move_player(p_map,mvts[i]);
		
		
		scell pos_mov = p_map_temp->player;
		scell pos = p_map->player;
		if (pos.c!=pos_mov.c || pos.l != pos_mov.l) {
			deallocate(p_map);
		}
		p_map = p_map_temp;
	}
	return p_map;
}
