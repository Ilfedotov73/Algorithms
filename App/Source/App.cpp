#include "Core/Core.h"
#include "SearchAlgorithms/tree.h"

#include <iostream>

int main()
{
	tree::bin_tree_node* root = new tree::bin_tree_node();
	tree::tree_example_init(root);
	tree::insert(root, 10);
	std::cout << tree::search(root, 8)->val << '\n';
	tree::del(root, 9);
	tree::dfs_lnr(root); std::cout << '\n';
	std::cout << tree::get_min(root)->val << ' ' << tree::get_max(root)->val;
}