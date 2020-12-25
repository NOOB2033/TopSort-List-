#include<iostream>
#include"TopSort.h"


void topSort()
{
	TopSort list; // initial list
	int a, b;
	std::cin >> a >> b; // When the entered graph is over, you need to enter: 0 0
	if (a == 0 || b == 0) 
		return;
	for (; a != 0 && b != 0;) {
		list.addEdge(a, b);
		std::cin >> a >> b;
	}
	TopSort sort; // sort list
	for (; !list.empty();) {
		Lider* node = list.findCount(0);
		if (!node) {
			std::cout << "Cycle!";
			return;
		}
		node->decTrValues();
		list.remove(node);
		sort.addToTail(node);
	}
	sort.print();
}


int main()
{
	topSort();
	return 0;
}