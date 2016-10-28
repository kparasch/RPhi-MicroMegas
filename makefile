OBJDIR = Object
SRCDIR = Source
INCDIR = Include

HEADERS = $(wildcard $(INCDIR)/*.h)
OBJECTS = $(subst $(INCDIR), $(OBJDIR), $(HEADERS:.h=.o))

CC = g++
CFLAGS = `root-config --libs --cflags` \
	-I$(INCDIR)

all: $(OBJECTS) mymain

mymain:	$(OBJECTS)
	@echo "Building executable..."
	@$(CC) $(CFLAGS) $^ -o mymain

$(OBJDIR)/raw.o: $(SRCDIR)/raw.C $(INCDIR)/raw.h 
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@
	
$(OBJDIR)/data.o: $(SRCDIR)/data.C $(INCDIR)/data.h 
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@
	
$(OBJDIR)/RPhi_analysis.o: $(SRCDIR)/RPhi_analysis.cc $(INCDIR)/RPhi_analysis.h 
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/hist_generator.o: $(SRCDIR)/hist_generator.cc $(INCDIR)/hist_generator.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/event_functions.o: $(SRCDIR)/event_functions.cc $(INCDIR)/event_functions.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/channels_map.o: $(SRCDIR)/channels_map.cc $(INCDIR)/channels_map.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm $(OBJDIR)/*.o
