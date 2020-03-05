struct LED
{
    int modulo;
    int led;
    bool estado;
};

struct LED amarelo = {5, 2, false};
struct LED vermelho = {7, 3, false};
struct LED verde = {11, 4, false};

struct LED *vetores[] = {&vermelho, &verde, &amarelo};

void setup() {
    pinMode(vermelho.led, OUTPUT);
    pinMode(verde.led, OUTPUT);
    pinMode(amarelo.led, OUTPUT);
    Serial.begin(9600);
}

// alterna o estado do led
void piscaLed(struct LED *led) {
    if (!led->estado) {
        digitalWrite(led->led, HIGH);
        led->estado = true;
    }
    else {
        digitalWrite(led->led, LOW);
        led->estado = false;
    }
}

// verifica se deve piscar o led
void testaLed(struct LED *led, int tempo) {
    if (tempo % led->modulo == 0 && tempo != 0) {
        piscaLed(led);
    }
}

void loop() {
    for (int i = 0; 1; i++) {
        Serial.println(i);

        for(int j = 0; j < 3; j++) {
            testaLed(vetores[j], i);
        }

        delay(1000);
    }
}