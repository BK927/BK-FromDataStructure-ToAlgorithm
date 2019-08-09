#pragma once
#include <cassert>
#include <memory>

#include "BaseContainer.h"
#include "BinaryNode.h"
#include "LinkedQueue.h"

using namespace std;

namespace bkDS
{
	template<typename T>
	class RecursiveBSTree : public BaseContainer
	{
	public:
		RecursiveBSTree();
		RecursiveBSTree(const T& data);
		RecursiveBSTree(const RecursiveBSTree<T>& rhs);
		RecursiveBSTree(RecursiveBSTree<T>&& rhs) = default;
		~RecursiveBSTree();
		
		RecursiveBSTree<T>& operator=(const RecursiveBSTree<T>& rhs);
		bool operator==(const RecursiveBSTree<T>& rhs) const;

		node::BinaryNode<T>* GetRoot();
		void Insert(const T& data);
		void Insert(const T&& data);
		bool Remove(const T& data);
		bool Remove(const T&& data);
		unsigned int GetCount() const;
		unsigned int GetHeight() const;
		unsigned int GetLeafCount() const;
		bool IsComplete() const;
		unsigned int Level(T& data) const;
		unsigned int Level(T&& data) const;
		unsigned int PathLength() const;
		bool 

	private:
		node::BinaryNode<T>* copyRecursive(node::BinaryNode<T>* srcParent, node::BinaryNode<T>* destNode);
		void destructRecursive(node::BinaryNode<T>* node);
		void insertRecursive(node::BinaryNode<T>* parent, node::BinaryNode<T>* node, const T& data);
		bool removeRecursive(node::BinaryNode<T>* node, const T& data);
		unsigned int getHeightRecursive(node::BinaryNode<T>* node) const;
		unsigned int getLeafCount(node::BinaryNode<T>* node) const;
		bool isCompleteRecursive(node::BinaryNode<T>* node, const unsigned int index) const;
		unsigned int searchLevelRecursive(node::BinaryNode<T>* node, const unsigned int level, const T& data) const;
		unsigned int pathLengthRecursive(node::BinaryNode<T>* node, const unsigned int length) const;
		bool isEqualRecursive(node::BinaryNode<T>* node, node::BinaryNode<T>* rhsNode) const;

		node::BinaryNode<T>* mRoot;
	};

	template<typename T>
	inline RecursiveBSTree<T>::RecursiveBSTree() : mRoot(nullptr), mSize(0)
	{
	}

	template<typename T>
	inline RecursiveBSTree<T>::RecursiveBSTree(const T& data) : mSize(1)
	{
		mRoot = new node::BinaryNode<T>(data);
	}

	template<typename T>
	inline RecursiveBSTree<T>::RecursiveBSTree(const RecursiveBSTree<T>& rhs) : mSize(0)
	{
		mRoot = copyRecursive(nullptr, rhs.mRoot);
		assert(mSize == rhs.mSize);
	}

	template<typename T>
	RecursiveBSTree<T>::~RecursiveBSTree()
	{
		destructRecursive(mRoot);
		assert(mSize == 0);
	}

	template<typename T>
	inline RecursiveBSTree<T>& RecursiveBSTree<T>::operator=(const RecursiveBSTree<T>& rhs)
	{
		destructRecursive(mRoot);
		assert(mSize == 0);
		mRoot = copyRecursive(nullptr, rhs.mRoot);
		assert(mSize == rhs.mSize);
		return *this;
	}

	template<typename T>
	bool RecursiveBSTree<T>::operator==(const RecursiveBSTree<T>& rhs) const
	{
		return isEqualRecursive(mRoot, rhs.mRoot);
	}

	template<typename T>
	inline node::BinaryNode<T>* RecursiveBSTree<T>::GetRoot()
	{
		return mRoot;
	}

	template<typename T>
	inline void RecursiveBSTree<T>::Insert(const T& data)
	{
		insertRecursive(nullptr, mRoot, data);
	}

	template<typename T>
	inline void RecursiveBSTree<T>::Insert(const T&& data)
	{
		insertRecursive(nullptr, mRoot, data);
	}

	template<typename T>
	inline bool RecursiveBSTree<T>::Remove(const T& data)
	{
		return removeRecursive(mRoot, data);
	}

	template<typename T>
	inline bool RecursiveBSTree<T>::Remove(const T&& data)
	{
		return removeRecursive(mRoot, data);
	}

	template<typename T>
	inline unsigned int RecursiveBSTree<T>::GetCount() const
	{
		return mSize;
	}

	template<typename T>
	inline unsigned int RecursiveBSTree<T>::GetHeight() const
	{
		return getHeightRecursive(mRoot);
	}

	template<typename T>
	unsigned int RecursiveBSTree<T>::GetLeafCount() const
	{
		return getLeafCount(mRoot);
	}

	template<typename T>
	bool RecursiveBSTree<T>::IsComplete() const
	{
		return isCompleteRecursive(mRoot, 0);
	}

	template<typename T>
	inline unsigned int RecursiveBSTree<T>::Level(T& data) const
	{
		return searchLevelRecursive(mRoot, 1, data);
	}

	template<typename T>
	inline unsigned int RecursiveBSTree<T>::Level(T&& data) const
	{
		return searchLevelRecursive(mRoot, 1, data);
	}

	template<typename T>
	inline unsigned int RecursiveBSTree<T>::PathLength() const
	{
		return pathLengthRecursive(mRoot, 0);
	}

	template<typename T>
	node::BinaryNode<T>* RecursiveBSTree<T>::copyRecursive(node::BinaryNode<T>* srcParent, node::BinaryNode<T>* destNode)
	{
		if (destNode == nullptr)
		{
			return nullptr;
		}

		node::BinaryNode<T>* srcNode = new node::BinaryNode<T>(destNode->Data);
		++mSize;
		srcNode->Parent = srcParent;
		srcNode->Left = copyRecursive(srcNode, destNode->Left);
		srcNode->Right = copyRecursive(srcNode, destNode->Right);
		assert(srcNode->Left != nullptr && srcNode->Right != nullptr ? srcNode->Left->Data < srcNode->Right->Data : true);
		return srcNode;
	}

	template<typename T>
	void RecursiveBSTree<T>::destructRecursive(node::BinaryNode<T>* node)
	{
		if (node == nullptr)
		{
			return;
		}

		destructRecursive(node->Left);
		destructRecursive(node->Right);
		delete node;
		--mSize;
	}

	template<typename T>
	void RecursiveBSTree<T>::insertRecursive(node::BinaryNode<T>* parent,  node::BinaryNode<T>* node, const T& data)
	{
		if (node == nullptr)
		{
			node = new node::BinaryNode<T>(data, parent);
			if (parent->Data >= data)
			{
				parent->Left = node;
			}
			else
			{
				parent->Right = node;
			}
			++mSize;
			return;
		}
		assert(node->Left != nullptr && node->Right != nullptr ? node->Left->Data < node->Right->Data : true);
		node::BinaryNode<T>* candiNode;

		if (node->Data >= data)
		{
			candiNode = node->Left;
		}
		else
		{
			candiNode = node->Right;
		}

		insertRecursive(node, candiNode, data);
	}
	template<typename T>
	bool RecursiveBSTree<T>::removeRecursive(node::BinaryNode<T>* node, const T& data)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (node->Data == data)
		{
			if (node->IsLeaf())
			{
				if (node->Parent->Left == node)
				{
					node->Left = nullptr;
				}
				else
				{
					node->Right = nullptr;
				}

				delete node;
			}
			else if (node->Left == nullptr || node->Right nullptr)
			{
				node::BinaryNode<T>* succNode = (node->Left == nullptr) ? node->Right : node->Left;
				if (node->Parent->Left == node)
				{
					node->Left = succNode;
				}
				else
				{
					node->Right = succNode;
				}

				delete node;
			}
			else
			{
				node::BinaryNode<T>* succNode = node->Right;
				while (succNode->Left != nullptr)
				{
					succNode = succNode->Left;
				}

				if (succNode->Parent->Left == succNode)
				{
					succNode->Parent->Left = nullptr;
				}
				else
				{
					succNode->Parent->Right = nullptr;
				}

				succNode->Parent = node->Parent;
				succNode->Left = node->Left;
				succNode->Right = node->Right;

				if (succNode->Left != nullptr)
				{
					succNode->Left->Parent = succNode;
				}
				if (succNode->Right != nullptr)
				{
					succNode->Right->Parent = succNode;
				}

				if (node->Parent->Left == node)
				{
					node->Parent->Left = succNode;
				}
				else
				{
					node->Parent->Right = succNode;
				}

				delete node;
			}
			--mSize;
			return true;
		}

		node::BinaryNode<T>* passNode = (data <= node->Data) ? node->Left : node->Right;

		return removeRecursive(passNode, data);
	}

	template<typename T>
	unsigned int RecursiveBSTree<T>::getHeightRecursive(node::BinaryNode<T>* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}

		unsigned int hLeft = getHeightRecursive(node->Left);
		unsigned int  hRight = getHeightRecursive(node->Right);
		return (hLeft > hRight) ? (hLeft + 1) : (hRight + 1);
	}

	template<typename T>
	unsigned int RecursiveBSTree<T>::getLeafCount(node::BinaryNode<T>* node) const
	{
		if (node->Left == nullptr && node->Right == nullptr)
		{
			return 1;
		}

		return getLeafCount(node->Left) + getLeafCount(node->Right);
	}

	template<typename T>
	bool RecursiveBSTree<T>::isCompleteRecursive(node::BinaryNode<T>* node, const unsigned int index) const
	{
		if (node == nullptr)
		{
			return true;
		}
		if (index > mSize)
		{
			return false;
		}
		return isCompleteRecursive(node->Left, index * 2) && isCompleteRecursive(node->Right, index * 2 + 1);
	}

	template<typename T>
	unsigned int RecursiveBSTree<T>::searchLevelRecursive(node::BinaryNode<T>* node, const unsigned int level, const T& data) const
	{
		if (node == nullptr)
		{
			return 0;
		}
		if (node->Data == data)
		{
			return level;
		}
		return searchLevelRecursive(node->Left, level + 1, data) + searchLevelRecursive(node->Right, level + 1, data);
	}

	template<typename T>
	unsigned int RecursiveBSTree<T>::pathLengthRecursive(node::BinaryNode<T>* node, const unsigned int length) const
	{
		if (node == nullptr)
		{
			return 0;
		}
		return pathLengthRecursive(node->Left, length * 2 + 1) + pathLengthRecursive(node->Right, length * 2 + 1);
	}
	template<typename T>
	bool RecursiveBSTree<T>::isEqualRecursive(node::BinaryNode<T>* node, node::BinaryNode<T>* rhsNode) const
	{
		if (node == nullptr && rhsNode == nullptr)
		{
			return true;
		}
		else if((node == nullptr && rhsNode != nullptr) || (node != nullptr && rhsNode == nullptr))
		{
			 return false
		}
		
		if (node->Data != rhsNode->Data)
		{
			return false;
		}

		return isEqualRecursive(node->Left, rhsNode->Left) && isEqualRecursive(node->Right, rhsNode->Right);
	}
}