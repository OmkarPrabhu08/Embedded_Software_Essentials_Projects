# Include source files
include sources.mk

IS:=$(SRCS:.c=.i)
AS:=$(IS:.i=.s)
OBJS:=$(AS:.s=.o)
PROJECT1IS:=$(PROJECT1SRCS:.c=.i)
PROJECT1AS:=$(PROJECT1IS:.i=.s)
PROJECT1OBJS:=$(PROJECT1AS:.s=.o)
LIBRARYOBJS:=$(MAIN:.c=.o)

DEP = project1.dep
MAP = project1.map

SRCDIR = ./src/
INCDIR = ./inc/
LIBDIR = ./lib/
BINDIR = ./bin/

#Flags
CFLAGS = -g -Wall -Werror -I$(INCDIR) -std=c99 -D PROJECT1
LDFLAGS= -Wl,-Map=$(MAP),-O0
ARFLAGS = rcs
LINKERFLAGS = -dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc -static

LIBRARY = libproject1.a

#This is final binary
TARGET=project1

#if platform is specified
export PLATFORM

# Default Compiler
CC = gcc

# Architecture
ARCH := $(shell uname -m)

ifeq ($(ARCH),x86_64)
CC = gcc
AR = ar
SIZE = size
NM = nm
LD = ld
endif

ifeq ($(ARCH),armv7l)
CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar
SIZE = arm-linux-gnueabihf-size
NM = arm-linux-gnueabihf-nm
LD = arm-linux-gnueabihf-ld
CFLAGS += -march=armv7-a -mtune=cortex-a8 -mfpu=neon
LINKERFLAGS = -dynamic-linker /usr/arm-linux-gnueabihf/lib/ld-linux-armhf.so.3 -lc -static
endif

ifeq ($(PLATFORM),host)
CC = gcc
AR = ar
SIZE = size
NM = nm
LD = ld
endif

ifeq ($(PLATFORM),bbb)
CC = arm-linux-gnueabihf-gcc
AR = arm-linux-gnueabihf-ar
SIZE = arm-linux-gnueabihf-size
NM = arm-linux-gnueabihf-nm
LD = arm-linux-gnueabihf-ld
CFLAGS += -march=armv7-a -mtune=cortex-a8 -mfpu=neon
LINKERFLAGS = -dynamic-linker /usr/arm-linux-gnueabihf/lib/ld-linux-armhf.so.3 -lc -static
endif

ifeq ($(PLATFORM),frdm)
CC = arm-none-eabi-gcc
AR = arm-none-eabi-ar
SIZE = arm-none-eabi-size
NM = arm-none-eabi-nm
LD = arm-none-eabi-ld
CFLAGS += -march=armv6-m -mcpu=cortex-m0plus -mthumb --specs=nosys.specs -D FRDM_PRINT
LINKERFLAGS = -dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc -static
endif

%.i : %.c
	$(CC) -E $< -o $@ $(CFLAGS)

%.s : %.i
	$(CC) -S $< -o $@ $(CFLAGS)

%.o : %.s
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: build compile-all clean
build: $(OBJS)
	$(CC) -o $(BINDIR)$(TARGET) $^ $(CFLAGS) $(LDFLAGS)
	$(SIZE) $(BINDIR)$(TARGET)
	$(NM) $(OBJS)
	$(CC) -M $(SRCS) -o $(DEP) $(CFLAGS)

compile-all: $(SRCS)
	$(CC) -c $^ $(CFLAGS)
	mv *.o ./src

build-lib: $(PROJECT1OBJS) | $(LIBRARYOBJS)
	$(AR) $(ARFLAGS) $(LIBDIR)$(LIBRARY) $(PROJECT1OBJS)
	$(LD) $(LINKERFLAGS) $(LIBRARYOBJS) $(LIBDIR)$(LIBRARY) --entry main -o $(BINDIR)$(TARGET)
	
clean:	
	rm -f $(IS) 
	rm -f $(AS)
	rm -f $(OBJS)
	rm -f $(BINDIR)$(TARGET)
	rm -f $(DEP)
	rm -f $(MAP)
	rm -f $(LIBDIR)$(LIBRARY)
