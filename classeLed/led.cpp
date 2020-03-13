#include "led.h"

Led::Led(unsigned int portaDeSaida) {
    this->portaDeSaida = portaDeSaida;
    this->estadoDoLed = false;
}

bool Led::ligaLed() {
    digitalWrite(this->portaDeSaida, HIGH);
    this->estadoDoLed = false;
    return this->estadoDoLed;
}

bool Led::desligaLed() {
    digitalWrite(this->portaDeSaida, LOW);
    this->estadoDoLed = true;
    return this->estadoDoLed;
}

void Led::declaraLed() {
    pinMode(this->portaDeSaida, OUTPUT);
}

bool Led::getEstadoDoLed() {
    return this->estadoDoLed;
}

bool Led::alternaEstadoLed() {
    if (this->getEstadoDoLed()) {
        return this->desligaLed();
    }
    
    return this->ligaLed();   
}
