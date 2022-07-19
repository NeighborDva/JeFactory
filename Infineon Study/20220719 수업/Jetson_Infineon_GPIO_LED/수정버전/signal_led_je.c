#include "Jeston_nano_GPIO.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define LED_GPIO_DIR "/sys/class/gpio"



FILE *je_led_gpio;
//char buff[256];
int je_LED_GPIO_Pin=0;


void sig_Handler(int sig);
void init(void);








int main(void) {
	
	int value;
	 
	printf("[MANDO_SW 1기 제현승  Infineon LED testing...]\n");
	printf("LED Pin:");
	scanf("%d",&je_LED_GPIO_Pin);
	
	
	gpio_export(je_LED_GPIO_Pin);
	/*
	snprintf(buff,sizeof(buff),"%s/export",LED_GPIO_DIR);
	je_led_gpio = fopen(buff,"w");	
	fprintf(je_led_gpio,"%d\n",je_LED_GPIO_Pin);
	fclose(je_led_gpio);
	*/
	
	gpio_set_dir(je_LED_GPIO_Pin,1);
	/*
	snprintf(buff,sizeof(buff),"%s/gpio%d/direction",LED_GPIO_DIR,je_LED_GPIO_Pin);
	je_led_gpio = fopen(buff,"w");
	fprintf(je_led_gpio,"out\n");
	fclose(je_led_gpio);
	*/
	
	/*
	snprintf(buff,sizeof(buff),"%s/gpio%d/value",LED_GPIO_DIR,je_LED_GPIO_Pin);
	je_led_gpio = fopen(buff,"w");
	setvbuf(je_led_gpio,NULL,_IONBF,0);
	*/
	signal(SIGINT, sig_Handler);
	
	
	//pinMode(je_LED_GPIO_Pin, OUTPUT); 젯슨에서는 않됨
	
	//LED동작
	 value = 0;
while(1){
  printf("value: %d\n",value);
  gpio_set_value(je_LED_GPIO_Pin, !value);
  //fprintf(je_led_gpio,"%d\n",!value);
  sleep(1);
  value = !value;
 }

return 0;

}

void sig_Handler(int sig)
{
		printf("\n\nEnding...\n\n");
		init();
		exit(0);
}

void init(void){
	 gpio_set_value(je_LED_GPIO_Pin, !0);

	gpio_unexport(je_LED_GPIO_Pin);
	/*
	snprintf(buff,sizeof(buff),"%s/unexport",LED_GPIO_DIR);
	je_led_gpio = fopen(buff,"w");
	fprintf(je_led_gpio,"%d\n",je_LED_GPIO_Pin);
	fclose(je_led_gpio);
	*/
	
	
}

