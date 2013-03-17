// This is pretty much the most basic of vertex shaders. Vertex shaders
// allow for us to manipulate the vertices of an object. The major 
// advantage of this would be if you were moving vertices or a mass
// group of vertices, in a particular way. For example, water could
// be created with a plane tesselated enough, and the vertex shader
// would be faster at computing the positions of the vertices than 
// if you were doing it in immediate mode.

// Anyway, this shader, just like all other GLSL shaders, has a main
// function, it is possible to have other functions inside a shader,
// but OpenGL will look for the main function and call it.

// Inside our main function, I am setting the position of the vertices
// to exactly where they would be if I hadn't used this shader. We are
// multiplying the projection matrix, by the current vertex to place
// the vertex where it should belong.

// The variable gl_Position, is used to set the position of the current
// vertex. Another method of setting the vertex to where it should be
// without shaders, to set gl_Position to ftransform; ftransform is a
// GLSL variable that does the exact same as 
// glModelViewProjectionMatrix * glVertex;

// I don't use ftransform() personally, and I believe it is even deprecated
// when using geometry shaders. (Just don't quote me on that)

// So all this shader will do is place the vertices we are drawing to where
// they should have been in the first place. 

// *Note* All vertex shaders are called for every vertex individually.

// Every vertex shader, needs to have the line
// gl_Position = *something*;
// because the point of the vertex shader is to set the positions of
// the vertices.

// nothing happens
/*void main() {			
 // Set the position of the current vertex 
 gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
 }*/


// simple toon shading
/*varying float intensity;
 
 void main()
 {
 vec3 lightDir = normalize(vec3(gl_LightSource[0].position));
 intensity = dot(lightDir,gl_Normal);
 
 gl_Position = ftransform();
 }*/

// better toon shading
/*varying vec3 normal;
 
 void main()
 {
 normal = gl_NormalMatrix * gl_Normal;
 gl_Position = ftransform();
 
 }*/

// directional light
/*void main() {
 
 vec3 normal, lightDir;
 vec4 diffuse;
 float NdotL;
 // first transform the normal into eye space and normalize the result
 
 normal = normalize(gl_NormalMatrix * gl_Normal);
 //now normalize the light's direction. Note that according to the
 
 //OpenGL specification, the light is stored in eye space. Also since
 //we're talking about a directional light, the position field is actually
 //direction 
 lightDir = normalize(vec3(gl_LightSource[0].position));
 //compute the cos of the angle between the normal and lights direction.
 
 //The light is directional so the direction is constant for every vertex.
 //Since these two are normalized the cosine is the dot product. We also
 //need to clamp the result to the [0,1] range. 
 NdotL = max(dot(normal, lightDir), 0.0);
 // Compute the diffuse term 
 
 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
 gl_FrontColor =  NdotL * diffuse;
 
 gl_Position = ftransform();
 }*/

// all lights per vertex - what I had prior to shaders using fixed pipeline 
/*void main()
 {
 vec3 normal, lightDir;
 vec4 diffuse, ambient, globalAmbient;
 float NdotL;
 
 normal = normalize(gl_NormalMatrix * gl_Normal);
 lightDir = normalize(vec3(gl_LightSource[0].position));
 NdotL = max(dot(normal, lightDir), 0.0);
 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
 // Compute the ambient and globalAmbient terms 
 
 ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
 globalAmbient = gl_LightModel.ambient * gl_FrontMaterial.ambient;
 gl_FrontColor =  NdotL * diffuse + globalAmbient + ambient;
 
 if (NdotL > 0.0) {
 
 // normalize the half-vector, and then compute the
 // cosine (dot product) with the normal
 NdotHV = max(dot(normal, gl_LightSource[0].halfVector.xyz),0.0);
 specular = gl_FrontMaterial.specular * gl_LightSource[0].specular *
 pow(NdotHV,gl_FrontMaterial.shininess);
 }
 
 gl_Position = ftransform();
 }*/

// Directional Light per pixel shading

/*varying vec4 diffuse,ambient;
 varying vec3 normal,lightDir,halfVector;
 
 void main()
 {
 // first transform the normal into eye space and
 // normalize the result 
 normal = normalize(gl_NormalMatrix * gl_Normal);
 // now normalize the light's direction. Note that
 
 // according to the OpenGL specification, the light
 // is stored in eye space. Also since we're talking about
 // a directional light, the position field is actually direction 
 lightDir = normalize(vec3(gl_LightSource[0].position));
 // Normalize the halfVector to pass it to the fragment shader 
 
 halfVector = normalize(gl_LightSource[0].halfVector.xyz);
 // Compute the diffuse, ambient and globalAmbient terms 
 
 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
 ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
 ambient += gl_LightModel.ambient * gl_FrontMaterial.ambient;
 gl_Position = ftransform();
 
 }*/

//Point Light per Pixel shading
varying vec4 diffuse,ambientGlobal,ambient;
varying vec3 normal,lightDir,halfVector;
varying float dist;

void main() {
	vec4 ecPos;
	vec3 aux;
	normal = normalize(gl_NormalMatrix * gl_Normal);
    
    /* these are the new lines of code to compute the light's direction */
    ecPos = gl_ModelViewMatrix * gl_Vertex;
    aux = vec3(gl_LightSource[0].position-ecPos);
    lightDir = normalize(aux);
    dist = length(aux);
    halfVector = normalize(gl_LightSource[0].halfVector.xyz);
    
    /* Compute the diffuse, ambient and globalAmbient terms */
    diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse;
    /* The ambient terms have been separated since one of them */
    
    /* suffers attenuation */
    ambient = gl_FrontMaterial.ambient * gl_LightSource[0].ambient;
    
    ambientGlobal = gl_LightModel.ambient * gl_FrontMaterial.ambient;
    gl_Position = ftransform();
}


