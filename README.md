# SOGame : Space Survivor

Game developed to SSC0140 Operating Systems classes in the University Of São Paulo. The task was to create a simple game from scratch and apply concepts - threads 
and semaphores - to its implementation.

## Portuguese version:

## Alunos 
 * [Diógenes da Silva Pedro](https://github.com/DioPedro) - nUSP: 11883476
 * [João Victor Sene Araújo](https://github.com/JoaoVSene) - nUSP: 11796382
 * [Pedro Augusto Ribeiro Gomes](https://github.com/pedroaurgomes) - nUSP: 11819125

## Manual

### 1. Como instalar

0. O jogo foi desenvolvido e concebido para ser executado em um Sistema Operacional Linux. Caso você não o tenha nativamente em seu computador, considere instalar uma máquina virtual, como a [VirtualBox](https://www.virtualbox.org/).

1. Certifique-se de que os seguintes programas estão instalados: <br>
 &nbsp;&nbsp;&nbsp; make; <br>
 &nbsp;&nbsp;&nbsp;git; <br>
 &nbsp;&nbsp;&nbsp;g++.<br>

2. Baixe as bibliotecas necessárias:<br>

  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sudo apt install libsdl2-dev <br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sudo apt install libsdl2-image-dev<br>
  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sudo apt install libsdl2-ttf-dev<br>
  
3. Clone este repositório para a sua máquina local.<br>
4. Entre no diretório src/ e execute o comando "make" para compilar o programa e depois execute "make run" para rodar o jogo.<br>

### 2. Como jogar

**Objetivo**: Sobreviver no espaço o máximo que puder, evitando os asteróides e acumulando pontos no score.

**Controles**: <br>
  &rarr; Utilize as teclas "a" e "d" para mover a nave para a esquerda e para a direita, respectivamente;<br>
  &rarr; Use a barra de espaço para tornar a nave instangível por um curto espaço de tempo. Cuidado, pois a habilidade só ficará disponível novamente após alguns segundos de carregamento;<br>
  &rarr; Na tela de Game Over, o jogador deve pressionar "r" para começar uma nova partida.<br>

**Observações**:<br>
  &rarr; Ao colidir com um asteróide, o jogador perde o jogo;<br>
  &rarr; A cada segundo é somado um ponto ao score do jogador;<br>
  &rarr; Quando a nave estiver intangível e o jogador ousar passar por um asteróide, ele ganhará uma grande quantidade de pontos rapidamente;<br>
  &rarr; A quantidade de pontos que o jogador ganha ao atravessar um asteróide no modo intangível é proporcional ao tempo que ele ficar na mesma posição que o asteróide. Ou seja, enquanto estiver sobrepondo o asteróide, o score será incrementado, e portanto, quanto mais tempo o jogador passar nessa situação, mais pontos ele ganhará. Porém, se a nave voltar a se tornar tangível enquanto estiver sobre um asteróide, ela colidirá e o jogador perderá.<br>
 

### 3. Aplicação dos conceitos de Threads e Semáforos no jogo
<p>No Game Loop do jogo, mais especificamente na função Update(), há uma função para verificar a colisão da nave com um asteróide e , se o jogador estiver intangível, somar pontos ao score - checkCollision() - e há também uma outra função que soma 1 ponto ao score a cada segundo passado - scoreByTime().</p>
  
<p>Com o objetivo de paralelizar esses procedimentos e consequenetemente otimizar a execução do programa, criamos duas threads e colocamos cada uma dessas funções para executar em uma delas. Dessa forma, a verificação de colisão é feita em uma thread, o incremento do score por segundo é feito em outra, e o resto das ações em Update() são performadas na thread principal.</p>
  
<p>No entanto, tanto a função checkCollision(), quanto a função scoreByTime() acessam a variável estática score - da classe Score - para somarem pontos à pontuação total do jogador. Sendo assim, tal variável é uma região crítica, e por isso deve haver um mecanismo para evitar as condições de corrida. Para resolver esse problema, criamos um semáforo Mutex para efetuar a Exclusão Mútua. Dessa forma, no momento que o jogador está ganhando pontos por estar sob um asteroide no modo intangível, a função checkCollision() que está em uma thread, tranca o semáforo, o que faz com que nenhuma outra função possa acessar a variável score simultaneamente. Ao terminar de incrementar a variável, o semáforo é destrancado. O mesmo ocorre a cada segundo quando a função scoreByTime(), que está em outra thread, acessa o score para incrementar um ponto em seu valor; primeiramente ela tranca o semáforo, impedindo que qualquer outra thread interfira em seu valor , realiza a operação de incremento,e em seguida destranca o semáforo, liberando a variável para novas alterações.</p>

