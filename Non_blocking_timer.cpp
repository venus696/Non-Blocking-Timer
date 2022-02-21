/*
 * Non_blocking_timer.cpp
 *
 * Created on: Nov 9, 2020
 * Author: Lynkit-Vinas
 */


#include "Non_blocking_timer.h"


bool startTimer(timerStruct *tID, uint32_t PeriodInMilliSeconds, uint8_t ReloadCount)
{
	if(tID->state != RUNNING)
	{
		tID->state = RUNNING;
		tID->targetTime = millis() + PeriodInMilliSeconds;
	    tID->reloadCnt = ReloadCount;
		tID->period = PeriodInMilliSeconds;
		return true;
	}
	return false;
}


bool stopTimer(timerStruct *tID)
{
   if(tID->state == RUNNING)
   {
	    tID->state = EXPIRED;
		return true;
   }
   return false;
}


bool updateTimer(timerStruct *tID, uint32_t newPeriod)
{
   if(tID->state == RUNNING)
   {
	    tID->targetTime = millis() + newPeriod;
		tID->period = newPeriod;
		return true;
   }
   return false; 
}


bool updateTimerRepeatCount(timerStruct *tID, uint8_t newReloadCount)
{
   if(tID->state == RUNNING)
   {
	    tID->reloadCnt = newReloadCount;
		return true;
   }
   return false; 
}


bool isTimerComplete(timerStruct *tID)
{
  // Only if we're running
  if (tID->state == RUNNING)
  {
    /*If we have passed the target time...*/
    if (millis() >= tID->targetTime)
    {
      /* Calculate repeat. If repeatCnt = REPEAT_NONSTOP, then we repeat forever until stopped. Otherwise, when we've hit the last repeat (1),then we stop.*/
      if (tID->reloadCnt != REPEAT_ONCE)
      {
        if (tID->reloadCnt > 0)
        {
          tID->reloadCnt--;
        }
        /* Set the new target (based on our last target time for accuracy)*/
		//Serial.println("time complete...");
        tID->targetTime += tID->period;
      }
      else
      {
        tID->state = EXPIRED;
      }
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}



bool isTimerStarted(timerStruct *tID)
{
    if(tID->state == RUNNING)
    {
        return true;
    }
    else
        return false;
}


// void delayMicroSec(int us)
// {
    // int i = SET_PERIOD_uS(us);
    // for(; i>0;i--);
// }