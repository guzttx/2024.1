/*A Média Total de Disciplinas (MTD) é o resultado do somatório do produto da média final
das disciplinas aprovadas com nota pela carga horária das disciplinas em que aluno foi
aprovado, menos o produto da média final das disciplinas reprovadas com nota pela carga
horária das disciplinas em que aluno foi reprovado. O programa deve ler os valores
necessários para o cálculo da MTD, conforme a fórmula:
MTD = (MDA1 * ChDA1 + MDA2 * ChDA2 + … + MDAn * ChDAn) - (MDR1 * ChDR1
+ MDR2 * ChDR2 + … + MDRm * ChDRj)
onde:
MDAi = Média da Disciplina Aprovada i;
ChDAi = Carga horária da Disciplina Aprovada i;
n = Número de disciplinas aprovadas com nota;
MDRj = Média da Disciplina Reprovada j;
ChDRj = Carga horária da Disciplina Reprovada j;
m = Número de disciplinas reprovadas com nota.
Caso o aluno apresente reprovações, as notas e o desempenho do mesmo permanecerão no
histórico, mesmo cursando a disciplina novamente e tendo aprovação. Dessa forma, a MTD
será afetada e terá de contemplar a mesma disciplina mais de uma vez, incluindo todas as
vezes que o aluno cursou.*/


float mtotald (float aprovadas, float reprovadas, float mediaAprovadas, float mediaReprovadas, float cargaAprovadas, float cargaReprovadas)
{
    float mtd;

    mtd = ((mediaAprovadas * cargaAprovadas) + (mediaReprovadas * cargaReprovadas)) - ((mediaReprovadas * cargaReprovadas) + (mediaReprovadas * cargaReprovadas));




}