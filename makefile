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
	@$(CC) $(CFLAGS) $^ -o mymain

$(OBJDIR)/raw.o: $(SRCDIR)/raw.C $(INCDIR)/raw.h 
	@echo $@
	@$(CC) -c $(CFLAGS) $< -o $@
	
$(OBJDIR)/RPhi_analysis.o: $(SRCDIR)/RPhi_analysis.cpp $(INCDIR)/RPhi_analysis.h 
	@echo $@
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJDIR)/hist_generator.o: $(SRCDIR)/hist_generator.cpp $(INCDIR)/hist_generator.h
	@echo $@
	@$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm $(OBJDIR)/*.o
