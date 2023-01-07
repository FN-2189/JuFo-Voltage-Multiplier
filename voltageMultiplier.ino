#define RED 3
#define GREEN 2

void setup() {
  cli(); // stop interrupts
  // put your setup code here, to run once:
  // setup pins
  DDRD = 0;
  DDRD |= (1 << PORTD2);// set green output
  DDRD |= (1 << PORTD3);// set red output

  // setup timer 1
  TCCR1A = 0; // reset control
  TCCR1B = 0;

  TCCR1B |= (1 << WGM12) | (1 << CS11); // set ctc mode and prescaler to 1024

   OCR1A = 18 >> 1; // div by 2 because code
  TIMSK1 = (1 << OCIE1A);
  
  TCNT1 = 0; // reset timer

  sei(); // restart interrupts

  PORTD &= ~(1 << PORTD3);// set red off
  PORTD |= (1 << PORTD2);// set green on 
}

void loop(){}

ISR(TIMER1_COMPA_vect){
  PORTD ^= (1 << PORTD3);// toggle red
  PORTD ^= (1 << PORTD2);// toggle green
}
