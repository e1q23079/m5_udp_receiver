# M5StickC UDP Receiver

M5StickCをUDP受信機として使用するプロジェクトです。UDPパケットを受信してLEDを制御します。

## 概要

このプロジェクトは、M5StickCをWi-Fiアクセスポイントとして動作させ、UDPパケットを受信してLEDを制御するシンプルなアプリケーションです。

## 機能

- M5StickCがWi-Fiアクセスポイントとして動作
- UDPポート3000でパケットを受信
- '1'を受信するとLEDを1秒間点灯

## 必要な機材

- M5StickC
- USB-Cケーブル

## 開発環境

- PlatformIO
- Arduino Framework
- ESP32プラットフォーム

## 依存ライブラリ

- M5Unified (^0.2.7)

## セットアップ

1. リポジトリをクローン

```bash
git clone <repository-url>
cd m5_udp_receiver
```

2. PlatformIOでビルド

```bash
pio run
```

3. M5StickCにアップロード

```bash
pio run --target upload
```

## 使い方

1. M5StickCに書き込み後、自動的にアクセスポイントとして起動します
2. ディスプレイに以下の情報が表示されます:
   - SSID: `sample`
   - PASSWORD: `samplePassword`
   - IPアドレス

3. デバイスをM5StickCのアクセスポイントに接続

4. UDPパケットを送信してLEDを制御

```bash
# Linuxの場合
echo -n "1" | nc -u <M5StickCのIPアドレス> 3000
```

## 設定変更

`src/main.cpp`の以下の定数を変更することで設定をカスタマイズできます:

```cpp
const char SSID[] = "sample";          // アクセスポイントのSSID
const char PASSWORD[] = "samplePassword"; // アクセスポイントのパスワード
const int port = 3000;                    // UDPポート番号
```

## ハードウェア仕様

- ボード: M5StickC
- LED: GPIO10
