#define trighPin 7
#define buzzerPin 8

int max = 50;
int min = 0;

void setup()
{
    pinMode(trighPin, OUTPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop()
{
    int olcum = mesafe(max, min);
    melodi(olcum*10);
}

int mesafe(int maxr, int minr)
{
    long duration, distance;

    digitalWrite(trighPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trighPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trighPin, LOW);

    duration = pulseIn(trighPin, HIGH);
    distance = duration / 58.2;
    delay(50);

    if (distance >= maxr || distance <= minr)
        return 0;
    return distance;
}

int melodi(int dly) 
{
    tone(buzzerPin, 440);
    delay(dly);
    noTone(buzzerPin);
    delay(dly);
}
