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
            if (this->getEstadoDoLed())
                return this->desligaLed();            
            return this->ligaLed();   
        }
        bool ligaLed() {
            digitalWrite(this->portaDeSaida, HIGH);
            this->estadoDoLed = true;
            return this->estadoDoLed;
        }
        bool desligaLed() {
            digitalWrite(this->portaDeSaida, LOW);
            this->estadoDoLed = false;
            return this->estadoDoLed;
        }
        ~Led(){}
};

class ledPiscante : public Led {
    private:
        bool *vetorControle;
        unsigned int piscadas;
        void incrementadorDePiscadas() {
            this->piscadas++;
        }
    public:
        ledPiscante(int portaDeSaida, int segundos, bool* vetor) : Led(portaDeSaida) {
            this->piscadas = 0;
            this->criaVetorDeControle(segundos,vetor);
        }
        void criaVetorDeControle(int segundos, bool* vetor) {
            this->vetorControle = new bool[segundos];
            for (int i = 0; i < segundos; i++)
                this->vetorControle[i] = vetor[i];
        }
        bool testaModuloLed(int segundos) {
            if (this->vetorControle[segundos])
                return this->ligaLedIncrementando();
            return this->desligaLed();
        }
        bool ligaLedIncrementando() {
            if (!this->getEstadoDoLed()){
                this->incrementadorDePiscadas();
                return this->ligaLed();
            }
            return false;
        }
        unsigned int getPiscadas() {
            return this->piscadas;
        }
        void freeVetor(){
            delete[] this->vetorControle;
        }
        ~ledPiscante(){
            freeVetor();
        }
};

#define TEMPOMAXDOSCICLOS 7
bool verde[2][TEMPOMAXDOSCICLOS] = {
    {true,true,false,false,false,false,true},
    {false,false,false,true,true,false,false}
};
bool amarelo[2][TEMPOMAXDOSCICLOS] = {
    {false,false,true,false,false,false,false},
    {false,false,false,false,false,true,false}
};
bool vermelho[2][TEMPOMAXDOSCICLOS] = {
    {false,false,false,true,true,true,false},
    {true,true,true,false,false,false,true}
};


ledPiscante verde0 = ledPiscante(4,TEMPOMAXDOSCICLOS,verde[0]);
ledPiscante amarelo0 = ledPiscante(3,TEMPOMAXDOSCICLOS,amarelo[0]);
ledPiscante vermelho0 = ledPiscante(2,TEMPOMAXDOSCICLOS,vermelho[0]);

ledPiscante verde1 = ledPiscante(10,TEMPOMAXDOSCICLOS,verde[1]);
ledPiscante amarelo1 = ledPiscante(9,TEMPOMAXDOSCICLOS,amarelo[1]);
ledPiscante vermelho1 = ledPiscante(8,TEMPOMAXDOSCICLOS,vermelho[1]);


typedef struct Semaforos{
    ledPiscante* semaforo[2][3];
    void declaraEstruturaDeLeds();
    void testaOsSemaforos(int segundos);
}SEMAFOROS;
void SEMAFOROS::declaraEstruturaDeLeds(){
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++){
            semaforo[i][j]->declaraLed();
        }
    }
}
void SEMAFOROS::testaOsSemaforos(int segundos){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            semaforo[i][j]->testaModuloLed(segundos);      
        }
    }
}
SEMAFOROS semaforo{{{&verde0 , &amarelo0, &vermelho0},{&verde1, &amarelo1, &vermelho1}}};

void mostraVesesQueLedVermelhoPiscou() {
    Serial.print("/1 semaforo->vermelho: ");
    Serial.println(vermelho0.getPiscadas());
    Serial.print("\\2 semaforo->vermelho: ");
    Serial.println(vermelho1.getPiscadas());
}

void setup() {
    semaforo.declaraEstruturaDeLeds();
    Serial.begin(9600);
}

void loop() {
    for (unsigned long segundos = 0; 1; segundos++) {
        semaforo.testaOsSemaforos(segundos % 6);
        mostraVesesQueLedVermelhoPiscou();
        delay(1000);
    }
}