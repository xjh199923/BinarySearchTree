/*
Created by xjh on 2019/10/29.
WeChat:xjh199923
Email:981715157@qq.com
Github:xjh199923
*/
/*二叉搜索树实现了以下功能
1.计算二叉搜索树的大小
2.前中后递归遍历二叉搜索树
3.前中后非递归遍历二叉搜索树
4.层序遍历二叉搜索树
5.二叉搜索树叶子个数
6.二叉搜索树的深度
7.二叉搜索树的结点的度
8.二叉搜索树的双亲以及左右子女的查找
9.查找某一节点
10.插入新的结点
11.删除某一节点
12.判断是否为平衡树
*/

#include <math.h>
#include "BinarySearchTree.h"
const int MAX_NUM = 100000;
vector<int> get_random(int n, int N);//产生n个小于N的随机数
void Menu()
{
	cout<<"+============================================================================+"<<endl;
	cout<<"|                          Welcome To BinarySearchTree                       |"<<endl;
	cout<<"+============================================================================+"<<endl;
	cout<<"|    1.二叉搜索树的大小      2.前序递归遍历      3.前序非递归遍历     4.中序递归遍历  |"<<endl;
	cout<<"+============================================================================+"<<endl;
	cout<<"|    5.中序非递归遍历        6.后序递归遍历      7.后序非递归遍历     8.层序遍历     |"<<endl;
	cout<<"+============================================================================+"<<endl;
	cout<<"|    9.叶子个数             10.树的深度        11.树结点的度       12.树结点的层次 |"<<endl;
	cout<<"+============================================================================+"<<endl;
	cout<<"|    13.树的双亲            14.树的左子女       15.树的右子女       16.查找结点    |"<<endl;
	cout<<"+============================================================================+"<<endl;
	cout<<"|    17.插入结点            18.删除结点         19.是否为平衡树      0.退出        |"<<endl;
	cout<<"+============================================================================+"<<endl;
	cout<<"Please choose:"<<endl;
}
int main() 
{
	srand((unsigned int)time(0));
	vector<int> randsample=get_random(20,MAX_NUM);
	BinarySearchTree<int>bt(randsample);
	BinaryTreeNode<int>* root=bt.GetRoot();
	Menu();
	int te;
	int choose=1;
	while(choose){
	cin>>choose;
	switch (choose) {		
		case 1:
			{
				cout<<"二叉树的大小是："<<bt.Size(root)<<endl;
			}
			break;
		case 2:
			{
				cout<<"前序递归遍历：";
				bt.PrevOrder(root);
				cout<<endl;
			}
			break;
		case 3:
			{
				cout<<"前序非递归遍历：";
				bt.PrevOrder_NonR();
				cout<<endl;
			}
			break;		
		case 4:
			{
				cout<<"中序递归遍历：";
				bt.InOrder(root);
				cout<<endl;
			}
			break;
		case 5:
			{
				cout<<"中序非递归遍历：";
				bt.InOrder_NonR();
				cout<<endl;
			}
			break;
		case 6:
			{
				cout<<"后序递归遍历：";
				bt.PostOrder(root);
				cout<<endl;
			}
			break;
		case 7:
			{
				cout<<"后序非递归遍历：";
				bt.PostOrder_NonR();
				cout<<endl;
			}
			break;		
		case 8:
			{
				cout<<"层序遍历二叉树：";
				bt.Leve1Order();
				cout<<endl;
			}
			break;
		case 9:
			{
				cout<<"二叉树叶子节点个数："<<bt.LeafSize(root)<<endl;
			}
			break;
		case 10:
			{
				cout<<"二叉树的深度："<<bt.Depth(root)<<endl;
			}
			break;
		case 11:
			{
				cout<<"请输入你要查询度的结点:"<<endl;
				cin>>te;
				if(bt.Search(te)){
					cout<<"这个节点的度为:"<<bt.DegreeofNode(te)<<endl;
				}
				else{
					cout<<"该结点不存在!"<<endl;
				}
			}
			break;		
		case 12:
			{
				cout<<"请输入你要查询层次的结点:"<<endl;
				cin>>te;
				if(bt.Search(te)){
					cout<<"这个节点的层次为:"<<bt.GetLevelofNode(te)<<endl;
				}
				else{
					cout<<"该结点不存在!"<<endl;
				}
			}
			break;
		case 13:
			{
				cout<<"请输入你要查询双亲的结点:"<<endl;
				cin>>te;
				if(bt.Search(te)){
					bt.ParentofNode(root,te);
				}
				else{
					cout<<"该结点不存在!"<<endl;
				}
			}
			break;
		case 14:
			{
				cout<<"请输入你要查询左子女的结点:"<<endl;
				cin>>te;
				if(bt.Search(te)){
					if(bt.LeftChildofNode(te)!=NULL)
					{
						cout<<"这个结点的左子女为:"<<bt.LeftChildofNode(te)->_data<<endl;
					}
					else{
						cout<<"该结点无左子女！"<<endl;
					}
				}
				else{
					cout<<"该结点不存在!"<<endl;
				}
			}
			break;
		case 15:
			{
				cout<<"请输入你要查询右子女的结点:"<<endl;
				cin>>te;
				if(bt.Search(te)){
					if(bt.RightChildofNode(te)!=NULL)
					{
						cout<<"这个结点的右子女为: "<<bt.RightChildofNode(te)->_data<<endl;
					}
					else{
						cout<<"该结点无右子女！"<<endl;
					}
				}
				else{
					cout<<"该结点不存在!"<<endl;
				}
				}
			break;		
		case 16:
			{
				cout<<"请输入你要查询的结点:"<<endl;
				cin>>te;
				if(bt.Search(te)){
					cout<<"该结点存在！"<<endl;
				}
				else{
					cout<<"该结点不存在!"<<endl;
				}
			}
			break;
		case 17:
			{
				cout<<"请输入你要插入的结点:"<<endl;
				cin>>te;
				if(bt.Search(te)){
					cout<<"该结点已经存在!"<<endl;
				}
				else{
					bt.insert(root,te);
				}
			}
			break;
		case 18:
			{
				cout<<"请输入你要删除的结点:"<<endl;
				cin>>te;
				if(!bt.Search(te)){
					cout<<"该结点不存在!"<<endl;
				}
				else{
					bt.Delete(te);
					cout<<"删除成功!"<<endl;
				}
			}
			break;
		case 19:
			{
				if(bt.isBalanced(root)){
					cout<<"该树为平衡树！"<<endl;
				}
				else{
					cout<<"该树为不平衡树！"<<endl;
				}
			}
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		cout<<endl;
		Menu();
		}
		cout << endl;
		Menu();
	}
	return 0;
}
vector<int> get_random(int n, int N)
{
	vector<int> vec(N);//N代表初始状态分配的空间大小
	vector<int> out_vec;
	for(int i=0;i<N;++i)
	{
		vec[i]=i;
	}
	for (int i=0;i<n;++i)
	{
		int rand_value=rand()%N;
		out_vec.push_back(vec[rand_value]);
		vec[rand_value]=vec[N-1];//将数组vec的元素
		N--;
	}
	return out_vec;
}
