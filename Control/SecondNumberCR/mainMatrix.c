#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Graph
{
	int **matrix;
	int count;
} Graph;

Graph* createGraph(const char* fileName)
{
	Graph* newGraph = calloc(1, sizeof(Graph));

	if (newGraph == NULL)
	{
		return NULL;
	}

	FILE* file = fopen(fileName, "r");
	int count = 0;
	fscanf(file, "%d\n", &count);
	newGraph->count = count;
	newGraph->matrix = calloc(count, sizeof(int*));

	for (int i = 0; i < count; i++)
	{
		newGraph->matrix[i] = calloc(count, sizeof(int));
		for (int j = 0; j < count; j++)
		{
			fscanf(file, "%d", &(newGraph->matrix[i][j]));
		}
	}

	fclose(file);
	return newGraph;
}

void printGraph(const Graph* graph)
{
	for (int i = 0; i < graph->count; i++)
	{
		for (int j = 0; j < graph->count; j++)
		{
			printf("%d ", graph->matrix[i][j]);
		}
		printf("\n");
	}
}

Graph* floydAlg(Graph* mainGraph)
{
	for (int k = 0; k < mainGraph->count; k++)
	{
		for (int i = 0; i < mainGraph->count; i++)
		{
			for (int j = 0; j < mainGraph->count; j++)
			{
				mainGraph->matrix[i][j] = mainGraph->matrix[i][j] || (mainGraph->matrix[i][k] && mainGraph->matrix[k][j]);
			}
		}
	}

	return mainGraph;
}

void writeFile(const Graph* mainGraph)
{
	FILE* file = fopen("textOut.txt", "w");
	if (file == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < mainGraph->count; i++)
	{
		for (int j = 0; j < mainGraph->count; j++)
		{
			fprintf(file, "%d ", mainGraph->matrix[i][j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
}

void deleteGraph(Graph** graph)
{
	for (int i = 0; i < (*graph)->count; i++)
	{
		free((*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}

bool isCorrectFloyd()
{
	Graph* mainGraph = createGraph("correctOpen.txt");
	mainGraph = floydAlg(mainGraph);
	FILE* fileOut = fopen("correctOut.txt", "r");
	for (int i = 0; i < mainGraph->count; i++)
	{
		for (int j = 0; j < mainGraph->count; j++)
		{
			int value = 0;
			fscanf(fileOut, "%d", &value);

			if (value != mainGraph->matrix[i][j])
			{
				return false;
			}
		}
	}
	fclose(fileOut);
	deleteGraph(&mainGraph);
	return true;
}

int main()
{
	if (!isCorrectFloyd())
	{
		printf("ERROR");
		return 1;
	}

	Graph* mainGraph = createGraph("text.txt");

	mainGraph = floydAlg(mainGraph);

	writeFile(mainGraph);

	deleteGraph(&mainGraph);
	return 0;
}