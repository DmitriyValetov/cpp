#include <iostream>
#include <stack> // ����

using namespace std;


struct Edge {
  int begin;
  int end;
};

int main()
{
  system("chcp 1251");
  system("cls");
  stack<int> Stack;
  stack<Edge> Edges;
  int req;
  Edge e;
  int mas[7][7] = { { 0, 1, 1, 0, 0, 0, 1 }, // ������� ���������
  { 1, 0, 1, 1, 0, 0, 0 },
  { 1, 1, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 1, 0, 1, 0 },
  { 0, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 0, 0, 0, 1, 0 } };
  int nodes[7]; // ������� �����
  for (int i = 0; i < 7; i++) // ������� ��� ������� ����� 0
    nodes[i] = 0;
  cout << "N = ";
  cin >> req;
  req--;
  Stack.push(0); // �������� � ������� ������ �������
  while (!Stack.empty())
  { // ���� ���� �� ����
    int node = Stack.top(); // ��������� �������
    Stack.pop();
    if (nodes[node] == 2) continue;
    nodes[node] = 2; // �������� �� ��� ����������
    for (int j = 6; j >= 0; j--)
    { // ��������� ��� ��� ��� ������� �������
      if (mas[node][j] == 1 && nodes[j] != 2)
      { // ���� ������� ������� � �� ����������
        Stack.push(j); // ��������� �� � c���
        nodes[j] = 1; // �������� ������� ��� ������������
        e.begin = node; e.end = j;
        Edges.push(e);
        if (node == req) break;
      }
    }
    cout << node + 1 << endl; // ������� ����� �������
  }
  cout << "���� �� ������� " << req + 1 << endl;
  cout << req + 1;
  while (!Edges.empty())
  {
    e = Edges.top();
    Edges.pop();
    if (e.end == req)
    {
      req = e.begin;
      cout << " <- " << req + 1;
    }
  }
  cin.get(); cin.get();
  return 0;
}