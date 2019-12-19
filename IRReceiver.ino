/*
 * Author: Áron Katona
 * Purpose: Receives IR codes.
 * Acknowledgements:  Ken Shirriff - IRRemote library
 */
#include <IRremote.h>

const int receiverPin = 11;

IRrecv irrecv(receiverPin);
decode_results results;

void IRReceiverSetup() 
{
   irrecv.enableIRIn();
}

int IRReceive()
{
  int res = 0;
  if (irrecv.decode(&results)) {
    res = results.value;    
    irrecv.resume();
  }
  return res;
}
