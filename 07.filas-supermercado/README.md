DESAFIO: Fila do supermercado daquele famoso professor de matemática

Uma rede de supermercados, buscando melhor atender seus clientes está implantando
uma loja modelo, que dentre outras diferenças em relação à loja tradicional, possibilitará a
seus clientes ficar em um espaço de convivência enquanto aguarda ser chamado ao caixa.

Ao adentrar o espaço de convivência, o cliente recebe um cupom mostrando a senha
específica de chamada ao caixa, data e hora de retirada do cupom. O cupom pode ser do tipo
caixa rápido (para até 20 volumes), caixa preferencial e caixa comum.

O tempo de espera na fila preferencial não pode ser superior a 15 minutos, segundo as
regras da loja modelo. Para a fila do caixa rápido, espera-se que o tempo de atendimento esteja
inferior a 25 minutos, enquanto do caixa normal não deve superar os 40 minutos.

Usando os conceitos de Estrutura de Dados, desenvolva um algoritmo que controle a
chegada do cliente ao espaço de convivência e a chamada para atendimento no caixa,
observando as premissas a seguir:

a) a loja modelo foi estruturada para abrir até 25 caixas ao mesmo tempo, porém, é
interessante que o menor número possível de caixas fique aberto, sendo três o número
mínimo;
b) a cada 15 minutos deve-se observar a necessidade de abrir ou fechar caixas;
c) não existe caixa reservado para um atendimento específico, todos os caixas podem atender
qualquer tipo de fila;
d) um sinal luminoso seguido de uma campainha indicará em qual caixa o próximo cliente
será atendido;
e) o chefe de caixa deve ter em mãos, sempre que requisitado, o tempo médio de atendimento
do dia;
f) o chefe de caixa deve ter em mãos qual o tempo de espera atual da fila para cada tipo de
atendimento.
