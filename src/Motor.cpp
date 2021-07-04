#include <Motor.h>
#include <Arduino.h>

Motor::Motor(int stepPin, int dirPin, int stepPerRev, int speed)
{
  this->_stepPin = stepPin;
  this->_dirPin = dirPin;
  this->_stepPerRev = stepPerRev;
  this->_oldPosition = 0;
  this->_speed = speed;
};

void Motor::moveTo(int step)
{
  int move;
  if(step == this->_position){
    return;
  }
  if (step > this->_position)
  {
    digitalWrite(this->_dirPin, HIGH);
    move = step - this->_position;
  }
  if (step < this->_position)
  {
    digitalWrite(this->_dirPin, LOW);
    move = this->_position - step;
  }

  for (int i = 0; i < move; i++) {
    digitalWrite(this->_stepPin, HIGH);
    delayMicroseconds(500*this->_speed);
    digitalWrite(this->_stepPin, LOW);
    delayMicroseconds(500*this->_speed);
  }

  this->_position = step;
};

int Motor::getPosition(){
  return this->_position;
};

