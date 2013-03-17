// The fragment shader needs a main function, just as the 
// vertex shader does. But unlike a vertex shader, this is
// called for every pixel on the screen.

// All fragment shaders must end with the line
// gl_FragColor = vec4(*something*);
// because the fragment shader is setting the current color
// drawn on the screen.

// In the fragment shader, gl_FragColor will end up being
// the color that we want to display on the screen. In
// this case we are setting that to the color white, so every pixel
// belonging to our shape will be white.

// GLSL has a few different types, I recommend taking a look at the
// GLSL quick reference guide to get an idea of all of them.
// gl_FragColor takes the value of vec4() which is a 4 float
// vector. This can be written as vec4(red, green, blue, alpha)
// or you can even pass through other vec4's in the constructor,
// and even shorthand to vec4(1.0) to make all values 1.0. This will
// give us our white color.

// And that is all there is to shaders (for now).
// If you have followed through this far, well done. Give
// yourself a pat on the back :)

// turn all vertices a single color
/*void main() {
 // Set the output color of our current pixel
 //gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
 }*/


// do simple toon shading
/*varying float intensity;
 
 void main()
 {
 vec4 color;
 if (intensity > 0.95)
 
 color = vec4(1.0,0.5,0.5,1.0);
 else if (intensity > 0.5)
 color = vec4(0.6,0.3,0.3,1.0);
 else if (intensity > 0.25)
 color = vec4(0.4,0.2,0.2,1.0);
 else
 color = vec4(0.2,0.1,0.1,1.0);
 gl_FragColor = color;
 
 }*/

// better toon shading using normals
/*varying vec3 normal;
 
 void main()
 {
 float intensity;
 vec4 color;
 vec3 n = normalize(normal);
 intensity = dot(normalize(vec3(gl_LightSource[0].position)),n);
 
 if (intensity > 0.95)
 color = vec4(1.0,0.5,0.5,1.0);
 else if (intensity > 0.75)
 color = vec4(0.75,0.3,0.3,1.0);
 else if (intensity > 0.5)
 color = vec4(0.6,0.3,0.3,1.0);
 else if (intensity > 0.25)
 color = vec4(0.4,0.2,0.2,1.0);
 else
 color = vec4(0.2,0.1,0.1,1.0);
 
 gl_FragColor = color;
 
 }*/

// directional light
/*void main()
 {
 gl_FragColor = gl_Color;
 }*/

// Directional Light per pixel shading
/*varying vec4 diffuse,ambient;
 varying vec3 normal,lightDir,halfVector;
 
 void main()
 {
 vec3 n,halfV;
 float NdotL,NdotHV;
 // The ambient term will always be present 
 
 vec4 color = ambient;
 // a fragment shader can't write a varying variable, hence we need
 
 a new variable to store the normalized interpolated normal 
 n = normalize(normal);
 // compute the dot product between normal and ldir 
 
 NdotL = max(dot(n,lightDir),0.0);
 
 if (NdotL > 0.0) {
 color += diffuse * NdotL;
 halfV = normalize(halfVector);
 NdotHV = max(dot(n,halfV),0.0);
 color += gl_FrontMaterial.specular *
 gl_LightSource[0].specular *
 pow(NdotHV, gl_FrontMaterial.shininess);
 }
 
 gl_FragColor = color;
 
 }*/

// point Light Per Pixel Shading
varying vec4 diffuse,ambientGlobal, ambient;
varying vec3 normal,lightDir,halfVector;
varying float dist;

void main()
{
	vec3 n,halfV,viewV,ldir;
	float NdotL,NdotHV;
	vec4 color = ambientGlobal;
	float att;
	/* a fragment shader can't write a varying variable, hence we need
     
     a new variable to store the normalized interpolated normal */
	n = normalize(normal);
	/* compute the dot product between normal and normalized lightdir */
    
	NdotL = max(dot(n,normalize(lightDir)),0.0);
	
    // 3 lights
    for (int i=0; i<1; i++){
        
        if (NdotL > 0.0) {
            
            att = 1.0 / (gl_LightSource[i].constantAttenuation +
                         gl_LightSource[i].linearAttenuation * dist +
                         gl_LightSource[i].quadraticAttenuation * dist * dist);
            
            color += att * (diffuse * NdotL + ambient);
            halfV = normalize(halfVector);
            
            NdotHV = max(dot(n,halfV),0.0);
            
            color += att * gl_FrontMaterial.specular * gl_LightSource[i].specular *
            pow(NdotHV,gl_FrontMaterial.shininess);
        }
    }
	gl_FragColor = color;
}
