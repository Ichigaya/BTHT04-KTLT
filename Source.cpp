#include <iostream>
using namespace std;


bool ktnt(int x)
{
	if (x <= 1) return false;
	if ((x == 2) || (x == 3) || (x == 5)) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i <= x / 2; i += 2)
	if (x % i == 0) return false;
	return true;
}

bool ktht(int x)
{
	if (x == 1) return true;
	int temp = 0;
	for (int i = 1; i < x; i++)
	if (x % i == 0) temp += i;
	if (temp == x) return true;
	return false;
}

float luythua(int x, int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
		result = result*x;
	return result;
}

float sum(int n)
{
	int result = 0;
	for (int i = 1; i <= n; i++)
		result = result + i;
	return result;
}


/*-----------1-----------*/
int Tich(int n)
{
	if (n == 1) return 1;
	int result;
	result = n*Tich(n - 1);
	return result;
}


/*-----------2-----------*/
float Tongps1(int n)
{
	if (n == 0) return 1;
	float result;
	result = 1.0 / (2 * n + 1) + Tongps1(n - 1);
	return result;
}


/*-----------3-----------*/
float Tongps(int n)
{
	if (n == 0) return 1.0 / 2;
	float result;
	result = (2 * n + 1.0) / (2 * n + 2) + Tongps(n - 1);
	return result;
}


/*-----------4-----------*/
int Tongluythua(int n, int x)
{
	if (n == 1) return x;
	int result = 0;
	result = Tongluythua(n - 1, x) + luythua(x, n);
	return result;
}


/*-----------5-----------*/
float Tongluythua2(int n, int x)
{
	if (n == 1) return x;
	float result = 0;
	result = Tongluythua2(n - 1, x) + (luythua(x, n) / sum(n));
	return result;
}


/*-----------6-----------*/
int demnt(int *A, int n)
{
	if (n == 1)
	if (ktnt(A[n - 1])) return 1;
	else return 0;
	int result = 0;
	result = demnt(A, n - 1) + ktnt(A[n - 1]);
	return result;
}


/*-----------7-----------*/
int demht(int *A, int n)
{
	if (n == 1)
	if (ktht(A[n - 1])) return 1;
	else return 0;
	int result = 0;
	result = demht(A, n - 1) + ktht(A[n - 1]);
	return result;
}


/*-----------8-----------*/
int sumchan(int *A, int n)
{
	if (n == 1)
	if (A[n - 1] % 2 == 0) return A[n - 1];
	else return 0;
	int result = 0, temp = 0;
	if (A[n - 1] % 2 == 0) temp = A[n - 1];
	result = sumchan(A, n - 1) + temp;
	return result;
}


/*-----------9-----------*/
void vitrint(int *A, int n, int *&B, int &m)
{
	if (n==1) 
	if (ktnt(A[0]))
	{
		m = 0;
		B[m] = 0;
		m++;
		return;
	}
	else
	{
		m = 0;
		return;
	}
	if (ktnt(A[n - 1]))
	{
		vitrint(A, n - 1, B, m);
		B[m] = n - 1;
		m++;
	}
	else vitrint(A, n - 1, B, m);
}


/*-----------10-----------*/
void vitrichan(int *A, int n, int *&B, int &m)
{
	if (n == 1)
	if (A[0] % 2 == 0)
	{
		m = 0;
		B[m] = 0;
		m++;
		return;
	}
	else
	{
		m = 0;
		return;
	}
	if (A[n - 1] % 2 == 0)
	{
		vitrichan(A, n - 1, B, m);
		B[m] = n - 1;
		m++;
	}
	else vitrichan(A, n - 1, B, m);
}


/*-----------11-----------*/
bool ktlt(int *A, int i)
{
	if (i == 0) return false;
	if (A[i] > A[i - 1]) return true;
	return false;
}

int sumlt(int *A, int n)
{
	if (n == 1) return 0;
	int result = 0, temp = 0;
	if (ktlt(A, n - 1)) temp = A[n - 1];
	result = sumlt(A, n - 1) + temp;
}


/*-----------12-----------*/
float ktpb(int *A, int n, int x)
{
	for (int i = 0; i < n; i++)
	if (A[i] == x) return 0;
	return 1;
}

float demphanbiet(int *A, int n)
{
	if (n == 1) return 1;
	float result = 0;
	result = demphanbiet(A, n - 1) + ktpb(A, n - 1, A[n]);
	return result;
}


void main()
{
	int *A = new int[100];
	int *B = new int[100];
	int n, m, x;
	cout << "Nhap so n: "; cin >> n;
	cout << "Nhap so x: "; cin >> x;
	cout << "- S(n)=" << Tich(n) << endl;
	cout << "- S(n)=" << Tongps1(n) << endl;
	cout << "- S(n)=" << Tongps(n) << endl;
	cout << "- S(n,x)=" << Tongluythua(n, x) << endl;
	cout << "- S(n,x)=" << Tongluythua2(n, x) << endl;
	cout << "Nhap so phan tu mang 1 chieu: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "A[" << i << "]= "; cin >> A[i];
	}
	cout << "So luong so nguyen to = " << demnt(A, n) << endl;
	cout << "So luong so hoan thien= " << demht(A, n) << endl;
	cout << "Tong cac so chan = " << sumchan(A, n) << endl;

	vitrint(A, n, B, m);
	cout << "Vi tri cac phan tu nguyen to: " << endl;
	for (int i = 0; i < m; i++)
		cout << B[i] << " ";
	cout << endl;

	vitrichan(A, n, B, m);
	cout << "Vi tri cac phan tu chan: " << endl;
	for (int i = 0; i < m; i++)
		cout << B[i] << " ";
	cout << endl;
	cout << "Tong cac so lon hon so lien truoc = " << sumlt(A, n) << endl;
	cout << "So luong gia tri phan biet trong mang = " << demphanbiet(A, n) << endl;

	system("pause");
}