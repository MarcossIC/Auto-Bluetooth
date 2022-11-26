//Marcos Lopez 5 Año E 2021 EPET4

//Librerias necesarias para hacer el codigo
#include <SoftwareSerial.h>

// CONEXIONES PARA EL BLUETOOTH.

    int bluetoothTx = 3;
    int bluetoothRx = 4;

SoftwareSerial miBT(bluetoothTx, bluetoothRx);

    // MOTOR 1.

int Motor1A = 9;
int Motor1B = 10;

// MOTOR 2.

int Motor2A = 6;
int Motor2B = 5;

void setup (){
  //Configura el bluetooth
    miBT.begin(115200);
    miBT.print("$$$");
    delay(100);
    miBT.println("U,9600,N");
    miBT.begin(9600);

//Decide que los pines son de salida
    pinMode( Motor1A, OUTPUT );
    pinMode( Motor2A, OUTPUT );
    pinMode( Motor1B, OUTPUT );
    pinMode( Motor2B, OUTPUT );
//Desactiva todos los pines
    digitalWrite( Motor1A, LOW );
    digitalWrite( Motor2A, LOW );
    digitalWrite( Motor1B, LOW );
    digitalWrite( Motor2B, LOW );
}

void loop(){
  //Este if mira si el bluetooth esta activo o no, si esta activo entra si no no entra
  if(miBT.available()){
    //Recupera el valor del boton que presionaste
      char botonPresionado = (char)miBT.read();
      //le paso el valor del boton y decide que accion debe hacer
      switch(botonPresionado){
        //  EL AUTO PARA
        case 'S':
            digitalWrite( Motor1A, LOW);
            analogWrite( Motor1B, LOW);
            digitalWrite( Motor2A, LOW),
            analogWrite( Motor2B, LOW);
        break;
        // EL AUTO VAYA HACIA ADELANTE
        case 'F':
            digitalWrite( Motor1A, HIGH );
            digitalWrite( Motor1B, HIGH);
            digitalWrite( Motor2A, HIGH);
            digitalWrite( Motor2B, HIGH );
        break;
        //EL AUTO VAYA HACIA ADELANTE Y A LA IZQUIERDA
        case 'G':      
            digitalWrite( Motor1A, HIGH);
            digitalWrite( Motor1B, HIGH );
            digitalWrite( Motor2A, HIGH);
            analogWrite( Motor2B, LOW );   
        break;
        // EL AUTO VAYA HACIA ADELANTE Y A LA DERECHA
        case 'I':
            analogWrite( Motor1A, LOW );
            analogWrite( Motor1B, LOW);
            digitalWrite( Motor2A, HIGH);
            digitalWrite( Motor2B, HIGH );        
        break;
        // EL AUTO VAYA EN REVERSA
        case 'B':
            digitalWrite( Motor1A, HIGH );
            analogWrite( Motor1B, LOW);
            analogWrite( Motor2A, LOW);
            digitalWrite( Motor2B, HIGH );
        break;
        // EL AUTO VAYA EN REVERSA Y A LA IZQUIERDA
        case 'H':   
            analogWrite( Motor1A, LOW);
            analogWrite( Motor1B, LOW );
            analogWrite( Motor2A, LOW);
            digitalWrite( Motor2B, HIGH );           
        break;
        // EL AUTO VAYA EN REVERSA Y A LA DERECHA
        case 'J':
            digitalWrite( Motor1A, HIGH );
            analogWrite( Motor1B, LOW);
            analogWrite( Motor2A, LOW);
            analogWrite( Motor2B, LOW );  
        break;
        // EL AUTO VAYA HACIA LA IZQUIERDA
        case 'L':
            analogWrite( Motor1A, LOW);
            analogWrite( Motor1B, LOW );
            analogWrite( Motor2A, LOW);
            digitalWrite( Motor2B, HIGH );
        break;
        // EL AUTO VAYA HACIA LA DERECHA
        case 'R':
            digitalWrite( Motor1A, HIGH );
            analogWrite( Motor1B, LOW);
            analogWrite( Motor2A, LOW);
            analogWrite( Motor2B, LOW );
        break;
    } 
  }
}
