#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Protobyte/Tendril.o \
	${OBJECTDIR}/Protobyte/Shader.o \
	${OBJECTDIR}/Protobyte/Face3.o \
	${OBJECTDIR}/Protobyte/Curve3.o \
	${OBJECTDIR}/Protobyte/Vector3.o \
	${OBJECTDIR}/Protobyte/Spline3.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/Protobyte/Tube.o \
	${OBJECTDIR}/Protobyte/Matrix3.o \
	${OBJECTDIR}/Protobyte/GeomBase.o \
	${OBJECTDIR}/Protobyte/Matrix4.o \
	${OBJECTDIR}/Protobyte/Vertex.o \
	${OBJECTDIR}/Protobyte/Toroid.o \
	${OBJECTDIR}/Protobyte/FrenetFrame.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-network.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-system.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-window.dylib /System/Library/Frameworks/GLUT.framework/GLUT /System/Library/Frameworks/OpenGL.framework/Versions/A/OpenGL

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-network.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-system.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ../libSFML/dylibs/root/usr/local/lib/libsfml-window.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: /System/Library/Frameworks/GLUT.framework/GLUT

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: /System/Library/Frameworks/OpenGL.framework/Versions/A/OpenGL

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Protobyte/Tendril.o: Protobyte/Tendril.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Tendril.o Protobyte/Tendril.cpp

${OBJECTDIR}/Protobyte/Shader.o: Protobyte/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Shader.o Protobyte/Shader.cpp

${OBJECTDIR}/Protobyte/Face3.o: Protobyte/Face3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Face3.o Protobyte/Face3.cpp

${OBJECTDIR}/Protobyte/Curve3.o: Protobyte/Curve3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Curve3.o Protobyte/Curve3.cpp

${OBJECTDIR}/Protobyte/Vector3.o: Protobyte/Vector3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Vector3.o Protobyte/Vector3.cpp

${OBJECTDIR}/Protobyte/Spline3.o: Protobyte/Spline3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Spline3.o Protobyte/Spline3.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/Protobyte/Tube.o: Protobyte/Tube.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Tube.o Protobyte/Tube.cpp

${OBJECTDIR}/Protobyte/Matrix3.o: Protobyte/Matrix3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Matrix3.o Protobyte/Matrix3.cpp

${OBJECTDIR}/Protobyte/GeomBase.o: Protobyte/GeomBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/GeomBase.o Protobyte/GeomBase.cpp

${OBJECTDIR}/Protobyte/Matrix4.o: Protobyte/Matrix4.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Matrix4.o Protobyte/Matrix4.cpp

${OBJECTDIR}/Protobyte/Vertex.o: Protobyte/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Vertex.o Protobyte/Vertex.cpp

${OBJECTDIR}/Protobyte/Toroid.o: Protobyte/Toroid.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Toroid.o Protobyte/Toroid.cpp

${OBJECTDIR}/Protobyte/FrenetFrame.o: Protobyte/FrenetFrame.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I../libSFML/dylibs/root/usr/local/include -I/System/Library/Frameworks/OpenGL.framework -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/FrenetFrame.o Protobyte/FrenetFrame.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/protobyte_research

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
