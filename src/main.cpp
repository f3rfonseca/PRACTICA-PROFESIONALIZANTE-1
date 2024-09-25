#include <WiFi.h>
#include <Wire.h>
#include <Arduino.h>

WiFiClient cliente; // Clase WiFiClient para establecer la comunicación
int pinsensorPH = 33; // Pin asignado para el sensor de pH

void setup() {
  Serial.begin(115200); // Inicialización de la comunicación serial
  delay(1000);
  Serial.print("Conectando a la red WiFi");
  
  // Conectar a la red WiFi
  WiFi.begin("Wokwi-GUEST", "", 6); // Reemplazar con las credenciales correctas
  
  // Esperar a que la conexión WiFi se establezca
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  } 

  Serial.println("\nConectado a WiFi!");
  pinMode(pinsensorPH, INPUT); // Configurar el pin del sensor como entrada
}

void loop() {
  int lecturaPH = analogRead(pinsensorPH); // Leer el valor del sensor de pH
  float voltaje = lecturaPH * (3.3 / 4095.0); // Convertir la lectura en voltaje
  float ph = voltaje * 3.5; // Conversión de voltaje a un valor aproximado de pH
  
  Serial.print("Valor de pH: ");
  Serial.println(ph); // Mostrar el valor de pH en la consola
  
  delay(1000); // Esperar 1 segundo antes de la próxima lectura

  // Ejemplo de implementación de protocolo MQTT
  // mqttClient.publish("sensor/ph", String(ph).c_str());
}
dhcps_dns_setserverdsds
ds
ds