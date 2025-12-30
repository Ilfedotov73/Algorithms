#include "tree.h"

#include <iostream>

namespace tree {

	void tree_example_init(bin_tree_node* root)
	{
		root->val = 6;
		root->left = new bin_tree_node(2);										
		root->right = new bin_tree_node(7);

		root->left->left = new bin_tree_node(1);
		root->left->right = new bin_tree_node(4);

		root->left->right->left = new bin_tree_node(3);
		root->left->right->right = new bin_tree_node(5);

		root->right->right = new bin_tree_node(9);
		root->right->right->left = new bin_tree_node(8);
	}

	void insert(bin_tree_node* root, int insert_value)
	{
		if (insert_value < root->val) {
			if (root->left == nullptr) { root->left = new bin_tree_node(insert_value); }
			else { insert(root->left, insert_value); }
		}
		else if (insert_value >= root->val) {
			if (root->right == nullptr) { root->right = new bin_tree_node(insert_value); }
			else { insert(root->right, insert_value); }
		}
	}

	bin_tree_node* search(bin_tree_node* root, int search_value)
	{
		if (root == nullptr) { return root; }
		if (root->val == search_value) { return root; }
		return (search_value < root->val) ? search(root->left, search_value) : search(root->right, search_value);
	}

	bin_tree_node* get_min(bin_tree_node* root)
	{
		if (root == nullptr) { return root; }
		if (root->left == nullptr) { return root; }
		return get_min(root->left);
	}
	bin_tree_node* get_max(bin_tree_node* root) 
	{
		if (root == nullptr) { return root; }
		if (root->right == nullptr) { return root; }
		return get_max(root->right);
	}

	bin_tree_node* del(bin_tree_node* root, int del_val)
	{
		if (root == nullptr) { return root; }
		if (del_val < root->val) { root->left = del(root->left, del_val); }
		else if (del_val > root->val) { root->right = del(root->right, del_val); }
		else {
			if (root->left == nullptr || root->right == nullptr) {
				return (root->left == nullptr) ? root->right : root->left;
			}
			else {
				bin_tree_node* right_min = get_min(root->right);
				root->val = right_min->val;
				root->right = del(root->right, right_min->val);
			}
		}
		return root;
	}

	void dfs_nlr(bin_tree_node* root)
	{
		std::cout << root->val << " ";
		if (root->left != nullptr) { dfs_nlr(root->left); }
		if (root->right != nullptr) { dfs_nlr(root->right); }
	}
	void dfs_lnr(bin_tree_node* root)
	{
		if (root->left != nullptr) { dfs_lnr(root->left); }
		std::cout << root->val << " ";
		if (root->right != nullptr) { dfs_lnr(root->right); }
	}
	void dfs_lrn(bin_tree_node* root)
	{
		if (root->left != nullptr) { dfs_lrn(root); }
		if (root->right != nullptr) { dfs_lrn(root); }
		std::cout << root->val << " ";
	}
}