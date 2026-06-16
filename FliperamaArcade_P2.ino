// Direções
const int PIN_CIMA = 32; 
const int PIN_BAIXO = 33;
const int PIN_ESQUERDA = 25;
const int PIN_DIREITA = 26;

// Botões
const int PIN_BOTAO_1 = 27;
const int PIN_BOTAO_2 = 14;
const int PIN_BOTAO_3 = 21;
const int PIN_BOTAO_4 = 13;

// Sistema
const int PIN_START = 18;
const int PIN_SELECT = 19;

const unsigned long debounce = 80;

struct Botao {
  int pino;
  String comando;
  bool estadoAnterior;
  unsigned long ultimoTempo;
};

Botao botoes[] = {
  {PIN_CIMA, "P2_UP", HIGH, 0},
  {PIN_BAIXO, "P2_DOWN", HIGH, 0},
  {PIN_ESQUERDA, "P2_LEFT", HIGH, 0},
  {PIN_DIREITA, "P2_RIGHT", HIGH, 0},

  {PIN_BOTAO_1, "P2_B1", HIGH, 0},
  {PIN_BOTAO_2, "P2_B2", HIGH, 0},
  {PIN_BOTAO_3, "P2_B3", HIGH, 0},
  {PIN_BOTAO_4, "P2_B4", HIGH, 0},

  {PIN_START, "P2_START", HIGH, 0},
  {PIN_SELECT, "P2_SELECT", HIGH, 0}
};

const int quantidade = sizeof(botoes) / sizeof(botoes[0]);

void enviar(String texto) {
  Serial.println(texto);
}

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < quantidade; i++) {
    pinMode(botoes[i].pino, INPUT_PULLUP);
    botoes[i].estadoAnterior = digitalRead(botoes[i].pino);
  }

  Serial.println("Arcade P2 pronto");
}

void loop() {
  for (int i = 0; i < quantidade; i++) {
    bool estadoAtual = digitalRead(botoes[i].pino);

    if (estadoAtual != botoes[i].estadoAnterior) {
      if (millis() - botoes[i].ultimoTempo > debounce) {
        botoes[i].ultimoTempo = millis();
        botoes[i].estadoAnterior = estadoAtual;

        if (estadoAtual == LOW) {
          enviar(botoes[i].comando + "_ON");
        } else {
          enviar(botoes[i].comando + "_OFF");
        }
      }
    }
  }
}