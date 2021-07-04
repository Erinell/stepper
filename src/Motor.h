class Motor {

 public:
  
  Motor(int stepPin, int dirPin, int stepPerRev, int speed);

  void moveTo(int step);
  int getPosition();
  int _position;
  int _oldPosition;

 private:
  int _stepPin;
  int _dirPin;
  int _stepPerRev;
  int _speed;
};
