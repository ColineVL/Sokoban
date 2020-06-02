#include "loader.h"

int main() {
	// je declare mes donnees
	char originals[8][50] = { "./data/soko_dumb.in",
							"./data/soko_dumb.in",
							"./data/soko_dumb.in",
							"./data/soko_dumb.in",
							"./data/soko_dumb.in",
							"./data/soko1.in",
							"./data/soko1.in",
							"./data/soko1.in",
							};
	
	int lengths[8] = {3,5,7,7,9,100,150,184};
	
	char results[8][50] = { "./data/soko_dumb_1.in",
						"./data/soko_dumb_2.in",
						"./data/soko_dumb_win.in",
						"./data/soko_dumb_3.in",
						"./data/soko_dumb_win.in",
						"./data/soko1_1.in",
						"./data/soko1_2.in",
						"./data/soko1_win.in"
						};

	char plans[8][200] = {"SSSEENN",
						"SSSEENN",
						"SSSEENN",
						"ESEESSWNN",
						"ESEESSWNN",
						"NNWWSWWNEESWSWWWNNEESSESSWWNSEENNNENENESSSWSWENEESWWNENNWWSWWNWWSSESSEENNWNEWNEEENESSSWSWENENNWWWWWWSSESSEENNWESEENEESWWWENENNWWWWSSENWNEEENESSNWWWWWWSSESSEENEEEENWSWWWNNWNEEENESSSESWW",
						"NNWWSWWNEESWSWWWNNEESSESSWWNSEENNNENENESSSWSWENEESWWNENNWWSWWNWWSSESSEENNWNEWNEEENESSSWSWENENNWWWWWWSSESSEENNWESEENEESWWWENENNWWWWSSENWNEEENESSNWWWWWWSSESSEENEEEENWSWWWNNWNEEENESSSESWW",
						"NNWWSWWNEESWSWWWNNEESSESSWWNSEENNNENENESSSWSWENEESWWNENNWWSWWNWWSSESSEENNWNEWNEEENESSSWSWENENNWWWWWWSSESSEENNWESEENEESWWWENENNWWWWSSENWNEEENESSNWWWWWWSSESSEENEEEENWSWWWNNWNEEENESSSESWW"
						};
				
	// je declare ce dont j'aurai besoin 					
	scell cell_mov;
	scell cell_ref;
	
	smap* p_map_original;
	smap* p_map_ref = NULL;
	smap* p_map_mov = NULL;
	
	int height;
	int width;
	
	// je verifie pour chaque map
	for (int i=0; i<8; i++) {
		
		p_map_original = load_map(originals[i]);
		p_map_ref = load_map(results[i]);
		p_map_mov = replay(p_map_original, lengths[i], plans[i]);				
		width = p_map_mov->wid;
		height = p_map_mov->hei;
		cell_mov = p_map_mov->player;
		cell_ref = p_map_ref->player;
		
		assert(p_map_mov->wid == p_map_ref->wid);
		assert(p_map_mov->hei == p_map_ref->hei);
		assert(cell_mov.c == cell_ref.c);
		assert(cell_mov.l == cell_ref.l);
		assert(cell_mov.val == cell_ref.val);
		
		for (int j=0; j<width*height; j++) {
			assert(p_map_mov->elts[j]==p_map_ref->elts[j]);
		}
		
		deallocate(p_map_ref);
		deallocate(p_map_mov); 
	}
	
	
	return 0;
}
