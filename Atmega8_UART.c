/**
* author: monoit
* date: 20-Nov-2019 07:43:06 PM
* blinky: toggles PORTB pins on and off every 150ms
*/

#define F_CPU 16000000UL

/*#include <avr/uart.h> 
#include <avr/interrupt.h>*/ 
#include <util/delay.h>
//#include <avr/io.h> 
#include <avr/myInputOutput.h>
//void usart_send(unsigned char ch);
int main() {
    UCSRB = (1<<TXEN) | (1<<RXEN);
    UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1<<URSEL);
    UBRRL = 0X67;
    //DDRC = DDRC | (1 << 5);
    //DDRC = DDRC & ~(1 << 1);
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
                //digitalWrite('C',5,1);
                //_delay_ms(500);
                //digitalWrite('C',5,0);
                reccive = ' ';
                unsigned char ch = ' ';
                /*while(! (UCSRA & (1<<UDRE)));
                {
                    UDR = ch;
                    _delay_ms(500);
                }*/
                _delay_ms(500);
                port_reccive = digitalRead('C',4);
                if(port_reccive == 1) {
                    digitalWrite('C',5,1);
                    _delay_ms(500);
                    digitalWrite('C',5,0);
                    ch = 'O';
                    while(! (UCSRA & (1<<UDRE)));
                    {
                        UDR = ch;
                        _delay_ms(500);
                    }  
                }
                else {
                    digitalWrite('C',5,1);
                    _delay_ms(200);
                    digitalWrite('C',5,0);
                    _delay_ms(200);
                    digitalWrite('C',5,1);
                    _delay_ms(200);
                    digitalWrite('C',5,0);
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
                digitalWrite('C',5,1);
                _delay_ms(500);
                digitalWrite('C',5,0);
                reccive = ' ';
                /*int port_reccive = digitalRead('C',4);
                if(port_reccive == 1) {
                    while(! (UCSRA & (1<<UDRE)));
                    {
                        UDR = 0b00000001;
                        _delay_ms(500);
                    }  
                }
                else {
                    while(! (UCSRA & (1<<UDRE)));
                    {
                        UDR = 0b00000000;
                        _delay_ms(500);
                    } 
                }*/
                    
            }
            
        }
    }
    return 0;
}
/*void usart_send(unsigned char ch) {
    while(! (UCSRA & (1<<UDRE)));
    {
        UDR = ch;
    }
}
void send_char(char c)
{
	while (! (UCSRA & (1 << UDRE)) );
	UDR = c;
}


void send_string(char s[])
{
	int i =0;
	
	while (s[i] != 0x00)
	{
		send_char(s[i]);
		i++;
	}
}*/
