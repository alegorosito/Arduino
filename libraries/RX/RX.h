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

#ifndef RX_h
#define RX_h
#define LIBRARY_VERSION 1.0

class RX
{

public:

	// Funciones

	int Procesar();
	void CalibrarSticks(int entrada);
	void DefPin(int pin);
	void DefCantLecturas(int cantLecturas);
	void DefLimitesRX(int minCh, int maxCh);
	void Inicializar();
	int Min();
	int Max();

private:
	// Variables para filtrado del Canal de RX

	float _ch, _chAnt = 0;
	int _cantLecturas = 10, _pos = 0, _pin;
	int _lectCh[10], _totalCh = 0, _salida = 0;
	
	// Limites de rangos de entradas de RX
	int _minCh = 1278, _maxCh = 2608;

};

#endif