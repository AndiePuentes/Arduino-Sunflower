//ENTREGA ARDUINO GIRASOL_ANDIE PUENTES FERNÁNDEZ 201
//servo
#include <Servo.h>                                            //inlcuimos la librería servo
Servo motor;                                                  //creamos un objeto de tipo servo

//ldr: lector fotosensible
int ldr1 = A0;                                                //pin(A0) donde está conectada la ldr1
int ldr2 = A1;                                                //pin(A1) donde está conectada la ldr2
int ldr3 = A2;                                                //pin(A2) donde está conectada la ldr3
int valorLdr1 = 0;                                            //valor para guardar el valor de la ldr1 (de 0-1024)
int valorLdr2 = 0;                                            //valor para guardar el valor de la ldr2 (de 0-1024)
int valorLdr3 = 0;                                            //valor para guardar el valor de la ldr3 (de 0-1024)

void setup() {
  motor.attach(3);                                            //conectamos el servomotor al pin PWM3 (3 con guión ondulado)
  Serial.begin(9600);                                         //iniciamos como serial
}

void loop() {
  valorLdr1 = analogRead(ldr1);                               //leemos el sensor ldr1 y guardamos el valor de la variable
  valorLdr2 = analogRead(ldr2);                               //leemos el sensor ldr2 y guardamos el valor de la variable
  valorLdr3 = analogRead(ldr3);                               //leemos el sensor ldr3 y guardamos el valor de la variable

  Serial.println("valorLdr1");                                //añadimos el texto "valorLdr1" para que sepamos cual es el valor que nos aparecerá a continuación
  Serial.println(valorLdr1);                                  //enviamos el valor del sensor Ldr1 a través del serial (usb) para verlo en el ordenador
  Serial.println("valorLdr2");                                //añadimos el texto "valorLdr2" para que sepamos cual es el valor que nos aparecerá a continuación
  Serial.println(valorLdr2);                                  //enviamos el valor del sensor Ldr2 a través del serial (usb) para verlo en el ordenador
  Serial.println("valorLdr3");                                //añadimos el texto "valorLdr3" para que sepamos cual es el valor que nos aparecerá a continuación
  Serial.println(valorLdr3);                                  //enviamos el valor del sensor Ldr3 a través del serial (usb) para verlo en el ordenador
  delay(30);                                                //delay para no recibir tanta información, y poder leerla


  if (valorLdr1 > valorLdr2 && valorLdr1 > valorLdr3) {       //si el valor de valorLdr1 supera el de valorLdr2 y valorLdr3
    motor.write (1);                                          //el servo de desplaza al ángulo 1 si se cumple la condición anterior
  }
  if (valorLdr2 > valorLdr1 && valorLdr2 > valorLdr3) {       //si el valor de valorLdr2 supera el de valorLdr1 y valorLdr3
    motor.write (90);                                         //el servo de desplaza al ángulo 90 si se cumple la condición anterior
  }
  if (valorLdr3 > valorLdr1 && valorLdr3 > valorLdr2) {       //si el valor de valorLdr3 supera el de valorLdr1 y valorLdr2
    motor.write (179);                                        //el servo de desplaza al ángulo 179 si se cumple la condición anterior
  }
}
