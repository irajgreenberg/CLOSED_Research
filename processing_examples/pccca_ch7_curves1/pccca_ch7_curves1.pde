/*
 Curves I
 Ira Greenberg, December 4, 2005
 updated, January 7, 2014
 */
int steps = 300;
float[]x = new float[steps];
float[]y = new float[steps];
float[]xSpeed = new float[steps];
float[]ySpeed = new float[steps];

void setup(){
  size(400, 400);
  background(255);
  float margin = height*.1;
  strokeWeight(1.5);
  for ( int i=0; i<steps; i++){
    x[i] = 0;
    y[i] = random(margin);
    xSpeed[i] = random(.75, 1.2);
    ySpeed[i] = random(1.0075, 1.04);
  }

  for ( int i=0; i<steps; i++){
    while(y[i]<height){
      point(x[i], y[i]);
      x[i]+=xSpeed[i];
      y[i]*=ySpeed[i];
    }
  }
}


