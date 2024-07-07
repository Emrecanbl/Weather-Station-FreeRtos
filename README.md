Weather Station using FreeRTOS
This project is a weather station utilizing the STM32F401 microcontroller, DHT11 sensor, ESP8266 module, and ST7735 SPI screen. The system is implemented using FreeRTOS for task management and communicates via UART. It also retrieves the date and time from the internet using the ESP8266 and provides an internet interface for data access.
**![Sample](https://github.com/Emrecanbl/Weather-Station-FreeRtos/blob/main/appearance.jpg?raw=true)**
Features
STM32F401 Microcontroller: Provides the core processing capabilities.
DHT11 Sensor: Measures temperature and humidity.
ESP8266 Module: Enables Wi-Fi connectivity for data transmission and retrieves date and time from the internet.
ST7735 SPI Screen: Displays sensor data and time information.
FreeRTOS: Manages tasks and ensures efficient real-time operation.
UART Communication: Facilitates communication between the STM32F401 and ESP8266.
Internet Time Synchronization: Automatically retrieves the current date and time from the internet.
Internet Interface: Provides an interface to access data over the internet.
Components
STM32F401 Microcontroller
DHT11 Temperature and Humidity Sensor
ESP8266 Wi-Fi Module
ST7735 SPI Screen
Various peripheral components (e.g., resistors, capacitors)
Installation
Clone the repository:

sh
Kodu kopyala
git clone https://github.com/Emrecanbl/Weather-Station-FreeRtos.git
Open the project:
Open the project in your preferred IDE (e.g., STM32CubeIDE).

Configure the environment:

Ensure that FreeRTOS is properly set up in your project.
Configure the UART settings to match the baud rate and other parameters used by the ESP8266.
Configure the SPI settings for the ST7735 screen.
Compile and upload:
Compile the code and upload it to your STM32F401 microcontroller using a suitable programmer (e.g., ST-Link).

Usage
Power on the weather station:
Ensure that the STM32F401, DHT11 sensor, ESP8266 module, and ST7735 screen are properly powered.

Initialize the system:
The FreeRTOS tasks will start automatically, initializing the DHT11 sensor and establishing UART communication with the ESP8266.

Internet Time Synchronization:
The ESP8266 module will connect to the internet and retrieve the current date and time.

Data Display and Transmission:
The weather station will read temperature and humidity data from the DHT11 sensor, display this data along with the current date and time on the ST7735 screen, and transmit the data via the ESP8266 module.

Internet Interface:
Access the weather station's data over the internet through the ESP8266's web interface.

FreeRTOS Tasks
The project utilizes FreeRTOS to manage multiple tasks:

Sensor Task: Reads data from the DHT11 sensor at regular intervals.
Communication Task: Handles UART communication with the ESP8266 module.
Time Sync Task: Retrieves the current date and time from the internet.
Display Task: Updates the ST7735 screen with sensor data and time information.
Data Processing Task: Processes the sensor data and prepares it for transmission.
Web Server Task: Manages the internet interface and serves data over the web.
Contributions are welcome! If you have any ideas, suggestions, or improvements, feel free to open an issue or submit a pull request.
![Sample](https://github.com/Emrecanbl/Weather-Station-FreeRtos/blob/main/Screenshot_1.jpg?raw=true)
![Sample](https://github.com/Emrecanbl/Weather-Station-FreeRtos/blob/main/Demo.jpg?raw=true)
License
This project is licensed under the MIT License. See the LICENSE file for more details.

Acknowledgments
Special thanks to the open-source community and the developers of the libraries and tools used in this project.
🌦️🚀

