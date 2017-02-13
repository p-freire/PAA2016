#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>

typedef struct
{
	int peso;
	int pai;
	int id;
} vertice;

// funcao de comparacao para a fila de prioridades
// ser ordenada de maneira crescente (o default eh decrescente)
// Referencia: http://www.technical-recipes.com/2011/priority-queues-and-min-priority-queues-in-c/
struct compare
{
  bool operator()(const vertice& l, const vertice& r)
  {
      return l.peso > r.peso;
  }
};

// retorna indice de vetor unidimensional como se fosse matriz
int get_index(int i, int j, int cols)
{
	return i * cols + j;
}

// retorna peso minimo e arestas escolhidas
int prim(int *mat_adj, vertice *v, bool *foi_visitado, int n_vertices, int raiz)
{
    // fila de prioridades decrescente
	std::priority_queue<vertice, std::vector<vertice>, compare> q;
	vertice aux;
	int peso = 0;

    // vertice inicial tem peso 0
	v[raiz].peso = 0;
	q.push(v[raiz]);

    while(!q.empty())
    {
        aux = q.top();
        q.pop();
        if(!foi_visitado[aux.id])
        {
            // backtracking
            if(aux.pai == -1)
                printf("Inicio: %d\n", aux.id);
            else
                printf("Aresta: %d-%d\n", aux.pai, aux.id);

            // verifica de forma gulosa as melhores
            // arestas a serem escolhidas
            foi_visitado[aux.id] = true;
            peso += aux.peso;
            for(int j = 0; j < n_vertices; ++j)
                if(!foi_visitado[j]
                   && mat_adj[get_index(aux.id, j, n_vertices)] > 0
                   && mat_adj[get_index(aux.id, j, n_vertices)] < v[j].peso)
                {
                    v[j].peso = mat_adj[get_index(aux.id, j, n_vertices)];
                    v[j].pai = aux.id;
                    q.push(v[j]);
                }
        }
    }
    return peso;

}


int main()
{
	int n;
	vertice *v;
	bool *foi_visitado;
	int *mat_adj;

	printf("Numero de vertices: ");
	scanf("%d", &n);

	v = new vertice[n];
	mat_adj = new int[n * n];
	foi_visitado = new bool[n];

    // inicializacao
	for(int i = 0; i < n; ++i)
	{
		v[i].peso = INT_MAX;
		v[i].pai = -1;
		v[i].id = i;
		foi_visitado[i] = false;
	}

    // inicializa matriz de adjacencia
	printf("Matriz de adjacencia:");
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%d", &mat_adj[get_index(i, j, n)]);

	printf("Peso minimo = %d\n", prim(mat_adj, v, foi_visitado, n, 0));

	delete [] v;
	delete [] foi_visitado;
	delete [] mat_adj;

	return 0;

}
