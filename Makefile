#############################################################################
# Makefile for building: cg3D
# Generated by qmake (2.01a) (Qt 4.8.6) on: lun. avr. 20 11:27:44 2015
# Project:  cg3D.pro
# Template: app
# Command: /opt/qt48/bin/qmake -o Makefile cg3D.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_XML_LIB -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/qt48/mkspecs/linux-g++ -I. -I/opt/qt48/include/QtCore -I/opt/qt48/include/QtGui -I/opt/qt48/include/QtOpenGL -I/opt/qt48/include/QtXml -I/opt/qt48/include -I/usr/X11R6/include -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/opt/qt48/lib
LIBS          = $(SUBLIBS)  -L/usr/X11R6/lib -L/opt/qt48/lib -lglut -lGLEW -lQGLViewer -lGL -lQtXml -L/opt/qt48/lib -lQtOpenGL -L/usr/X11R6/lib -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/qt48/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = body.cpp \
		conicalFrustrum.cpp \
		cube.cpp \
		cylinder.cpp \
		dragon.cpp \
		dynamicSystem.cpp \
		ears.cpp \
		eyes.cpp \
		head.cpp \
		jaw.cpp \
		leg.cpp \
		main.cpp \
		neck.cpp \
		particle.cpp \
		spring.cpp \
		tail.cpp \
		teeth.cpp \
		viewer.cpp 
OBJECTS       = body.o \
		conicalFrustrum.o \
		cube.o \
		cylinder.o \
		dragon.o \
		dynamicSystem.o \
		ears.o \
		eyes.o \
		head.o \
		jaw.o \
		leg.o \
		main.o \
		neck.o \
		particle.o \
		spring.o \
		tail.o \
		teeth.o \
		viewer.o
DIST          = /opt/qt48/mkspecs/common/unix.conf \
		/opt/qt48/mkspecs/common/linux.conf \
		/opt/qt48/mkspecs/common/gcc-base.conf \
		/opt/qt48/mkspecs/common/gcc-base-unix.conf \
		/opt/qt48/mkspecs/common/g++-base.conf \
		/opt/qt48/mkspecs/common/g++-unix.conf \
		/opt/qt48/mkspecs/qconfig.pri \
		/opt/qt48/mkspecs/modules/qt_webkit_version.pri \
		/opt/qt48/mkspecs/features/qt_functions.prf \
		/opt/qt48/mkspecs/features/qt_config.prf \
		/opt/qt48/mkspecs/features/exclusive_builds.prf \
		/opt/qt48/mkspecs/features/default_pre.prf \
		/opt/qt48/mkspecs/features/debug.prf \
		/opt/qt48/mkspecs/features/default_post.prf \
		/opt/qt48/mkspecs/features/warn_on.prf \
		/opt/qt48/mkspecs/features/unix/opengl.prf \
		/opt/qt48/mkspecs/features/qt.prf \
		/opt/qt48/mkspecs/features/unix/thread.prf \
		/opt/qt48/mkspecs/features/moc.prf \
		/opt/qt48/mkspecs/features/shared.prf \
		/opt/qt48/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/qt48/mkspecs/features/resources.prf \
		/opt/qt48/mkspecs/features/uic.prf \
		/opt/qt48/mkspecs/features/yacc.prf \
		/opt/qt48/mkspecs/features/lex.prf \
		/opt/qt48/mkspecs/features/include_source_dir.prf \
		cg3D.pro
QMAKE_TARGET  = cg3D
DESTDIR       = 
TARGET        = cg3D

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: cg3D.pro  /opt/qt48/mkspecs/linux-g++/qmake.conf /opt/qt48/mkspecs/common/unix.conf \
		/opt/qt48/mkspecs/common/linux.conf \
		/opt/qt48/mkspecs/common/gcc-base.conf \
		/opt/qt48/mkspecs/common/gcc-base-unix.conf \
		/opt/qt48/mkspecs/common/g++-base.conf \
		/opt/qt48/mkspecs/common/g++-unix.conf \
		/opt/qt48/mkspecs/qconfig.pri \
		/opt/qt48/mkspecs/modules/qt_webkit_version.pri \
		/opt/qt48/mkspecs/features/qt_functions.prf \
		/opt/qt48/mkspecs/features/qt_config.prf \
		/opt/qt48/mkspecs/features/exclusive_builds.prf \
		/opt/qt48/mkspecs/features/default_pre.prf \
		/opt/qt48/mkspecs/features/debug.prf \
		/opt/qt48/mkspecs/features/default_post.prf \
		/opt/qt48/mkspecs/features/warn_on.prf \
		/opt/qt48/mkspecs/features/unix/opengl.prf \
		/opt/qt48/mkspecs/features/qt.prf \
		/opt/qt48/mkspecs/features/unix/thread.prf \
		/opt/qt48/mkspecs/features/moc.prf \
		/opt/qt48/mkspecs/features/shared.prf \
		/opt/qt48/mkspecs/features/unix/gdb_dwarf_index.prf \
		/opt/qt48/mkspecs/features/resources.prf \
		/opt/qt48/mkspecs/features/uic.prf \
		/opt/qt48/mkspecs/features/yacc.prf \
		/opt/qt48/mkspecs/features/lex.prf \
		/opt/qt48/mkspecs/features/include_source_dir.prf \
		/opt/qt48/lib/libQtXml.prl \
		/opt/qt48/lib/libQtCore.prl \
		/opt/qt48/lib/libQtOpenGL.prl \
		/opt/qt48/lib/libQtGui.prl
	$(QMAKE) -o Makefile cg3D.pro
/opt/qt48/mkspecs/common/unix.conf:
/opt/qt48/mkspecs/common/linux.conf:
/opt/qt48/mkspecs/common/gcc-base.conf:
/opt/qt48/mkspecs/common/gcc-base-unix.conf:
/opt/qt48/mkspecs/common/g++-base.conf:
/opt/qt48/mkspecs/common/g++-unix.conf:
/opt/qt48/mkspecs/qconfig.pri:
/opt/qt48/mkspecs/modules/qt_webkit_version.pri:
/opt/qt48/mkspecs/features/qt_functions.prf:
/opt/qt48/mkspecs/features/qt_config.prf:
/opt/qt48/mkspecs/features/exclusive_builds.prf:
/opt/qt48/mkspecs/features/default_pre.prf:
/opt/qt48/mkspecs/features/debug.prf:
/opt/qt48/mkspecs/features/default_post.prf:
/opt/qt48/mkspecs/features/warn_on.prf:
/opt/qt48/mkspecs/features/unix/opengl.prf:
/opt/qt48/mkspecs/features/qt.prf:
/opt/qt48/mkspecs/features/unix/thread.prf:
/opt/qt48/mkspecs/features/moc.prf:
/opt/qt48/mkspecs/features/shared.prf:
/opt/qt48/mkspecs/features/unix/gdb_dwarf_index.prf:
/opt/qt48/mkspecs/features/resources.prf:
/opt/qt48/mkspecs/features/uic.prf:
/opt/qt48/mkspecs/features/yacc.prf:
/opt/qt48/mkspecs/features/lex.prf:
/opt/qt48/mkspecs/features/include_source_dir.prf:
/opt/qt48/lib/libQtXml.prl:
/opt/qt48/lib/libQtCore.prl:
/opt/qt48/lib/libQtOpenGL.prl:
/opt/qt48/lib/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile cg3D.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/cg3D1.0.0 || $(MKDIR) .tmp/cg3D1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/cg3D1.0.0/ && $(COPY_FILE) --parents body.h conicalFrustrum.h cube.h cylinder.h dragon.h dynamicSystem.h ears.h eyes.h head.h jaw.h leg.h neck.h particle.h renderable.h spring.h tail.h teeth.h viewer.h .tmp/cg3D1.0.0/ && $(COPY_FILE) --parents body.cpp conicalFrustrum.cpp cube.cpp cylinder.cpp dragon.cpp dynamicSystem.cpp ears.cpp eyes.cpp head.cpp jaw.cpp leg.cpp main.cpp neck.cpp particle.cpp spring.cpp tail.cpp teeth.cpp viewer.cpp .tmp/cg3D1.0.0/ && (cd `dirname .tmp/cg3D1.0.0` && $(TAR) cg3D1.0.0.tar cg3D1.0.0 && $(COMPRESS) cg3D1.0.0.tar) && $(MOVE) `dirname .tmp/cg3D1.0.0`/cg3D1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/cg3D1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

body.o: body.cpp body.h \
		renderable.h \
		cylinder.h \
		conicalFrustrum.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o body.o body.cpp

conicalFrustrum.o: conicalFrustrum.cpp conicalFrustrum.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o conicalFrustrum.o conicalFrustrum.cpp

cube.o: cube.cpp cube.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cube.o cube.cpp

cylinder.o: cylinder.cpp cylinder.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cylinder.o cylinder.cpp

dragon.o: dragon.cpp dragon.h \
		renderable.h \
		body.h \
		cylinder.h \
		conicalFrustrum.h \
		leg.h \
		tail.h \
		neck.h \
		head.h \
		ears.h \
		jaw.h \
		teeth.h \
		eyes.h \
		cube.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dragon.o dragon.cpp

dynamicSystem.o: dynamicSystem.cpp viewer.h \
		dynamicSystem.h \
		spring.h \
		particle.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dynamicSystem.o dynamicSystem.cpp

ears.o: ears.cpp ears.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ears.o ears.cpp

eyes.o: eyes.cpp eyes.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o eyes.o eyes.cpp

head.o: head.cpp head.h \
		renderable.h \
		ears.h \
		jaw.h \
		teeth.h \
		eyes.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o head.o head.cpp

jaw.o: jaw.cpp jaw.h \
		renderable.h \
		teeth.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o jaw.o jaw.cpp

leg.o: leg.cpp leg.h \
		renderable.h \
		conicalFrustrum.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o leg.o leg.cpp

main.o: main.cpp viewer.h \
		dynamicSystem.h \
		spring.h \
		particle.h \
		renderable.h \
		dragon.h \
		body.h \
		cylinder.h \
		conicalFrustrum.h \
		leg.h \
		tail.h \
		neck.h \
		head.h \
		ears.h \
		jaw.h \
		teeth.h \
		eyes.h \
		cube.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

neck.o: neck.cpp neck.h \
		renderable.h \
		head.h \
		ears.h \
		jaw.h \
		teeth.h \
		eyes.h \
		cylinder.h \
		cube.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o neck.o neck.cpp

particle.o: particle.cpp particle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o particle.o particle.cpp

spring.o: spring.cpp spring.h \
		particle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o spring.o spring.cpp

tail.o: tail.cpp tail.h \
		renderable.h \
		conicalFrustrum.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o tail.o tail.cpp

teeth.o: teeth.cpp teeth.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o teeth.o teeth.cpp

viewer.o: viewer.cpp viewer.h \
		renderable.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o viewer.o viewer.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

