//ESCLAVO 1
#include "Wire.h"  // Librería
const int Trigger = 2;  //Pin 2 Trigger del sensor 
const int Echo = 3;  //Pin 3 Echo del sensor
byte entra=0; //Valor de entrada 
int t; //tiempo de respuesta
byte CODE; //distancia del objeto y envio

void setup() {
//Pin MOTOR
pinMode(5, OUTPUT); // ANALOGSPEED- VELOCIDAD ANALOGICA 
pinMode(6, OUTPUT); //CONTROL DIGITAL -SENTIDO 
pinMode(7, OUTPUT); //CONTROL DIGITAL -SENTIDO


Serial.begin(9600); //Puerto Serial 
pinMode(Trigger, OUTPUT); //Salida señal del ultrasónico 
pinMode(Echo, INPUT);  //Entrada de señal 
digitalWrite(Trigger, LOW); //inicio



//---------CODIGO SLAVE------------------------------
Wire.begin(0x01); //Me identifico como Slave 1 
Wire.onReceive(EntradaSolicitud); //Declaro Evento 
Wire.onRequest(Peticion); //Declaro Evento
}

void loop()
{
int d=0;  //Distancia -variable
digitalWrite(Trigger, HIGH);  //FUNCIONAMIENTO DEL SENSOR ULTRASONICO
delayMicroseconds(10);  //pausa para integrar respuesta 
digitalWrite(Trigger, LOW);

t = pulseIn(Echo, HIGH); //Lectura de respuesta 
d =round( t/59);  //Distancia -tiempo
Serial.println(entra);  //ENVIO LO QUE TIENE ENTRADA

//----DECISIONES INDEPENDIENTES---

// if (d==0)
// {CODE=30} else

if(d<40) // ALTO OBSTACULO A 40 CM
 
{
analogWrite(5, 0); //VELOCIDAD 
digitalWrite(6, HIGH); 
digitalWrite(7, HIGH);

CODE=11;  //CODIGO PARA EL MAESTRO
}
else
if(d<70) // ATRAS OBSTACULO A 70 CM
{
analogWrite(5, 64); //VELOCIDAD 
digitalWrite(6, HIGH); 
digitalWrite(7, LOW);

CODE=10;  //CODIGO PARA EL MAESTRO
}
else  //SIgue ADELANTE SIN OBSTACULO
{
analogWrite(5, 128); //VELOCIDAD 
digitalWrite(6, LOW); 
digitalWrite(7, HIGH);

CODE=12;
}

//---------CODIGO PARA SOLICITUDES DEL MAESTRO---

}

//-------EVENTO DE ENTRADA--- ENVIADO POR EL MAESTRO---
void  EntradaSolicitud(int re )
{
while (Wire.available())
{
entra= Wire.read();
}
Serial.println(entra);
}

//-----EVENTO DE PETICIÓN--- SOLICITADO POR EL MAESTRO---
void  Peticion()
{
Wire.write(CODE);
}

