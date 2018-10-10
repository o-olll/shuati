SOLFILE=
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

solution-list: src/$(SOLFILE).cc $(IDIR)/list.h $(IDIR)/utils.h $(LDIR)/liblist.so
	$(CC) $(CSOLFLAGS) -llist src/$(SOLFILE).cc

solution-tree: src/$(SOLFILE.cc $(IDIR)/tree.h $(IDIR)/utils.h $(LDIR)/libtree.so
	$(CC) $(CSOLFLAGS) -ltree src/$(SOLFILE).cc
