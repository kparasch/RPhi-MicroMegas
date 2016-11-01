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

$(OBJDIR)/Histograms.o: $(SRCDIR)/Histograms.cc $(INCDIR)/Histograms.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/event_functions.o: $(SRCDIR)/event_functions.cc $(INCDIR)/event_functions.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/channels_map.o: $(SRCDIR)/channels_map.cc $(INCDIR)/channels_map.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/clustering.o: $(SRCDIR)/clustering.cc $(INCDIR)/clustering.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/fitting_functions.o: $(SRCDIR)/fitting_functions.cc $(INCDIR)/fitting_functions.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/dumping.o: $(SRCDIR)/dumping.cc $(INCDIR)/dumping.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/EmptyChannels.o: $(SRCDIR)/EmptyChannels.cc $(INCDIR)/EmptyChannels.h
	@echo "Building "$@"..."
	@$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm $(OBJDIR)/*.o
