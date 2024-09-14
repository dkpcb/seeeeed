#pragma once

#include <Arduino.h>

// CAN設定
/** CAN RX */
const int CAN_RX = D1;
/** CAN TX */
const int CAN_TX = D0;

// UART設定
/** UART RX */
const int UART_RX = D7;
/** UART TX */
const int UART_TX = D6;
/** UART ボーレート */
const int UART_BAUD_RATE = 9600;