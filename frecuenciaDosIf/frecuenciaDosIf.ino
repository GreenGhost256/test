const int salida = 2;       // Defino una "variable" constante llamada "salida" y le asigno el numero 2, que es el pin de salida
const int alta = 2;         // Defino otra constante con valor 2 que es el tiempo del pulso 

float ms;                   // Defino una variable de tipo foat en la cual voy a guardar milisegundos 
float msAnterior;           // Defino otra variable donde voy a guardar los milisegundos anteriores
boolean estado;             // Defino una variable booleana 
int aux = 0;                // Defino una variable de tipo int.


void setup(void){   // Función setup, que se ejecuta una ves al iniciar el arduino
  pinMode(salida, OUTPUT);    //defino salida (pin 2) como OUTPUT o salida
  Serial.begin(9600);
}

void loop(void){  // Función loop que se ejecuta una y otra ves
  ms = millis();  // Leo el contador de milisegundos del micro y lo asigno a la variable ms

  if (((ms - msAnterior) > alta) && estado) {     // Sentencia if en donde verifico si ms (tiempo actual) menos msAnterior (que en la primera ejecucion vale 0) 
                                                  //es mayor a alta (que es el tiempo que la salida tiene que estar en alto) y si la variable estado es verdadera.
                                                  //Si alta es mayor y estado es verdadero, entra al if.
    digitalWrite(salida, estado = !estado); 
    //pongo salida en HIGH, (la funcion digitalWrite admite HIGH o true para poner el pin en alto). 
    Serial.print("if Alto - ms= ");
    Serial.print(ms);
    Serial.print(" - Estado ");
    Serial.println(estado);                                             //¨= !estado¨ esto cambia la variable estado a falso
    msAnterior = ms;                              // asigno el tiempo acutal a la variable msAnterior 
  }

  if (((ms - msAnterior) > aux) && !estado) {     // Verifico si ms menos msAnterior es mayor a aux y la variable estado es falsa
    digitalWrite(salida, estado = !estado);       // Si ambos se cumplen, pongo la salida en low y cambio la variable estado nuevamente a verdadero
    msAnterior = ms;     
    Serial.print("if Bajo - ms= "); 
    Serial.print(ms);
    Serial.print(" -  Estado ");              // asigno el tiempo acutal a la variable msAnterior 
    Serial.println(estado);
    aux = (analogRead(A0) / 17) + 16;             // leo el valor del pote (conectado al pin A0) lo divido en 17 y le sumo 16. El resultado se asigna a la variable aux
  }
}


