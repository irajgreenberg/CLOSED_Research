varying vec3 N;
varying vec3 v;    
void main (void)  
{  
   vec3 L = normalize(gl_LightSource[0].position.xyz - v);   
   vec3 E = normalize(-v); // we are in Eye Coordinates, so EyePos is (0,0,0)  
   vec3 R = normalize(-reflect(L,N));  
 
   //calculate Ambient Term:  
   vec4 Iamb = gl_FrontLightProduct[0].ambient;    

   //calculate Diffuse Term: 
  //gl_FrontMaterial.emission * gl_LightModel.ambient
   vec4 Idiff = gl_FrontLightProduct[0].diffuse * max(dot(N,L), 0.0);
   //vec4 Idiff = gl_Color * max(dot(N,L), 0.0);
   Idiff = clamp(Idiff, 0.0, 1.0);     
   
   // calculate Specular Term:
   vec4 Ispec = gl_FrontLightProduct[0].specular
                * pow(max(dot(R,E),0.0), gl_FrontMaterial.shininess);
   Ispec = clamp(Ispec, 0.0, 1.0); 
   // write Total Color:  
   //gl_FragColor = gl_FrontMaterial.emission + gl_FrontMaterial.ambient * gl_LightModel.ambient + Iamb + Idiff + Ispec;
   //gl_FragColor = gl_FrontLightModelProduct.sceneColor + Iamb + Idiff + Ispec;  
    gl_FragColor = gl_FrontMaterial.emission + gl_Color * gl_LightModel.ambient + Iamb + Idiff + Ispec;   
} 