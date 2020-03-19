class Led {
    private:
        unsigned int portaDeSaida;
        bool estadoDoLed;
        
    public:
        Led(unsigned int portaDeSaida);
        void declaraLed();
        bool getEstadoDoLed();
        bool alternaEstadoLed();
        bool ligaLed();
        bool desligaLed();
        ~Led() {}
};

Led::Led(unsigned int portaDeSaida) {
    this->portaDeSaida = portaDeSaida;
    Led::desligaLed();
}

bool Led::ligaLed() {
    digitalWrite(this->portaDeSaida, HIGH);
    this->estadoDoLed = true;
    return this->estadoDoLed;
}

bool Led::desligaLed() {
    digitalWrite(this->portaDeSaida, LOW);
    this->estadoDoLed = false;
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

Led azul = Led(2);
Led verde = Led(3);
Led leds[] = {azul,verde};

void setup(){
    for (int i = 0; i < 2; i++) {
        leds[i].declaraLed();
    }
    azul.alternaEstadoLed();
}

void loop(){
    delay(1000);
    azul.alternaEstadoLed();
    verde.alternaEstadoLed();
    // for (int i = 0; i < 2; i++) leds[i].alternaEstadoLed();   
}
