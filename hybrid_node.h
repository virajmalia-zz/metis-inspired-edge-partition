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

    HybridNode* parent;
    HybridNode* leftChild;
    HybridNode* rightChild;

public:
                    HybridNode();
    void            changeId(int);
    void            addVertexToBoundaryList(int);
    void            updateWeight(int, int);
    HybridNode*     findParent();
};
