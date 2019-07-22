#pragma once
#include <cassert>

#include "BaseContainer.h"
#include "BinaryNode.h"

namespace bkDS
{
	namespace tree
	{
		template <typename T>
		class BinaryTree
		{
		public:
			BinaryTree();
			BinaryTree(BinaryNode<T>* root);
			BinaryTree(const BinaryTree<T>& rhs) = delete;
			~BinaryTree();

			BinaryTree<T>& operator=(const BinaryTree<T>& rhs) = delete;

			unsigned int GetCount() const;
			unsigned int GetHeight() const;
			unsigned int GetLeafCount() const;
			bool IsFull() const;
			bool IsEmpty() const;
			unsigned int GetLevel(T& node) const;
			unsigned int GetLevel(T&& node) const;
			bool IsBalanced() const;
			unsigned int GetPathLength() const;
			void Reverse();
			bool IsDisjointFrom(BinaryTree<T> that);
			bool IsValid() const;
			void Clear();

		private:
			void clearRecursive(BinaryNode<T>* node, BinaryNode<T>* deletionTarget);
			unsigned int getCountRecursive(BinaryNode<T>* node) const;
			unsigned int getLeafCountRecursive(BinaryNode<T>* node) const;
			unsigned int getHeightRecursive(BinaryNode<T>* node) const;

			BinaryNode<T>* mRoot;
		};

		template<typename T>
		inline BinaryTree<T>::BinaryTree() : mRoot(nullptr)
		{
		}

		template<typename T>
		inline BinaryTree<T>::BinaryTree(BinaryNode<T>* root) : mRoot(root)
		{
		}

		template<typename T>
		inline BinaryTree<T>::~BinaryTree()
		{
			clearRecursive(mRoot, nullptr);
		}

		template<typename T>
		inline unsigned int BinaryTree<T>::GetCount() const
		{
			if (mRoot == nullptr)
			{
				return 0;
			}

			unsigned int count = 0;
			BinaryNode<T>* current;
			BinaryNode<T>* pre;

			current = mRoot;
			while (current != nullptr)
			{
				if (current->GetLeft() == nullptr)
				{
					count++;
					current = current->GetRight();
				}
				else
				{
					/* Find the inorder predecessor of current */
					pre = current->GetLeft();
					while (pre->GetRight() != nullptr && pre->GetRight() != current)
					{

					}

					/* Make current as the right child of its inorder predecessor */
					if (pre->GetRight() == nullptr)
					{
						pre->GetRight() = current;
						current = current->GetLeft();
					}
					else /* Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor */
					{
						pre->GetRight() == nullptr;
						count++;
						current = current->GetRight();
					} /* End of if condition pre->right == NULL */
				} /* End of if condition current->left == NULL*/
			} /* End of while */

			return count
		}

		template<typename T>
		inline unsigned int BinaryTree<T>::GetHeight() const
		{
			return 0;
		}

		template<typename T>
		inline unsigned int BinaryTree<T>::GetLeafCount() const
		{

		}

		template<typename T>
		inline bool BinaryTree<T>::IsEmpty() const
		{
			return mRoot == nullptr;
		}

		template<typename T>
		inline void BinaryTree<T>::Clear()
		{
			clearRecursive(mRoot, nullptr);
			mRoot = nullptr;
		}

		template<typename T>
		inline void BinaryTree<T>::clearRecursive(BinaryNode<T>* node, BinaryNode<T>* deletionTarget)
		{
			if (deletionTarget != nullptr)
			{
				delete deletionTarget;
			}
			
			if (node == nullptr)
			{
				return;
			}

			clearRecursive(node->GetLeft(), nullptr);
			clearRecursive(node->GetRight(), node);
		}

		template<typename T>
		inline unsigned int BinaryTree<T>::getCountRecursive(BinaryNode<T>* node) const
		{
			if (node == nullptr)
			{
				return 0;
			}

			return 1 + getCount(node->GetLeft(), count);
			return 1 + getCount(node->GetRight(), count);
		}
		template<typename T>
		inline unsigned int BinaryTree<T>::getLeafCountRecursive(BinaryNode<T>* node) const
		{
			if (node == nullptr)
			{
				return 0;
			}

			if (node->IsLeaf())
			{
				return 1;
			}

			return getLeafCount(node->GetLeft(), count) + getLeafCount(node->GetRight(), count);
		}

		template<typename T>
		inline unsigned int BinaryTree<T>::getHeightRecursive(BinaryNode<T>* node) const
		{
			if (node = nullptr)
			{
				return 0;
			}

			unsigned int hLeft = getHeightRecursive(node->GetLeft());
			unsigned int hRight = getHeightRecursive(node->GetRight());
			return hLeft > hRight ? hLeft + 1 : hRight + 1;
		}
	}
}