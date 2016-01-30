
#ifndef UTILS_H_
#define UTILS_H_

/**** interesting stuff ****/
#define M1(a)        (1 << (a))
#define M2( a, b  ) (M1(a) | M1(b))
#define M3( a, ...) (M1(a) | M2(__VA_ARGS__))
#define M4( a, ...) (M1(a) | M3(__VA_ARGS__))
#define M5( a, ...) (M1(a) | M4(__VA_ARGS__))
#define M6( a, ...) (M1(a) | M5(__VA_ARGS__))
#define M7( a, ...) (M1(a) | M6(__VA_ARGS__))
#define M8( a, ...) (M1(a) | M7(__VA_ARGS__))

#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,NAME,...) NAME
#define M(...) GET_MACRO(__VA_ARGS__, M7, M6, M5, M4, M3, M2, M1)(__VA_ARGS__)

#define AT(num, ...) (num & M(__VA_ARGS__))

#define SET_1(reg, ...) reg |= M(__VA_ARGS__)
#define SET_0(reg, ...) reg &= ~M(__VA_ARGS__)

//#define SET(num, at, val) {}
/**** interesting stuff finished ****/

#define uchar unsigned char

void strcpylen( char * to, char * from, uchar len );
void nops( int num );

float getKelvinFromCelsius (float celsius);
float getFahrenheitFromCelsius (float celsius);

int flRound(float flNum);

#endif /* UTILS_H_ */