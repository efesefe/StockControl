#include<stdio.h>

void input(int arr[][10]); //To enter amounts of products in each store

void stockControl(int arr[][10] ,int size,int pid , int sid);

void listProductsOfN(int arr[][10],int sid);

void listProductsInNnotM(int arr[][10] , int size,int nid , int mid);

void listProductsInMandN(int arr[][10], int size,int mid,int nid);

void listSorted(int arr[][10], int size, int* sortedid, int* sortedamount);

void update(int arr[][10],int namount,int sid , int pid);
int main(void)
{
	int decision, cont = 1, arr[10][10],k,l,dec,con=1, sam[10] , sid[10] ,ids,idp,n,m,nstock;
	for (k = 0; k < 10; k++)
	{
		for (l = 0; l < 10; l++)
		{
			arr[k][l] = 0;
		}
	}

	printf("***********************************************************\n");
	do
	{
		printf("Main Menu: \n0- Input product amount of stores\n1- Stock control with product id and store id\n");
		printf("2- List products\n3- Update stock\n4- Quit\n\n");
		scanf("%d", &decision);
		do 
		{
			switch (decision)
			{
			case 0:
				input(arr);
				printf("1- Continue\n2- Return main menu\n\n");
				scanf("%d", &cont);
				break;
				
			case 1:
				printf("Enter product id: ");
				scanf("%d", &idp);
				printf("Enter store id: ");
				scanf("%d", &ids);
				stockControl(arr, 10,ids,idp);
				printf("1- Continue\n2- Return main menu\n\n");
				scanf("%d", &cont);
				break;
			case 2:
				do
				{
					printf("1- List all products of store n\n");
					printf("2- List products exist in store n but not store m\n");
					printf("3- List products exist in both store n and store m\n");
					printf("4- List sorted product by stock\n");
					scanf("%d", &dec);
					switch (dec)
					{
					case 1:
						printf("Input store id: ");
						scanf("%d", &ids);
						listProductsOfN(arr,ids);
						printf("1- Continue\n2- Return main menu\n");
						scanf("%d", &con);
						break;
					case 2:
						printf("Select two stores to compare: ");
						scanf("%d %d", &n, &m);
						listProductsInNnotM(arr, 10,n,m);
						printf("1- Continue\n2- Return main menu\n");
						scanf("%d", &con);
						break;
					case 3:
						printf("Choose two stores: ");
						scanf("%d %d", &n, &m);
						listProductsInMandN(arr, 10,m,n);
						printf("\n\n1- Continue\n2- Return main menu\n");
						scanf("%d", &con);
						break;
					case 4:
						listSorted(arr, 10, sid, sam);
						printf("Total product amounts in order:\n");
						printf("Product ");
						for (k = 0; k < 10; k++)
						{
							printf("%3d", sid[k]);
						}
						printf("\n");
						printf("Amount  ");
						for (k = 0; k < 10; k++)
						{
							printf("%3d", sam[k]);
						}
						printf("\n");
						printf("1- Continue\n2- Return main menu\n");
						scanf("%d", &con);
						break;
					default:
						break;
					}

				} while (con == 1);
				break;

			case 3:
				printf("Select store 1-10: ");
				scanf("%d", &ids);
				printf("Enter product id in store %d: ", ids);
				scanf("%d", &idp);
				printf("Current stock of %d in store %d : %d ", idp, ids, arr[ids - 1][idp - 1]);
				printf("Enter new stock: ");
				scanf("%d", &nstock);
				update(arr,nstock,ids,idp);
				printf("\n");
				printf("1- Continue\n2- Return main menu\n");
				scanf("%d", &cont);
				break;
			case 4:
				printf("BYE...\n\n***********************************************************");
				cont = 0;
				break;
			default:
				break;
			
			}
			
		}
		while (cont == 1);
	} while (decision != 4);

	return 0;
}

void input(int arr[][10])
{
	
	int sid, pid;

	printf("Enter product id: ");
	scanf("%d", &pid);
	printf("Enter store id: ");
	scanf("%d", &sid);
	printf("Enter amount: ");
	scanf("%d", &arr[sid - 1][pid - 1]);

}

void stockControl(int arr[][10], int size,int pid , int sid)
{
	printf("Store %d: product %d amount: %d\n", sid, pid, arr[sid - 1][pid - 1]);
}

void listProductsOfN(int arr[][10],int sid)
{
	int k;
	
	printf("Store %d:\n", sid);
	printf("Product");
	for (k = 0; k < 10; k++)
	{
		printf("%3d",(k+1));
	}
	printf("\n");
	printf("Stock  ");
	for (k = 0; k < 10; k++)
	{
		printf("%3d",arr[sid - 1][k]);
	}
	printf("\n\n");
}

void listProductsInNnotM(int arr[][10], int size,int nid , int mid)
{
	int k, l;
	bool exists;
	
	printf("Products exist in store %d and not in store %d\n", nid, mid);
	printf("Product ");
	for (k = 0; k < size; k++)
	{
		exists = false;
		for (l = 0; l < size; l++)
		{
			if (arr[nid - 1][k] == arr[mid - 1][l])
			{
				exists = true;
			}
		}
		if (exists == false)
		{
			printf("%d ", (k + 1));
		}
	}
	printf("\n");
	printf("Amount ");
	for (k = 0; k < size; k++)
	{
		exists = false;
		for (l = 0; l < size; l++)
		{
			if (arr[nid - 1][k] == arr[mid - 1][l])
			{
				exists = true;
			}
		}
		if (exists == false)
		{
			printf("%d ", arr[nid - 1][k]);
		}	
	}
	printf("\n");
}

void listProductsInMandN(int arr[][10], int size,int mid , int nid)
{
	int k;
	bool exists;
	
	printf("Products available both store %d and %d: ", mid, nid);
	for (k = 0; k < size; k++)
	{
		exists = false;
		if (arr[mid - 1][k] > 0 && arr[nid - 1][k] > 0)
		{
			exists = true;
		}
		if (exists == true)
		{
			printf("%d ", (k + 1));
		}
	}
}

void listSorted(int arr[][10], int size, int* sortedid, int* sortedamount)
{
	int k, l, temp , sum , tempid;
	for (k = 0; k < size; k++)
	{
		sum = 0;
		for (l = 0; l < size; l++)
		{
			sum += arr[l][k];

		}
		sortedamount[k] = sum;
		sortedid[k] = k + 1;
	}
	for (k = 0; k < size ; k++)
	{
		for (l = 0; l < size; l++)
		{
			temp = sortedamount[k];
			tempid = k ;
			if (sortedamount[k] > sortedamount[l])
			{
				sortedamount[k] = sortedamount[l];
				sortedamount[l] = temp;
				sortedid[k] = sortedid[l];
				sortedid[l] = tempid;
				
			}
		}
	}
}

void update(int arr[][10],int namount,int sid , int pid)
{
	
	arr[sid - 1][pid - 1] = namount;
	if (arr[sid - 1][pid - 1] == 0)
	{
		printf("Product %d is out of stock in store %d\nDone!", pid, sid);
	}
	else
	{
		printf("New value of %d is %d\n", pid, arr[sid - 1][pid - 1]);
	}
}
