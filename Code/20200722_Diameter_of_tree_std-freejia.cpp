#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string.h>
using namespace std;

// Ʈ���� ���� ���� 1967  
/*
Ʈ���� �����ϴ� ��� ��ε� �߿��� ���� �� ���� ���̸� ���Ѵ�.
����� ���� n(1 �� n �� 10,000)
��° �ٺ��� n��° �ٱ��� �� ������ ���� ����
�θ� ����� ��ȣ�� ��Ÿ����, �� ��° ������ �ڽ� ��带, �� ��° ������ ������ ����ġ

��Ʈ ����� ��ȣ�� �׻� 1�̶�� �����ϸ�, ������ ����ġ�� 100���� ũ�� ���� ���� �����̴�. 
*/

vector<pair<int,int>> node[10001];
bool check[10001] = {false, }; // �湮����  
int diameter_end;
int node_cnt;
int max_sum; // �ִ� ����  

void search_max(int start, int sum){
	int i = 0;
	 
	if(!check[start]){
		return;
	}else{
		check[start] = true; // �湮 ǥ�� 
	}
		
	if(max_sum < sum){ // ���簡 �ִ밪�̶�� �հ� �������� ����  
		max_sum = sum;
		diameter_end = start;
	}
	
	for(i = 0; i < node[start].size(); i++){
		search_max(node[start][i].first, sum + node[start][i].second);
	}
} 

int main(void){

	int first, second, len = 0;
	int i = 0;
	//freopen("input.txt", "rt", stdin);
	
	scanf("%d", &node_cnt);
	
	for(i = 0; i < node_cnt; i++){
		scanf("%d %d %d", &first, second, len);
		node[first].push_back(make_pair(second, len));
		node[second].push_back(make_pair(first, len));
	} // �Է¹ޱ� ��  
	
	search_max(1, 0); // ���� �� ���
	
	// �ʱ�ȭ  
	max_sum = 0; 
	memset(check, false, sizeof(check));
	
	// ���� �� ��� �������� ���� �� ���. 
	search_max(diameter_end, 0);
	
	printf("%d", max_sum);
	
	return 0;
}

