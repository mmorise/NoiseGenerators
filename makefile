CXX = g++
C99 = gcc -std=c99
LINK = g++
AR = ar
#DEBUG_FLAG=-g
CXXFLAGS = -O1 -Wall -fPIC $(DEBUG_FLAG)
CFLAGS = $(CXXFLAGS)
ARFLAGS = -rv
OUT_DIR = ./build
OBJS = $(OUT_DIR)/objs/ng/gaussianwhitenoise.o $(OUT_DIR)/objs/ng/modifiedvelvetnoise.o $(OUT_DIR)/objs/ng/originalvelvetnoise.o
LIBS =

all: default test

###############################################################################################################
### Tests
###############################################################################################################
test: $(OUT_DIR)/test

test_OBJS=$(OUT_DIR)/objs/test/test.o
$(OUT_DIR)/test: $(OUT_DIR)/libng.a $(test_OBJS)
	$(LINK) $(CXXFLAGS) -o $(OUT_DIR)/test $(test_OBJS) $(OUT_DIR)/libng.a -lm

$(OUT_DIR)/objs/test/test.o : src/noisegenerators/gaussianwhitenoise.h src/noisegenerators/modifiedvelvetnoise.h src/noisegenerators/originalvelvetnoise.h

###############################################################################################################
### Library
###############################################################################################################
default: $(OUT_DIR)/libng.a

$(OUT_DIR)/libng.a: $(OBJS)
	$(AR) $(ARFLAGS) $(OUT_DIR)/libng.a $(OBJS) $(LIBS)
	@echo Done.

$(OUT_DIR)/objs/ng/gaussianwhitenoise.o : src/noisegenerators/gaussianwhitenoise.h
$(OUT_DIR)/objs/ng/modifiedvelvetnoise.o : src/noisegenerators/modifiedvelvetnoise.h
$(OUT_DIR)/objs/ng/originalvelvetnoise.o : src/noisegenerators/originalvelvetnoise.h

###############################################################################################################
### Global rules
###############################################################################################################
$(OUT_DIR)/objs/test/%.o : %.cpp
	mkdir -p $(OUT_DIR)/objs/test
	$(CXX) $(CXXFLAGS) -Isrc -Itools -o "$@" -c "$<"

$(OUT_DIR)/objs/ng/%.o : src/%.cpp
	mkdir -p $(OUT_DIR)/objs/ng
	$(CXX) $(CXXFLAGS) -Isrc -o "$@" -c "$<"

clean:
	@echo 'Removing all temporary binaries... '
	@$(RM) $(OUT_DIR)/libng.a $(OBJS)
	@$(RM) $(test_OBJS) $(ctest_OBJS) $(OUT_DIR)/test
	@echo Done.

clear: clean

.PHONY: clean clear test default
.DELETE_ON_ERRORS: