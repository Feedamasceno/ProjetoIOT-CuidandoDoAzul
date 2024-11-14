# Projeto de monitoramento de turbidez e pH com ESP32 e MQTT

Este projeto monitora parâmetros de turbidez e pH utilizando um dispositivo ESP32 e envia dados para um broker MQTT, onde podem ser processados e visualizados em dashboards.

## Descrição do projeto
O sistema mede a turbidez e o pH de uma solução e envia as leituras para um broker MQTT, utilizando a plataforma de programação "low code" Node-RED para processar e exibir os dados em um dashboard.

### Funcionalidades
- Monitoramento de turbidez e pH com o ESP32.
- Transmissão dos dados para um broker MQTT (HiveMQ).
- Integração com Node-RED para exibição em tempo real.

## Estrutura do repositório
- `codigofonte-mqtt/`: Código fonte do ESP32 para realizar a leitura dos sensores e enviar os dados via MQTT.
- `codigolowcode-nodered/`: Código JSON exportado do Node-RED, que contém o fluxo utilizado para o monitoramento.

## Código fonte do dispositivo
O código do dispositivo (ESP32) conecta-se ao Wi-Fi e a um broker MQTT, realizando leituras dos sensores de turbidez e pH e publicando os valores.

### Dependências
- Biblioteca WiFi.h
- Biblioteca PubSubClient.h

## Código fonte da plataforma "Low Code"
O código da plataforma "low code" é um fluxo JSON exportado do Node-RED, que configura o recebimento dos dados do MQTT e exibe os valores em um dashboard.

## Como usar
1. Carregue o código do ESP32 a partir de `codigofonte-mqtt/sketch.ino`.
2. Importe o fluxo JSON em `codigolowcode-nodered/fluxo_node_red.json` para o Node-RED.
3. Configure o Node-RED para conectar-se ao broker MQTT e exibir os dados.
