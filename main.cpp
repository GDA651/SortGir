#include <iostream>
#include <Vector>
#include <stdlib.h>
#include <time.h>
#include <QTime>

using namespace std;
void sort_hoar(vector<int> &arr, int left, int right);
void sort_merge (vector<int> &arr, int left, int right, int num);
void sort_bubble (vector<int> &arr, int num);
void copy (vector<int> arr, vector<int> &arr_temp, int num);

int main()
{
    srand(time(0));
    vector<int> arr;
    int num=10000;
    cout<<"WORK IN PROGRESS..."<<endl<<endl;
    for (int k=0; k<num; k++)
    {
        int temp=rand()%21;
        arr.push_back(temp);
    }

    vector<int> arr_temp;
    arr_temp.resize(num);

    copy(arr, arr_temp, num);
    QTime time_bubble;
    time_bubble.start();                            //Запуск таймера
    sort_bubble(arr_temp, num);
    int t_bubble=time_bubble.elapsed();             //Показ времени таймера
    cout<<"BUBBLE SORTING TIME: "<<t_bubble<<endl<<"____________________________"<<endl<<endl;

    copy(arr, arr_temp, num);
    QTime time_hoar;
    time_hoar.start();
    sort_hoar(arr_temp, 0, num-1);
    int t_hoar=time_hoar.elapsed();
    cout<<"HOAR SORTING TIME: "<<t_hoar<<endl<<"____________________________"<<endl<<endl;

    copy(arr, arr_temp, num);
    QTime time_merge;
    time_merge.start();
    sort_merge(arr_temp, 0, num-1, num);
    int t_merge=time_merge.elapsed();
    cout<<"MERGE SORTING TIME: "<<t_merge<<endl<<"____________________________"<<endl<<endl;

    copy(arr, arr_temp, num);
    QTime time_sort;
    time_sort.start();
    sort(arr_temp.begin(), arr_temp.begin()+num);                       //Стандартная сортировка С++
    int t_sort=time_sort.elapsed();

    cout<<"STANDART SORTING TIME: "<<t_sort<<endl;

    return 0;
}

void sort_bubble (vector<int> &arr, int num)                            //Сортировка пузырем
{
    for (int k=0; k<num-1; k++)
        for (int p=0; p<num-k-1; p++)
            if (arr[p]>arr[p+1])
                    swap(arr[p], arr[p+1]);
}

void sort_hoar(vector<int> &arr, int left, int right)                   //Сортировка Хоар
{
    int p=right;
    int k=left;
    int middle=(left+right+1)/2;
    do
    {
        while(arr[k]<arr[middle]) k++;
        while(arr[p]>arr[middle]) p--;
        if (k<=p)
        {
            swap(arr[k], arr[p]);
            k++;
            p--;
        }
    } while (k<=p);
    if (left<p) sort_hoar(arr, left, p);
    if (k<right) sort_hoar(arr, k, right);

}

void sort_merge (vector<int> &arr, int left, int right, int num)        //Сортировка слиянием
{
    if (left==right) return;
    if (right-left==1)
    {
        if (arr[left]>arr[right])
            swap(arr[left], arr[right]);
        return;
    }
    int mid=(left+right)/2;
    sort_merge(arr, left, mid, num);
    sort_merge(arr, mid+1, right, num);
    vector<int> arr_temp;
    arr_temp.resize(num);
    int _left=left;
    int _right=mid+1;
    int cur=0;
    while (right-left+1 != cur)
    {
        if (_left>mid)
            arr_temp[cur++]=arr[_right++];
        else if (_right>right)
            arr_temp[cur++]=arr[_left++];
        else if (arr[_left]>arr[_right])
            arr_temp[cur++]=arr[_right++];
        else arr_temp[cur++]=arr[_left++];
    }
    for (int k=0; k<cur; k++)
        arr[k+left]=arr_temp[k];
}

void copy (vector<int> arr, vector<int> &arr_temp, int num)
{
    for (int k=0; k<num; k++)
        arr_temp[k]=arr[k];
}

void show (vector<int> arr, int num)
{
    for (int k=0; k<num; k++)
        cout<<arr[k]<<" ";
    cout<<endl;
}
