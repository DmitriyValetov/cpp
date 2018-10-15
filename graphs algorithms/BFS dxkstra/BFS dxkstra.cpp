#include <iostream>
#include <queue> 
#include <vector>
#include <algorithm>
using namespace std;


class Node{
public:
	long name;
	long dist;
	long prev;

	Node(long name, long dist, long prev): name(name), dist(dist), prev(prev){}
	bool operator<(const Node &other){
		return (this->dist < other.dist);
	}
	bool operator==(const Node &other){
		return (this->dist == other.dist);
	}
};

class PrioQueue{
public:	
    vector<Node> Queue;

	PrioQueue(){};
	PrioQueue(long *arr, long size);
	PrioQueue(const vector<Node> &inQueue): Queue(inQueue){}
	vector<Node> giveVector();
	void insert(const Node &newNode);
	void DecreaseKey(long i, long newDist, long newPrev);
	Node DeleteMin();
	bool empty(){ return Queue.empty(); }
	Node operator[](long i);
	long size(){ return Queue.size(); }
};

Node PrioQueue::operator [](long i){
	for(long j=0; j<Queue.size(); j++){
		if(Queue[j].name == i)
			return Queue[j];
	}
}

PrioQueue::PrioQueue(long *arr, long size){
	for(int i=0; i<size; i++){
		Queue.push_back(Node(i, arr[i], -1));
	}
}

vector<Node> PrioQueue::giveVector(){
    return Queue;
}

void PrioQueue::insert(const Node &newNode){
	Queue.push_back(newNode);
	sort(Queue.begin(), Queue.end());	
}

void PrioQueue::DecreaseKey(long pos, long newDist, long newPrev){
	for(long i=0; i<Queue.size(); i++){
		if(Queue[i].name == pos){
			Queue[i].dist = newDist;
			Queue[i].prev = newPrev;
		}
	}
    sort(Queue.begin(), Queue.end());
}

Node PrioQueue::DeleteMin(){
	Node buf = Queue[0];
	Queue.erase(Queue.begin(), Queue.begin()+1);
	return buf;
}


int main()
{

  setlocale(0, "");
  //PrioQueue niceVector();
  //niceVector.insert(Node(1,4,0));
  //niceVector.insert(Node(2,6,0));
  //niceVector.insert(Node(3,1,0));
  //for(int i=0; i<niceVector.Queue.size(); i++){
	 // cout << niceVector.Queue[i].name << " " << niceVector.Queue[i].dist << endl;
  //}

  const int size = 5;
  
  int mas[size][size] = { 
  { 0, 4, 2, 0, 0 }, // матрица смежности
  { 0, 0, 3, 2, 3 },
  { 0, 1, 0, 4, 5 },
  { 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0 } };

  long infinity = 66666;
  long dist[size];
  long prev[size];
  long status[size];
  for(int i=0; i<size; i++){
	  dist[i] = infinity;
	  prev[i] = -1;
	  status[i] = 0;
  }
  long start = 0;
  long end = 5;
  cout << "Where to start (default = 0) ?" << endl;
  cin >> start;
  cout << "Where to end (default = 5) ?" << endl;
  cin >> end;
  
  dist[start] = 0;
  PrioQueue niceVector(dist, size);

  vector<long> Path;

  while(!niceVector.empty()){
	  Node bufNode = niceVector.DeleteMin();
	  status[bufNode.name] = 1;
	  Path.push_back(bufNode.name);
	  for(int i=0; i<size; i++){
		  if(mas[bufNode.name][i]>0 && status[i] == 0)
			  if(niceVector[i].dist > bufNode.dist +  mas[bufNode.name][i]){
				  dist[i] = dist[bufNode.name] + mas[bufNode.name][i];
				  prev[i] = bufNode.name;
				  niceVector.DecreaseKey(i, dist[i], prev[i]);
			  }
	  }
  }

  cout << "Path: " << endl;
  for(int i=0; i<Path.size(); i++){
	  cout << Path[i] << endl;
	  cout << "Way: ";
	  long k = i;
	  for(;k>=0;){
		  cout << k << (k!=0 ? " <- ": "");
		  k = prev[k];
	  }
	  cout << endl << endl;
  }

  // cin.get();
  return 0;
}