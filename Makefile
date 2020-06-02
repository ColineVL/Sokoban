_GUI = $(if $(NOGUI),,-D GUI)
CC = gcc
CFLAGS = -g -std=c99 -Wall -I ./include $(_GUI)
LDFLAGS = -lSDL

.PHONY: clean doc add-files-svn

%.o: ./src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

check-syntax: sokoban.o loader.o replay.o play.o test-loader.o test-move.o test-replay.o linked-list-map.o test-linked-list-map.o queue-map.o test-queue-map.o solver.o test-solver.o

test-loader: test-loader.o sokoban.o loader.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test-move: test-move.o sokoban.o loader.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test-replay: test-replay.o sokoban.o loader.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
replay: replay.o sokoban.o loader.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

play: play.o sokoban.o loader.o gui.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test-linked-list-map: test-linked-list-map.o sokoban.o loader.o linked-list-map.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test-queue-map: test-queue-map.o sokoban.o loader.o queue-map.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
test-solver: test-solver.o sokoban.o loader.o queue-map.o linked-list-map.o solver.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	
	
compile-all: replay play test-loader test-move test-replay test-linked-list-map test-queue-map test-solver

	
	

read-file: read-file.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

write-fact: write-fact.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

app-ex-loader: app-ex-loader.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

app-ex-gui: app-ex-gui.o gui.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

add-files-svn:
	svn add --force src/*.c include/*.h data/*.txt --auto-props --parents --depth infinity -q

doc: conf/doxygen.conf
	doxygen $<
	firefox doc/html/index.html

clean:
	- rm -f *.o *.csv fact.txt read-file write-fact app-ex-loader app-ex-gui test-loader test-move test-replay replay play test-linked-list-map

	

