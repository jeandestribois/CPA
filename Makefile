# VARIABLE
CC:=gcc
CFLAGS:=-Wall -g
SOURCESDIR:=src
BUILDDIR:=build
BINDIR:=bin
TARGET:=cpa
SOURCES:=$(wildcard $(SOURCESDIR)/*.c)
OBJECTS:=$(patsubst $(SOURCESDIR)/%, $(BUILDDIR)/%, $(SOURCES:.c=.o))

# NETOYAGE, COMPILATION ET EXECUTION
all: clean $(TARGET)

# EXECUTION :
run: $(TARGET)
	./$(TARGET)

# EDITION DE LIEN :
$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CC) $^ -o $@ $(CFLAGS)

# COMPILATION :
$(BUILDDIR)/%.o: $(SOURCESDIR)/%.c
	mkdir -p $(BUILDDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

# EDITEUR:
subl:
	subl $(SOURCES)
	subl include/*.h

# NETOYAGE :
clean:
	rm -rf $(BUILDDIR) $(BINDIR)