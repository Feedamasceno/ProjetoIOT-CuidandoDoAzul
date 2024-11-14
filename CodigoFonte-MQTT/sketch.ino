#include <WiFi.h>
#include <PubSubClient.h>

// Definir as credenciais do Wi-Fi e do broker MQTT
const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char* mqttClientId = "mqtt-mack-pub-sub";

// Pinos dos sensores
const int turbidezPin = 34;
const int phPin = 35;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  
  // Conectar ao Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi!");
  
  // Conectar ao broker MQTT
  client.setServer(mqttServer, mqttPort);
  while (!client.connected()) {
    if (client.connect(mqttClientId)) {
      Serial.println("Conectado ao broker MQTT");
    } else {
      delay(1000);
      Serial.println("Tentando conectar ao broker MQTT...");
    }
  }
}

void loop() {
  // Leitura dos sensores
  int turbidezValor = analogRead(turbidezPin);
  int phValor = analogRead(phPin);

  // Conversão dos valores
  float turbidez = (turbidezValor / 1023.0) * 100;
  float pH = map(phValor, 0, 1023, 0, 14);
  
  // Enviar dados via MQTT
  client.publish("TESTMACK10408854/Turbidez", String(turbidez).c_str());
  client.publish("TESTMACK10408854/pH", String(pH).c_str());
  
  // Imprimir valores no Serial Monitor
  Serial.print("Turbidez: ");
  Serial.print(turbidez);
  Serial.print(" NTU, pH: ");
  Serial.println(pH);
  
  // Manter a conexão MQTT
  client.loop();
  
  // Aguardar 1 segundo antes de ler novamente
  delay(1000);
}
