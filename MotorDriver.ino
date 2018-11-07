/*
 * Author: Áron Katona
 * Purpose: Communicates with the motor driver. The code responsible for the movement of the robot. 
 */
 
enum MotorPins {MPEnableLeft = 2, MPForwardLeft, MPBackwardLeft, MPForwardRight, MPBackwardRight, MPEnableRight};

void motorSetup() {
  pinMode(MPEnableRight, OUTPUT);
  pinMode(MPEnableLeft, OUTPUT);
  analogWrite(MPEnableRight, 200);
  analogWrite(MPEnableLeft, 200);
}

void go(int m_direction) {
  switch (m_direction) {
    case FORWARD:
      digitalWrite(MPForwardRight, HIGH);
      digitalWrite(MPForwardLeft, HIGH);
      break;
    case BACKWARD:
      digitalWrite(MPBackwardRight, HIGH);
      digitalWrite(MPBackwardLeft, HIGH);
      break;
    case LEFT:
      digitalWrite(MPForwardRight, HIGH);
      digitalWrite(MPForwardLeft, LOW);
      break;
    case RIGHT:
      digitalWrite(MPForwardRight, LOW);
      digitalWrite(MPForwardLeft, HIGH);
      break;
    default:
      digitalWrite(MPBackwardRight, LOW);
      digitalWrite(MPForwardRight, LOW);
      digitalWrite(MPBackwardLeft, LOW);
      digitalWrite(MPForwardLeft, LOW);

  }
}
