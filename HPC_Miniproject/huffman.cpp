
#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<time.h>
#include<fstream>
#include <list>
#include <algorithm>
#include <unordered_set>

using namespace std;
struct node
{


 node * leftChild;
 node * rightChild;
 double frequency;
    string content;
 string code;


};
vector<node> nodeArray;

node  extractMin()
{ 
 double temp = (double) INT8_MAX;
    vector<node>::iterator i1,pos;
   for(i1 = nodeArray.begin();i1!=nodeArray.end();i1++)
 {
  
 if(temp>(*i1).frequency)
  {
     pos = i1;
     temp = (*i1).frequency;
  }
 }
 
 node tempNode = (*pos);
 nodeArray.erase(pos);
 return tempNode;
}
                     
node getHuffmanTree()
{
 while(!nodeArray.empty())
 { 
   node * tempNode = new node;   
      node * tempNode1 = new node;
   node * tempNode2 = new node;
      *tempNode1 = extractMin();
   *tempNode2 = extractMin();

   tempNode->leftChild = tempNode1;
   tempNode->rightChild = tempNode2;
   tempNode->frequency = tempNode1->frequency+tempNode2->frequency;
   nodeArray.push_back(*tempNode);
   if(nodeArray.size() == 1)//only the root node exsits
   {
    break;
   }
 }
    return nodeArray[0];
}

void BFS(node * temproot,string s)
{
   node * root1 = new node;
   root1 = temproot;
  
   root1->code = s;
  if(root1 == NULL)
   {
    
   }
    else if(root1->leftChild == NULL && root1->rightChild == NULL)
   {
    
    cout<<"the content is "<<root1->content<<endl;
    cout<<"and its corresponding code is "<<root1->code<<endl;
   }
    else
   {
   
      root1->leftChild->code = s.append("0");
   s.erase(s.end()-1);
   root1->rightChild->code = s.append("1");
   s.erase(s.end()-1);


      BFS(root1->leftChild,s.append("0"));
   s.erase(s.end()-1);
      BFS(root1->rightChild,s.append("1"));
   s.erase(s.end()-1);
 }
   
}

void getHuffmanCode()
{
 int size,i;
 double tempDouble;
 string tempString;

 fstream newfile;
 string t;

 newfile.open("text.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      
      while(getline(newfile, t)){  //read data from file object and put it into string.
         cout << t <<endl;   //print the data of the string
      }
      newfile.close();   //close the file object.
   }
    std::list<char> chars;
    for (char c: t)
        chars.push_back(c);


    std::unordered_set<int> s(chars.begin(), chars.end());
    chars.assign(s.begin(), s.end()); 
    
    for (char c: chars)
      {
        tempString=c;
        tempDouble=count(t.begin(), t.end(), c);
        node tempNode;
        tempNode.frequency = tempDouble;
        tempNode.content = tempString;
        tempNode.leftChild = NULL;
        tempNode.rightChild = NULL;
        nodeArray.push_back(tempNode);
        cout<<"  "<<c<<" : "<<count(t.begin(), t.end(), c)<<endl;
      }
  

 node root = getHuffmanTree();


 BFS(&root,"");
 
}


int main()
{
    double time_spent = 0.0;

	  clock_t begin = clock();
 getHuffmanCode();

     clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<"Serial Time :  "<<time_spent;

 return 0;
}

