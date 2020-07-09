#include <stdio.h>
#include <algorithm>
using namespace std;

// �ϰ������� (���� 2309) std-freejia

 
int dwarf[10];
int selected[10];
int total_sum;

void Check_select()
{	
	int i = 1, minus = total_sum; 
	
	for(i = 1; i <= 9; i++){
		if(selected[i] == 1){
			minus -= dwarf[i];
		}
	}
	
	if(100 == minus){
		for(i = 1; i <= 9; i++){
			if(selected[i] == 0){
				printf("%d\n", dwarf[i]);
				//minus = total_sum - dwarf[i];
			}
		}
		exit(0); // ���α׷� ���� 
	}
		
	return;
}

/* 9�� �߿� 2���� ���� */
void DFS(int idx, int cnt)
{
	int i = 0;
	
	if(cnt == 2){ // 2���� ��� total_sum ���� �Q���� 100���� Ȯ��  
  		
		Check_select();
		return;
	}
	
	for(i = idx; i <= 9; i++){
	
		if(selected[i] == 1) continue;
		
		selected[i] = 1;
		DFS(i, cnt+1);
		selected[i] = 0;
	}

}

int main(void)
{
	freopen("input.txt", "rt", stdin);	
	int i = 0;
	
	for(i = 1; i <= 9; i++){
		scanf("%d", &dwarf[i]);
		total_sum += dwarf[i];
	} // �Է¹ޱ� ��. 
	
	sort(dwarf, dwarf+10);
	
	DFS(1, 0);
	
	return 0;
}
