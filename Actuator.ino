const int RELAY_1_A = 5;
const int RELAY_1_B = 7;

char incoming[12];

void setup() {
   pinMode(RELAY_1_A, OUTPUT);
   pinMode(RELAY_1_B, OUTPUT);
   
   Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    Serial.readBytesUntil('\n', incoming, sizeof(incoming));

    switch (incoming[0]) {
    case 'O':
      extendActuator();
      Serial.println("Extending actuator...");
      break;
    case 'C':
      retractActuator();
      Serial.println("Retracting actuator...");
      break;
    default:
      break;
    }
    
    // Clear the array before looping for more
    for (int i=0; i<sizeof(incoming); i++) {
      incoming[i] = (char)0;
    }
  } else {
    // 1/2s delay
    delay(500);
  }
}

void extendActuator() {
  //Set one relay on and the other off
  //this will move extend the actuator
  Serial.println("EXTEND");
  digitalWrite(RELAY_1_B, LOW);
  digitalWrite(RELAY_1_A, HIGH);
}

void retractActuator() { 
  //Set one relay off and the other on 
  //this will move retract the actuator 
  Serial.println("RETRACT");
  digitalWrite(RELAY_1_A, LOW);
  digitalWrite(RELAY_1_B, HIGH); 
}

void stopActuator() {
 //Set both relays off
 //this will stop the actuator in a braking
 digitalWrite(RELAY_1_A, LOW);
 digitalWrite(RELAY_1_B, LOW); 
 }
 
