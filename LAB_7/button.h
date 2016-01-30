
#ifndef BUTTON_H_
#define BUTTON_H_
// Input Port pin SWITCH_IP
#define PORT_SWITCH_IP  PORTB
#define DDR_SWITCH_IP   DDRB
#define PIN_SWITCH_IP   PINB
#define BIT_SWITCH_IP   5

void vButtonInit(void);
char xButtonGetStatus(void);

#endif /* BUTTON_H_ */