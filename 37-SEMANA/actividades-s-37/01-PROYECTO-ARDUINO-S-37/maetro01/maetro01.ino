//DOS ARDUINOS -- MAESTRO
// BY : JAVIER DIAZ SANCHEZ
//Librería Wire 
#include "Wire.h"
// Incluir la librería pública 
#include <LiquidCrystal.h>
// Inicializa el dispositivo con los parámetros
// definidos
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
byte CODE;

void setup()
{
//Maestro 
Wire.begin();
// conectividad serial 
Serial.begin(9600);
//LCD Preparaciòn 
lcd.clear();
// Configura al LCD en 16 columnas y 2 filas 
lcd.begin(16, 2);
// Envía un texto de inicio 
lcd.print("Master 2 ARD"); 
delay(200);
}
void loop() {

String CADENA="";
//RECOPILA informacion "CODIGO" al esclavo 1 
Wire.requestFrom(0x01,1); 
while(Wire.available())
{
CODE=Wire.read();
}
//Compara la información recibida "DISTANCIA"


//------
// if(CODE==30 )
// {CADENA="APAGADO"} else
//---- 
if(CODE==10)
{
CADENA="RETROCEDE";
}
else if(CODE==11)
{ CADENA="ALTO";
}
else
{
CADENA="Seguro AVANZA";
}

//Limpia pantalla y coloca distancia 
lcd.clear();
lcd.setCursor(0, 0);
//Escribe la distancia 
lcd.print(CODE);

lcd.setCursor(0, 1);
//Escribe cadena 
lcd.print(CADENA); 
delay(50);
}

