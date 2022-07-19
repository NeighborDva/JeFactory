
/*********************************************************************************************************************/
/*-----------------------------------------------------Includes------------------------------------------------------*/
/*********************************************************************************************************************/
#include "IfxPort.h"

/*********************************************************************************************************************/
/*-----------------------------------------------------Macros--------------------------------------------------------*/
/*********************************************************************************************************************/
#define LED1     &MODULE_P00,5   /* Port pin for the LED     */
#define LED2     &MODULE_P00,6   /* Port pin for the LED     */
#define PIN  &MODULE_P02,7   /* Port pin for the button  */

/*********************************************************************************************************************/
/*---------------------------------------------Function Implementations----------------------------------------------*/
/*********************************************************************************************************************/
/* Function to configure the port pins for the push button and the LED */
void init_GPIOs(void)
{

    //출력
    IfxPort_setPinMode(LED1, IfxPort_Mode_outputPushPullGeneral);
    IfxPort_setPinMode(LED2, IfxPort_Mode_outputPushPullGeneral);

    //입력
    IfxPort_setPinMode(PIN, IfxPort_Mode_inputPullUp);


}

void control_LED(void)
{
    if(IfxPort_getPinState(PIN) == 0)
    {
               IfxPort_setPinState(LED1, IfxPort_State_low);
               IfxPort_setPinState(LED2, IfxPort_State_high);
    }
    else
    {
               IfxPort_setPinState(LED2, IfxPort_State_low);
               IfxPort_setPinState(LED1, IfxPort_State_high);
    }
}

