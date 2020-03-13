#ifndef LED_H
#define LED_H

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
        ~Led();
};

#endif
