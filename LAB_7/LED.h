#ifndef LED_H_
#define LED_H_
// Output Port pin LED_O
#define PORT_LED_O      PORTB
#define DDR_LED_O       DDRB
#define BIT_LED_O       6
void vLEDInit(void);
void vLEDToggle(void);

void vLEDInit1(void);
void vLEDToggle1(void);


#endif /* LED_H_ */