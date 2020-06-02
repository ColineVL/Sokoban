#include "linked-list-map.h"

int main(void) {
	// je cree une liste vide
	list_map list;
	list_map* p_list = &list;
	nil(p_list);
	
	// je charge des maps
	smap* p_map_1 = load_map("./data/soko1.in");
	smap* p_map_2 = load_map("./data/soko2.in");
	smap* p_map_3 = load_map("./data/soko3.in");
	smap* p_map_4 = load_map("./data/soko4.in");
	cons(p_list,p_map_4); 
	cons(p_list,p_map_3); 
	cons(p_list,p_map_2); 
	cons(p_list,p_map_1);
	
	// test fonction is_empty
	if (0) {
		printf("is_empty ? %d\n", is_empty(p_list));
	}
	
	// test fonction size
	if (0) {
		printf("size = %d\n",size(p_list));
	}
	
	// test fonction get_element
	if (0) {
		smap* p_map_test = get_element(p_list,1);
		printf("a la position 1 :\n");
		print_map(p_map_test);
		printf("il devrait y avoir : \n");
		print_map(p_map_3);
	}
	// test fonction insert 
	if (0) {
		smap* p_map_81 = load_map("./data/soko81.in");
		insert_element(p_list, 3, p_map_81);
		print_list(p_list);
		free(p_map_81);
	}
	
	// test fonction remove
	if (0) {
		remove_element(p_list, 3);
		print_list(p_list);
	}
	
	// test fonction print_list
	if (0) {
		print_list(p_list);
	}
	
	// test fonction deallocate_list

	deallocate_list(p_list);
	free(p_map_1);
	free(p_map_2);
	free(p_map_3);
	free(p_map_4);

	return 0;
}
