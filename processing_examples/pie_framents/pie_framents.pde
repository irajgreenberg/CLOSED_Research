/*
 Pie Fragments
 Ira Greenberg, December, 2005
 Updated, January 7, 2014
 */
size(400, 400);
background(255);
noStroke();
float radius = 10;
for (int i=0; i<=width; i+=radius/2){
  for (int j=0; j<=height; j+=radius/2){
    float size = (random(radius*2));
    fill(255);
    arc(random(i), random(j), size, size, random(PI*2), random(PI*2));
    fill(0);
    arc(random(i), random(j), size, size, random(PI*2), random(PI*2));
  }
}


