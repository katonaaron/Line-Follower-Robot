/*
 * Author: Áron Katona
 * Purpose: A robot which follows a black line on a white surface.
 */
 
enum Directions {LEFT, CENTER, RIGHT, FORWARD, BACKWARD, STOP};
enum IRCommands {IR_START = 0x2C, IR_STOP = 0x30};

bool wasBlack = false;
bool isStarted = false;

void setup() {
  motorSetup();
  IRReceiverSetup();
}

void loop() {
  switch(IRReceive())
  {
    case IR_START:
      isStarted = true;
      break;
    case IR_STOP:
      isStarted = false;
      break;
    default:
      break;
  }
  
  if(!isStarted)
  {
    go(STOP);
    return;
  }
     
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
