#define F_CPU 1200000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    unsigned char buttonpress=0;
	DDRB = 0b00000110;
	PORTB = 0b00000011;
    while (1) 
    {
		if (!(PINB&0b00000001))
		{
			if (buttonpress<5)
			{
				buttonpress++;
			} 
			else
			{
				PORTB = 0b00000101;
				_delay_ms(3000);
			}
		} 
		else
		{
			if (buttonpress>0)
			{
				buttonpress--;
			} 
			else
			{
				PORTB = 0b00000011;				
			}
		}
    }
}

