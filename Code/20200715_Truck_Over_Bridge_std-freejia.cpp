#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// �ٸ��� ������ Ʈ��   (���α׷��ӽ� std-freejia) 

int solution(int bridge_length, int weight, vector<int> truck_weights) {

	// �ð�
	int answer = 0;
	
	// ���� �� �� 
	queue<int> count;
	
	// ������ ������ ���� �Ÿ� (���θ� �󸶳� �� ���� �ϴ���)  
	queue<int> bridge_on;
	
	// ���� ���� �� ���� �հ�
	int current_weight = 0;
	
	int i = 0;
	
	while(true){
	
		//������ ������ �Ÿ� 
		int togo_size = bridge_on.size();
		
		// ���� ���ο� ���Խ�Ų��.  
		for(i = 0; i < togo_size; i++){
		
			// ���� �տ� �����ִ� ���� ���� �Ÿ�  
			int len_front = bridge_on.front();
			
			bridge_on.pop();
			
			if(len_front <= 1){ // ���� �Ÿ��� 1 ���϶��, �� ���� ���Ը� ���ܽ�Ų�� 
				current_weight -= count.front();
				count.pop();
				continue;
			} else{
				//  �Ÿ� ���ҽ�Ű�� �ٽ� push  
				bridge_on.push(--len_front); 
			}
		} 
		
		// ������ ���ѹ��� ��ŭ ���� ����ִ´�. ��� ������ 1�� �̻� �־�� ��.  
		if(truck_weights.at(0) + current_weight <= weight && truck_weights.size() > 0 ) {
			
			count.push(truck_weights.at(0)); // ���ο� �� �߰�
						
			current_weight += truck_weights.at(0); // ���� ���� ���Կ� �� ���� �߰�  
			
			truck_weights.erase(truck_weights.begin());  // ��� ���� ����  
			
			bridge_on.push(bridge_length); // �� ���� �������� ���� �Ÿ� �߰�  
			
			
		}
		
		answer++; // �ð��� ������ 
		
		if(count.size() == 0 && truck_weights.size() == 0){
			break;
		} 
	
	}
	 
    return answer;
}
