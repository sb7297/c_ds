#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

struct BSTNode {
	int value;
	struct BSTNode* left;
	struct BSTNode* right;
};

struct BSTNode* BSTNode_new(int val) {
	struct BSTNode* ret = malloc(sizeof(struct BSTNode));
	ret->left = NULL; ret->right = NULL;
	ret->value = val;
	return ret;
}

void BST_insert(struct BSTNode* head, int val) {
	if (val >= head->value) {
		if (head->right != NULL) {
			BST_insert(head->right, val);
		} else {
			head->right = BSTNode_new(val);
		}
	} else {
		if (head->left != NULL) {
			BST_insert(head->left, val);
		} else {
			head->left = BSTNode_new(val);
		}
	}
}

void BST_depth_traverse(struct BSTNode* head, void (*sideEffect)(struct BSTNode*)) {
	if (head->left != NULL) {
		BST_depth_traverse(head->left, sideEffect);
	}
	(*sideEffect)(head);
	if (head->right != NULL) {
		BST_depth_traverse(head->right, sideEffect);
	}
}

void BST_destroy(struct BSTNode* head) {
	if (head->left != NULL) {
		BST_destroy(head->left);
	}
	if (head->right != NULL) {
		BST_destroy(head->right);
	}
	free(head);
}

struct BSTNode* BST_find_parent(struct BSTNode* root, int key) {
    struct BSTNode* parent = NULL;
    struct BSTNode* ptr = root;
    while(ptr != NULL) {
        if (key > ptr->value && ptr->right != NULL) {
            parent = ptr;
            ptr = ptr->right;
        }
        else if (key < ptr->value && ptr->left != NULL) {
            parent = ptr;
            ptr = ptr->left;
        }
        else if (key == ptr->value) {
            return parent;
        } else {
            return NULL;
        }
    }
    return NULL;
}

struct BSTNode* BST_delete(struct BSTNode* root, int key) {
    if (root == NULL) return root;
    
    struct BSTNode* tmp;
    struct BSTNode* origLeft;
    struct BSTNode* origRight;
    struct BSTNode* ret;
    
    if (key == root->value) {
        origLeft = root->left;
        origRight = root->right;
        ret = origRight;
        if (origRight == NULL) {
            return origLeft;
        }
        tmp = ret;
        while (tmp->left != NULL) tmp = tmp->left;
        tmp->left = origLeft;
        free(root);
        return ret;
    }
    
    struct BSTNode* parent = BST_find_parent(root, key);
    if (parent == NULL) return root;
    bool isParentRight = parent->right != NULL && parent->right->value == key;
    struct BSTNode* ptr = isParentRight ? parent->right : parent->left;
    origLeft = ptr->left;
    origRight = ptr->right;
    if (isParentRight) {
        parent->right = origRight == NULL ? origLeft : origRight;
    } else {
        parent->left = origRight == NULL ? origLeft : origRight;
    }
    free(ptr);
    if (origRight != NULL) {
        tmp = origRight;
        while (tmp->left != NULL) tmp = tmp->left;
        tmp->left = origLeft;
    }
    return root;
}

void print_node(struct BSTNode* node) {
	printf("%d\n", node->value);
}

void do_nothing(struct BSTNode* node) {}

int main(int argc, char** argv) {
	struct BSTNode* tree = BSTNode_new(3);
	BST_insert(tree, 1);
	BST_insert(tree, 7);
	tree = BST_delete(tree, 1);
	BST_depth_traverse(tree, &print_node);
	BST_destroy(tree);
	return 0;
}
