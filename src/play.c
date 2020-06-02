#include "loader.h"
#include "gui.h"

void print_map_GUI(smap* p_map) {
	scell cell;
   	for (int line = 0; line < p_map->hei; line++) {
		cell.l = line;
		for (int col = 0; col < p_map->wid; col++) {
			cell.c = col;
			cell.val = access_map(p_map, cell);
			GUI_Show(col, line, cell.val);
		}
	}
}

void print_map_win_GUI(smap* p_map) {
	for (int line=0; line < p_map->hei; line++) {
		for (int col=0; col < p_map->wid; col ++) {
			GUI_Show(col, line, BOX);
		}
	}
}

int main(int argc, char *argv[]) {
	char* filename = argv[1];

	smap* p_map = load_map(filename);
	smap* p_new_map = NULL;
	int height = p_map->hei;
	int width = p_map->wid;
	scell pos;
	scell pos_new;
	
	bool stop = false;
	bool win = false;

	// initialize GUI window

   	GUI_Init("Sokoban", width, height);
	
	// main loop
	while (true) {
		
		print_map_GUI(p_map);
		
		switch(GUI_GetKey()) {
			
		case SDLK_UP:
			p_new_map = move_player(p_map, 'N');
			// Si p_new_map et p_map ne pointent pas vers la même chose, je free p_map
			pos_new = p_new_map->player;	
			pos = p_map->player;
			if (pos.c!=pos_new.c || pos.l != pos_new.l) {
				deallocate(p_map);
			}
			
			p_map = p_new_map;
			if (p_map->storage == 0) {
				win = true;
			}
			break;
			
		case SDLK_DOWN:
			p_new_map = move_player(p_map, 'S');
			// Si p_new_map et p_map ne pointent pas vers la même chose, je free p_map
			pos_new = p_new_map->player;
			pos = p_map->player;
			if (pos.c!=pos_new.c || pos.l != pos_new.l) {
				deallocate(p_map);
			}
			
			p_map = p_new_map;
			if (p_map->storage == 0) {
				win = true;
			}
			break;
			
		case SDLK_LEFT:
			p_new_map = move_player(p_map, 'W');
			// Si p_new_map et p_map ne pointent pas vers la même chose, je free p_map
			pos_new = p_new_map->player;
			pos = p_map->player;
			if (pos.c!=pos_new.c || pos.l != pos_new.l) {
				deallocate(p_map);
			}
			
			p_map = p_new_map;
			if (p_map->storage == 0) {
				win = true;
			}
			break;
			
		case SDLK_RIGHT:
			p_new_map = move_player(p_map, 'E');
			// Si p_new_map et p_map ne pointent pas vers la même chose, je free p_map
			pos_new = p_new_map->player;
			pos = p_map->player;
			if (pos.c!=pos_new.c || pos.l != pos_new.l) {
				deallocate(p_map);
			}
			
			p_map = p_new_map;
			if (p_map->storage == 0) {
				win = true;
			}
			break;
		
		
		case 'q':
			stop = true;
			break;
			
		}
		if (stop) {
			break;
		}
		if (win) {												// il n'y a plus de storage vide sur la map
			print_map_win_GUI(p_map);
			Pause(500);
			printf("\n \n \nCongrats, you won !\n \n \n");
			break;
		}
	}
	deallocate(p_map);
	GUI_Close(EXIT_SUCCESS);
	return EXIT_SUCCESS;
}
	
