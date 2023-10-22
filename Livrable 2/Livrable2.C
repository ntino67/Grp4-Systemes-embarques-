#define LEDPIN 7  // Définition du numéro de la broche de la LED
#define PUSHPIN 2 // Définition du numéro de la broche du bouton

int randNumber = 0;         // Variable pour stocker le nombre aléatoire
volatile bool data = false; // Variable pour stocker l'état du bouton
unsigned long int start;    // Variable pour stocker le temps de début
unsigned long int stop;     // Variable pour stocker le temps de fin

void setup()
{
    Serial.begin(9600);        // Initialisation port série
    randomSeed(analogRead(0)); // Initialisation générateur de nombres aléatoires
    pinMode(LEDPIN, OUTPUT);   // Initialisation LED
    pinMode(PUSHPIN, INPUT);   // Initialisation bouton
    interruption_init();       // Initialisation interruption
}

void loop()
{
    acquisition(); // Je simule l'acquisition de données
}

void acquisition()
{ // Je simule l'acquisition de données avec cette fonction

    randNumber = random(3, 7); // Je tire un nombre au hasard entre 3 et 6
    delay(randNumber * 1000);  // delai du nombre de secondes simulant l'acquisition de données
}

void basculer()
{ // Fonction appelée lors de l'interruption

    data = !data; // Je bascule la valeur de data
    if (data)
    {                     // Si data est vrai
        allumer();        // J'allume la LED
        start = millis(); // Je récupère le temps en millisecondes
    }
    else
    {                                                   // Si data est faux
        stop = millis();                                // Je récupère le temps en millisecondes
        eteindre();                                     // J'éteins la LED
        Serial.print("temps de pressage du bouton : "); // J'affiche le temps de pressage du bouton
        Serial.println(stop - start);                   // J'affiche le temps de pressage du bouton
    }
}
void interruption_init(void)
{                                                                      // Fonction d'initialisation de l'interruption
    attachInterrupt(digitalPinToInterrupt(PUSHPIN), basculer, CHANGE); // J'attache l'interruption au bouton
}

void allumer()
{ // Fonction d'allumage de la LED
    digitalWrite(LEDPIN, HIGH);
}

void eteindre()
{ // Fonction d'extinction de la LED
    digitalWrite(LEDPIN, LOW);
}

