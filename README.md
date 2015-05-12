# Arduino
Proyectos y librerias desarrolladas para la plataforma Arduino.

Librerías agregadas.

RX

Descripción de la librería.

Filtrado
La librería permite un filtrado simple de las señales mediante el promediado de las mismas. Se puede definir la cantidad de muestras que se tomarán (por defecto se toman 10 muestras). Si desea lograr una respuesta más agresiva o inmediata, por ejemplo para vuelo acrobático, puede reducir la cantidad de muestras hasta 5 y seguir teniendo un buen resultado en el filtrado.

Definiendo el Pin de conexión
En esta librería los canales deben definirse por separado, cada canal se conecta a un pin exclusivo. Utilizando la función DefPin(numeroPin) definimos el pin al cuál está conectado el canal.

Procesar señal
Para utilizar el filtrado deben llamar a la función Procesar(). La misma retorna un valor entero filtrado.

Limites de Salidas
La salida de la librería posee por defecto un límite máximo y mínimo, estos son modificables a través de la función DefLimitesRX(valorMinimo,valorMaximo)

Límites de salidas por defecto:
Mínimo: 1278
Máximo: 2608

Calibrar Sticks.
Esta función les permite asignar de manera pseudo-automática los valores máximo y mínimo. Cabe aclarar que los datos no son guardados de manera permanente en EEPROM esa implementación correrá por su cuenta.
El procedimiento para utilizar la funcion CalibrarSticks(señal) sería, una vez que estamos leyendo correctamente y obteniendo las salidas filtradas, aplicamos la señal filtrada a esta función moviendo los controles en todas las direcciones de manera de obtener el máximo rango de valores.

Otras funciones

Inicializar() Reinicia las lecturas a 0 y empieza a muestrear nuevamente.

Min() Devuelve el valor mínimo que puede devolver el filtrado.

Max() Devuelve el valor máximo que puede devolver el filtrado.
