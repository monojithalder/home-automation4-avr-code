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
    pinMode('C',3,0);
    pinMode('C',4,0);
    pinMode('C',2,1);
    pinMode('C',1,1);
    int button = 0;
    int test = 0;
    unsigned char reccive;
    unsigned char ch;
    int port_reccive = 66;
    while(1) {
        while(! (UCSRA & (1<<RXC)));
        {
            reccive = UDR;
            ch = ' ';
            digitalWrite('C',2,0);
            digitalWrite('C',1,0);
            if(reccive == 'A') {
                reccive = ' ';
                _delay_ms(500);
                port_reccive = digitalRead('C',3);
                if(port_reccive == 0) {
                    digitalWrite('C',2,1);
                    ch = 'O';
                    while(! (UCSRA & (1<<TXC)));
                    {
                        UDR = 'O';
                        _delay_ms(500);
                    }  
                }
                else {
                    digitalWrite('C',1,1);
                    ch = 'F';
                    while(! (UCSRA & (1<<TXC)));
                    {
                        UDR = 'F';
                        _delay_ms(500);
                    } 
                }
                port_reccive = 66;  
                ch = ' ';          
            }
            if(reccive == 'B') {
                reccive = ' ';
                _delay_ms(500);
                port_reccive = digitalRead('C',4);
                if(port_reccive == 0) {
                    ch = 'O';
                    while(! (UCSRA & (1<<TXC)));
                    {
                        UDR = 'O';
                        _delay_ms(500);
                    }  
                }
                else {
                    ch = 'F';
                    while(! (UCSRA & (1<<TXC)));
                    {
                        UDR = 'F';
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
