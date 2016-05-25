#include<vector>
#include<iostream>
#include<string>

class Node{
	Node* leftc;
	Node* rightc;
	int data;
	int num;
	bool leaf;
public:
	
	Node(int dat=0,int occur=0,bool l=false){
		leftc=NULL;
		rightc=NULL;
		data=dat;
		num=occur;
		if(l){leaf=true;}
		else{leaf=false;}
	}
	
	void setLChild(Node* n){leftc=n;}
	
	void setRChild(Node* n){rightc=n;}
	
	Node* getLChild(){return leftc;}
	
	Node* getRChild(){return rightc;}
	
	int getData(){return data;}
	
	int getDataS(){return char(data);}
	
	int getNum(){return num;}
	
	bool getLeaf(){return leaf;}

	std::string printNodePre(std::string str){
	
		if(leaf){
			str=str+"L:"+/*data<<" :"<<*/char(data)+" ";
		}
		else{
			str=str+"I:"+std::to_string(data)+" ";
			if(leftc!=NULL){str=leftc->printNodePre(str);}
			if(rightc!=NULL){str=rightc->printNodePre(str);}
		}
		return str;
	}

	std::string printNodeIn(std::string str){
		if(leftc!=NULL){str=leftc->printNodeIn(str);}
		if(leaf){
			str=str+"L:"+/*data<<" :"<<*/char(data)+" ";
		}
		else{
			str=str+"I:"+std::to_string(data)+" ";
			if(rightc!=NULL){str=rightc->printNodeIn(str);}
		}
		return str;
	}

	std::string printNodePost(std::string str){
			if(leftc!=NULL){str=leftc->printNodePost(str);}
			if(rightc!=NULL){str=rightc->printNodePost(str);}
		if(leaf){
			str=str+"L:"+/*data<<" :"<<*/char(data)+" ";
		}
		else{
			str=str+"I:"+std::to_string(data)+" ";}
		return str;
	}

};