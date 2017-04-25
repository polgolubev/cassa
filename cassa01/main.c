#define F_CPU 1200000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    unsigned char buttonpress=0;
	unsigned char i;
	DDRB = 0b00001110;
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
				PORTB = 0b00001100;
				_delay_ms(2000);
				for (i=0;i < 58; i++)
				{
					PORTB = 0b00000100;
					_delay_ms(1000);
				}				
				PORTB = 0b00000101;
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

