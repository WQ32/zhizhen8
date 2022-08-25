#include <stdio.h>

//指针例题
// 1.
int main()
{
	//数组名是首元素的地址
	//除这两种情况：
	//1. sizeof(数组名) - 数组名表示整个数组
	//2. &数组名        - 数组名表示整个数组
	//一维数组
	int a[] = {1,2,3,4};   // 4*4=16
	printf("%d\n", sizeof(a));		//16  sizeof(数组名)—计算的是数组总大小-单位是字节
	printf("%d\n", sizeof(a + 0));  //4/8   a+0不是数组名，还是首元素地址，地址大小4/8个字节
	printf("%d\n", sizeof(*a));		//4	  数组名表示首元素地址，*a就是首元素，首元素地址解引用
	printf("%d\n", sizeof(a+1));	//4/8 跳过一个元素，它还是一个元素的地址大小 
	printf("%d\n", sizeof(a[1]));	//4   第二个元素的大小
	printf("%d\n", sizeof(&a));		//4/8   &a取出的是数组的地址，也是地址，地址的大小就是4/8个字节（地址的大小不变）
	printf("%d\n", sizeof(*&a));	//16（一个整形解引用访问一个整形，一个字符解引用访问一个字符，
	// 一个数组解引用访问一个数组的大小）&a是数组的地址，数组的地址解引用访问的是数组
	// sizeof计算的就是数组的大小，单位是字节
	printf("%d\n", sizeof(&a + 1));	//4/8  &a是数组的地址，&a+1虽然地址跳过整个数组，它还是一个地址，是地址，大小就是4/8个字节//
	printf("%d\n", sizeof(&a[0]));	//4/8   取出第一个元素的地址，a[0]是第一个元素
	printf("%d\n", sizeof(&a[0]+1));//4/8	取出第二个元素的地址
	return 0;
}

// 2.
int main()
{
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", sizeof(arr));       //6*1=6字节  sizeof计算都是数组大小
	printf("%d\n", sizeof(arr + 0));   //4/8  这里指首元素地址，地址大小都是4/8个字节
	printf("%d\n", sizeof(*arr));      //1  arr是首元素地址，*arr就是首元素，首元素是字符
	printf("%d\n", sizeof(arr[1]));    //1
	printf("%d\n", sizeof(&arr));      //4/8 &arr是数组地址，还是一个地址，大小4/8
	printf("%d\n", sizeof(&arr + 1));   //4/8 &arr+1还是一个地址，跳过整个数组
	printf("%d\n", sizeof(&arr[0] + 1));//4/8  这里是第二个元素的地址
	return 0;
}

// 3.
int main()
{
	//strlen求字符串长度，找到'\0'截止，传递至给strlen函数计算,参数是地址
	char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n", strlen(arr));       //1随机值 ，arr中没有‘\0’,arr这里指首元素地址，从开头开始数，直到‘\0’
	printf("%d\n", strlen(arr + 0));   //2随机值，arr+0也是从首元素开始数长度
	//printf("%d\n", strlen(* arr));      //代码错误，解引用后是首元素，即'a'，它的ascii码是97，函数就会把97看做是参数使用，然后就会错误
	//printf("%d\n", strlen(arr[1]));    //和上一样，传入'b',相当于把98当成了地址，错误
	printf("%d\n", strlen(&arr));      //3随机值，&arr取得是数组的地址，还是相当于从首元素地址处开始向后数
	// 1 2 3的随机值都一样
	printf("%d\n", strlen(&arr + 1));   //随机值，= 1 2 3 的随机值-6，它跳过了已整个数组
	printf("%d\n", strlen(&arr[0] + 1));//随机值，= 1 2 3 的随机值-1
	return 0;
}