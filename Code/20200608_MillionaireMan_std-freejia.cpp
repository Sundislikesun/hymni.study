#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

// ��� 20200608_MillionaireMan  
// by std.freejia 


int main(int argc, char** argv){
	
	int arr_length = 0, min_value=0, i=0;
	
	freopen("input.txt", "rt", stdin);
	
	scanf("%d", &arr_length); // �Է¹ޱ� ����  
	
	vector<int> a_arr(arr_length), b_arr(arr_length);
	
	for(i=0; i<arr_length; i++){
		scanf("%d", &a_arr[i]);
	}
	
	for(i=0; i<arr_length; i++){
		scanf("%d", &b_arr[i]);
	}	// �Է¹ޱ� ��  
	
	sort(a_arr.begin(), a_arr.end(), greater<int>());  // ��������  
	sort(b_arr.begin(), b_arr.end()); // �������� 
	
	for(i=0; i<arr_length; i++){
		min_value += (a_arr[i]*b_arr[i]);
	}
	printf("%d", min_value);
	
	return 0;
}
