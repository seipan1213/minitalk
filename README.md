# minitalk
https://user-images.githubusercontent.com/38822155/212701010-8b2e9f28-b66c-4a20-85ba-19e2418343f3.mp4

## 概要
- プロセスIDとシグナルを用いて、文字列の送受信を行うプログラム
- サーバ側とクライアント側で、実行ファイルを起動して通信を行う

## 使い方
```
make

./server
output: [PID]

./client [PID] [Charcter]
```
bonusを付けるととclient側がコネクション結果を出力します。
```
make bonus

./server_bonus
output: [PID]

./client_bonus [PID] [Charcter]
```
