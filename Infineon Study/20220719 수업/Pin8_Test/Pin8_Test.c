#include "IfxPort.h"
#include "Bsp.h"

/*********************************************************************************************************************/
/*------------------------------------------------------Macros-------------------------------------------------------*/
/*********************************************************************************************************************/
#define PIN8         &MODULE_P00,8                                           /* LED: Port, Pin definition            */
#define WAIT_TIME   200                                                     /* Wait time constant in milliseconds   */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* This function initializes the port pin which drives the LED */
void initPin(void)
{
    /* Initialization of the LED used in this example */
    IfxPort_setPinModeOutput(PIN8, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);

    /* Switch OFF the LED (low-level active) */
    IfxPort_setPinHigh(PIN8);
}

/* This function toggles the port pin and wait 500 milliseconds */
void sigHigh(void)
{
    IfxPort_togglePin(PIN8);                                                     /* Toggle the state of the LED      */
    waitTime(IfxStm_getTicksFromMilliseconds(BSP_DEFAULT_TIMER, WAIT_TIME));    /* Wait 500 milliseconds            */
}


