#include <iostream>
#include <queue>

using namespace std;


int main()
{

  setlocale(0, "");
  queue<int> Queue;
  
  const int size = 9;
  
  int mas[size][size] = { 
  { 0, 1, 1, 0, 0, 0, 1, 0, 0 }, // матрица смежности
  { 1, 0, 1, 1, 0, 0, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0 },
  { 1, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 1, 0 } };

  int nodes[size]; // вершины графа
  int connectivityNumber = 0;
  for (int i = 0; i < size; i++){
    nodes[i] = 0; // исходно все вершины равны 0
  }

  for(int i=0; i<size; i++){

	  if(nodes[i]==2) continue;

	  connectivityNumber++;

	  cout << "Routine №" << connectivityNumber << ": " << endl;
	  cout << "Start in " << i << "." << endl;

	  Queue.push(i); // помещаем в очередь первую вершину
	  while (!Queue.empty())
		  { // пока очередь не пуста
			int node = Queue.front(); // извлекаем вершину
			Queue.pop();
			nodes[node] = 2; // отмечаем ее как посещенную
			for (int j = 0; j < size; j++)
				{ // проверяем для нее все смежные вершины
				  if (node!=j && mas[node][j] == 1 && nodes[j] == 0)
					  { // если вершина смежная и не обнаружена
						Queue.push(j); // добавляем ее в очередь
						nodes[j] = 1; // отмечаем вершину как обнаруженную
					  }
				}
			cout << node << endl; // выводим номер вершины
		  }

	  cout << endl;
  }

  cout << "Connectivity number: " << connectivityNumber << endl;

  // cin.get();
  return 0;
}