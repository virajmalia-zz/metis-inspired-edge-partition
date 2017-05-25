#include "tree.h"

using namespace std;

Tree::Tree():
    nodeCount = 0,
    currentLevelCount = 0,
    nextLevelCount = 0
{}

HybridNode::HybridNode* merge(HybridNode::HybridNode* left, HybridNode::HybridNode* right){

    HybridNode* family = new HybridNode();

    family->changeId(left->getId(), right->getId());
    family->addVertexToBoundaryList(left->vOnBoundary, right->vOnBoundary);
    family->updateWeight(left->weight, right->weight);

    if((family->getId().to_string()).length() == 2)
        family->updateSubCount(2);
    else
        family->updateSubCount(left->getSubCount() + right->getSubCount() + 2);

    family->hasLeftChild(left);
    family->hasRightChild(right);


    return family;
}
