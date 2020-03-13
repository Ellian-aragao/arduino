#include "led.h"
class ledPiscante : public Led {
    private:
        unsigned int modulo;
    public:
        ledPiscante(unsigned int portaDeSaida, unsigned int modulo) : Led(portaDeSaida) {
            this->modulo = modulo;
        }

        void testaModuloLed(unsigned int tempo) {
            if (tempo % this->modulo == 0 && tempo != 0) {
                this->alternaEstadoLed();
            }
        }

        ~ledPiscante();
};

ledPiscante amarelo = ledPiscante(2,5);
ledPiscante vermelho = ledPiscante(3,5);
ledPiscante verde = ledPiscante(4,11);

ledPiscante vetorDeLeds[] = {amarelo,vermelho, verde};

void setup() {
    for (int i = 0; i < 3; i++) {
        vetorDeLeds[i].declaraLed();
    }
    Serial.begin(9600);
}

void loop() {
    for (int i = 0; 1; i++) {
        Serial.println(i);

        for(int j = 0; j < 3; j++) {
            vetorDeLeds[i].testaModuloLed(i);
        }
        
        delay(1000);
    }
}