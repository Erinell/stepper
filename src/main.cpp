#include <Arduino.h>
#include <Motor.h>
#include <functions.h>
#include <config.h>

Motor moteur = Motor(stepPin, dirPin, stepPerRev, speed);

void setup()
{
  Serial.begin(115200);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop()
{
  if (Serial.available() > 0)
  {
    float pos = Serial.parseFloat(SKIP_ALL, '\n');
    Serial.print("Déplacement à ");
    Serial.print(pos);
    Serial.print("°  ;  ");
    Serial.print("Déplacement à ");
    Serial.print(angleToStep(pos));
    Serial.println(" pas");
    if (pos <= 360)
    {
      moteur.moveTo((int)angleToStep(pos));
    }
    else
    {
      Serial.println("L'angle doit être <= à 360°");
    }
  }
}