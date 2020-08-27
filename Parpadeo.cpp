/*
 * Ejemplo.cpp
 *
 * Created: 26/08/2020 19:01:14
 * Author : xdzohlx
 */ 
#define F_CPU 8000000 //frecuencia del microcontrolador
#include <avr/io.h>//librerio de los nombres de los registros y los bits
#include <util/delay.h>//libreria delay

int main(void){
	//setup configuracion
	DDRC |= (1<<PORTC6);//Poner en '1' el bit 6 del registro ddrc con un corrimiento
	//1<<n es una operaccion bit a bit
	//la parte de la izquierda es el valor que va a estar en corrimento
	//n la parte de la derecha es cuantas veces se va a hacer este corrimiento
	// despues hace la operacion or donde los 0 se sobreescriben con 1 con el valor del corrimiento
    while (1){
		PORTC |= (1<<PORTC6);//poner en la salida del puerto c en el portc6 en 1
		_delay_ms(500);//funcion delay, genera un tiempo de retraso donde el procesador no hace nada
    //se genera al haciendo que el procesador queme cierto número de instrucciones para que se 
    //cumpla en tiempo
		PORTC &= ~(1<<PORTC6);//poner en la salida del puerto c en el portc6 en 0
		//ahora el enmascaramiento es con el operador and del mismo registo sobreescribiendo los 1 por 0
		// en el lugar donde ocurrio el corrimiento
		_delay_ms(500);//la funcion delay en atmel studio 7 tiene un limite en la funcion
    //dependiendo de la frecuencia del cpu definida anteriormente como F_CPU
    }
}
