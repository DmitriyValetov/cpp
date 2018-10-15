#include <iostream>
# include "List.cpp"


int main()
{
	node *root = add_node(NULL, 10);
	root = add_node(root, 9);
	root = add_node(root, 8);
	root = add_node(root, 7);
	print_list(root);

	root = delete_from_list(root, 10);
	print_list(root);
	
	free_list(root);
	print_list(root);

	system("pause");
	return 0;
}
