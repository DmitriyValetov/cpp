#include <iostream>
#include <queue>

using namespace std;


int main()
{
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
  int dist[size];
  for (int i = 0; i < size; i++){
    nodes[i] = 0; // исходно все вершины равны 0
    dist[i] = -1; // infinity
  }

  int start = 0;
  cout << "Where to start (default = 0) in [0," << size-1 << "] ? " << endl;
  cin >> start;
  Queue.push(start); // помещаем в очередь первую вершину
  dist[start] = 0;
 
  cout << endl << "Routine of algorithm: " << endl;

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
					dist[j] = dist[node]+1;
				  }
			}
		cout << node + 1 << endl; // выводим номер вершины
	  }

  cout << endl;
  cout << "Start was in: " << start << endl;
  for(int i=0; i<size; i++){
	  cout << "vertex: " << i << "; Distance from start: " << dist[i] << endl;
  }

  cin.get();
  return 0;
}