#define LEDPIN 7
#define PUSHPIN 2

int randNumber = 0;
volatile bool data = false;
unsigned long int start;
unsigned long int stop;

void setup()
{
    Serial.begin(9600);
    randomSeed(analogRead(0)); // Initialisation générateur de nombres aléatoires
    pinMode(LEDPIN, OUTPUT);   // Initialisation LED
    pinMode(PUSHPIN, INPUT);   // Initialisation bouton
    interruption_init();       // Initialisation interruption
}

void loop()
{
    acquisition();
}

void acquisition() // Je simule l'acquisition de données avec cette fonction
{
    randNumber = random(3, 7); // Je tire un nombre au hasard entre 3 et 6
    delay(randNumber * 1000);  // delai du nombre de secondes simulant l'acquisition de données
}

void basculer()
{
    data = !data;
    if (data)
    {
        allumer();
        start = millis();
    }
    else
    {
        stop = millis();
        eteindre();
        Serial.print("temps de pressage du bouton : ");
        Serial.println(stop - start);
    }
}
void interruption_init(void)
{
    attachInterrupt(digitalPinToInterrupt(PUSHPIN), basculer, CHANGE);
}

void allumer()
{
    digitalWrite(LEDPIN, HIGH);
}

void eteindre()
{
    digitalWrite(LEDPIN, LOW);
}