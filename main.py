from machine import Pin  # Importa controle de pinos digitais (Pin)
import time              # Importa biblioteca de tempo (para delay))

# configuração de saidas dos pinos  (Leds)
led_vermelho = Pin(15, Pin.OUT)
led_amarelo  = Pin(16, Pin.OUT)
led_verde    = Pin(17, Pin.OUT)  

# configuração de entradas (Botoes Push buttons)
botao_1 = Pin(25, Pin.IN, Pin.PULL_UP)
botao_2 = Pin(26, Pin.IN, Pin.PULL_UP)
botao_3 = Pin(27, Pin.IN, Pin.PULL_UP)

# Como usamos Pull-Up, a lógica é invertida:
# 0 = Pressionado (GND)
# 1 = Solto (3.3V)

# Leitura do Estado de um loop infinito 
while True:
    # condição1 : se o Botão1(Verde) pressionado o led Verde acende 
    estado = botao_1.value()  
    if estado == 0:     
        led_verde.on() 
    else:
        led_verde.off()

    # condição2: se o Botão2(Azul) pressionado o led Verde e o led Amarelo acendem  
    estado = botao_2.value()
    if estado == 0:
        led_verde.on()
        led_amarelo.on()
    else:
        led_verde.off()
        led_amarelo.off()
        
    # condição3: se o Botão3(Amarelo) pressionado acendem todos os Leds 
    estado = botao_3.value()
    if estado == 0:
        led_verde.on()
        led_amarelo.on()
        led_vermelho.on()
    else:
        led_verde.off()
        led_amarelo.off()
        led_vermelho.off()
    # Pequena pausa para não sobrecarregar a CPU 
    time.sleep(0.01)



    

