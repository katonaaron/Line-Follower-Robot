/*
 * Author: Áron Katona
 * Purpose: A robot which follows a black line on a white surface.
 */
 
enum Directions {LEFT, CENTER, RIGHT, FORWARD, BACKWARD, STOP};

bool wasBlack = false;

void setup() {
  motorSetup();
}

void loop() {
  // put your main code here, to run repeatedly:
  getSensorData();
  go(STOP);
  
  

  if (isWhite(LEFT) && isBlack(CENTER) && isWhite(RIGHT)) {
    go(FORWARD);
    wasBlack = true;
  }
  if (isBlack(LEFT)) {
    go(LEFT);
    wasBlack = true;
    while (isBlack(LEFT)) {
      getSensorData();
    }
  }
  if (isBlack(RIGHT)) {
    go(RIGHT);
    wasBlack = true;
    while (isBlack(RIGHT)) {
      getSensorData();
    }
  }
  if (isWhite(LEFT) && isWhite(CENTER) && isWhite(RIGHT)) {
    if (!wasBlack) {
      go(FORWARD);
    } else {
      go(BACKWARD);
    }
  }
}
