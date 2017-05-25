#include "hybrid_node.cpp"

using namespace std;

class Tree{

private:
    int nodeCount;
    int currentLevelCount;
    int nextLevelCount = currentLevelCount/2;
    int* currentLevelNodes;
    int* nextLevelNodes;

public:
                                Tree();

    HybridNode::HybridNode*     merge(HybridNode::HybridNode*, HybridNode::HybridNode*);
};
