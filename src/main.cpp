#include <WiFi.h>
#include <Wire.h>
#include <Arduino.h>

WiFiClient cliente; // Nombre de clase corregido
int pinsensorPH = 33; // Pin del sensor de pH

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.print("Conectando a la red WiFi");
  
  // Conectar a WiFi
  WiFi.begin("Wokwi-GUEST", "", 6); // Reemplaza con tus credenciales
  
  // Esperar a que se establezca la conexión
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  
  Serial.println("\nConectado a la red WiFi");
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  delay(10); // Acelera la simulación

  // Leer el valor del sensor de pH
  int sensorValue = analogRead(pinsensorPH);
  Serial.print("Valor del sensor pH: ");
  Serial.println(sensorValue);
}