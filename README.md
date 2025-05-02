# Facebook Captive Portal Fake Login  
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)  
![Platform](https://img.shields.io/badge/platform-ESP8266-orange.svg) 
![HTML](https://img.shields.io/badge/frontend-Fake%20Facebook%20UI-blue)

## Description  
This project creates a **fake Facebook login page** using the ESP8266 in Access Point (AP) mode. When users connect to the WiFi network, they are redirected to a custom login page mimicking Facebook’s interface. The credentials are captured and displayed locally.

> **Disclaimer**: This project is for educational purposes only. Do not use it for unauthorized activities.

---

## Features  
- Fake Facebook login form  
- Captures and stores credentials in memory (up to 10 entries)  
- DNS spoofing for redirecting all URLs to the fake portal  
- Blinks built-in LED upon each credential submission  
- Minimal and mobile-friendly HTML/CSS layout  

---

---

## Setup Instructions  

1. **Requirements**  
   - ESP8266 (e.g., NodeMCU, Wemos D1 mini)  
   - Arduino IDE with ESP8266 board support  
   - Required libraries:  
     - `ESP8266WiFi`  
     - `ESP8266WebServer`  
     - `DNSServer`  

2. **Installation Steps**  
   - Clone or download this repo  
   - Open `main.ino` from `src/` in Arduino IDE  
   - Select the correct board and COM port  
   - Upload the code  
   - Open Serial Monitor to debug  

3. **Operation**  
   - Connect to the WiFi named `Facebook Free WiFi`  
   - Any URL will redirect to a Facebook-like login  
   - Entering credentials will blink the onboard LED  
   - To view captured credentials, visit: `http://192.168.4.1/pass`  

---

## Demo Screenshot  

![Demo Login Portal](docs/example.png)

---

## About  
This project demonstrates how a **captive portal phishing method** works using microcontrollers and embedded servers. It can be used for:  
- Security education  
- Demonstration of ethical hacking techniques  
- IoT web interfaces  

**Author:** *Kayes Azam*  
**License:** MIT  

---

> **NOTE**: Avoid using this on real users. Always test ethically and responsibly.