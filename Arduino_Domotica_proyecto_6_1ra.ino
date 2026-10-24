//link del repositorio para no perderlo
//https://dl.espressif.com/dl/package_esp32_index.json

 //se incluyen las librerías de bluetooth y de los ESP
 #include "BluetoothSerial.h"
 #include "esp_adc_cal.h"

 //se define el valor máximo del sensor MQ2 en mV y el valor máximo numérico que nos va a enviar
 #define ADC_VREF_mV    5000.0
 #define ADC_RESOLUTION 4096.0

 //se define el pin del sensor de gas MQ2
 #define MQ2pin 35

 //se definen los mensajes que nos va a enviar si falla el proceso de conexión bluetooth
 #if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
 #error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
 #endif

  //se define la consola bluetooth para enviar y recibir datos en el celular
  BluetoothSerial SerialBT;

  //se definen las variables y constantes para usar en el sketch
  int pir = 33;
  int pirState = LOW;
  int pirValue = 0;
  int sensorValue;
  int alarma = 0;
  int alarma2 = 0;
  int alarmagases = 0;
  int buzzer = 13;
  int relay1 = 23;
  int relay2 = 22;
  int r1 = 1;
  int r2 = 1;
  int alarmen = 0;
  int alarm2en = 0;
  bool datos0 = false;
  bool datos1 = false;
  bool datos2 = false;
  bool datos3 = false;
  bool datos4 = false;
  bool datos5 = false;
  bool datos6 = false;
  bool datos7 = false;
  bool datos8 = false;
  bool datos9 = false;

void setup() {
  //se inicializa el puerto de comunicaciones de la consola de arduino y de la consola del celular con bluetooth
  Serial.begin(9600);
  SerialBT.begin("ESP32_Hz");
  
  //se declaran los pines de entrada o de salida
  pinMode(buzzer, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  pinMode(pir, INPUT);

  //se esperan 10 segundos para que el MQ2 se caliente y mida bien con temperatura constante
  Serial.println("MQ2 se está calentando");
  delay(10000);
}
void loop() {
  //se almacena la lectura del pin del MQ2 en la variable sensorValue
  sensorValue = analogRead(MQ2pin);

  //se lee el valor del PIR y se lo almacena en la variable pirValue
  pirValue = digitalRead(pir);
  delay(10);

  //se revisa si el sensor PIR detecta algo
  if (pirValue == HIGH and alarm2en == 1){         
    alarma2=1;

    //si detectó algo envía el mensaje movimiento detectado a la consola de arduino y bluetooth
    if (pirState == LOW){
      Serial.println("¡Movimiento detectado!");
      SerialBT.println("¡Movimiento detectado!");
      pirState = HIGH;
    }
  } 

  //si el valor de sensor MQ2 pasa los 1200, la alarma de intrusos está desactivada (para que no se superpongan) y el habilitador está activo
  //se activa la alarma de gases junto con los mensajes que se envían a la consola bluetooth de la alerta de gases peigrosos
  if (sensorValue > 1200 and alarma2 == 0 and alarmen == 1){
    alarma=1;
    alarmagases=1;
  }

  //si alarma es 1 el buzzer hace un tono de 1000hz por 100ms, para por 10ms y se repite hasta que alarma = 0
  if (alarma == 1){
    tone(buzzer,1000);
    delay(150);
    noTone(buzzer);
    delay(10);
  }

  //si alarma2 es 1 y alarma es 0 para que no se superpongan, el buzzer hace un tono de 1500hz por 50ms, para por 10ms y se repite hasta que alarma2 = 0
  if (alarma2 == 1 and alarma == 0){
    tone(buzzer,1500);
    delay(50);
    noTone(buzzer);
    delay(10);
  }

  if (alarmagases == 1 && datos9 == false){
    r1=0;
    SerialBT.println ("ALERTA DE GASES PELIGROSOS");
    datos8 = false;
    datos9 = true;
  }

  if (alarmagases == 0 && datos8 == false){
    r1=1;
    datos9 = false;
    datos8 = true;
  }

  //si la variable r1 está activada se manda una señal alta al pin relay1 y se envía un mensaje de que se activó el extractor
  if (r1 == 1 && datos4 == false){
    digitalWrite(relay1, HIGH);
    SerialBT.println("Extractor desactivado");
    datos5 = false;
    datos4 = true;
  }

  //si la variable r1 está desactivada se manda una señal baja al pin relay1 y se envía un mensaje de que se desactivó el extractor
  if (r1 == 0 && datos5 == false){
    digitalWrite(relay1, LOW);
    SerialBT.println("Extractor activado");
    datos4 = false;
    datos5 = true;
  }

  //si la variable r2 está activada se manda una señal alta al pin relay2 y se envía un mensaje de que se activaron las luces
  if (r2 == 1 && datos6 == false){
    digitalWrite(relay2, HIGH);
    SerialBT.println("Luz apagada");
    datos7 = false;
    datos6 = true;
  }

  //si la variable r2 está desactivada se manda una señal baja al pin relay2 y se envía un mensaje de que se desactivaron las luces
  if (r2 == 0 && datos7 == false){
    digitalWrite(relay2, LOW);
    SerialBT.println("Luz encendida");
    datos7 = true;
    datos6 = false;
  }

  if (alarmen == 1 && datos0 == false){
    SerialBT.println("Sensor de gases habilitado");
    datos0 = true;
    datos1 = false;
  }

  if (alarmen == 0 && datos1 == false){
    SerialBT.println("Sensor de gases deshabilitado");
    datos1 = true;
    datos0 = false;
  }

  if (alarm2en == 1 && datos2 == false){
    SerialBT.println("Sensor de movimiento habilitado");
    datos2 = true;
    datos3 = false;
  }

  if (alarm2en == 0 && datos3 == false){
    SerialBT.println("Sensor de movimiento deshabilitado");
    datos3 = true;
    datos2 = false;
  }

  //en toda esta sección se establece que si las variables superan el 1 pasen a 0 para hacer 1 y 0 como un interruptor de un botón
  if (alarma > 1){
    alarma = 0;
  }

  if (alarma2 > 1){
    alarma2 = 0;
    pirState = 0;
  }
  
  if (alarmen > 1){
    alarmen = 0;
  }

  if (alarm2en > 1){
    alarm2en = 0;
  }
  if (r1 > 1){
    r1 = 0;
  }

  if (r2 > 1){
    r2 = 0;
  }

  //si está habilitado el puerto de comunicaciones bluetooth previamente activado se inicializa
  if (SerialBT.available()) {

    //se declara la variable mensaje en la unidad char en vez de int para guardar el dato de lectura que se envia desde el celular
    char Mensaje = SerialBT.read();

    //si el mensaje enviado del celular es tal suma 1 a ese tal, al igual que un tal = tal+1 y esto funciona como un botón con activado y desactivado
    if (Mensaje == 'a'){
      r1++;     
    }
    if (Mensaje == 'b'){
      r2++;
    }
    if (Mensaje == 'c') {
      alarmen++;
    }
    if (Mensaje == 'd') {
      alarm2en++;
    }
    if (Mensaje == 'e') {
      alarma++;
      alarmagases = 0;
    }
    if (Mensaje == 'f') {
      alarma2++;
    }
    if (Mensaje == 'g') {
      SerialBT.println(sensorValue);
    }
   }
  }
