#include <Non_blocking_timer.h>

timerStruct LedToggleTimer = {0};

void setup() 
{
  Serial.begin(9600);
  Serial.println("setup...in");
  pinMode(LED_BUILTIN, OUTPUT);  //initialize digital pin LED_BUILTIN as an output.
  startTimer(&LedToggleTimer,5000,REPEAT_NONSTOP);
  Serial.println("setup...exit");
}

void loop() 
{
  if(isTimerComplete(&LedToggleTimer))
  {
    if(digitalRead(LED_BUILTIN))
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
    else
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
  }
}
