#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HybridNode{

private:
    string id;                  // Concatenation of child ids

    vector<int> vOnBoundary;    // List of vertices on boudary
    vector<int> eList;          // List of edges enclosed

    int weight;                 // Total weight of edges enclosed
    int subCount;               // Number of nodes below this node

    HybridNode* parent;
    HybridNode* leftChild;
    HybridNode* rightChild;

public:
                    HybridNode();
    // Writes
    void            changeId(int, int);
    void            addVertexToBoundaryList(vector<int>, vector<int>);
    void            updateWeight(int, int);
    void            updateSubCount(int);
    void            hasLeftChild(HybridNode*);
    void            hasRightChild(HybridNode*);

    // Reads
    int             getId();
    int             getSubCount();
    HybridNode*     findParent();
};
