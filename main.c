// #include <stdio.h>
// #include <C:\avr\avr\include\util\delay.h>
// #include <C:\avr\avr\include\avr\io.h> 

#include <util/delay.h>
#include <avr/io.h>

#define BIT_SET(a,b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL << (b)))

#define R_LED_PORT PORTB
#define R_LED_BIT 1         // Pin 9 = PB1  00000001
#define Y_LED_PORT PORTB
#define Y_LED_BIT 0         // Pin 8 = PB0  00000000
#define G_LED_PORT PORTD
#define G_LED_BIT 7         // Pin 7 = PD7  00000111

void trafficLight() {
    while (1) {
        // 1.   Tänd röd LED - ska vara tänd i 5 sekunder
        BIT_SET(PORTB, 1);
        _delay_ms(5000);
        BIT_CLEAR(PORTB, 1);
        _delay_ms(200);

        // 2.   Tänd gul LED - ska vara tänd i 2 sekunder
        BIT_SET(PORTB, 0);
        _delay_ms(2000);
        BIT_CLEAR(PORTB, 0);
        _delay_ms(200);
        
        // 3.   Tänd grön LED - ska vara tänd i 5 sekunder
        BIT_SET(PORTD, 7);
        _delay_ms(5000);
        BIT_CLEAR(PORTD, 7);
        _delay_ms(200);
        
        // 4.  Tänd gul LED - ska vara tänd i 2 sekunder
        BIT_SET(PORTB, 0);
        _delay_ms(2000);
        BIT_CLEAR(PORTB, 0);
        _delay_ms(200);    
    }
}

int main(void) {
    DDRB |= (1 << 1);    // Pin 9, PB1)     00000001    <<  00000010
    DDRB |= (1 << 0);    // Pin 8, PB0)     00000000    <<  00000000
    DDRD |= (1 << 7);    // Pin 7, PD7)     00000111    <<  00000111
    
    trafficLight();
    return 0;
}

// Lektion1
// #include <util/delay.h>
// #include <avr/io.h>
// #define BIT_SET(a,b) ((a) |= (1ULL << (b)))
// #define BIT_CLEAR(a,b)((a) &= ~(1ULL << (b)))        // ~ = bitvis not (!, destruct?)
// void internal_led() {
//     while (1) {
//         BIT_SET(PORTB, 5);      // dvs. pin PB5 (Motsvarande ligger exempelvis på Arduino UNOs pinmode 13)
//         _delay_ms(1000);
//         BIT_CLEAR(PORTB, 5);
//         _delay_ms(1000);
//     }
// }
// int main(void) {
//     DDRB |= (1 << 5);        // register som används för mode B? '<<' = bitskifte?
//     internal_led();
//     return 0;
// }

/*
        BIT_SET(PORTB, 1);      //  BIT_SET(LED_PORT, LED_BIT)      //  // digitalWrite(RED_LED, HIGH);
        _delay_ms(5000);        //  _delay_ms(milliseconds)         //  // delay(5000);
        BIT_CLEAR(PORTB, 1);    //  BIT_CLEAR(LED_PORT, LED_BIT)    //  // digitalWrite(RED_LED, LOW);
        _delay_ms(200);         //  _delay_ms(milliseconds)         //  // delay(200);  
*/