#!/bin/bash
lin_cmd="-o protobyteApp main.cpp Protobyte/Vector3.cpp Protobyte/Face3.cpp Protobyte/Matrix3.cpp Protobyte/FrenetFrame.cpp Protobyte/Vertex.cpp Protobyte/GeomBase.cpp Protobyte/Texture2.cpp Protobyte/Toroid.cpp Protobyte/Tube.cpp Protobyte/Curve3.cpp Protobyte/Shader.cpp Protobyte/Spline3.cpp -lGLEW -lGL -lglut -lGLU"
app_cmd="-o protobyteApp main.cpp Protobyte/Vector3.cpp Protobyte/Face3.cpp Protobyte/Matrix3.cpp Protobyte/FrenetFrame.cpp Protobyte/Vertex.cpp Protobyte/GeomBase.cpp Protobyte/Texture2.cpp Protobyte/Toroid.cpp Protobyte/Tube.cpp Protobyte/Curve3.cpp Protobyte/Shader.cpp Protobyte/Spline3.cpp -framework GLUT -framework OpenGL"

OS=$(uname -s)

case $( uname -s ) in
Linux) g++ $lin_cmd;;
*)     g++ $app_cmd;;
esac
        

echo "********* Compilation Successful *********"
./protobyteApp
