# SOGame : Space Survivor

Game developed to SSC0140 Operating Systems classes in the University Of São Paulo. The task was to create a simple game from scratch and apply concepts - threads 
and semaphores - to its implementation.

## Portuguese version:

## Alunos 
 * Diógenes da Silva Pedro - nUSP:
 * João Victor Sene Araújo - nUSP:
 * Pedro Augusto Ribeiro Gomes - nUSP: 11819125

## Manual

### 1. Como instalar

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
