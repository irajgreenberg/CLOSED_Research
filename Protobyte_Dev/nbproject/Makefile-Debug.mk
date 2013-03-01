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
	${OBJECTDIR}/_ext/1345892673/Face3.o \
	${OBJECTDIR}/_ext/1345892673/Toroid.o \
	${OBJECTDIR}/_ext/1345892673/GeomObj.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/_ext/1345892673/Vertex.o \
	${OBJECTDIR}/_ext/1345892673/Vector3.o \
	${OBJECTDIR}/_ext/1345892673/Matrix4.o


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
LDLIBSOPTIONS=/System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreFSCache.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreVMClient.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreVMClient.mono.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCVMSPluginSupport.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGFXShared.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLImage.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLProgrammability.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLU.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLVMPlugin.dylib /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libLLVMContainer.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-network.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-system.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.0.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.dylib ../libSFML/dylibs/root/usr/local/lib/libsfml-window.dylib

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreFSCache.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreVMClient.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCoreVMClient.mono.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libCVMSPluginSupport.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGFXShared.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGL.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLImage.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLProgrammability.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLU.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libGLVMPlugin.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/libLLVMContainer.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-audio.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-graphics.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-network.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-network.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-system.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-system.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.0.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-window.2.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ../libSFML/dylibs/root/usr/local/lib/libsfml-window.dylib

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/_ext/1345892673/Face3.o: ../Protobyte/Face3.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345892673
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -I/System/Library/Frameworks/OpenGL.framework/Headers -I../libSFML/dylibs/root/usr/local/include -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345892673/Face3.o ../Protobyte/Face3.cpp

${OBJECTDIR}/_ext/1345892673/Toroid.o: ../Protobyte/Toroid.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345892673
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -I/System/Library/Frameworks/OpenGL.framework/Headers -I../libSFML/dylibs/root/usr/local/include -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345892673/Toroid.o ../Protobyte/Toroid.cpp

${OBJECTDIR}/_ext/1345892673/GeomObj.o: ../Protobyte/GeomObj.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345892673
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -I/System/Library/Frameworks/OpenGL.framework/Headers -I../libSFML/dylibs/root/usr/local/include -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345892673/GeomObj.o ../Protobyte/GeomObj.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -I/System/Library/Frameworks/OpenGL.framework/Headers -I../libSFML/dylibs/root/usr/local/include -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/_ext/1345892673/Vertex.o: ../Protobyte/Vertex.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345892673
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -I/System/Library/Frameworks/OpenGL.framework/Headers -I../libSFML/dylibs/root/usr/local/include -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345892673/Vertex.o ../Protobyte/Vertex.cpp

${OBJECTDIR}/_ext/1345892673/Vector3.o: ../Protobyte/Vector3.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345892673
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -I/System/Library/Frameworks/OpenGL.framework/Headers -I../libSFML/dylibs/root/usr/local/include -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345892673/Vector3.o ../Protobyte/Vector3.cpp

${OBJECTDIR}/_ext/1345892673/Matrix4.o: ../Protobyte/Matrix4.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1345892673
	${RM} $@.d
	$(COMPILE.cc) -g -I/System/Library/Frameworks/GLUT.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Versions/A/Headers -I/System/Library/Frameworks/OpenGL.framework/Headers -I../libSFML/dylibs/root/usr/local/include -I.. -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1345892673/Matrix4.o ../Protobyte/Matrix4.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/opengl02

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
