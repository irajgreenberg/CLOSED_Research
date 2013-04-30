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
	${OBJECTDIR}/Protobyte/Spline3.o \
	${OBJECTDIR}/Protobyte/Tube.o \
	${OBJECTDIR}/Protobyte/Curve3.o \
	${OBJECTDIR}/Protobyte/Vector3.o \
	${OBJECTDIR}/Protobyte/Matrix3.o \
	${OBJECTDIR}/Protobyte/Texture2.o \
	${OBJECTDIR}/Protobyte/Lindenmayer.o \
	${OBJECTDIR}/Protobyte/Matrix4.o \
	${OBJECTDIR}/Protobyte/GeomBase.o \
	${OBJECTDIR}/Protobyte/GroundPlane.o \
	${OBJECTDIR}/Protobyte/Vertex.o \
	${OBJECTDIR}/Protobyte/Toroid.o \
	${OBJECTDIR}/Protobyte/Image.o \
	${OBJECTDIR}/Protobyte/FrenetFrame.o \
	${OBJECTDIR}/Protobyte/Tree.o \
	${OBJECTDIR}/Protobyte/BlockGrid.o \
	${OBJECTDIR}/Protobyte/ConvolveFilter.o \
	${OBJECTDIR}/Protobyte/Branch.o \
	${OBJECTDIR}/Protobyte/Sphere.o \
	${OBJECTDIR}/Protobyte/Block.o \
	${OBJECTDIR}/main_growthTendril_01.o \
	${OBJECTDIR}/Protobyte/FilterBase.o


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
LDLIBSOPTIONS=/System/Library/Frameworks/GLUT.framework/Versions/A/GLUT /System/Library/Frameworks/OpenGL.framework/OpenGL /Library/Frameworks/sfml-graphics.framework/sfml-graphics /Library/Frameworks/sfml-window.framework/sfml-window /Library/Frameworks/sfml-system.framework/sfml-system

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research: /System/Library/Frameworks/GLUT.framework/Versions/A/GLUT

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research: /System/Library/Frameworks/OpenGL.framework/OpenGL

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research: /Library/Frameworks/sfml-graphics.framework/sfml-graphics

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research: /Library/Frameworks/sfml-window.framework/sfml-window

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research: /Library/Frameworks/sfml-system.framework/sfml-system

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	g++ -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Protobyte/Tendril.o: Protobyte/Tendril.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Tendril.o Protobyte/Tendril.cpp

${OBJECTDIR}/Protobyte/Shader.o: Protobyte/Shader.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Shader.o Protobyte/Shader.cpp

${OBJECTDIR}/Protobyte/Face3.o: Protobyte/Face3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Face3.o Protobyte/Face3.cpp

${OBJECTDIR}/Protobyte/Spline3.o: Protobyte/Spline3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Spline3.o Protobyte/Spline3.cpp

${OBJECTDIR}/Protobyte/Tube.o: Protobyte/Tube.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Tube.o Protobyte/Tube.cpp

${OBJECTDIR}/Protobyte/Curve3.o: Protobyte/Curve3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Curve3.o Protobyte/Curve3.cpp

${OBJECTDIR}/Protobyte/Vector3.o: Protobyte/Vector3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Vector3.o Protobyte/Vector3.cpp

${OBJECTDIR}/Protobyte/Matrix3.o: Protobyte/Matrix3.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Matrix3.o Protobyte/Matrix3.cpp

${OBJECTDIR}/Protobyte/Texture2.o: Protobyte/Texture2.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Texture2.o Protobyte/Texture2.cpp

${OBJECTDIR}/Protobyte/Lindenmayer.o: Protobyte/Lindenmayer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Lindenmayer.o Protobyte/Lindenmayer.cpp

${OBJECTDIR}/Protobyte/Matrix4.o: Protobyte/Matrix4.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Matrix4.o Protobyte/Matrix4.cpp

${OBJECTDIR}/Protobyte/GeomBase.o: Protobyte/GeomBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/GeomBase.o Protobyte/GeomBase.cpp

${OBJECTDIR}/Protobyte/GroundPlane.o: Protobyte/GroundPlane.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/GroundPlane.o Protobyte/GroundPlane.cpp

${OBJECTDIR}/Protobyte/Vertex.o: Protobyte/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Vertex.o Protobyte/Vertex.cpp

${OBJECTDIR}/Protobyte/Toroid.o: Protobyte/Toroid.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Toroid.o Protobyte/Toroid.cpp

${OBJECTDIR}/Protobyte/Image.o: Protobyte/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Image.o Protobyte/Image.cpp

${OBJECTDIR}/Protobyte/FrenetFrame.o: Protobyte/FrenetFrame.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/FrenetFrame.o Protobyte/FrenetFrame.cpp

${OBJECTDIR}/Protobyte/Tree.o: Protobyte/Tree.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Tree.o Protobyte/Tree.cpp

${OBJECTDIR}/Protobyte/BlockGrid.o: Protobyte/BlockGrid.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/BlockGrid.o Protobyte/BlockGrid.cpp

${OBJECTDIR}/Protobyte/ConvolveFilter.o: Protobyte/ConvolveFilter.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/ConvolveFilter.o Protobyte/ConvolveFilter.cpp

${OBJECTDIR}/Protobyte/Branch.o: Protobyte/Branch.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Branch.o Protobyte/Branch.cpp

${OBJECTDIR}/Protobyte/Sphere.o: Protobyte/Sphere.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Sphere.o Protobyte/Sphere.cpp

${OBJECTDIR}/Protobyte/Block.o: Protobyte/Block.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/Block.o Protobyte/Block.cpp

${OBJECTDIR}/main_growthTendril_01.o: main_growthTendril_01.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_growthTendril_01.o main_growthTendril_01.cpp

${OBJECTDIR}/Protobyte/FilterBase.o: Protobyte/FilterBase.cpp 
	${MKDIR} -p ${OBJECTDIR}/Protobyte
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers -I/Library/Frameworks/SFML.framework/Headers -MMD -MP -MF $@.d -o ${OBJECTDIR}/Protobyte/FilterBase.o Protobyte/FilterBase.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/research

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
