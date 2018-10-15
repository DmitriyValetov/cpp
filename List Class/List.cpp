struct node {
	int value;
	struct node *next;
};

struct node* add_node(struct node *root, int value)
{
	if(!root){
		root = (node*) malloc(sizeof(struct node));
		root->value=value;
		root->next=NULL;
		return root;
	}
	struct node *new_node = (node*) malloc(sizeof(struct node));
	new_node->value = value;
	new_node->next = NULL;
	struct node *iter = root;
	while(iter->next){
		iter = iter->next;
	}
	iter->next = new_node;
	return root;
}

void print_list (struct node *root)
{
	if(!root) printf("The list is empty.\n");
	else printf("\n\nThe list: \n"); while(root){
		printf("%d\n", root->value);
		root = root->next;
	}
	printf("\n");
}

struct node* delete_from_list(struct node *root, int value)
{	
	struct node *rootresult = root;
	if(root->value==value){
		struct node *iter = root->next;
		free(root);
		return iter;
	}

	while(root){
		if(root->next && (root->next->value==value)){
			struct node *todelete = root->next;
			root->next = (root->next->next ? root->next->next : NULL);
			delete todelete;
			break;
		}
		root = root->next;
	}
	return rootresult;
}

void free_list(struct node *&root)
{
	struct node *iter = NULL;
	while(root){
		iter = root;
		root = root->next;
		iter->next = NULL;
		free(iter);

	}

	printf("List was cleared.\n\n");
}