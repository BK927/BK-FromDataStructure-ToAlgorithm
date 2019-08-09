#pragma once

namespace bkDS
{
	namespace node
	{
		template<typename T>
		class BinaryNode
		{
		public:
			BinaryNode(const T& data) : Data(data), Parent(nullptr), Left(nullptr), Right(nullptr)
			{
			}
			BinaryNode(const T& data, BinaryNode* parent, BinaryNode* left = nullptr, BinaryNode* right = nullptr) : Data(data), Parent(parent), Left(left), Right(right)
			{
			}
			~BinaryNode() = default;

			bool IsLeaf() const;

			T Data;
			BinaryNode* Parent;
			BinaryNode* Left;
			BinaryNode* Right;
		};

		template<typename T>
		inline bool BinaryNode<T>::IsLeaf() const
		{
			return Left == nullptr && Right == nullptr;
		}
	}
}