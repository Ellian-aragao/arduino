// iniciação das entradas dos sensores
const int interruptor = 0;
const int ledVermelho = 3;
const int ledAzul = 4;
const int sensorGas = A0;

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

void setup()
{
    // configura a velocidade de leitura
    Serial.begin(9600);

    //configurando entradas e saídas do Arduino
    pinMode(sensorGas, INPUT);
    pinMode(ledVermelho, OUTPUT);
    pinMode(interruptor, INPUT);
}

void loop()
{
    // verifica se a leitura do interruptor é verdadeira
    if (digitalRead(interruptor))
    {
        Serial.println("ligado");

        unsigned int time = 500; // meio segundo
        int seg = 4;

        // faz o led piscar pela variável segundos
        for (int i = 0; i < seg; i++)
        {
            piscaLed(time,ledAzul);
        }
    }
    else
    {
        Serial.println("desligado");
    }
    

    Serial.println(analogRead(A0));

    while (analogRead(A0) >= ativacao)
    {
        Serial.println(analogRead(A0));

        // determina a velocidade que o led irá piscar de acordo com a medição do sensor de gás
        unsigned int time = 1024 - analogRead(A0);

        // faz o led piscar
        piscaLed(time,ledVermelho);
    }

    // digitalWrite(led, LOW); // mantém o led desligado

    // delay(1000);
}