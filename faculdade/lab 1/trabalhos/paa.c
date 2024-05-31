/*O Percentual de Aproveitamento do Aluno (PAA) é calculado com base na quantidade de
disciplinas em que o aluno obteve aprovação em relação à quantidade total de disciplinas
cursadas. O programa deve ler os valores necessários para o cálculo do PAA, conforme a
fórmula:
PAA = (QDA * 100) / QTC
onde:
QDA = quantidade de disciplinas cursadas com aprovação;
QTC = quantidade total de disciplinas cursadas.
Caso o aluno não tenha nenhuma reprovação, o programa deve exibir o percentual de
aproveitamento de 100% acompanhado de uma mensagem de felicitação.
*/

float paproveitamentoa(float aprovadas, float disciplinas)
{
    int paa;

    paa = (aprovadas * 100) / disciplinas;

    return paa;
}