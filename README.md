# 🕹️ Arcade Retrô com Arduino

Projeto desenvolvido para a disciplina de Sistemas Digitais da CESAR School com o objetivo de construir um fliperama funcional utilizando Arduino como interface de controle para jogos de arcade executados no computador.

## 📖 Sobre o projeto

O Arcade Retrô consiste em um gabinete equipado com joystick e botões para dois jogadores, proporcionando uma experiência inspirada nos fliperamas clássicos.

O sistema utiliza dois Arduinos Nano ESP32, responsáveis pela leitura dos comandos dos controles e envio das entradas ao computador. Os jogos são executados por meio do emulador MAME em um monitor convencional.

## 🚀 Tecnologias utilizadas

- Arduino Nano ESP32
- C++
- Arduino IDE
- Python
- Comunicação Serial
- MAME Emulator

## ⚙️ Funcionalidades

- Controle para dois jogadores
- Leitura de joystick e botões
- Comunicação serial entre Arduino e computador
- Integração com o emulador MAME
- Estrutura física de um fliperama funcional

## 🏗️ Arquitetura

O projeto é composto por:

- Arduino do Jogador 1
- Arduino do Jogador 2
- Script em Python responsável por receber os comandos enviados pelos Arduinos e convertê-los em entradas reconhecidas pelo computador
- Emulador MAME para execução dos jogos

### Fluxo de funcionamento

```text
Joystick/Botões
        │
        ▼
Arduino Nano ESP32
        │
 Comunicação Serial (USB)
        │
        ▼
Script em Python
        │
        ▼
MAME
        │
        ▼
Jogo
```

## 📂 Estrutura do projeto

```text
📦 Arcade
 ├── FliperamaArcade_P1.ino/
 ├── FliperamaArcade_P2.ino/
 ├── ponte_mame.py/
 ├── Imagens/
 └── README.md
```

## 🎓 Objetivos de aprendizagem

Durante o desenvolvimento foram aplicados conceitos de:

- Sistemas Digitais
- Programação embarcada
- Comunicação serial
- Integração entre hardware e software
- Desenvolvimento em C++ para Arduino
- Programação em Python
- Trabalho em equipe

## 📸 Demonstração

<img src="https://github.com/giimvm/magic-arcade/blob/main/imagens/imagem1.jpeg" width="300"> <img src="https://github.com/giimvm/magic-arcade/blob/main/imagens/imagem2.jpeg" width="300">
<img src="https://github.com/giimvm/magic-arcade/blob/main/imagens/imagem3.jpeg" width="300">

## 👥 Equipe

Projeto desenvolvido como atividade da disciplina de Sistemas Digitais da CESAR School.

<img src="https://github.com/giimvm/magic-arcade/blob/main/imagens/equipe.jpeg" width="400">
