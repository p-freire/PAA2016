/*
    Esse algoritmo simula a situação descrita no problema.
    Complexidade: O(nm)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, *p, m, contador, i;

    printf("Entre com o numero de pessoas: ");
    scanf("%d", &n);
    printf("Entre com o salto: ");
    scanf("%d", &m);

    // Aloca o vetor de tamanho n
    p = (int*)malloc(n * sizeof(int));

    if(p == NULL)
        return -1;

    // Preenche o vetor com numeros sequenciais de 1 a N
    for(i = 0; i < n; ++i)
        p[i] = i + 1;

    contador = n; // conta o numero de pessoas ainda vivas
    i = 0;
    int aux = 0; // auxiliar pra contar quantas pessoas ja passaram
    while(contador > 1)
    {
        while(aux < m)
        {
            if(p[i] != -1)
                ++aux;
            if(aux < m)
                i = (i + 1) % n;
        }
        p[i] = -1;
        --contador;
        aux = 0;
    }

    // Acha o sobrevivente
    for(i = 0; i < n; ++i)
        if(p[i] != -1)
            printf("O sobrevivente foi: %d\n", p[i]);

    free(p);
    return 0;
}
