#include<stdio.h>
unsigned char * serialize_int(unsigned char *buffer, int value, int index)
{
	buffer[index] = value >> 24;
	buffer[index + 1] = value >> 16;
	buffer[index + 2] = value >> 8;
	buffer[index + 3] = value;
	return buffer;
}
unsigned char* deserialize_uint32B(unsigned char *buffer, int* value)
{
	*value = 0;

	*value |= buffer[0] << 24;
	*value |= buffer[1] << 16;
	*value |= buffer[2] << 8;
	*value |= buffer[3];
	return buffer + 4;
}
void main()
{
	unsigned char buffer[20],*buff;
	int i = 2,value=0;
	buff=serialize_int(buffer,i, 0);
	buff = deserialize_uint32B(buffer, &value);
	printf("%d", value);
}