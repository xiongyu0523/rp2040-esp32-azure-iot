# Azure IoT middleware for Azure RTOS runs on Raspberry Pi RP2040 MCU and Espressif ESP32-C3 SoC

## Introduction

This project is to connect 1$ [Raspberry Pi RP2040](https://www.raspberrypi.org/documentation/microcontrollers/rp2040.html) MCU to Azure IoT by using a [ESP32-C3](https://www.espressif.com/en/products/socs/esp32-c3) SoC as network processor. 

The Application is a standard Azure IoT example built on [Azure IoT middleware for Azure RTOS](https://github.com/azure-rtos/netxduo/blob/master/addons/azure_iot/docs/README.md) and it leverages [LwESP](https://github.com/MaJerle/lwesp) project to get WiFi connectivity support, integrated with NetX Duo 6.1.8 [offload driver](https://docs.microsoft.com/en-us/azure/rtos/netx-duo/chapter5#tcpip-offload-driver-guidance). 

## Hardware

The demo is verified on [Raspberry Pi Pico](https://www.st.com/en/evaluation-tools/b-l4s5i-iot01a.html) and [ESP32-C3-DevKitM-1](https://docs.espressif.com/projects/esp-idf/en/latest/esp32c3/hw-reference/esp32c3/user-guide-devkitm-1.html) hardware, and it can be easily ported to other board like Arduino Nano RP2040 Connect. 

| Signal name | Raspberry Pi Pico | ESP32-C3-DevKitM-1 |
| ---- |  ----  | ---- |
| 3V3  |  | J1-21  |
| GND |    | J1-1   | 
| TX  |  | J3-9 (UART1-RX) | 
| RX  |  | J3-8 (URAT1-TX) | 
| RESET |  | CN1-7 (EN) |

## Prequisite 

ESP32-C3 must be programmed with ESP-AT firmware. Refer to this [link](https://download.espressif.com/esp_at/firmware/ESP32C3/ESP32-C3-MINI-1_AT_Bin_V2.2.0.0.zip) for pre-built binary and document. 

## License

| Components | License
| ---- |  ----  | 
| app  | Refer to [LICENSE](./LICENSE)  |
| lwesp | Refer to [LICENSE](./lwesp/LICENSE)  |
| threadx / netxduo | Refer to [LICENSE.txt](./threadx/LICENSE.txt) and [LICENSED-HARDWARE.txt](./threadx/LICENSED-HARDWARE.txt) | 

> Please be aware that this project is ONLY for demo and study purpose. Azure RTOS does not include a commerical license for Raspberry Pi RP2040 MCU. 

