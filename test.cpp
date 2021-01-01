#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告


#include <stdio.h>
#include <assert.h>

//实现memcpy 和memmove功能函数
void *my_memcpy(void*, const void*, size_t );
void* my_memmove(void*, const void*, size_t);
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,0 };
	int b[10] = { 0 };
	//my_memcpy(b, a,  sizeof(a));//此函数只能拷贝不同空间 地址重合的数据

	my_memmove(&a[3], a, 20);

	//memcpy()
	return 0;
}


void* my_memcpy(void* dest, const void* src, size_t i_count)//将src中的数据拷贝到dest中 拷贝i_count个字节
{
	assert(dest);
	assert(src);
	char* dest1 = (char*)dest;
	char* src1 = (char*)src;
	while (i_count--)
	{
		*dest1 = *src1;
		dest1++;
		src1++;
	}
	return dest;
}


void* my_memmove(void* dest, const void*src, size_t i_count)//将src中的数据拷贝到dest中 拷贝i_count个字节 可以地址重复
{
	assert(dest);
	assert(src);
	char* dest1 = (char*)dest;
	char* src1 = (char*)src;
	if (dest>src)//如果dest位置位于src坐标  从后往前拷贝
	{
		dest1 = dest1 + i_count-1;
		src1 = src1 + i_count-1;
		while (i_count--)
		{
			*dest1 = *src1;
			src1--;
			dest1--;
		}
	}
	else//如果dest位置位于src右边  从前往后拷贝
	{
		while (i_count--)
		{
			*dest1 = *src1;
			src1++;
			dest1++;
		}
	}
	return dest;
}