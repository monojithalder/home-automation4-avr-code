/**
* author: monoit
* date: 20-Nov-2019 07:43:06 PM
*/

#define F_CPU 16000000UL

#include <util/delay.h>
//#include <avr/io.h> 
#include <avr/myInputOutput.h>
//void usart_send(unsigned char ch);
int main() {
    UCSRB = (1<<TXEN) | (1<<RXEN);
    UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1<<URSEL);
    UBRRL = 0X67;
    pinMode('C',5,1);
    pinMode('C',1,0);
    pinMode('C',4,0);
    int button = 0;
    int test = 0;
    unsigned char reccive;
    int port_reccive = 66;
    while(1) {
        while(! (UCSRA & (1<<RXC)));
        {
            reccive = UDR;
            
            if(reccive == 'A') {
                reccive = ' ';
                unsigned char ch = ' ';
                _delay_ms(500);
                port_reccive = digitalRead('C',5);
                if(port_reccive == 1) {
                    ch = 'O';
                    while(! (UCSRA & (1<<UDRE)));
                    {
                        UDR = ch;
                        _delay_ms(500);
                    }  
                }
                else {
                    ch = 'F';
                    while(! (UCSRA & (1<<UDRE)));
                    {
                        UDR = ch;
                        _delay_ms(500);
                    } 
                }
                port_reccive = 66;  
                ch = ' ';          
            }
            if(reccive == 'B') {
                reccive = ' ';
                unsigned char ch = ' ';
                _delay_ms(500);
                port_reccive = digitalRead('C',4);
                if(port_reccive == 1) {
                    ch = 'O';
                    while(! (UCSRA & (1<<UDRE)));
                    {
                        UDR = ch;
                        _delay_ms(500);
                    }  
                }
                else {
                    ch = 'F';
                    while(! (UCSRA & (1<<UDRE)));
                    {
                        UDR = ch;
                        _delay_ms(500);
                    } 
                }
                port_reccive = 66;  
                ch = ' ';
            }
            
        }
    }
    return 0;
}
