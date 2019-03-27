//Senzor Voltaj Arduino Nano si Uno
//
//pentru citirea voltajului intre 0 si 80V
//
//Code created by Popescu Lary, sigmanortec.ro

//www.sigmanortec.ro


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display


int voltage_sensor = A0;
float analogvalue = 0;
//float volt = 0.0;
//float voltcorrected = 0.0;
float temp=0.0;
float voltaj = 0.0;
float voltajcorectat = 0.0;

float vin=0.0;

float r1=29600.0;    //r1 value
float r2=5700.0;      //r2 value
//float r3=10000.0;     //r3 value


void setup(){

   //analogReference (INTERNAL); //set the analog reference to internal
   analogReference (DEFAULT);
  
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Voltaj Masurat");
  
}

void loop(){

   
   
   // read the value at analog input

      analogvalue = analogRead(voltage_sensor); //read analog value
       temp = (analogvalue * 5) / 1024;   /// read normal arduino value
       vin = temp / (r2/(r1+r2)); //calculate voltage read with 0-25v sensor
       voltaj = vin * 3;
       voltajcorectat = voltaj - ((voltaj * 20) / 100);

       //correcting the voltage

//      float supply = readVcc()/1000;
//      float valcorrected = (supply / 5 * vin);

//      //showing voltage after resistor divider
//      volt = valcorrected * 3;  //transform arduino value to match resistors divider
//      voltcorrected = volt + ((volt * 20)/100);
//      
     
     

    lcd.setCursor (5, 1);
    lcd.print (voltajcorectat, 2); //show value, with 2 decimals
     lcd.setCursor (12, 1);
    lcd.print ("V");
   
    delay (500);
}

//     long readVcc() {
//  long result;
//  // Read 1.1V reference against AVcc
//#if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
//  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
//#elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
//  ADMUX = _BV(MUX5) | _BV(MUX0);
//#elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
//  ADMUX = _BV(MUX3) | _BV(MUX2);
//#else
//  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
//#endif
//  delay(2); // Wait for Vref to settle
//  ADCSRA |= _BV(ADSC); // Convert
//  while (bit_is_set(ADCSRA, ADSC));
//  result = ADCL;
//  result |= ADCH << 8;
//  result = 1205186L / result; // Calculate Vcc (in mV); 1126400 = 1.1*1024*1000
//  return result;
//      }
