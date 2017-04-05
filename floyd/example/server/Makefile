CXX = g++
ifeq ($(__REL), 1)
	CXXFLAGS = -O0 -g -pg -pipe -fPIC -W -Wwrite-strings -Wpointer-arith -Wreorder -Wswitch -Wsign-promo -Wredundant-decls -Wformat -Wall -D_GNU_SOURCE -std=c++11 -D__STDC_FORMAT_MACROS -std=c++11 -gdwarf-2 -Wno-redundant-decls
else
	CXXFLAGS = -O0 -g -pipe -fPIC -W -D__XDEBUG__ -DLOG_LEVEL=LEVEL_DEBUG -Wwrite-strings -Wpointer-arith -Wreorder -Wswitch -Wsign-promo -Wredundant-decls -Wformat -Wall -D_GNU_SOURCE -D__STDC_FORMAT_MACROS -std=c++11 -gdwarf-2 -Wno-redundant-decls
	# CXXFLAGS = -Wall -W -DDEBUG -g -O0 -D__XDEBUG__ -D__STDC_FORMAT_MACROS -fPIC -std=c++11 -gdwarf-2
endif

OBJECT = floyd_node
SRC_DIR = ./
THIRD_PATH = ../../third
OUTPUT = ./output

LIB_PATH = -L../../output/lib/ \
		   -L$(THIRD_PATH)/leveldb/ \
			 -L$(THIRD_PATH)/slash/output/lib/\
			 -L$(THIRD_PATH)/pink/output/lib/


LIBS = -lfloyd \
			 -lpink \
			 -lslash \
			 -lleveldb \
			 -lsnappy \
			 -lprotobuf \
			 -lpthread

INCLUDE_PATH = -I../../output/include/ \
			   -I$(THIRD_PATH)/leveldb/include \
			   -I$(THIRD_PATH)/slash/output/include/ \
			   -I$(THIRD_PATH)/pink/output/include/ \
			   -I$(THIRD_PATH)/pink/output/

LIBRARY = libfloyd.a
.PHONY: all clean version


BASE_BOJS := $(wildcard $(SRC_DIR)/*.cc)
BASE_BOJS += $(wildcard $(SRC_DIR)/*.c)
BASE_BOJS += $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst %.cc,%.o,$(BASE_BOJS))

all: $(OBJECT)
	rm -rf $(OUTPUT)
	mkdir -p $(OUTPUT)
	mkdir -p $(OUTPUT)/bin
	cp $(OBJECT) $(OUTPUT)/bin/
	rm -rf $(OBJECT)
	@echo "Success, go, go, go..."


floyd_node:  $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INCLUDE_PATH) $(LIB_PATH) $(LIBS)


$(OBJS): %.o : %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCLUDE_PATH) 

clean: 
	rm -rf $(OUTPUT)
	rm -rf $(SRC_DIR)/log
	rm -f $(SRC_DIR)/*.o
	rm -rf $(OBJECT) 