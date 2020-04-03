#include<iostream>
using namespace std;
void createheap(int *arr,int size);
void del(int *arr,int *size);
void insert(int *arr,int *size);
void display(int *arr,int size);
int main()
{
	int a,b,c,temp,size;
	cout << "Enter the number of elements of array" << endl;
	cin >> size;
	int arr[100];
	cout << "Enter the elements" << endl;
	for(a=1;a<=size;a++)
		cin >> arr[a];
	for(a=1;a<=size;a++)
		cout << arr[a] << " ";
	cout << "Enter the operation to be performed" << endl;
	while(1)
	{
		cout << "1.Create a Heap\n2.Insert a element in heap\n3.Delete Root\n4.Display\n5.Exit" << endl;
		cin >> a;
		switch(a)
		{
			case 1:
				createheap(arr,size);
				break;
			case 2:
				insert(arr,&size);
				break;
			case 3:
				del(arr,&size);
				break;	
			case 4:
				display(arr,size);
				break;
			case 5:
				exit(0);
			default:
				cout << "Enter the right key" << endl;			
		}
	}	
	cout << endl;	
	return 0;	
}
void createheap(int *arr,int size)
{
	int a,b,c,temp,ishan;
	for(a=2;a<=size;a++)
	{
		temp = a;
		while(temp/2 >= 1 && arr[temp/2] < arr[temp])
		{
			b = arr[temp];
			arr[temp] = arr[temp/2];
			arr[temp/2] = b;
			temp = temp / 2;
		}
	}
}
void del(int *arr,int *size)
{
	int a,b,c,temp,ishan;
	b = arr[1];
	arr[1] = arr[*size];
	temp = 1;
	while(1)
	{
		if(arr[2*temp] > arr[2*temp+1] && arr[2*temp] > arr[temp] && 2*temp < *size)
		{
			b = arr[2*temp];
			arr[2*temp] = arr[temp];
			arr[temp] = b;
			temp = temp * 2;
		}
		else if(arr[2*temp+1] > arr[2*temp] && arr[2*temp+1] > arr[temp] && 2*temp+1 < *size)
		{
			b = arr[2*temp+1];
			arr[2*temp+1] = arr[temp];
			arr[temp] = b;
			temp = temp * 2+1;
		}
		else if(arr[2*temp+1] == arr[2*temp] && arr[2*temp+1] > arr[temp] && 2*temp+1 < *size)
		{
			b = arr[2*temp+1];
			arr[2*temp+1] = arr[temp];
			arr[temp] = b;
			temp = temp * 2+1;
		}
		else
			break;
	}
	arr[*size] = b;
	*size = *size - 1;
}
void insert(int *arr,int *size)
{
	int a,b,c,temp,ishan;
	cout << "Enter the element to be inserted" << endl;
	cin >> b;
	*size = *size + 1;
	arr[*size] = b;
	temp = *size;
	while(temp/2 > 0 && arr[temp/2] < arr[temp])
	{
		b = arr[temp/2];
		arr[temp/2] = arr[temp];
		arr[temp] = b;
		temp = temp / 2;
	}
}
void display(int *arr,int size)
{
	for(int a=1;a<=size;a++)
		cout << arr[a] << " ";
	cout << endl;	
}
