//adam pluth
//cs101
//project5
//HuffmanCodeTree
//
// Project5.cpp : main project file.
//#include "stdafx.h"//remove before submit!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string>
//#include"minHeap.h"
#include"huffTree.h"

void printFreq(std::vector<std::vector<int>> Chars){
	for(int i=0;i!=static_cast<std::vector<int>::size_type>(Chars.size());i++){
			std::cout<<char(Chars[i][1])<<": ";
			std::cout<<Chars[i][0]<<", ";
	}//prints frequency
}


std::vector<std::vector<int>> readIn(int argc, char* argv[]){    
	std::ifstream fin;
    std::string line;
	std::vector<std::vector<int>> hertz;
	std::vector<int> freq;
	for(int i=0;i<256;i++){freq.push_back(int(0));}

	if (argc<2){std::cout << "sorry you need to enter a file as command line argument"; exit(0);}
	fin.open(argv[1]);
    if (fin!=NULL){
		while (!fin.eof()){
			fin >> line;
			int x = line.size();
			for (int i=0; i < x ;i++){//parse threw letters
				freq[line[i/*ascii convert to int*/]]++;//counting frequency of ascii characters
			}
		}
		fin.close();
		int k=freq.size();
		for(int i=0;i<k;i++){
			std::vector<int> h;
			if(freq[i]!=0){
				h.push_back(freq[i]);
				h.push_back(i);//ascii value
				hertz.push_back(h);
			}
		}
	}
    else {std::cout<<"Cannot read from input.txt";exit(0);}
	return hertz;
}


void writeOutBinCode(){}



int main(int argc, char* argv[])
{
	std::vector<std::vector<int>> freq=readIn(argc, argv);
	minHeap Heap=minHeap(freq);
	huffTree huff=huffTree(Heap,argc,argv);
	//writeOutBinCode();
	//readInCode();//seperate .cpp file needed
}
