namespace tree {
	struct bin_tree_node 
	{
		int val;
		bin_tree_node* left;
		bin_tree_node* right;

		bin_tree_node() : val(0), left(nullptr), right(nullptr) {}
		bin_tree_node(int val): val(val), left(nullptr), right(nullptr) {}
		bin_tree_node(int val, bin_tree_node* left, bin_tree_node* right) : val(val), left(left), right(right) {}
	};

	void tree_example_init(bin_tree_node* root);

	void insert(bin_tree_node* root, int insert_value);
	bin_tree_node* search(bin_tree_node* root, int search_value);
	bin_tree_node* get_min(bin_tree_node* root);
	bin_tree_node* get_max(bin_tree_node* root);
	bin_tree_node* del(bin_tree_node* root, int del_val);

	void dfs_nlr(bin_tree_node* root);
	void dfs_lrn(bin_tree_node* root);
	void dfs_lnr(bin_tree_node* root);
}
