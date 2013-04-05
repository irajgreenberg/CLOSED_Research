/* !!GLSL */

varying vec4 eposition;
varying vec3 normal;
varying vec3 diffuseColor;
varying vec3 specularColor;
varying vec3 emissiveColor;
varying vec3 ambientColor;
varying float shininess;

void main()
  {
  // Position in clip space
  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

  // Position in eye space
    eposition = gl_ModelViewMatrix * gl_Vertex;

  // Normal in eye space
    normal = mat3(gl_ModelViewMatrix) * gl_Normal;

  // Retrieves diffuse, specular emissive, and ambient color from the OpenGL state.
    diffuseColor = vec3(gl_FrontMaterial.diffuse);
    specularColor = vec3(gl_FrontMaterial.specular);
    emissiveColor = vec3(gl_FrontMaterial.emission);
    ambientColor = vec3(gl_FrontMaterial.ambient);
    shininess = gl_FrontMaterial.shininess;
  }

