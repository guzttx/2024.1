/*Criar um algoritmo para preencher um cubo 3*3*3 com
"red",'green', e 'blue‘, respectivamente. Preencha a
primeira matriz (red) com 200, a segunda com 100, e a
terceira com 50.*/

int main() 
{
    int cubo[3][3][3], i, j, k;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            for(k=0; k<3; k++)
            {
                if(i==0)
                {
                    cubo[i][j][k] = 200;
                }
                else if(i==1)
                {
                    cubo[i][j][k] = 100;
                }
                else
                {
                    cubo[i][j][k] = 50;
                }
            }
        }
    }

}