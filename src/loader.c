#include "loader.h"

smap* load_map(char* filename) {
	
    FILE *p_file = NULL;
    p_file = fopen(filename, "r");
    if (p_file == NULL) {
        fprintf(stderr, "Cannot read file %s!\n", filename);
        exit(EXIT_FAILURE);
    }
	
	// je lis la première ligne et je range les dimensions dans la map
    int width = 0;
    int height = 0;
    int fscanf_result = 0;
    fscanf_result = fscanf(p_file, "%d %d\n", &width, &height);
    if (fscanf_result != 2) {
        fprintf(stderr, "First line is not syntactically correct!\n");
        exit(EXIT_FAILURE);
    }
    
	// ca y est je peux créer ma map
			
	smap* p_map = NULL;
	p_map = malloc(sizeof(smap)+width*height*sizeof(char));
	if (p_map == NULL) {
		printf("ERREUR DE MALLOC DANS LOADER"); }
	p_map->elts = (char*)(p_map+1);
	p_map->wid = width;
	p_map->hei = height;
	p_map->storage = 0;
	scell player;
	
    // je lis les lignes suivantes et je les range dans p_map->elts
    // width + 2 is needed to get the carriage return symbol
    char line_buffer[width + 2];
	scell cell;
	
    for (int i = 0; i < height; i++) {
		fgets(line_buffer, width + 2, p_file);
		cell.l = i;
        
		for (int j=0; j < width; j++) {
			cell.c = j;
			
			modify_map(p_map,cell,line_buffer[j]);
			cell.val = access_map(p_map, cell);
			// je recupere la position du joueur
			if (cell.val==BOY	|| cell.val==BOY_ON) {
				player.c = j;
				player.l = i;
				player.val = cell.val;
			}
			// je compte le nombre de storage vides
			if (cell.val == PARK || cell.val == BOY_ON) {
				p_map->storage += 1;
			}
			
		}
    }
    p_map->player = player;

    fclose(p_file);
	return p_map;
}
