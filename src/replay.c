#include "loader.h"

int main(int argc, char *argv[]) {	
	smap* p_map = load_map(argv[1]);
	smap* p_map_played = replay(p_map, atoi(argv[2]), argv[3]);
	
	print_map(p_map_played);
			
	deallocate(p_map_played);
	return 0;
}

