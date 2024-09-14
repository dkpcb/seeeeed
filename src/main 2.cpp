#include <Arduino.h>
#include "utils/Config.h"  // 設定ファイルのインクルード
#include "CAN_73/CAN_73.h"

CAN_73 can;

void setup() {
    can.begin((gpio_num_t)CAN_RX, (gpio_num_t)CAN_TX, BoardId::REAL_TIME_VIDEO);
  // UART通信の初期化（Raspberry Piとの通信）
  Serial1.begin(UART_BAUD_RATE, SERIAL_8N1, UART_RX, UART_TX);
  
  // デバッグ用シリアル（PCとの通信）
  Serial.begin(115200);

  Serial.println("Setup complete. Ready to relay commands.");
}

void loop() {
  // 通信基板（com）からのコマンドを受け取り、Raspberry Piに中継
  if (can.available()) {
    char command = can.read();  // 通信基板からのコマンドを受信
    Serial1.print(command);  // Raspberry Piにコマンドを中継
    Serial.print("Sent to Raspberry Pi: ");
    Serial.println(command);
  }

  // Raspberry Piからの応答を受け取り、通信基板に中継
  if (Serial1.available()) {
    char response = Serial1.read();  // Raspberry Piからの応答を受信
    Serial.print("Received from Raspberry Pi: ");
    Serial.println(response);
    can.write(BoardId::COMMUNICATION, response);  // 通信基板に応答を中継
  }

  delay(100);  // 少し待機して負荷を軽減
}
