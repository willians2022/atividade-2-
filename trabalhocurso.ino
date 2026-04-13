
#define Botao_Verde     D3
#define Botao_Vermelho  D4
#define Botao_Amarelo   D5

#define Led_verde       D6
#define Led_amarelo     D7
#define Led_vermelho    D8

void setup() {

  // ===== LEDs =====
  
  pinMode(Led_verde, OUTPUT);
  pinMode(Led_amarelo, OUTPUT);
  pinMode(Led_vermelho, OUTPUT);

  // ===== BOTÕES =====
  pinMode(Botao_Verde, INPUT_PULLUP);
  pinMode(Botao_Amarelo, INPUT_PULLUP);
  pinMode(Botao_Vermelho, INPUT_PULLUP);
}

void loop() {

  // ===== LEITURA DOS BOTÕES =====
  int bVerde     = digitalRead(Botao_Verde);
  int bAmarelo   = digitalRead(Botao_Amarelo);
  int bVermelho  = digitalRead(Botao_Vermelho);

  // ===== RESET DOS LEDs =====
  digitalWrite(Led_verde, LOW);
  digitalWrite(Led_amarelo, LOW);
  digitalWrite(Led_vermelho, LOW);

  // ===== LÓGICA =====

  // Botão Verde → LED verde
  if (bVerde == LOW) {
    digitalWrite(Led_verde, HIGH);
  }

  // Botão Amarelo → Verde + Amarelo
  if (bAmarelo == LOW) {
    digitalWrite(Led_verde, HIGH);
    digitalWrite(Led_amarelo, HIGH);
  }

  // Botão Vermelho → Todos os LEDs
  if (bVermelho == LOW) {
    digitalWrite(Led_verde, HIGH);
    digitalWrite(Led_amarelo, HIGH);
    digitalWrite(Led_vermelho, HIGH);
  } 
}