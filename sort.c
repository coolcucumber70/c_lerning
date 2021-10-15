void swap(int*a,int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void InsertSort(int a[], int n) {
    int i, j;
    int temp;
    for (i = 1; i < n; ++i) {
        if (a[i] < a[i-1]) {
            temp = a[i];  
            for (j = i; a[j-1] > temp && j >= 1; --j) {
                a[j] = a[j-1];
            }
            a[j] = temp;
        }
    }
}
void BinaryInsertSort(int R[],int n) {
    int i,j,low,mid,high,temp;
    for(i=1; i<n; i++) {
        low=0;
        high=i-1;
        temp=R[i];
        // 下面的折半是为了在i元素的前面查找到合适的插入位置
        while(low <= high) {
            mid=(low+high)/2;
            if(R[mid]>temp) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        for(j=i-1;j>=high+1;j--) {
            R[j+1]=R[j];
        }
        R[j+1]=temp;   
    }
}
// 更小间隔的排序并没有破坏之前的排序后的相对性，但是排序的结果可能不一样了
void ShellSort(int arr[], int n) {
    int d,i;
    for ( d = n/2; d > 0; d /= 2) {
        // 下面的内容就是把上面插入排序中所有的1改为d，一共有5处修改，别忘了--j也要改
        for ( i = d; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= d && temp < arr[j-d]; j -= d) {
                arr[j] = arr[j-d];
            }
            arr[j] = temp;
        }
    }
}
void BubbleSort(int arr[], int n) {
    int temp,i,j;
    
    for ( i = 0; i < n; ++i) {
        for ( j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void QuickSort(int arr[], int l, int r) {
    if (l >= r) return;
    swap(&arr[l], &arr[rand()%(r-l+1)+l]);
    int v = arr[l];

    // arr[l+1...i) <= v, arr(j...r] >= v
    int i = l+1, j = r;  // 一边开，一边闭，所以初始值取端点值即可
    while (1) {
        while (i <= r && arr[i] < v) ++i;
        while (j >= l+1 && arr[j] > v) --j;
        if (i > j) break;
        swap(&arr[i++], &arr[j--]);
    }
    swap(&arr[l], &arr[j]);
    int p = j;
    
    QuickSort(arr, l, p-1);
    QuickSort(arr, p+1, r);
}
// 在原地堆排序中，元素是从数组下标0的位置开始存储的，因此i的左孩子应该为2*i+1
void __shiftDown(int arr[], int n, int k) {
    while (2*k+1 < n) {
        int j = 2*k + 1;
        if (j + 1 < n && arr[j+1] > arr[j]) {
            ++j;
        }
        if (arr[k] >= arr[j]) break;
        swap(&arr[j], &arr[k]);
        k = j;
    }
}
void heapSort3(int arr[], int n) {
    // heapify
    int i;
    for ( i = (n-1)/2; i >= 0; --i) {
        __shiftDown(arr, n, i);
    }

    for ( i = n-1; i > 0; --i) {
        swap(&arr[0], &arr[i]);
        __shiftDown(arr, i, 0);
    }
}
// 将arr[l...mid]和arr[mid+1...r]进行归并

void __merge(int arr[], int l, int mid, int r) {
    int aux[r-l+1];
    int i,k;
    for ( i = l; i <= r; ++i) {
        aux[i-l] = arr[i];
    }
     i = l;
     int j = mid+1;
    for ( k = l; k <= r; ++k) {
        // 首先处理i, j越界
        if (i > mid) {
            arr[k] = aux[j-l];
            ++j;
        } else if (j > r) {
            arr[k] = aux[i-l];
            ++i;
        } else if (aux[i-l] <= aux[j-l]) {
            arr[k] = aux[i-l];
            ++i;
        } else {
            arr[k] = aux[j-l];
            ++j;
        }
    }
}
// 递归使用归并排序，对arr[l...r]的范围进行排序

void __mergeSort(int arr[], int l, int r) {
    if (l >= r) return;
    int mid = l + (r-l)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if (arr[mid] > arr[mid+1]) {  // 优化处理，使之能够更好处理近乎有序的数组
        __merge(arr, l, mid, r);
    }
}





