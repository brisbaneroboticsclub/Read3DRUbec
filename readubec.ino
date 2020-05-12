float voltage = 0;
float amps = 0;
// http://brisbaneroboticsclub.id.au/read-voltage-and-amps-from-3dr-power-monitor-ubec/

void setup() {
  // put your setup code here, to run once:

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  voltage = analogRead(A0);

  voltage = voltage / 1023;

  voltage = voltage * 50.0;
  
  // 4.3V Range
  // voltage = (analogRead(A0) / 1023) * 4.3;
  
  // 5V range
  //voltage = analogRead(A0) * 0.004882814; //convert the analog reading, which varies from 0 to 1023, back to a voltage value from 0-5 volts
  //or could use voltage = analogRead(A0) * 5.0/1023.;

  amps = analogRead(A1);
  
  amps = amps / 1023;

  amps = amps * 50.0;
  
  
  // amps = analogRead(A1) * 0.004882814; //convert the analog reading, which varies from 0 to 1023, back to a voltage value from 0-5 volts
  //or could use voltage = analogRead(A0) * 5.0/1023.;

  // Print motor speed to montor.
  Serial.print("Volts/Amps : ");
  Serial.print("\t");
  Serial.print(voltage);
  Serial.print("\t");
  Serial.println(amps);
  
  //Serial.println(voltage, 2);
  delay(100);        // delay in between reads for stability

}
