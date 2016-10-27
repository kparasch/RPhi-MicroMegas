SRCDIR = ../../Source
INCDIR = ../../Include

CC = g++
CFLAGS = `root-config --libs --cflags` \
	-I$(INCDIR)

all: test_map

test_map: test_map.cpp $(SRCDIR)/channels_map.cpp $(INCDIR)/channels_map.h
	@echo "Building executable..."
	@$(CC) $(CFLAGS) $^ -o test_map

clean: 
	rm test_map
