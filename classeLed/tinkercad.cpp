class Led {
    private:
        unsigned int portaDeSaida;
        bool estadoDoLed;
        
    public:
        Led(unsigned int portaDeSaida) {
            this->portaDeSaida = portaDeSaida;
            this->estadoDoLed = false;
        }
        void declaraLed() {
            pinMode(this->portaDeSaida, OUTPUT);
        }
        bool getEstadoDoLed() {
            return this->estadoDoLed;
        }
        bool alternaEstadoLed() {
            if (this->getEstadoDoLed()) {
                return this->desligaLed();
            }
            
            return this->ligaLed();   
        }
        bool ligaLed() {
            digitalWrite(this->portaDeSaida, HIGH);
            this->estadoDoLed = false;
            return this->estadoDoLed;
        }
        bool desligaLed() {
            digitalWrite(this->portaDeSaida, LOW);
            this->estadoDoLed = true;
            return this->estadoDoLed;
        }
        ~Led();
};
