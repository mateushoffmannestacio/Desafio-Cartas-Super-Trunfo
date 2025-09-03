# Desafio-Cartas-Super-Trunfo

Super Trunfo: Batalha de Cartas
Este é um projeto em C que simula um jogo de Batalha de Cartas, inspirado no clássico Super Trunfo. O programa permite que o usuário insira os dados de duas cartas, calcula atributos derivados e um "Super Poder" especial, e então compara as cartas para determinar a vencedora em cada categoria.

Compilação e Execução
Para rodar este programa, você precisará de um compilador de C, como o GCC.

1. Compilar o Código
Abra o seu terminal ou prompt de comando, navegue até a pasta onde o arquivo super_trunfo.c está salvo e use o seguinte comando:

gcc -o super_trunfo super_trunfo.c

Este comando irá criar um arquivo executável chamado super_trunfo.

2. Executar o Programa
Após a compilação, execute o programa com o comando:

No Linux ou macOS:

./super_trunfo

No Windows:

super_trunfo.exe

Como Usar
Ao executar o programa, você será guiado a inserir os dados para as duas cartas. Siga as instruções que aparecem na tela, digitando as informações solicitadas para cada atributo.

Exemplo de interação:

--- Cadastro da Carta 1 ---
Digite o nome do estado: Santa Catarina
Digite o codigo da carta: SC-01
Digite o nome da carta: Florianopolis
Digite a populacao (unsigned long int): 516524
Digite a area (float): 675.4
Digite o PIB (long long int): 24500000000
Digite o numero de pontos turisticos (int): 150

Após inserir os dados para ambas as cartas, o programa calculará automaticamente os atributos e exibirá o resultado da comparação.

Atributos de Comparação
O jogo compara as cartas com base nos seguintes atributos. A regra de comparação é indicada ao lado de cada um:

População: Maior valor vence.

Área: Maior valor vence.

PIB: Maior valor vence.

Pontos Turísticos: Maior valor vence.

Densidade Populacional: Menor valor vence.

PIB per Capita: Maior valor vence.

Super Poder: Maior valor vence. (Soma de todos os atributos numéricos, incluindo o inverso da densidade populacional.)

O resultado de cada comparação será exibido no formato Nome do Atributo: Vencedor (Resultado). O valor 1 indica que a Carta 1 venceu, e 0 indica que a Carta 2 venceu.
