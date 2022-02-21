/*
 * Non_blocking_timer.h
 *
 * Created on: Nov 9, 2020
 * Author: Lynkit-Vinas
 */
#ifndef Non_blocking_timer_h
#define Non_blocking_timer_h

#include <inttypes.h>
#include "Arduino.h"

// #define FREQUENCY       16000000                //this is the frequency in which the system will run

// #define SET_PERIOD_MS(x)   (unsigned int)((x)/((1.0/FREQUENCY)*1000.00))       //x is the time in milliseconds
// #define SET_PERIOD_uS(x)   (unsigned int)((x)/((1.0/FREQUENCY)*1000000.00))       //x is the time in milliseconds

#define RUNNING             1
#define EXPIRED             0
#define REPEAT_ONCE         1  
#define REPEAT_NONSTOP      0
/*******************************************************************/

/*Timer related sturctures*/
typedef struct tStructure
{
    bool state;                   //running status
    uint32_t targetTime;          //timer time in ms
    uint8_t reloadCnt;            //to restart timer or not
    uint32_t period;              //intrervaal
}timerStruct;

/*******************************************************************/

/*Function Prototypes*/
bool startTimer(timerStruct *tID, uint32_t PeriodInMilliSeconds, uint8_t ReloadCount);
bool isTimerComplete(timerStruct *tID);
bool isTimerStarted(timerStruct *tID);
//void delayMicroSec(int us);
bool stopTimer(timerStruct *tID);
bool updateTimerRepeatCount(timerStruct *tID, uint8_t newReloadCount);
bool updateTimer(timerStruct *tID, uint32_t newPeriod);

/*******************************************************************/

#endif
