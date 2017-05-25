#include "hybrid_node.h"

using namespace std;

HybridNode::HybridNode():
    id = NULL
    {}

void HybridNode::changeId(int edgeLabel_l, int edgeLabel_r){
    this->id = to_string(edgeLabel_l) + to_string(edgeLabel_r);
}

void HybridNode::addVertexToBoundaryList(vector<int> list_l, vector<int> list_r){

    for(int i=0; i<list_l.size(); i++){                         // For every element in list_l

        int j=0;
        while(list_l[i] != list_r[j] && j<list_r.size()){       // Check if also found in list_r
            j++;
        }

        bool found;
        if(j == list_r.size())
            found = false;
        else
            found = true;

        if(found == false){
            vOnBoundary.push_back(list_l[i]);
        }
        else{
            // Vertex repeated in both lists.
            // If it has any other edge(How do we find this?), add it to boundary.
        }
    }

}

void HybridNode::updateWeight(int wt_l, int wt_r){
    this->weight = wt_l + wt_r;
}

void HybridNode::updateSubCount(int newCount){
    this->subCount = newCount
}

void HybridNode::hasLeftChild(HybridNode::HybridNode* left){
    this->leftChild = left;
}

void HybridNode::hasRightChild(HybridNode::HybridNode* right){
    this->rightChild = right;
}

int HybridNode::getId(){
    return stoi(this->id);
}

int HybridNode::getSubCount(){
    return this->subCount;
}

HybridNode::HybridNode* HybridNode::findParent(){
    return this->parent;
}
