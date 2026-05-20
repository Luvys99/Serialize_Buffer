#include "Serialize_Buffer.h"
#include <string.h>
#include <cassert>

// 데이터 얻기
int Serializer::DequeueData(char* chpDest, int isize)
{
	// 빼내려는 데이터 크기보다 버퍼 안의 데이터 크기가 작으면 로그남기고 종료
	if (GetUseSize() < isize)
	{
		wprintf(L"GetData Error ( GetDataSize > GetUseSize )\n");
		return -1;
	}

	memcpy(chpDest, GetReadPtr(), isize);
	MoveReadPos(isize);

	//넣은 데이터 크기만큼 반환
	return isize;
}

// 데이터 삽입 ( 가변 크기 때문에 문자열과 문자열의 복사는 memcpy를 사용해야 됨 )
// 헤더 삽입에도 사용
int Serializer::EnqueueData(char* chpSrc, int isize)
{
	// 데이터를 저장했을 때 버퍼의 크기를 넘어서면 로그 남기고 함수 종료
	if (GetUseSize() + isize > buffer_size)
	{
		wprintf(L"EnqueueData Error ( GetUseSize() + isize > buffer_size )\n");
		return -1;
	}

	memcpy(GetWritePtr(), chpSrc, isize);
	MoveWritePos(isize);

	// 넣은 데이터 크기만큼 반환
	return isize;
}

Serializer& Serializer::operator << (unsigned char uchvalue)
{
	// 버퍼에 넣을 공간이 있으면 통과!
	if (GetUseSize() + sizeof(unsigned char) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(unsigned char) > buffer_size)\n");
		return;
	}

	// 데이터를 복사하지 않고 직접 포인터에 값을 저장 후에 rearpos 위치 옮김
	*(unsigned char*)GetWritePtr() = uchvalue;
	MoveWritePos(sizeof(unsigned char));

	// 연산자 오버로딩을 연속적으로 사용할 수 있게 객체 자신을 반환
	return *this;
}

Serializer& Serializer::operator << (char chvalue)
{
	if (GetUseSize() + sizeof(char) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(char) > buffer_size)\n");
		return;
	}

	*(char*)GetWritePtr() = chvalue;
	MoveWritePos(sizeof(char));

	return *this;
}

Serializer& Serializer::operator << (unsigned short ushvalue)
{
	if (GetUseSize() + sizeof(unsigned short) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(unsigned short) > buffer_size)\n");
		return;
	}

	// GetWritePtr의 반환형이 char*이기 때문에 short의 값을 온전하게 넣기 위해서 반환되는 값에다 포인터 캐스팅으로 바라봐야 한다. 
	*(unsigned short*)GetWritePtr() = ushvalue;
	MoveWritePos(sizeof(unsigned short));

	return *this;
}
Serializer& Serializer::operator << (short shvalue)
{
	if (GetUseSize() + sizeof(short) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(short) > buffer_size)\n");
		return;
	}

	*(short*)GetWritePtr() = shvalue;
	MoveWritePos(sizeof(short));

	return *this;
}

Serializer& Serializer::operator << (int ivalue)
{
	if (GetUseSize() + sizeof(int) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(int) > buffer_size)\n");
		return;
	}

	*(int*)GetWritePtr() = ivalue;
	MoveWritePos(sizeof(int));

	return *this;
}
Serializer& Serializer::operator << (long lvalue)
{
	if (GetUseSize() + sizeof(long) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(long) > buffer_size)\n");
		return;
	}

	*(long*)GetWritePtr() = lvalue;
	MoveWritePos(sizeof(long));

	return *this;
}
Serializer& Serializer::operator << (float fvalue)
{
	if (GetUseSize() + sizeof(float) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(float) > buffer_size)\n");
		return;
	}

	*(float*)GetWritePtr() = fvalue;
	MoveWritePos(sizeof(float));

	return *this;
}

Serializer& Serializer::operator << (__int64 __ivalue)
{
	if (GetUseSize() + sizeof(__int64) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(__int64) > buffer_size)\n");
		return;
	}

	*(__int64*)GetWritePtr() = __ivalue;
	MoveWritePos(sizeof(__int64));

	return *this;
}
Serializer& Serializer::operator << (double dvalue)
{
	if (GetUseSize() + sizeof(double) > buffer_size)
	{
		wprintf(L"operator << error ( GetUseSize() + sizeof(double) > buffer_size)\n");
		return;
	}

	*(double*)GetWritePtr() = dvalue;
	MoveWritePos(sizeof(double));

	return *this;
}
