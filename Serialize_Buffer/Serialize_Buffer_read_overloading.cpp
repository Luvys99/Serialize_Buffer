#include "Serialize_Buffer.h"
#include <string.h>
#include <cassert>


Serializer& Serializer::operator >> (unsigned char& uchvalue)
{
	// 언직렬화 하려는 데이터의 크기보다 버퍼 내의 데이터 크기가 작을 때 로그남기고 종료
	if (GetUseSize() < sizeof(unsigned char))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(unsigned char) )\n");
		return;
	}

	// 여기 역시 읽어올 버퍼의 주소에다가 포인터 캐스팅을 통해서 바라보는 자료형 크기만큼 값을 변수에 저장
	uchvalue = *(unsigned char*)GetReadPtr();
	MoveReadPos(sizeof(unsigned char));

	return *this;

}

Serializer& Serializer::operator >> (char& chvalue)
{
	if (GetUseSize() < sizeof(char))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(char) )\n");
		return;
	}

	chvalue = *(char*)GetReadPtr();
	MoveReadPos(sizeof(char));

	return *this;

}

Serializer& Serializer::operator >> (unsigned short& ushvalue)
{
	if (GetUseSize() < sizeof(unsigned short))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(unsigned short) )\n");
		return;
	}

	ushvalue = *(unsigned short*)GetReadPtr();
	MoveReadPos(sizeof(unsigned short));

	return *this;
}

Serializer& Serializer::operator >> (short& shvalue)
{
	if (GetUseSize() < sizeof(short))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(short) )\n");
		return;
	}

	shvalue = *(short*)GetReadPtr();
	MoveReadPos(sizeof(short));

	return *this;
}

Serializer& Serializer::operator >> (int& ivalue)
{
	if (GetUseSize() < sizeof(int))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(int) )\n");
		return;
	}

	ivalue = *(int*)GetReadPtr();
	MoveReadPos(sizeof(int));

	return *this;
}

Serializer& Serializer::operator >> (long& lvalue)
{
	if (GetUseSize() < sizeof(long))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(long) )\n");
		return;
	}

	lvalue = *(long*)GetReadPtr();
	MoveReadPos(sizeof(long));

	return *this;
}

Serializer& Serializer::operator >> (float& fvalue)
{
	if (GetUseSize() < sizeof(float))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(float) )\n");
		return;
	}

	fvalue = *(float*)GetReadPtr();
	MoveReadPos(sizeof(float));

	return *this;
}

Serializer& Serializer::operator >> (__int64& __ivalue)
{
	if (GetUseSize() < sizeof(__int64))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(__int64) )\n");
		return;
	}

	__ivalue = *(__int64*)GetReadPtr();
	MoveReadPos(sizeof(__int64));

	return *this;
}

Serializer& Serializer::operator >> (double& dvalue)
{
	if (GetUseSize() < sizeof(double))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(double) )\n");
		return;
	}

	dvalue = *(double*)GetReadPtr();
	MoveReadPos(sizeof(double));

	return *this;
}