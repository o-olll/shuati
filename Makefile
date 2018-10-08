SOLDIR=
IDIR=lib
LDIR=lib
CC=g++
CFLAGS=-std=c++11 -Wall
CSOLFLAGS=$(CFLAGS) -I$(IDIR) -L$(LDIR)
CLIBFLAGS=$(CFLAGS) -shared -fPIC

liblist: $(LDIR)/list.cc $(LDIR)/list.h
	$(CC) $(CLIBFLAGS) -o $(LDIR)/liblist.so $(LDIR)/list.cc

libtree: $(LDIR)/tree.cc $(LDIR)/tree.h
	$(CC) $(CLIBFLAGS) -o $(LDIR)/libtree.so $(LDIR)/tree.cc

solution-list: $(SOLDIR)/main.cc $(IDIR)/list.h $(IDIR)/utils.h $(LDIR)/liblist.so
	$(CC) $(CSOLFLAGS) -llist $(SOLDIR)/main.cc

solution-tree: $(SOLDIR)/main.cc $(IDIR)/tree.h $(IDIR)/utils.h $(LDIR)/libtree.so
	$(CC) $(CSOLFLAGS) -ltree $(SOLDIR)/main.cc
