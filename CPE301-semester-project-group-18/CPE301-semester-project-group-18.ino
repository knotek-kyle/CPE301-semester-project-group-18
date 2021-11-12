//Kyle Knotek, Clifford Stewart, Joel Castillo

#define DHT11_PIN 54
#define WS_ADC_ID 1
#define WATER_MIN 64
#define ANALOGUE_PIN( n ) ( 54 + n )

volatile unsigned char* my_ADMUX = (unsigned char*) 0x7C;
volatile unsigned char* my_ADCSRB = (unsigned char*) 0x7B;
volatile unsigned char* my_ADCSRA = (unsigned char*) 0x7A;
volatile unsigned int* my_ADC_DATA = (unsigned int*) 0x78;

void setup() 
{
  //Monitering
  Serial.begin(9600);
  //Screen printing begin
  lcd.begin(16, 2);
  // LED setup
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() 
{
  //Print on LCD
  PollDHT();
  PollWaterSensor();
  // Delay for 2 seconds
  delay(2000);

}
