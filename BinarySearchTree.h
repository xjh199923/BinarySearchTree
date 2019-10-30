#include<iostream>
#include<stack>
#include<queue>
#include <iomanip>
using namespace std;
template<class T>
//定义二叉树的节点结构体
struct BinaryTreeNode
{
	BinaryTreeNode <T>* _left;
	BinaryTreeNode <T>* _right;
	T _data;
	BinaryTreeNode(T &data)
		:_left(NULL)
		,_right(NULL)
		,_data(data)
	{}
};

template<class T>
class BinarySearchTree
{
	private:
		BinaryTreeNode<T>* _root;
	public:
		//无参的构造函数
		BinarySearchTree()
		:_root(NULL){}
		BinarySearchTree(vector<T> v)
		{
			_root=NULL;
			for (int i = 0; i < v.size(); i++)
			{
				insert(_root,v[i]);
			}	
		}
		//复制构造函数
		BinarySearchTree(const BinarySearchTree<T> &s)
		{_root=CopyBintTree(s.GetRoot());}
		BinaryTreeNode<T>* GetRoot()
		{return  this->_root;}
		//递归先序遍历
		void PrevOrder(BinaryTreeNode<T>* root);
		//非递归先序遍历
		void PrevOrder_NonR();
		//递归中序遍历二叉树
		void InOrder(BinaryTreeNode<T>* root);
		//非递归中序遍历
		void InOrder_NonR();
		//递归后续遍历
		void PostOrder(BinaryTreeNode<T>* root);
		//非递归后序遍历
		void PostOrder_NonR();
		//层序遍历二叉树
		void Leve1Order();
		int Size(BinaryTreeNode<T>* root);
		//二叉搜索树的深度
		int Depth(BinaryTreeNode<T>* root);
		//递归求二叉搜索树叶子节点的个数
		int LeafSize(BinaryTreeNode<T>* root);
		//求节点的度
		int DegreeofNode(T tmp);
		//求节点的层次
		void level(BinaryTreeNode<T>* root,int val,int &ans,int lev);
		int GetLevelofNode(T tmp);
		//二叉搜索树的复制
		BinaryTreeNode<T>* CopyBintTree(BinaryTreeNode<T>* originNode);
		//寻找二叉搜索树某一节点的双亲
		void ParentofNode(BinaryTreeNode<T>* r,T data);
		//寻找二叉搜索树某一节点的左子女
		BinaryTreeNode<T>* LeftChildofNode(T tmp);
		//寻找二叉搜索树某一节点的右子女	
		BinaryTreeNode<T>* RightChildofNode(T tmp);
		//查找某一个结点
		BinaryTreeNode<T>* FindNode(T tmp,BinaryTreeNode<T>* &root);
		bool insert(BinaryTreeNode<T>* &root, T val);//二叉搜索树的插入一个结点
		bool Delete(T val);//删除某一个结点
		bool Search(T x);//二叉搜索树的搜索
		BinaryTreeNode<T> * Remove(BinaryTreeNode<T> * &root,T val);//二叉搜索树的删除结点
		bool isBalanced(BinaryTreeNode<T> * &root);//判断是否为平衡二叉树
		
};
template<class T>
inline void BinarySearchTree<T>::PrevOrder(BinaryTreeNode<T>* root)
{		
	if(root==NULL)
	return;
	cout<<root->_data<<" ";
	PrevOrder(root->_left );
	PrevOrder(root->_right);
}
template<class T>
inline void BinarySearchTree<T>::PrevOrder_NonR()
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T>* cur=_root;
	while(cur||!s.empty())
	{
		if(cur)
		{//先将左子树遍历输出后压栈
		cout<<cur->_data <<" ";
		s.push(cur);
		cur=cur->_left;
		}
		else{//当左子树为空时开始访问右子树
		cur=s.top ();
		s.pop();
		cur=cur->_right;
		}
		}
}
template<class T>
inline void BinarySearchTree<T>::InOrder(BinaryTreeNode<T>* root)
{
	if(root==NULL)
		return;
	InOrder(root->_left );
	cout<<root->_data <<" ";
	InOrder(root->_right );
}
template<class T>
inline void BinarySearchTree<T>::PostOrder(BinaryTreeNode<T>* root)
{
	if(root!=NULL)
	{
		PostOrder(root->_left);
		PostOrder(root->_right);
		cout<<root->_data<<" ";
	}
}
template<class T>
inline void BinarySearchTree<T>::PostOrder_NonR()
{
	stack<BinaryTreeNode<T>*> s;
	BinaryTreeNode<T>* cur=_root;
	BinaryTreeNode<T>* prev=NULL;//设置标志域
	s.push(_root);
	while(!s.empty())
	{
		cur=s.top();
		if((cur->_left ==NULL&&cur->_right ==NULL)
			||(prev!=NULL&&(prev==cur->_left ||prev ==cur->_right )))
		{  
			cout<<cur->_data<<" ";
			prev=cur;
			s.pop();
		}
		else
		{
			if(cur->_right!=NULL)
			s.push(cur->_right);
			if(cur->_left!=NULL)
			s.push(cur->_left); 
		}
	}

}
/*按层次顺序访问二叉树的处理需要利用一个队列。
在访问二又树的某一层结点时，把下一层结点指针预先
记忆在队列中，利用队列安排逐层访问的次序。因此，每
当访问一个结点时，将它的子女依次加到队列的队尾，然
后再访问已在队列队头的结点。这样可以实现二叉树结
点的按层访问。*/
template<class T>
inline void BinarySearchTree<T>::Leve1Order()
{
	queue<BinaryTreeNode<T>*>q;
	if(_root!=NULL)
	{
		q.push(_root);
	}
	while(!q.empty())
	{
		BinaryTreeNode<T>* front=q.front();
		cout<<front->_data <<" ";
		if(front->_left!=NULL){
			q.push(front->_left);
		}
		if(front->_right!=NULL)
		q.push(front->_right);
		q.pop();
	}
	cout<<endl;
}
template<class T>
inline void BinarySearchTree<T>::InOrder_NonR()
{
	BinaryTreeNode<T>* cur=_root;
	stack<BinaryTreeNode<T>*> s;
		while(cur||!s.empty())//cur非空或者栈非空
		{
			if(cur)
			{
				s.push(cur);//根节点进栈遍历左子树
				cur=cur->_left;
			}
			else
			{
				BinaryTreeNode<T>* top=s.top();
				cout<<top->_data<<" ";
				s.pop();
				cur=top->_right;
			}
		}
		cout<<endl;
}
template<class T>
inline int BinarySearchTree<T>::Size(BinaryTreeNode<T>* root)
{
	static size_t Ssize=0;
	if(root==NULL)
		return 0;
	++Ssize;
	Size(root->_left);
	Size(root->_right);
	return Ssize;
}
template<class T>
inline int BinarySearchTree<T>::Depth(BinaryTreeNode<T>* root)
{	
	if(root==NULL)
	return 0;
	size_t left=Depth(root->_left )+1;
	size_t right=Depth(root->_right)+1;
	return (left>right)?left:right;
}
template<class T>
inline int BinarySearchTree<T>::LeafSize(BinaryTreeNode<T>* root)
{
	if(root==NULL)
		return 0;
	if(root->_left  ==NULL&&root->_right ==NULL)
	{
		return 1;
	}
	return LeafSize(root->_left )+LeafSize(root->_right );
}
//利用二叉树的层次遍历方法来统计各个节点的度	
template<class T>
inline int BinarySearchTree<T>::DegreeofNode(T tmp)
{
	queue<BinaryTreeNode<T>*>q;
		if(_root!=NULL)
		{
			q.push(_root);
		}
		while(!q.empty())
		{
			BinaryTreeNode<T>* cur=q.front();
			if(cur->_data==tmp){
				if((cur->_left==NULL&&cur->_right!=NULL)||(cur->_left!=NULL&&cur->_right==NULL))
				return 1;
				else if(cur->_left==NULL&&cur->_right==NULL){
					return 0;
				}
				else{
					return 2;
				}
			}
			if(cur->_left!=NULL){
				q.push(cur->_left);
			}
			if(cur->_right!=NULL)
			q.push(cur->_right);
			q.pop();
		}
		return -1;
}
template<class T>
inline BinaryTreeNode<T>* BinarySearchTree<T>::CopyBintTree(BinaryTreeNode<T>* originNode)
{
	if(originNode==NULL){
		return NULL;
	}
	BinaryTreeNode<T>* temp=new BinaryTreeNode<T>;
	temp->_data=originNode->_data;
	temp->_left=CopyBintTree(originNode->_left);
	temp->_right=CopyBintTree(originNode->_right);
	return temp;
}
template<class T>
inline BinaryTreeNode<T>* BinarySearchTree<T>:: LeftChildofNode(T tmp)
{
	queue<BinaryTreeNode<T>*>q;
	if(_root!=NULL)
	{
		q.push(_root);
	}
	while(!q.empty())
	{
		BinaryTreeNode<T>* cur=q.front();
		if(cur->_data==tmp&&cur->_left!=NULL){
			return cur->_left;
		}
		if(cur->_left!=NULL){
			q.push(cur->_left);
		}
		if(cur->_right!=NULL)
		q.push(cur->_right);
		q.pop();
	}
	return NULL;
}
template<class T>
inline BinaryTreeNode<T>* BinarySearchTree<T>::RightChildofNode(T tmp)
{
	queue<BinaryTreeNode<T>*>q;
	if(_root!=NULL)
	{
		q.push(_root);
	}
	while(!q.empty())
	{
		BinaryTreeNode<T>* cur=q.front();
		if(cur->_data==tmp&&cur->_right!=NULL){
			return cur->_right;
		}
		if(cur->_left!=NULL){
			q.push(cur->_left);
		}
		if(cur->_right!=NULL)
		q.push(cur->_right);
		q.pop();
	}
	return NULL;
}
template<class T>
inline void BinarySearchTree<T>::ParentofNode(BinaryTreeNode<T>* r,T data)
{
	if(r ==NULL)
	{
		return;
	}
	if(r->_left != NULL)//当左孩子存在的时候才进行判断，否则程序出错
	{
		if(r->_left->_data == data){
			cout<<"这个节点的双亲结点是:"<<r->_data<<endl;
		}
	}
	if(r->_right != NULL)//如左子树所示
	{
		if(r->_right->_data == data)    
		{
			cout<<"这个节点的双亲结点是:"<<r->_data<<endl;
		}
	}
	ParentofNode(r->_left,data);		
	ParentofNode(r->_right,data);
}
template<class T>
inline void BinarySearchTree<T>::level(BinaryTreeNode<T>* root,int val,int &ans,int lev)
{
	if(NULL==root)
		ans=-1;
	else if(root->_data==val)
		ans=lev;
	else
	{
		level(root->_left,val,ans,lev+1);//在左子树中查找
		if(ans==-1)
			level(root->_right,val,ans,lev+1);//在右子树中查找
		}
}
template<class T>
inline int BinarySearchTree<T>::GetLevelofNode(T tmp)
{
	int res=-1;
	level(_root,tmp,res,1);
	return res;	
}
template<class T>
inline  BinaryTreeNode<T>* BinarySearchTree<T>::FindNode(T tmp,BinaryTreeNode<T>* &root)
{
	if(root==NULL){
		return NULL;
	}
	else if(tmp<root->_data){
		return FindNode(tmp,root->_left);
	}
	else if(tmp>root->_data){
			return FindNode(tmp,root->_right);
		}
	else return root;
}
template <class T>
inline bool BinarySearchTree<T>::insert(BinaryTreeNode<T>* &root, T val)
{
	if (root == NULL)
	{
		root=new BinaryTreeNode<T>(val);
		return true;
	}
	else if(val<root->_data){
		insert(root->_left,val);
	}
	else if(val>root->_data){
			insert(root->_right,val);
		}
	return false;
}
template <class T>
inline bool BinarySearchTree<T>::Search(T x)
{
	if(this->FindNode(x,_root)==NULL)
	{
		return false;
	}
	else return true;
}
template <class T>
inline BinaryTreeNode<T> * BinarySearchTree<T>::Remove(BinaryTreeNode<T> * &root,T val)
{
	if (root == NULL)
			return NULL;

		if (root->_data > val)
			root->_left = Remove(root->_left, val);
		else if (root->_data < val)
			root->_right = Remove(root->_right, val);
		else
		{
			if (root->_left == NULL&&root->_right == NULL)
				root = NULL;
			else if (root->_left == NULL)
				root = root->_right;
			else if (root->_right == NULL)
				root = root->_left;
			else
			{
				BinaryTreeNode<T> *minnode = root->_right;
				while (minnode->_left != NULL)
					minnode = minnode->_left;
				root->_data = minnode->_data;
				root->_right = Remove(root->_right, minnode->_data);
			}
		}
		return root;
}
template <class T>
inline bool BinarySearchTree<T>::Delete(T val)
{
	if (!Search(val))
		return false;

	Remove(_root, val);
	return true;
}
template <class T>
inline bool BinarySearchTree<T>::isBalanced(BinaryTreeNode<T> * &root)
{
	if (!root)
		return true;
	if (!root->_left && !root->_right)
		return true;
	else if (abs(Size(root->_left) - Size(root->_right)) > 1)
			return false;
	else
			return isBalanced(root->_left) && isBalanced(root->_right);
}


