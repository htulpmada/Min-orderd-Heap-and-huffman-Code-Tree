#include<vector>
#include<iostream>
#include<string>

class minHeap{

private:
	std::vector<std::vector<int>> vec;
	void bubbleDown(int index){
		int len=vec.size();
		int lci=2*index+1;//left child index
		int rci=2*index+2;//right child index
		if(lci>=len){return;}
		int minIndex=index;
		if(vec[index][0]>vec[lci][0]){minIndex=lci;}
		if((rci<len)&&(vec[minIndex][0]>vec[rci][0])){minIndex=rci;}
		if(minIndex!=index){
			std::vector<int> temp=vec[index];
			vec[index]=vec[minIndex];
			vec[minIndex]=temp;
			bubbleDown(minIndex);
		}//
	}

	void bubbleUp(int index){
		if(index==0){return;}
		int parentI=(index-1)/2;
		if(vec[parentI][0]>vec[index][0]){
			std::vector<int> temp=vec[parentI];
			vec[parentI]=vec[index];
			vec[index]=temp;
			bubbleUp(parentI);
		}
	}
	
	void heapify(){
		int length=vec.size();
		for(int i=length-1;i>=0;--i){
			bubbleDown(i);
		}
	}

public:
	minHeap(std::vector<std::vector<int>> vector){
		vec=vector;
		heapify();
	}

	void insert(std::vector<int> n){
		int len=vec.size();
		vec[len]=n;
		bubbleUp(len);
	}

	std::vector<int> getMin(bool del){
		std::vector<int> min=vec[0];
		if(del){
			int len=vec.size();
			if(len==0){return min;}
			vec[0]=vec[len-1];
			vec.pop_back();
			bubbleDown(0);
		}
		return min;
	}
	 
	int getSize(){int k=vec.size();return k;}

	void printHeap(){
		int len=vec.size();
		std::cout<<"\n";
		for(int i=0;i<len;i++){
			std::cout<<char(vec[i][1])<<": "<<vec[i][0]<<", ";
		}
		std::cout<<"\n";
	}

};