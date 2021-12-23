# SOGame : Space Survivor

Game developed to SSC0140 Operating Systems classes in the University Of São Paulo. The task was to create a simple game from scratch and apply concepts - threads 
and semaphores - to its implementation.

## Portuguese version:

## Alunos 
 * [Diógenes da Silva Pedro](https://github.com/DioPedro) - nUSP:
 * [João Victor Sene Araújo](https://github.com/JoaoVSene) - nUSP:
 * [Pedro Augusto Ribeiro Gomes](https://github.com/pedroaurgomes) - nUSP: 11819125

## Manual

### 1. Como instalar

0. O jogo foi desenvolvido e concebido para ser executado em Sistema Operacional Linux. Caso, você não o tenha nativamente em seu computador, considere instalar uma máquina virtual como [VirtualBox](https://www.virtualbox.org/).

1. Primeiramente, baixe as bibliotecas necessárias:<br>

  sudo apt install libsdl2-dev <br>
  sudo apt install libsdl2-image-dev<br>
  sudo apt install libsdl2-ttf-dev<br>
  
2. Em seguida, clone este repositório para a sua máquina local.<br>
3. Então, entre no diretório src/ e execute o comando "make" para compilar o programa e depois execute "make run" para rodar o jogo.<br>

### 2. Como jogar

**Objetivo**: Sobreviver no espaço o máximo que puder, evitando os asteróides e acumulando pontos no score.

**Controles**: <br>
  => Utilize as teclas "a" e "d" para mover a nave para a esquerda e para a direita, respectivamente;<br>
  => Use a barra de espaço para tornar a nave instangível por um curto espaço de tempo. Cuidado, pois a habilidade só ficará disponível novamente após alguns segundos de carregamento;<br>
  => Na tela de Game Over, o jogador deve pressionar "r" para começar uma nova partida.<br>

**Observações**:<br>
  => Ao colidir com um asteróide, o jogador perde o jogo;<br>
  => A cada segundo é somando um ponto ao score do jogador;<br>
  => Quando a nave estiver intangível e o jogador ousar passar por um asteróide, ele ganhará uma grande quantidade de pontos rapidamente;<br>
  => A quantidade de pontos que o jogador ganha ao atravessar um asteróide no modo intangível é proporcional ao tempo que ele ficar na mesma posição que o asteróide. Ou seja, enquanto estiver sobrepondo o asteróide, o score será incrementado, e portanto, quanto mais tempo o jogador passar nessa situação, mais pontos ele ganhará. Porém, se a nave voltar a se tornar tangível enquanto estiver sobre um asteróide, ela colidirá e o jogador perderá.<br>
 

### 3. Aplicação dos conceitos de Threads e Semáforos no jogo
