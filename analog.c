//#define F_CPU		10000000
#include <avr/io.h>
#include <util/delay.h>


void startADC(){
	ADMUX = 0b00100011; // Vcc as reference voltage and pin3 set for ADC3 // ADLAR = LEFT shifted 8 bit precision
	ADCSRA = 0b10000011; // enable and prescalar

}



int main(){
	DDRB |= (1<<4); // pinB4 output data (discrete)
	
	startADC();

	for(;;){
	ADCSRA |= (1<< ADSC);
	while(ADCSRA & (1<<ADSC));
	_delay_ms(5);      // 
		if(ADCH >100){ 
			PORTB |=(1<<4); // fan on
		}

		if(ADCH <= 100){
			PORTB &=~(1<<4);// fan off

		}

	}

	return 0;
 }

