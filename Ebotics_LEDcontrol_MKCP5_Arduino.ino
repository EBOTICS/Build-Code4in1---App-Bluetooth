//PROGRAMA PARA EL CONTROL DE UN LED CON BLUETOOTH

//Cambio de nombre dirección Bluetooth 4in1
char nombre[10] = "4in1_A01"; //Entre comillas: nombre del módulo Bluetooth que podemos personalizar

char password[10] = "0000"; //Entre comillas: contraseña del módulo Bluetooth que podemos personalizar 

char baud = '4'; //4 = 9600 baud

//Variables programa Bluetooth y LED

char data = 0; //Variable de lectura Bluetooth

int PLED = 9; //Puerto de conexión del LED

void setup() {

  Serial.begin(9600); //Abre puerto serial a 9600 bps

  pinMode(13, OUTPUT); //LED placa como salida 
  digitalWrite(13, LOW); //LED placa apagado

  Serial.print("AT"); //Iniciar la configuración
  delay(1000); //Espera 1000 mseg (1 segundo)
   
  Serial.print("AT+NAME"); Serial.print(nombre); //Instrucción que reconoce la placa para cambiar nombre
  delay(1000);
   
  Serial.print("AT+PIN"); Serial.print(password); //Instrucción que reconoce la placa para cambiar contraseña
  delay(1000);   
   
  Serial.print("AT+BAUD"); Serial.print(baud); //Instrucción que reconoce la placa para cambiar baudios
  delay(1000);

  digitalWrite(13, HIGH); //LED placa encendido
  delay(3000);
  digitalWrite(13, LOW); 

  pinMode (PLED, OUTPUT); //LED como salida 
}
void loop() {

// LECTURA DE DATOS POR BLUETOOTH
   
   if (Serial.available() > 0) 
  {
   data = Serial.read(); //Guarda en la variable “data” el dato recibido por Bluetooth

    switch (data){

      case 'A': //LED ON
      
      digitalWrite(PLED, HIGH);
    
      break;

      case 'B': //LED OFF
      
      digitalWrite(PLED, LOW);
    
      break;
     }
   }
}
