#include "dataloader.h"
#include <bits/stdc++.h>
using namespace std;

#ifndef __DECISION_TREE__
#define __DECISION_TREE__

struct node{
	bool 	isLeaf;
	vi		data;
	set<int> parAttr;

	int attribute; //the atrribute used to make this split
	map<int,int>	m;
	vector<node*>	children;
};

pii ComputeTreeSize(node* curr);

class DecisionTree{
/* Delete this comment */ 
private:
	node *root;
	vvi train, validation, test; //data
	int size; //size of training data
	int tree_size; //size of decision tree
	vpid accTrain, accVal, accTest;
public:
	DecisionTree(){
		LoadAllData();
		root = new node;
		root->isLeaf = true;
		root->data = vi(size, 0);
		root->parAttr.clear();
		for(int i=0; i<size; i++)
			root->data[i] = i;
		tree_size = 0;

	}
	void LoadAllData();
	double ComputeEntropy(int attr, vi& data);
	double ComputeEntropyGivenSurvival(int attr, vi& data);
	int ChooseAttributeToSplit(node* curr); //Well, its obvious from the name, isn't it?
	void GrowDecisionTree(); //Grow the decision tree iteratively using the training data
	void ComputeAccuracy(); //Every time the size of tree is increased, this function will be called to compute the accuracy
	bool CheckPrediction(vi& v);
	void FlushIntoFile(); //flush the (tree_size, accuracy) tuples into file. After the decision tree has grown fully. 
	void PrintRequiredOutput();
};

#endif