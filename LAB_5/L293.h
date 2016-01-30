
#ifndef L293_H_
#define L293_H_


void L293_init();
void L293_setPow(unsigned int power);
void L293_antiClockwise();
void L293_clockwise();
void L293_stop();
void L293_free();


#endif /* L293_H_ */