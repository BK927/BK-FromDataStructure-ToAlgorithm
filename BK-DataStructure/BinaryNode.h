#pragma once

namespace bkDS
{
	namespace tree
	{
		template <typename T>
		class BinaryNode
		{
		public:
			BinaryNode(T& data, BinaryNode<T>* left = nullptr, BinaryNode<T>* right = nullptr);
			BinaryNode(const BinaryNode<T>& rhs) = delete;

			BinaryNode& operator=(const BinaryNode<T>& rhs) = delete;

			void SetData(T& data);
			void SetData(T&& data);
			void SetLeft(BinaryNode<T>* left);
			void SetRight(BinaryNode<T>* right);

			T& GetData();
			BinaryNode<T>* GetLeft();
			BinaryNode<T>* GetRight();
			bool IsLeaf() const;

		protected:
			T mData;
			BinaryNode* mLeft;
			BinaryNode* mRight;
		};

		template<typename T>
		inline BinaryNode<T>::BinaryNode(T& data, BinaryNode<T>* left, BinaryNode<T>* right): mData(data), mLeft(left), mRight(right)
		{
		}

		template<typename T>
		inline void BinaryNode<T>::SetData(T& data)
		{
			mData = data;
		}

		template<typename T>
		inline void BinaryNode<T>::SetData(T&& data)
		{
			mData = data;
		}

		template<typename T>
		inline void BinaryNode<T>::SetLeft(BinaryNode<T>* left)
		{
			mLeft = left;
		}

		template<typename T>
		inline void BinaryNode<T>::SetRight(BinaryNode<T>* right)
		{
			mRight = right;
		}

		template<typename T>
		inline T& BinaryNode<T>::GetData()
		{
			return mData;
		}

		template<typename T>
		inline BinaryNode<T>* BinaryNode<T>::GetLeft()
		{
			return mLeft;
		}

		template<typename T>
		inline BinaryNode<T>* BinaryNode<T>::GetRight()
		{
			return mRight;
		}

		template<typename T>
		inline bool BinaryNode<T>::IsLeaf() const
		{
			return mLeft == nullptr && mRight == nullptr;
		}
	}
}