#pragma once

#include <vector>
#include <string>
class Node;
//~ class AddBinaryNode;
//~ class SubBinaryNode;
//~ class MulBinaryNode;
//~ class DivBinaryNode;
//~ class IntLiteral;
//~ class FloatLiteral;
//~ class IdentNode;

class PoolOfNodes {
public:
	static PoolOfNodes& getInstance();
	void add(const Node* node) { nodePool.push_back(node); }
	//~ void createAsgBinaryNode(Node* l, Node* r){
	  //~ nodePool.push_back(new AsgBinaryNode(l, r));
	//~ }
	//~ void createAddBinaryNode(Node* l, Node* r){
	  //~ nodePool.push_back(new AddBinaryNode(l, r));
	//~ }
	//~ void createSubBinaryNode(Node* l, Node* r){
	  //~ nodePool.push_back(new SubBinaryNode(l, r));
	//~ }
	//~ void createMulBinaryNode(Node* l, Node* r){
	  //~ nodePool.push_back(new MulBinaryNode(l, r));
	//~ }
	//~ void createDivBinaryNode(Node* l, Node* r){
	  //~ nodePool.push_back(new DivBinaryNode(l, r));
	//~ }
	//~ void createIntLiteral(int v){
		//~ nodePool.push_back(new IntLiteral(v));
	//~ }
	//~ void createFloatLiteral(float v){
		//~ nodePool.push_back(new FloatLiteral(v));
	//~ }
	//~ void createIdentNode(const std::string id){
		//~ nodePool.push_back(new IdentNode(id));
	//~ }
  void drainThePool();
private:
  std::vector<const Node*> nodePool;
  PoolOfNodes() : nodePool() {}
};
