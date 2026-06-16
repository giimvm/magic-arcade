// Direções
const int PIN_CIMA = 32; 
const int PIN_BAIXO = 33;
const int PIN_ESQUERDA = 25;
const int PIN_DIREITA = 26;

// Botões
const int PIN_BOTAO_1 = 27;
const int PIN_BOTAO_2 = 14;
const int PIN_BOTAO_3 = 13;
const int PIN_BOTAO_4 = 21;

// Sistema
const int PIN_START = 18;
const int PIN_SELECT = 19;

// Configuração de Debounce:
// Tempo mínimo (em milissegundos) para validar uma mudança
// de estado do botão e evitar múltiplas leituras causadas
// por ruído mecânico (efeito bounce)
const unsigned long debounce = 80;

// Estrutura de Dados dos Botões:
// Estrutura que armazena todas as informações necessárias
// para controlar cada botão do arcade
struct Botao {
  // Pino físico conectado ao botão
  int pino;
  // Nome do comando que será enviado ao PC
  String comando;
  // Último estado lido do botão
  bool estadoAnterior;
  // Momento da última alteração válida
  unsigned long ultimoTempo;
};

// Vetor com Todos os Controles:
// Cada posição representa um controle do jogador 1

Botao botoes[] = {
  // Direções
  {PIN_CIMA, "P1_UP", HIGH, 0},
  {PIN_BAIXO, "P1_DOWN", HIGH, 0},
  {PIN_ESQUERDA, "P1_LEFT", HIGH, 0},
  {PIN_DIREITA, "P1_RIGHT", HIGH, 0},

  // Botões de ação
  {PIN_BOTAO_1, "P1_B1", HIGH, 0},
  {PIN_BOTAO_2, "P1_B2", HIGH, 0},
  {PIN_BOTAO_3, "P1_B3", HIGH, 0},
  {PIN_BOTAO_4, "P1_B4", HIGH, 0},

  // Botões de sistema
  {PIN_START, "P1_START", HIGH, 0},
  {PIN_SELECT, "P1_SELECT", HIGH, 0}
};

// Quantidade Total de Controles
// Calcula automaticamente quantos elementos existem
// dentro do vetor "botoes"

const int quantidade = sizeof(botoes) / sizeof(botoes[0]);

// Função de Envio de Comandos:

// Envia uma mensagem pela porta serial
void enviar(String texto) {
  // Transmite o texto e pula para a próxima linha
  Serial.println(texto);
}

// Configuração Inicial

void setup() {
  // Inicia comunicação serial a 115200 bps
  Serial.begin(115200);
  // Percorre todos os controles cadastrados
  for (int i = 0; i < quantidade; i++) {
    // Configura cada pino como entrada com resistor pull-up interno
    pinMode(botoes[i].pino, INPUT_PULLUP);
    // Armazena o estado inicial do botão
    botoes[i].estadoAnterior = digitalRead(botoes[i].pino);
  }
  // Mensagem indicando que o sistema está pronto
  Serial.println("Arcade P1 pronto");
}

// Loop Principal:

void loop() {
  // Verifica continuamente todos os controles
  for (int i = 0; i < quantidade; i++) {
    // Lê o estado atual do botão
    bool estadoAtual = digitalRead(botoes[i].pino);

    // Verifica se houve mudança de estado
    if (estadoAtual != botoes[i].estadoAnterior) {
      // Aplica o debounce para evitar leituras falsas
      if (millis() - botoes[i].ultimoTempo > debounce) {
        // Atualiza o momento da última alteração válida
        botoes[i].ultimoTempo = millis();
        // Atualiza o estado armazenado
        botoes[i].estadoAnterior = estadoAtual;

        // Como estamos usando INPUT_PULLUP:
        // LOW = botão pressionado
        // HIGH = botão solto

        if (estadoAtual == LOW) {
          // Informa ao computador que o botão foi pressionado
          enviar(botoes[i].comando + "_ON");
        } else {
           // Informa ao computador que o botão foi liberado
          enviar(botoes[i].comando + "_OFF");
        }
      }
    }
  }
}