#pragma once
#include <stdio.h>


#ifndef __PACKET__
#define __PACKET__

class Serializer
{
	enum en_PACKET
	{
		BUFFER_DEFAULT = 1400
	};
private:
	int buffer_size;
	int use_size;
	char* s_buffer;
	int rear;
	int front;

public:
	Serializer() : buffer_size(BUFFER_DEFAULT), use_size(0), rear(0), front(0)
	{
		s_buffer = new char[BUFFER_DEFAULT];
		if (s_buffer == nullptr)
		{
			wprintf(L"buffer allocate failed!!\n");
			return;
		}
	}
	Serializer(int size) : buffer_size(size), use_size(0), rear(0), front(0)
	{
		s_buffer = new char[size];
		if (s_buffer == nullptr)
		{
			wprintf(L"buffer allocate failed!!\n");
			return;
		}
	}
	virtual ~Serializer()
	{
		delete[]s_buffer;
	}

	inline int GetBufferSize() { return buffer_size; }
	inline int GetUseSize()
	{ 
		use_size = rear - front;
		return use_size; 
	}
	inline char* GetBufferPtr() { return s_buffer; }
	inline char* GetWritePtr() { return &s_buffer[rear]; }
	inline char* GetReadPtr() { return &s_buffer[front]; }
	// 직렬화 하기 위해 집어 넣은 데이터의 크기를 확인하기 위함

	inline int MoveWritePos(int size)
	{
		rear += size;
		return size;
	}
	// 역직렬화 할 때 어디 까지 데이터를 꺼냈는지 확인하기 위함
	inline int MoveReadPos(int size)
	{
		front += size;
		return size;
	}
	inline void Clear() { rear = 0, front = 0; }

	// 데이터 얻기
	int DequeueData(char* chpDest, int isize);
	// 데이터 삽입
	int EnqueueData(char* chpSrc, int isize);

	// 연산자 오버로딩 대입이 발생하지 않게 차단!
	Serializer& operator = (Serializer& SrcMessage) = delete;

	// 연산자 오버로딩 Write 함수
	Serializer& operator << (unsigned char uchvalue);
	Serializer& operator << (char chvalue);

	Serializer& operator << (unsigned short ushvalue);
	Serializer& operator << (short shvalue);

	Serializer& operator << (int ivalue);
	Serializer& operator << (unsigned int ivalue);

	Serializer& operator << (long lvalue); // 운영체제에 따라 값이 들쭉 날쭉해서 unsinged long X
	Serializer& operator << (float fvalue); // 실수는 부호 비트가 무조건 1칸 할당되어 있어서 unsigned가 없음

	Serializer& operator << (__int64 __ivalue);
	Serializer& operator << (double dvalue);

	// 연산자 오버로딩 Read 함수
	Serializer& operator >> (unsigned char& uchvalue);
	Serializer& operator >> (char& chvalue);

	Serializer& operator >> (unsigned short& ushvalue);
	Serializer& operator >> (short& shvalue);

	Serializer& operator >> (unsigned int ivalue);
	Serializer& operator >> (int& ivalue);

	Serializer& operator >> (long& lvalue);
	Serializer& operator >> (float& fvalue);

	Serializer& operator >> (__int64& __ivalue);
	Serializer& operator >> (double& dvalue);

};

#endif