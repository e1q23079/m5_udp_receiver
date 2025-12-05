#include <Arduino.h>
#include <M5Unified.h>
#include <WiFi.h>
#include <WiFiUdp.h>

const char SSID[] = "sample";
const char PASSWORD[] = "samplePassword";

// UDP設定
WiFiUDP wifiudp;
const int port = 3000;

void setup() {
    // セットアップ
    auto cfg = M5.config();
    M5.begin(cfg);
    // アクセスポイント設定
    WiFi.softAP(SSID, PASSWORD);
    // 画面
    M5.Display.setRotation(1);
    M5.Display.setTextSize(2);
    M5.Display.println("receiver");
    M5.Display.printf("SSID:%s\n", SSID);
    M5.Display.printf("PASSWORD:%s\n", PASSWORD);
    M5.Display.println(WiFi.softAPIP());  // ホストIPアドレス
}

void loop() {
    if (wifiudp.parsePacket()) {
        char x;
        x = (char)wifiudp.read();
        if (x == '1') {
            pinMode(10, OUTPUT);  // LED_ON
            sleep(1);
            pinMode(10, HIGH);  // LED_OFF
        }
    }
}