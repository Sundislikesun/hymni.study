#include <stdio.h>
#include <algorithm>
using namespace std;
 
// �ټ����  (����2631) by std-freejia 

 
int a[1001];  // �Է¹��� ����  
int dp[1001]; // i�� ������ ���� ������ LIS ����  
 
int main() {

	int i, j, n, ans = 0;
	
    scanf("%d",&n);
    
    for(i=1; i<=n; i++){
		scanf("%d",&a[i]); 
    }// �Է¹ޱ� �� 
    
    for(i=1; i<=n; i++){
    
        for(j=0; j<i; j++){
		
            if(a[j] < a[i])
                dp[i] = max(dp[i], dp[j]+1);
                
        	ans = max(ans, dp[i]); // ����  
        }
    }
    
    printf("%d", n - ans); // �̵��ؾ� �� �л� ��  
    
	return 0;
}
 
