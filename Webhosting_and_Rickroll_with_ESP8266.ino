#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void handleHomePage() {
  String html = "<html><body>";
  html += "<h1>Welcome to Home Page</h1>";
  html += "<button onclick=\"location.href='/about'\">Go to About</button>";
  html += "<button onclick=\"location.href='/contact'\">Go to Contact</button>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleAboutPage() {
  String html = "<html><body>";
  html += "<h1>About Page</h1>";
  html += "<button onclick=\"location.href='https://www.youtube.com/watch?v=dQw4w9WgXcQ'\">Go to Home</button>";
  html += "<button onclick=\"location.href='/contact'\">Go to Contact</button>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void handleContactPage() {
  String html = "<html><body>";
  html += "<h1>Contact Page</h1>";
  html += "<button onclick=\"location.href='https://www.youtube.com/watch?v=dQw4w9WgXcQ'\">Go to Home</button>";
  html += "<button onclick=\"location.href='/about'\">Go to About</button>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);

  Serial.begin(74880);
  WiFi.begin("WI-FI SSID", "Password");           /*enter the wifi ssid and the password*/

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.println("Connecting to WiFi...");
    digitalWrite(LED_BUILTIN,HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN,LOW);
     delay(10);


  }

  Serial.println("WiFi connected");
  
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleHomePage);
  server.on("/about", handleAboutPage);
  server.on("/contact", handleContactPage);

  server.begin();
}

void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  server.handleClient();
}
