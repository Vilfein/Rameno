#include "Rameno.h"

Rameno::Rameno(int dirPin, int stepPin, int enPin) {
  this->dirPin = dirPin;
  this->stepPin = stepPin;
  this->enPin = enPin;

  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, LOW);
}

byte Rameno::getDirPin() {
  return this->dirPin;
}

void Rameno::setDirPin(byte newPin) {
  this->dirPin = newPin;
}

byte Rameno::getStepPin() {
  return this->stepPin;
}

void Rameno::setStepPin(byte newPin) {
  this->stepPin = newPin;
}


byte Rameno::getEnPin() {
  return this->enPin;
}

void Rameno::setEnPin(byte newPin) {
  this->enPin = newPin;
}

void Rameno::RunR(int pause, int pulses) {
  digitalWrite(dirPin, HIGH);
  for (int x = 0; x < pulses; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pause);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pause);
  }
}

void Rameno::RunR2(int pause, int pulses,  Rameno &R2) {
  digitalWrite(dirPin, HIGH);
  digitalWrite(R2.getDirPin(), HIGH);

  for (int x = 0; x < pulses; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(R2.getStepPin(), HIGH);
    delayMicroseconds(pause);
    digitalWrite(stepPin, LOW);
    digitalWrite(R2.getStepPin(), LOW);
    delayMicroseconds(pause);
  }
}

void Rameno::RunR3(int pause, int pulses,  Rameno &R2, Rameno &R3) {
  digitalWrite(dirPin, HIGH);
  digitalWrite(R2.getDirPin(), HIGH);
  digitalWrite(R3.getDirPin(), HIGH);

  for (int x = 0; x < pulses; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(R2.getStepPin(), HIGH);
    digitalWrite(R3.getStepPin(), HIGH);
    delayMicroseconds(pause);
    digitalWrite(stepPin, LOW);
    digitalWrite(R2.getStepPin(), LOW);
    digitalWrite(R3.getStepPin(), LOW);
    delayMicroseconds(pause);
  }
}

void Rameno::RunL(int pause, int pulses) {
  digitalWrite(dirPin, LOW);
  for (int x = 0; x < pulses; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(pause);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(pause);
  }
}

void Rameno::RunL2(int pause, int pulses,  Rameno &R2) {
  digitalWrite(dirPin, LOW);
  digitalWrite(R2.getDirPin(), LOW);

  for (int x = 0; x < pulses; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(R2.getStepPin(), HIGH);
    delayMicroseconds(pause);
    digitalWrite(stepPin, LOW);
    digitalWrite(R2.getStepPin(), LOW);
    delayMicroseconds(pause);
  }
}

void Rameno::RunL3(int pause, int pulses,  Rameno &R2, Rameno &R3) {
  digitalWrite(dirPin, LOW);
  digitalWrite(R2.getDirPin(), LOW);
  digitalWrite(R3.getDirPin(), LOW);
  for (int x = 0; x < pulses; x++) {
    digitalWrite(stepPin, HIGH);
    digitalWrite(R2.getStepPin(), HIGH);
    digitalWrite(R3.getStepPin(), HIGH);
    delayMicroseconds(pause);
    digitalWrite(stepPin, LOW);
    digitalWrite(R2.getStepPin(), LOW);
    digitalWrite(R3.getStepPin(), LOW);
    delayMicroseconds(pause);
  }
}
