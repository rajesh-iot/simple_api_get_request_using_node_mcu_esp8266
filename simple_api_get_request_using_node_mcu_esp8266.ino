#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";
const char* apiUrl = "http://example.com/api";

void setup() {
  Serial.begin(115200);
  delay(10);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    // Set up the GET request URL
    String url = apiUrl + "?param1=value1&param2=value2";
    
    http.begin(url);
    
    int httpResponseCode = http.GET();
    
    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("HTTP Response: " + response);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  }
  
  delay(5000); // Wait for 5 seconds before sending the next request
}
