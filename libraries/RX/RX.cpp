/*  
	This file is part of RX library.

    RX is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    RX is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with RX.  If not, see <http://www.gnu.org/licenses/>.
*/

 /*
	Esta librería ha sido creada para el uso con
	Receptores de radio control para todo tipo 
	de vehiculos radiocontrolados.

	Autor: Alejandro G. Gorosito
 */

#include "Arduino.h"
#include "RX.h"

int RX::Procesar() {
	// Realiza la lectura para el pin asignado y calcula el promedio segun la cantidad de lecturas definidas
	_ch = pulseIn(_pin, HIGH, 25000);
	_totalCh = _totalCh - _lectCh[_pos];
	_lectCh[_pos] = _ch;
	_totalCh = _totalCh + _lectCh[_pos];
	_pos++;
	if(_pos >= _cantLecturas) 
	_pos = 0;
	_salida = _totalCh / _cantLecturas;

	if (_salida < _minCh) _salida = _minCh;
	if (_salida > _maxCh) _salida = _maxCh;

	return _salida;
}

void RX::CalibrarSticks(int entrada) {
	// Comprueba los valores minimos y maximos del canal.
	// Durante el proceso de calibracion el control debe moverse 
	// para generar el rango maximo de valores 
	if (entrada < _minCh) _minCh = entrada;
	if (entrada > _maxCh) _maxCh = entrada;
}

void RX::DefPin(int pin) {
	// Define el pin fisico donde esta conectado al arduino
	if (pin > 0)
	{
		pinMode(pin, INPUT);
		_pin = pin;
		Inicializar();
	}
}

void RX::DefCantLecturas(int cantLecturas) {
	// Define la cantidad de lecturas a promediar. Por defecto 10.
	if (cantLecturas > 0) {
		_cantLecturas = cantLecturas;
		unsigned long int _lectCh[_cantLecturas];
		Inicializar();
	}
}

void RX::DefLimitesRX(int minCh, int maxCh) {
	// Define los limites minimos y maximos para el canal.
	if (minCh < maxCh)
	{
		_minCh = minCh;
		_maxCh = maxCh;
		Inicializar();
	}
}

void RX::Inicializar() {
	// Reinicia las lecturas a 0
	for(int lectura=0; lectura < _cantLecturas; lectura++){
		_lectCh[lectura] = 0;
	}
}

int RX::Min(){
	// Minimo para el canal
	return _minCh;
}

int RX::Max(){
	// Maximo para el canal
	return _maxCh;
}