/*
 Particle Wave
 Ira Greenberg, December 5, 2005
 Revised January 26, 2007
 Updated January 7, 2014
 */

void setup(){
  size(800, 400);
  background(0);

  /*lots of stuff to manipulate. I packed
   the arguments into arrays just to make the
   setParticles function argument/parameter
   lists less unwieldy*/
  //particle style
  /* increase strokeWt if
  you don't see any output*/
  float strokeWt = 1.5; 
  float strokeCol= 255;
  float[]strokeStyle = { 
    strokeWt, strokeCol   };

  //particle limits
  int timeLimit = 1000;
  int particleCount = 100;
  int[]particleLimits = { 
    timeLimit, particleCount   };

  //particle dynamics
  float amplitudeMin = .5;
  float amplitudeMax = 4.0;
  float frequencyMin = 4.0;
  float frequencyMax = 40.0;
  float materialMin = .25; // lead
  float materialMax = .99; // rubber
  float[]particleDynamics = { 
    amplitudeMin, amplitudeMax, frequencyMin,
    frequencyMax, materialMin, materialMax   };

  // speed limits
  float accelMin = .005;
  float accelMax = .2;
  float xSpeedMin = -2.0;
  float xSpeedMax = 2.0;
  float[]speedLimits = { 
    xSpeedMin, xSpeedMax, accelMin, accelMax   };

  float gravity = .85;
  //postion of particle emitter
  float emitterX = width/2;
  float emitterY = 0;
  float[]world = { 
    gravity, emitterX, emitterY   };

  //start particle engine
  setParticles(strokeStyle, particleLimits, 
    particleDynamics, speedLimits, world);
}

// main particle engine-fully parameterized
void setParticles(float[]strokeStyle, int[]particleLimits, 
  float[]particleDynamics, float[]speedLimits,  float[]world){
  //create arrays
  float[]xSpeed = new float[particleLimits[1]];
  float[]ySpeed = new float[particleLimits[1]];
  float[]accel = new float[particleLimits[1]];
  float[]x = new float[particleLimits[1]];
  float[]y = new float[particleLimits[1]];
  float[]amplitude = new float[particleLimits[1]];
  float[]frequency = new float[particleLimits[1]];
  float[]material = new float[particleLimits[1]];

  // particle style
  strokeWeight(strokeStyle[0]);
  stroke(strokeStyle[1]);

  //angle used as argument for makeWaves function call
  float angle = 0;

  //fill arrays
  for (int i = 0; i< particleLimits[1]; i++){
    xSpeed[i] = random(speedLimits[0], speedLimits[1]);
    accel[i] = random(speedLimits[2], speedLimits[3]);
    amplitude[i] = random(particleDynamics[0], particleDynamics[1]);
    frequency[i] = random(particleDynamics[2], particleDynamics[3]);
    material[i] = random(particleDynamics[4], particleDynamics[5]);
    //emitter initial position
    x[i] = world[1];
    y[i] = world[2];
  }

  // dynamics engine
  for (int i =0; i< particleLimits[1]; i++){
    for (int j = 0; j< particleLimits[0]; j++){
      x[i]+=xSpeed[i];
      // add waviness to call to makeWaves function
      x[i]=makeWaves(x[i], angle+=frequency[i], amplitude[i]);
      ySpeed[i]+=accel[i];
      y[i]+=ySpeed[i];
      // plot function just calls point() method
      plot(new float[]{ 
        x[i], y[i]       }
      );

      //ground detection
      if (y[i]>=height){
        ySpeed[i]*=-1*material[i];
        ySpeed[i]*=world[0];
        y[i] = height;
      }
      //wall detection
      if (x[i]>=width || x[i]<=0){
        xSpeed[i] *=-1;
      }
    }
  }
}

//generate wave
float makeWaves(float x, float angle, float amplitude){
  x+=sin(radians(angle))*amplitude;
  return x;
}

// draw points
void plot(float[]pt){
  point(pt[0], pt[1]);
}


