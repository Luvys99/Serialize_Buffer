#include "Serialize_Buffer.h"
#include <string.h>
#include <cassert>


Serializer& Serializer::operator >> (unsigned char& uchvalue)
{
	// 이전 오버로딩함수에서 에러가 발생했었다면? 아무것도 안하고 종료
	if (error_flag == true) { return *this; }

	// 언직렬화 하려는 데이터의 크기보다 버퍼 내의 데이터 크기가 작을 때 로그남기고 종료
	if (GetUseSize() < sizeof(unsigned char))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(unsigned char) )\n");
		error_flag = true;
		return *this;
	}

	// 여기 역시 읽어올 버퍼의 주소에다가 포인터 캐스팅을 통해서 바라보는 자료형 크기만큼 값을 변수에 저장
	uchvalue = *(unsigned char*)GetReadPtr();
	MoveReadPos(sizeof(unsigned char));

	return *this;

}

Serializer& Serializer::operator >> (char& chvalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(char))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(char) )\n");
		error_flag = true;
		return *this;
	}

	chvalue = *(char*)GetReadPtr();
	MoveReadPos(sizeof(char));

	return *this;

}

Serializer& Serializer::operator >> (unsigned short& ushvalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(unsigned short))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(unsigned short) )\n");
		error_flag = true;
		return *this;
	}

	ushvalue = *(unsigned short*)GetReadPtr();
	MoveReadPos(sizeof(unsigned short));

	return *this;
}

Serializer& Serializer::operator >> (short& shvalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(short))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(short) )\n");
		error_flag = true;
		return *this;
	}

	shvalue = *(short*)GetReadPtr();
	MoveReadPos(sizeof(short));

	return *this;
}

Serializer& Serializer::operator >> (unsigned int ivalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(unsigned int))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(unsigned int) )\n");
		error_flag = true;
		return *this;
	}

	ivalue = *(unsigned int*)GetReadPtr();
	MoveReadPos(sizeof(unsigned int));

	return *this;
}

Serializer& Serializer::operator >> (int& ivalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(int))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(int) )\n");
		error_flag = true;
		return *this;
	}

	ivalue = *(int*)GetReadPtr();
	MoveReadPos(sizeof(int));

	return *this;
}

Serializer& Serializer::operator >> (long& lvalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(long))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(long) )\n");
		error_flag = true;
		return *this;
	}

	lvalue = *(long*)GetReadPtr();
	MoveReadPos(sizeof(long));

	return *this;
}

Serializer& Serializer::operator >> (float& fvalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(float))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(float) )\n");
		error_flag = true;
		return *this;
	}

	fvalue = *(float*)GetReadPtr();
	MoveReadPos(sizeof(float));

	return *this;
}

Serializer& Serializer::operator >> (__int64& __ivalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(__int64))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(__int64) )\n");
		error_flag = true;
		return *this;
	}

	__ivalue = *(__int64*)GetReadPtr();
	MoveReadPos(sizeof(__int64));

	return *this;
}

Serializer& Serializer::operator >> (double& dvalue)
{
	if (error_flag == true) { return *this; }

	if (GetUseSize() < sizeof(double))
	{
		wprintf(L"operator >> error ( GetUseSize() < sizeof(double) )\n");
		error_flag = true;
		return *this;
	}

	dvalue = *(double*)GetReadPtr();
	MoveReadPos(sizeof(double));

	return *this;
}