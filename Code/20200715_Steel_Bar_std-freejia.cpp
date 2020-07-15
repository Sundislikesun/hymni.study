#include <string>
#include <vector>
#include <stack>
using namespace std;

// �踷��� ���α׷��ӽ� (std-freejia) 

int solution(string arrangement) {

    int answer = 0;
	int i, len = 0;
	stack<char> st;
	bool open_flag = true; // ���� ��ȣ�� ���°�ȣ���ٸ� true 
	 
	len = arrangement.size();
	
	for(i=0; i<len; i++){
		
		char pa = arrangement[i];
		
		if(pa == '(') { // ���� ��ȣ���  
			st.push(pa);
			open_flag = true;
			
		}else{ // ')' �ݴ� ��ȣ���  
		    st.pop();
			if(open_flag){ // ������: ���°�ȣ �ݴ°�ȣ �����̹Ƿ�. 
				answer += st.size();
			}else{
				answer++;
			}
			open_flag = false;
			
			
		}
	}
	

    return answer;
}
