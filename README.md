# JOGO PINGUIM PULA!

## SOBRE O JOGO

Pule nos blocos de gelo sem encostar no mar, vá até os outros pinguins para salvá-los. Se você cair no mar, você perde esse pinguim, mas caso tenha pinguins no seu inventário, você passa a jogar com o primeiro que salvou. Os pinguins no inventário são salvos em uma posição específica, caracterizando uma lista encadeada, porém, paralelo a isso, a ordem em que coleta os pinguins é salva, e o próximo pinguim a jogar é o primeiro coletado, e assim por diante, respeitando uma fila. Você perde o jogo caso caia no mar e não tenha nenhum pinguim no inventário. Quanto mais pinguins continuarem no inventário, ou seja, quanto mais você conseguir pegar e menos vezes cair no mar, mais pontos você consegue ao concluir o jogo. Após recolher todos os pinguins deve avançar para a plataforma final que é seu ponto de chegada, assim você ganha o jogo.

# Como jogar

 É precisor ter:
 - Makefile (simplifica compilação)
 - SFML 3.0.0
 - g++ atualizado

Depois basta editar "...\include" e "...\lib" na pasta Make para o local onde o seu include e lib da biblioteca SFML 3.0.0 estão.

Feito isso, para jogar é preciso compilar o jogo. Para isso basta estar na mesma pasta que o main e digitar no terminal:

make

Logo apos:

.\main

Uma janela com o jogo deve ser aberta. Caso isso não aconteça, é preciso abrir o arquivo .exe manualmente.

