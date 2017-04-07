#include<stdio.h>
void find_max_height(int *parent_arr, int *depth_arr, int current_index)
{
	if (parent_arr[current_index] == -1)
	{
		depth_arr[current_index] = 0;
		return;
	}
	else{
		if (depth_arr[parent_arr[current_index]] == -1)
			find_max_height(parent_arr, depth_arr, parent_arr[current_index]);
		depth_arr[current_index] = depth_arr[parent_arr[current_index]] + 1;
	}
	find_max_height(parent_arr, depth_arr, current_index + 1);
}
void main()
{
	int parent_arr[] = { 5, 4, 4, 4, 7, 7, 5, -1, 5 };
	int depth_arr[] = { -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	find_max_height(parent_arr,depth_arr,0);
	int i = 0,max_height=0;
	for (i = 0; i < 9;i++)
	{
		if (depth_arr[i]>max_height)
			max_height = depth_arr[i];
	}
	printf("%d", max_height);
}