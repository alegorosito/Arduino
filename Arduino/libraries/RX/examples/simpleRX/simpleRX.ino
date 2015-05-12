/*  
	This simpleRX is part of RX library.

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
	Este es un ejemplo del uso de la libreria RX.

	Autor: Alejandro G. Gorosito

 */

#include "RX.h"
// Define los canales
RX c1, c2;

// Pines a los que estan conectados los canales de salida del receptor
// En arduino debe utilizar los pines digitales
int pinC1 = 2;
int pinC2 = 4;

void setup() {
  
  Serial.begin(115200);
  c1.DefPin(pinC1);
  c2.DefPin(pinC2);
}

void loop() {
  
  int canal1 = c1.Procesar();
  int canal2 = c2.Procesar();
  
  Serial.print(canal1);
  Serial.print("     ");
  Serial.println(canal2);
}
