#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10
void cal(void (*sort)(int *, int), int a[], int len);
void cal1(void (*sort1)(int *, int,int), int a[], int len);
void swap(int *a, int *b);
void InsertSort(int a[], int n);       //直接插入
void BinaryInsertSort(int R[], int n); //折半插入
void ShellSort(int arr[], int n);
void BubbleSort(int arr[], int n);       //冒泡排序
void QuickSort(int a[], int l, int r);//快速排序
void my_QuickSort(int a[], int l, int r);//快速排序
void SelectSort(int arr[], int n);
void __shiftDown(int arr[], int n, int k);
void heapSort(int arr[], int n);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int mid, int r);
int findtheKMin(int a[],int n,int k);
int main()
{
     int a[N]={3,1,4,6,2,9,5,8,7,10};
    //  int b[N]={3,1,4,6,2,9,5,8,7,10};
    //  int c[N]={3,1,4,6,2,9,5,8,7,10};
    //  int d[N]={3,1,4,6,2,9,5,8,7,10};
     //int e[N]={3,1,4,6,2,9,5,8,7,10};
    // cal(BinaryInsertSort, a, 10);
    // cal(heapSort,c,10);
    // cal1(QuickSort,b,10);
    // cal1(mergeSort,d,10);
    int result=findtheKMin(a,10,3);
    printf("%d\n",result);


    
    return 0;
}
void cal(void (*sort)(int *, int), int a[], int len)//函数作为参数
{
    time_t start = clock();
    int i;
    sort(a, len);
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    time_t finish = clock();
    double Total_time = (double)(finish - start)* 1000000000 / CLOCKS_PER_SEC;
    printf("%lf\n", Total_time );
}
void cal1(void (*sort1)(int *, int,int), int a[], int len)//函数作为参数
{
    time_t start = clock();
    int i;
    sort1(a, 0,len-1);
    for(i=0;i<N;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    time_t finish = clock();
    double Total_time = (double)(finish - start)* 1000000000 / CLOCKS_PER_SEC;
    printf("%lf\n", Total_time );
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void InsertSort(int a[], int n)
{
    int i, j;
    int temp;
    for (i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            temp = a[i];
            for (j = i; a[j - 1] > temp && j >= 1; --j)
            {
                a[j] = a[j - 1];
            }
            a[j] = temp;
        }
    }
}
void BinaryInsertSort(int R[], int n)
{
    int i, j, low, mid, high, temp;
    for (i = 1; i < n; i++)
    {
        low = 0;
        high = i - 1;
        temp = R[i];
        // 下面的折半是为了在i元素的前面查找到合适的插入位置
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (R[mid] > temp)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; j--)
        {
            R[j + 1] = R[j];
        }
        R[j + 1] = temp;
    }
}
// 更小间隔的排序并没有破坏之前的排序后的相对性，但是排序的结果可能不一样了
void ShellSort(int arr[], int n)
{
    int d, i;
    for (d = n / 2; d > 0; d /= 2)
    {
        // 下面的内容就是把上面插入排序中所有的1改为d，一共有5处修改，别忘了--j也要改
        for (i = d; i < n; ++i)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= d && temp < arr[j - d]; j -= d)
            {
                arr[j] = arr[j - d];
            }
            arr[j] = temp;
        }
    }
}
void BubbleSort(int arr[], int n)
{
    int temp, i, j;

    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void  QuickSort(int a[], int l, int r)
{
    int tmp = a[l];
    int p = l, q = r;
    if (r <= l)
        return;
    while (l < r)
    {
        if (tmp < a[r] && (l < r))
        {
            r--;
        }
        a[l] = a[r];
        if (a[l] <= tmp && (l < r))
        {
            l++;
        }
        a[r] = a[l];
    }
    a[l] = tmp;
    QuickSort(a, p, l - 1);
    QuickSort(a, l + 1, q);
}
void SelectSort(int arr[], int n)
{
    int i, j, k = 0;
    for (i = 0; i < n; i++)
    {
        int k = i;
        for (j = i + 1; j < n; j++)
        {
            arr[k] > arr[j];
            k = j;
        }
        int tmp = arr[i];
        arr[i] = arr[k];
        arr[k] = tmp;
    }
}
// 在原地堆排序中，元素是从数组下标0的位置开始存储的，因此i的左孩子应该为2*i+1
void __shiftDown(int arr[], int n, int k)
{
    while (2 * k + 1 < n)
    {
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j + 1] > arr[j])
        {
            ++j;
        }
        if (arr[k] >= arr[j])
            break;
        swap(&arr[j], &arr[k]);
        k = j;
    }
}
void heapSort(int arr[], int n)
{
    // heapify
    //这一步就完成了堆的组成，堆的最大项第一项就到手里了
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
    {
        __shiftDown(arr, n, i);
    }

    for (i = n - 1; i > 0; --i)
    {
        swap(&arr[0], &arr[i]);
        __shiftDown(arr, i, 0);
    }
}
//将arr[l...mid]和arr[mid+1...r]进行归并

// void merge(int arr[], int l, int mid, int r)
// {
//     int aux[r - l + 1];
//     int i, k;
//     for (i = l; i <= r; ++i)
//     {//
//         aux[i - l] = arr[i];
//     }//这一步，我把数组复制到了aux数组中
//     i = l;
//     int j = mid + 1;
//     for (k = l; k <= r; ++k)
//     {
//         // 首先处理i, j越界
//         if (i > mid)
//         {
//             arr[k] = aux[j - l];
//             ++j;
//         }
//         else if (j > r)
//         {
//             arr[k] = aux[i - l];
//             ++i;
//         }
//         else if (aux[i - l] <= aux[j - l])
//         {
//             arr[k] = aux[i - l];
//             ++i;
//         }
//         else
//         {
//             arr[k] = aux[j - l];
//             ++j;
//         }
//     }
// }
//递归使用归并排序，对arr[l...r]的范围进行排序

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    if (arr[mid] > arr[mid + 1])
    { // 优化处理，使之能够更好处理近乎有序的数组
        merge(arr, l, mid, r);
    }
}
int findtheKMin(int a[],int n,int k)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int m=0;
        for(j=1;j<n-i;j++)
        {
            if(a[j]>a[m])
               m=j;
        }
        if(i==k-1)
        {
            return a[m];
        }
        int tmp=a[m];
        a[m]=a[n-i];
        a[n-i]=tmp;
    }

}
void my_QuickSort(int a[], int l, int r){
    int tmp=a[l];
    int low=l,high=r;
    while(low<high)
    {
        while(tmp<a[high])high--;
        a[low]=a[high];
        while(a[low]<tmp)low++;
        a[high]=a[low];
    }
    a[low]=tmp;
    my_QuickSort(a,l,low-1);
    my_QuickSort(a,low+1,r);
}

