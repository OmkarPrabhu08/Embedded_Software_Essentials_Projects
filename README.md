This is the readme file for the project-1 for the class [ECEN 5013]. The aim of the project was to create a makefile for compiling files for 3 platforms Beaglebone black, Freedom Freescale, Host machine.

The Makefile can be executed in following way:

$ make "target" ARCH=bbb

Here ARCH can be 'bbb' or 'frdm', if no arch is provided then host machine is taken as the architecture.

The Makefile also has source.mk file. This file consist of all the sources which the make file access

The Makefile has the following features:

make build ARCH="arch" : This target build the executable file for the platform specified by ARCH. It also creates dependencies(.dep file) and linker map file.

make compile-all ARCH="arch": This target compiles the object files and stores them into ./obj directory.

make preprocess ARCH="arch":	This target creates Preprocessed files and stores them in the preproc directory.

make asm ARCH="arch":This target generates assembly files and stores them in ./asm directory.

make upload ARCH="arch": This target is used to upload the generated executable to the platform in the ARCH variable using scp command.

make build-all ARCH="arch": This target is used to generate the library file libproject.a using all the object files.

make objdump ARCH="arch": This target gives the disassembly of the generated executable.

Indivisual files can be generated using command: make file. For example: make main.o: This will generate main.o and all the dependancies.

make clean: This target erases all the build and leaves only source, the Makefile and source.mk.
