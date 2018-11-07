enum IRSensorPins {IRRight = A5, IRCenter = A6, IRLeft = A7};

int SensorData[3];
const int minHigh = 500;

void getSensorData() {
  SensorData[LEFT] = analogRead(IRLeft);
  SensorData[CENTER] = analogRead(IRCenter);
  SensorData[RIGHT] = analogRead(IRRight);
}

bool isBlack(int sensor) {
  switch (sensor) {
    case LEFT:
    case CENTER:
    case RIGHT:
      return SensorData[sensor] < minHigh;
      break;
    default:
      return false;
  }
}

bool isWhite(int sensor) {
  return !isBlack(sensor);
}
