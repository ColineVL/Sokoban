#include "queue-map.h"

int main() {
	queue_map queue;
	queue_map* p_queue = &queue;
	nil_queue(p_queue);
	printf("is empty ? %d\n",is_empty(p_queue));
	
	
	smap* p_map_1 = load_map("./data/soko1.in");
	smap* p_map_2 = load_map("./data/soko2.in");
	smap* p_map_3 = load_map("./data/soko3.in");
	smap* p_map_4 = load_map("./data/soko4.in");
	cell_queue* p_mother = create_first_mother(p_map_1);
	
	enqueue(p_queue, p_map_2, p_mother, 'N');

	
	enqueue(p_queue, p_map_3, p_mother, 'S');

	dequeue(p_queue);
	dequeue(p_queue);
	print_queue(p_queue);
	return 0;
}
