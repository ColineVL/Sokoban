#include "loader.h"

int main() {
	// je declare mes donnees
	char original[][26] = { "./data/soko_move_1.in",
						"./data/soko_move_1.in",
						"./data/soko_move_1.in",
						"./data/soko_move_1.in",
						"./data/soko_move_2.in",
						"./data/soko_move_2.in",
						"./data/soko_move_2.in",
						"./data/soko_move_2.in",
						"./data/soko_move_3_1.in",
						"./data/soko_move_3_2.in",
						"./data/soko_move_3_3.in",
						"./data/soko_move_3_4.in",
						"./data/soko_move_4_1.in",
						"./data/soko_move_4_2.in",
						"./data/soko_move_4_3.in",
						"./data/soko_move_4_4.in",
						"./data/soko_move_5_1.in",
						"./data/soko_move_5_2.in",
						"./data/soko_move_5_3.in",
						"./data/soko_move_5_4.in",
						"./data/soko_move_6_1.in",
						"./data/soko_move_6_2.in",
						"./data/soko_move_6_3.in",
						"./data/soko_move_6_4.in",
						"./data/soko_move_W_E.in",
						"./data/soko_move_W_W.in",
						"./data/soko_move_W_N.in",
						"./data/soko_move_W_S.in",
						"./data/soko_move_B_W_E.in",
						"./data/soko_move_B_W_W.in",
						"./data/soko_move_B_W_N.in",
						"./data/soko_move_B_W_S.in",
						"./data/soko_move_B_B_E.in",
						"./data/soko_move_B_B_W.in",
						"./data/soko_move_B_B_N.in",
						"./data/soko_move_B_B_S.in"
						};
						
	char result[][26] = { "./data/soko_move_1_N.in",
						"./data/soko_move_1_S.in",
						"./data/soko_move_1_E.in",
						"./data/soko_move_1_W.in",
						"./data/soko_move_2_N.in",
						"./data/soko_move_2_S.in",
						"./data/soko_move_2_E.in",
						"./data/soko_move_2_W.in",
						"./data/soko_move_3_1_E.in",
						"./data/soko_move_3_2_E.in",
						"./data/soko_move_3_3_E.in",
						"./data/soko_move_3_4_E.in",
						"./data/soko_move_4_1_W.in",
						"./data/soko_move_4_2_W.in",
						"./data/soko_move_4_3_W.in",
						"./data/soko_move_4_4_W.in",
						"./data/soko_move_5_1_N.in",
						"./data/soko_move_5_2_N.in",
						"./data/soko_move_5_3_N.in",
						"./data/soko_move_5_4_N.in",
						"./data/soko_move_6_1_S.in",
						"./data/soko_move_6_2_S.in",
						"./data/soko_move_6_3_S.in",
						"./data/soko_move_6_4_S.in",
						"./data/soko_move_W_E.in",
						"./data/soko_move_W_W.in",
						"./data/soko_move_W_N.in",
						"./data/soko_move_W_S.in",
						"./data/soko_move_B_W_E.in",
						"./data/soko_move_B_W_W.in",
						"./data/soko_move_B_W_N.in",
						"./data/soko_move_B_W_S.in",
						"./data/soko_move_B_B_E.in",
						"./data/soko_move_B_B_W.in",
						"./data/soko_move_B_B_N.in",
						"./data/soko_move_B_B_S.in" };
						
	int liste_N[] = {0,4,16,17,18,19,26,30,34};
	int liste_S[] = {1,5,20,21,22,23,27,31,35};
	int liste_E[] = {2,6,8,9,10,11,24,28,32};
	int liste_W[] = {3,7,12,13,14,15,25,29,33};
	
	// je declare ce dont j'aurai besoin 	
	char direction;
	smap* p_map;
	smap* p_map_ref; 
	smap* p_map_mov;
	scell pos;
	scell pos_ref;
	scell pos_mov;
	
	
	// je verifie pour chaque map
	for (int i=0; i<6*4+12; i++) {
				
		if (is_in(i,liste_N,9)) {
			direction = 'N';}
		
		if (is_in(i,liste_S,9)) {
			direction = 'S';}
		
		if (is_in(i,liste_E,9)) {
			direction = 'E';}
		
		if (is_in(i,liste_W,9)) {
			direction = 'W';}
		
		p_map = load_map(original[i]);
		p_map_ref = load_map(result[i]);
		p_map_mov = move_player(p_map,direction);
		
		pos = p_map->player;
		pos_ref = p_map_ref->player;
		pos_mov = p_map_mov->player;
		
		
		assert(p_map_mov->wid == p_map_ref->wid);
		assert(p_map_mov->hei == p_map_ref->hei);
		assert(p_map_mov->storage == p_map_ref->storage);
				
		assert(pos_mov.c == pos_ref.c);
		assert(pos_mov.l == pos_ref.l);
		assert(pos_mov.val == pos_ref.val);
		
		for (int j=0;j<p_map_mov->wid*p_map_mov->hei;j++) {
			assert(p_map_mov->elts[j]==p_map_ref->elts[j]);
		}
		
		// Si p_map_mov et p_map ne pointent pas vers la même chose, je free p_map_mov
		if (pos.c!=pos_mov.c || pos.l != pos_mov.l) {
			deallocate(p_map_mov);
		}
		deallocate(p_map);
		deallocate(p_map_ref);
	}	
	return 0;
}
