#include<vector>
#include<fstream>
#include<algorithm>
#include<iostream>
#include<string>
#include"Node.h"
#include"minHeap.h"

class huffTree
{
public:
	int internalNodes;
	Node* root;
	std::vector<std::string> CodeList;
	std::vector<std::string> CodeList2;

	huffTree(minHeap freq,int argc, char* argv[]){
		std::string huffCode;
		std::string pre;
		std::string in;
		root=makeNodes(freq);
		pre=root->printNodePre(pre);
		in=root->printNodeIn(in);
		//write tree.txt
		std::ofstream treetxt;
		treetxt.open("tree.txt");
		treetxt<<pre<<"\n"<<in;
		treetxt.close();
		//write length.txt
		CodeList=makeCode(root,CodeList,huffCode);
		std::ofstream lentxt;
		lentxt.open("length.txt");
		for(int i=0;i<CodeList.size();i++){
			lentxt<<CodeList[i][2];
			lentxt<<CodeList[i][3];
			lentxt<<CodeList[i][4];
			for(int j=6;j<CodeList[i].size();j++){
				if(CodeList[i][j]==' '){lentxt<<" "<<j-6;break;}
			}
			lentxt<<"\n";
		}
		lentxt.close();
		//write code.txt
		std::ifstream fin;
		std::string line;
		std::string estr;
		std::ofstream codetxt;
		codetxt.open("code.txt");
		fin.open(argv[1]);
		if (fin!=NULL){
			while (!fin.eof()){
				fin >> line;
				int x = line.size();
				for (int i=0; i < x ;i++){//parse threw letters
					codetxt<<getcode(line[i],CodeList);
				}
			}
			fin.close();
		codetxt.close();

		}
	
	}
	std::string getcode(char c,std::vector<std::string> CodeList){
		int len=0;
		std::string s;
		for(int i=0;i<CodeList.size();i++){
			if(CodeList[i][0]==c){
			for(int j=6;j<CodeList[i].size();j++){
				if(CodeList[i][j]==' '){len=j-6;break;}
			
			}
			s=CodeList[i].substr(6,len);			
			return s;
			}
		}
	}
	//makes vector of internal nodes
	Node* makeNodes(minHeap freq/*list of letters*/){
//		freq.printHeap();
		std::vector<Node*> treeL;
		int internalNodes=0;
		int	index=0;
		Node* tNode1;
		Node* tNode2;
		Node* parent;


		while(freq.getSize()!=0){
			std::vector<int> i=freq.getMin(true);
			treeL.push_back(new Node(i[1],i[0],true));
		}

		while(treeL.size()>1){
			int sum=0;
			index++;
			internalNodes++;
			tNode1=treeL[0];
			sum+=treeL[0]->getNum();
			std::reverse(treeL.begin(),treeL.end());
			treeL.pop_back();
			tNode2=treeL[treeL.size()-1];
			sum+=treeL[treeL.size()-1]->getNum();
			treeL.pop_back();
			std::reverse(treeL.begin(),treeL.end());
			index++;
			parent=new Node(internalNodes,sum,false);
			parent->setLChild(tNode1);
			parent->setRChild(tNode2);
			treeL.push_back(parent);
		}
		return treeL[0];
	}
	std::vector<std::string> makeCode(Node* n,std::vector<std::string> outCodes,std::string code){
		if(n->getLChild()==NULL||n->getRChild()==NULL){
			char c=n->getDataS();
			std::string codes=std::to_string(code.size());
			std::string co=std::to_string(c);
			code+=" ";
			code+=c; 
			if(n->getData()>99){
				code=co+" "+code+" "+codes;
				code=" "+code;
				code=c+code; 
				
			}
			else{
				code="0"+co+" "+code+" "+codes;
				code=" "+code;
				code=c+code; 
			}
			outCodes.push_back(code);
		}
		
		else {
			code+=("0");
			outCodes=makeCode(n->getLChild(),outCodes,code);
			code+=("1");
			outCodes=makeCode(n->getRChild(),outCodes,code);
		}
		return outCodes;
	}
		std::vector<std::string> makeCode2(Node* n,std::vector<std::string> outCodes,std::string code){
		if(n->getLChild()==NULL||n->getRChild()==NULL){
			char c=n->getDataS();
			std::string codes=std::to_string(code.size());
			std::string co=std::to_string(c);
			code+=" ";
			code+=c; 
			if(n->getData()>99){
				code=co+" "+codes;
				code=" "+code;
				code=c+code; 
			}
			else{
				code="0"+co+" "+codes;
				code=" "+code;
				code=c+code; 
			}
			outCodes.push_back(code);
		}
		else if(n->getLChild()!=NULL&&n->getRChild()!=NULL){
			code+=("0");
			outCodes=makeCode(n->getLChild(),outCodes,code);
			code+=("1");
			outCodes=makeCode(n->getRChild(),outCodes,code);
		}
		return outCodes;
	}
};