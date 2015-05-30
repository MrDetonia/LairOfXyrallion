###################
# BUILD VARIABLES #
###################

# Compiler to use
CC = g++

# Compiler flags
CFLAGS = -g -std=c++14 -Wall -Wextra -Wpedantic -Werror

# Linker flags
LFLAGS = -lcurses

# Directory containing source files
SOURCEDIR = src

# Directory to build objects
OBJDIR = obj

# Directory to build executable
BUILDDIR = bin

# Executable to produce
TARGET = RL

# Directory to install to
INSTDIR = /usr/local/bin

# NOTHING SHOULD NEED TO CHANGE BEYOND THIS POINT

# Source files to use
SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)

# Objects to compile in executable
OBJS = $(patsubst $(SOURCEDIR)/%.cpp,$(OBJDIR)/%.o,$(SOURCES))


#################
# BUILD TARGETS #
#################

# make target
.PHONY: all
all: $(SOURCES) $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LFLAGS)

$(OBJS): $(OBJDIR)/%.o: $(SOURCEDIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

# install target
.PHONY: install
install:
	cp $(BUILDDIR)/$(TARGET) $(INSTDIR)/$(TARGET)

# uninstall target
.PHONY: uninstall
uninstall:
	rm $(INSTDIR)/$(TARGET)

# clean build directories
.PHONY: clean
clean:
	rm -fr $(OBJDIR)/*o $(BUILDDIR)/$(TARGET)
