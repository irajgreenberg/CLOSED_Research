#!/bin/bash
lin_cmd="-Wall -v -o protobyteApp main.cpp Protobyte/Vector3.cpp Protobyte/Face3.cpp Protobyte/Block.cpp Protobyte/Matrix3.cpp Protobyte/FilterBase.cpp Protobyte/ConvolveFilter.cpp Protobyte/FrenetFrame.cpp Protobyte/Vertex.cpp Protobyte/GeomBase.cpp Protobyte/Branch.cpp Protobyte/Texture2.cpp Protobyte/Toroid.cpp Protobyte/Tube.cpp Protobyte/Curve3.cpp Protobyte/GroundPlane.cpp Protobyte/Shader.cpp Protobyte/Spline3.cpp -lGLEW -lGL -lglut -lGLU"
app_cmd="-Wall -v -o protobyteApp main.cpp Protobyte/Vector3.cpp Protobyte/Face3.cpp Protobyte/Block.cpp Protobyte/Matrix3.cpp Protobyte/FilterBase.cpp Protobyte/ConvolveFilter.cpp Protobyte/FrenetFrame.cpp Protobyte/Vertex.cpp Protobyte/GeomBase.cpp Protobyte/Branch.cpp Protobyte/Texture2.cpp Protobyte/Toroid.cpp Protobyte/Tube.cpp Protobyte/Curve3.cpp Protobyte/GroundPlane.cpp Protobyte/Shader.cpp Protobyte/Spline3.cpp -framework GLUT -framework OpenGL"

OS=$(uname -s)

case $( uname -s ) in
Darwin) g++ $app_cmd;;
*)     g++ $lin_cmd;;
esac
        

echo "********* Compilation Successful *********"
./protobyteApp
