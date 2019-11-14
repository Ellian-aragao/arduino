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

void display(int x)
{
    switch (x)
    {
        case 0:
            pinWrite(A, HIGH);
            pinWrite(B, HIGH);
            pinWrite(C, HIGH);
            pinWrite(D, HIGH);
            pinWrite(E, HIGH);
            pinWrite(F, HIGH);
            break;
        case 1:


            break;
        case 2:

            break;
        case 3:

            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        case 9:
            
            break;
    }
}

void setup()
{
    // configura a velocidade de leitura
    Serial.begin(9600);

    //configurando entradas e saídas do Arduino
    pinMode(sensorGas, INPUT);
    pinMode(ledVermelho, OUTPUT);
    pinMode(interruptor, INPUT);
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
}

void loop()
{
    display(0);
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
    int analog = analogRead(A0)
    //Serial.println(analog);

    // enquanto o sensor tiver passado do limite de ativacao ficará no loop
    while (analogRead(A0) >= ativacao)
    {
        Serial.println(analogRead(A0));

        // determina a velocidade que o led irá piscar de acordo com a medição do sensor de gás
        unsigned int time = 1024 - analogRead(A0);

        // faz o led piscar
        piscaLed(time, ledVermelho);
    }
}