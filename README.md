
# Blackjack Lite using SDL2:

Uma versão leve do jogo Blackjack, popularmente conhecido como vinte e um (21), usando linguagem C e SDL2.

![image](https://github.com/user-attachments/assets/c090245e-f655-4685-ab07-1dc851bab66c)

# Regras:

O objetivo do jogo é chegar aos 21 pontos somando os valores das cartas.
1) O ás vale 1 ou 11 pontos, dependendo da situação;
2) Existem apenas duas opçoes, comprar uma carta para aumentar os pontos ou manter os que você ja possui;
3) Caso alguem ultrapasse os 21 pontos, perde;
4) Caso haja empate, há somente a opção de reiniciar o jogo;

Caso o jogador ganhe, a seguinte tela aparecerá:

![image](https://github.com/user-attachments/assets/db29c588-ad8a-4d8e-ae8d-9c4205ebcc74)

Caso o jogador perca:

![image](https://github.com/user-attachments/assets/96b55580-9d5a-4e95-8fbb-ba507761cd58)

Em caso de empate:

![image](https://github.com/user-attachments/assets/3f48c4a8-134e-4095-bedd-57f2d428d526)




# Funcionamento:

O jogo usa três principais bibliotecas SDL2:
- SDL2/SDL.h;
- SDL2/SDL_image.h;
- SDL2/SDL_ttf.h;
  
Para o funcionamento do jogo é necessário a instalação das três bibliotecas através de https://wiki.libsdl.org/SDL2/Installation.

# Instruções básicas para execução:

1) Clone o repositório git em um diretório de sua preferência;
2) Mude para o diretório em que foi clonado e entre na pasta BlackJackGame;
3) Entre no terminal e digite "make" para que ocorra a compilação e execução dos arquivos;

# Informações sobre a estrutura do projeto:

O projeto é dividido em sete pastas principais:

1) apps: diretório da main.c;
2) bin: diretório do executável da main.c;
3) imagens: onde estão os arquivos png de todas as imagens utilizadas;
4) include: onde estão todos os "headers";
5) obj: onde estão os executáveis;
6) src: onde estão os arquivos ".c";
7) Um arquivo Makefile;

# Link para os slides;

https://www.canva.com/design/DAGMTB93gW4/uFPJO9BSCmwpuVamPUy2yQ/edit


