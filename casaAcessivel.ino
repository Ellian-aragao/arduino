// declarando as variaveis das entradas dos sensores
const int sensorGas = A0;
const int interruptor = 2;

// declarando as variaveis das saídas
const int ledVermelho = 3;
const int ledAzul = 4;
const int A =  7;
const int B =  8;
const int C =  9;
const int D = 10;
const int E = 11;
const int F = 12;
const int G = 13;

// definição de ativação do sensor de gás
const int ativacao = 1024 / 4;

// função para execultar a piscada do led
void piscaLed(unsigned int time, int led)
{
    digitalWrite(led, HIGH);
    delay(time);
    digitalWrite(led, LOW);
    delay(time);
}

// desliga todos os leds
void desligaDisplay(void)
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
}

// exibe no display o "0"
void print0(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
}
// exibe no display o "1"
void print1(void)
{
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
}
// exibe no display o "2"
void print2(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(G, HIGH);
}
// exibe no display o "3"
void print3(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(G, HIGH);
}
// exibe no display o "4"
void print4(void)
{
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}
// exibe no display o "5"
void print5(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}
// exibe no display o "6"
void print6(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}
// exibe no display o "7"
void print7(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(F, HIGH);
}
// exibe no display o "8"
void print8(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}
// exibe no display o "9"
void print9(void)
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
}

// função do display de 7 segmentos
void display(int analog, int time)
{
    // cálculo para determinar qual valor a ser exibido
    int x = analog * 0.009765625; // a constante é "10 / 1024"

    // setar os leds para o próximo valor
    desligaDisplay();
    digitalWrite(0, LOW);

    switch (x)
    {
        case 0:
            print0();
            break;
        case 1:
            print1();
            break;
        case 2:
            print2();
            break;
        case 3:
            print3();
            break;
        case 4:
            print4();
            break;
        case 5:
            print5();
            break;
        case 6:
            print6();
            break;
        case 7:
            print7();
            break;
        case 8:
            print8();
            break;
        case 9:
            print9();
            break;
        default:
            digitalWrite(0, HIGH);
    }
    delay(time);
}

void setup()
{
    // configura a velocidade de leitura
    Serial.begin(9600);

    //configurando entradas do Arduino
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
    display(analog, 0);
    Serial.println(analog);

    // enquanto o sensor tiver passado do limite de ativacao ficará no loop
    while (analog >= ativacao)
    {
        // determina a velocidade que o led irá piscar de acordo com a medição do sensor de gás
        unsigned int time = 1024 - analog;

        // faz o led piscar e atualiza o display
        display(analog, 0);
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