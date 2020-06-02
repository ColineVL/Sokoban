#include "loader.h"

int main(int argc, char *argv[]) {
	smap* p_map = load_map(argv[1]); 	//je charge la map
	print_map(p_map);					//je l'affiche
	deallocate(p_map);					// je la free
	return 0;
}


