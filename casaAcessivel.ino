// iniciação das entradas dos sensores
const int interruptor = 0;
const int sensorGas = A0;

// iniciação das saídas
const int ledVermelho = 1;
const int ledAzul = 2;
const int A =  7;
const int B =  8;
const int C =  9;
const int D = 10;
const int E = 11;
const int F = 12;
const int G = 13;

// definição de ativação do sensor de gás
const int ativacao = 1023 / 4;

// função para execultar a piscada do led
void piscaLed(unsigned int time, int led)
{
    digitalWrite(led, HIGH);
    delay(time);
    digitalWrite(led, LOW);
    delay(time);
}

// função do display de 7 segmentos
void display(int x, int time)
{
    // desliga todos os leds para setar o próximo valor
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);

    switch (x)
    {
        case 0:
            digitalWrite(A, HIGH);
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(F, HIGH);
            break;
        case 1:
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            break;
        case 2:
            digitalWrite(A, HIGH);
            digitalWrite(B, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 3:
            digitalWrite(A, HIGH);
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 4:
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 5:
            digitalWrite(A, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 6:
            digitalWrite(A, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 7:
            digitalWrite(A, HIGH);
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(F, HIGH);
            break;
        case 8:
            digitalWrite(A, HIGH);
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 9:
            digitalWrite(A, HIGH);
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
        default:
            digitalWrite(3, HIGH);
    }
    delay(time);
}

void setup()
{
    // configura a velocidade de leitura
    Serial.begin(9600);

    //configurando entradas e saídas do Arduino
    pinMode(sensorGas, INPUT);
    pinMode(interruptor, INPUT);

    // configurando saídas dos leds
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledAzul, OUTPUT);

    // configurando saídas do display de 7 segmentos 
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
}

void loop()
{
    int analog = analogRead(A0);
    // display(analog * 10 / 1023, 0);
    Serial.println(analog);

    // enquanto o sensor tiver passado do limite de ativacao ficará no loop
    while (analog >= ativacao)
    {
        // determina a velocidade que o led irá piscar de acordo com a medição do sensor de gás
        unsigned int time = 1023 - analog;

        // faz o led piscar e atualiza o display
        // display(analog * 100 / 1023, 0);
        piscaLed(time, ledVermelho);

        // refaz a leitura do sensor de gás
        analog = analogRead(A0);
        Serial.println(analog);
    }


    // verifica se a leitura do interruptor é verdadeira
    if (digitalRead(interruptor))
    {
        Serial.println("ligado");

        // determina o tempo de variação do led ligado/desligado e define o tempo do loop
        int time = 500; // meio segundo
        int seg = 4;

        // faz o led piscar pela variável segundos
        for (int i = 0; i < seg; i++) piscaLed(time, ledAzul);
    }
}